

/******************************************************************************
DSU Microproject : Database to organize patients in clinic
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
//structure dec ..Objects:details, new_details
struct patients
{
	char name[20], last_name[20], email[20], address[40], contact[12], symptoms[45], disease[20], doctor[20];
	int age, id;
} details, new_details;
int id = 0;

//functions dec
void welcome();
void main_menu();
void add_patients();
void edit();
void list_all();
void view_rec_id();
void report();
void exit_function();
//main func
int main()
{
	welcome();
	main_menu();
	return 0;
}
//displays menu
void main_menu()
{
	int choice;
	system("cls");
	printf("\n\t\t\t MAIN MENU");
	printf("\n\n\t Contents: ");
	printf("\n\n\t 1. Register new patient. ");
	printf("\n\n\t 2. List the records of previous patients. ");
	printf("\n\n\t 3. Edit a record. ");
	printf("\n\n\t 4. Generate Report ");
	printf("\n\n\t 5. View Record by ID ");
	printf("\n\n\t 6. Exit");
	printf("\n\n\t\t\t Enter your choice(only enter the number of the task to be performed): ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		add_patients();
		break;
	case 2:
		list_all();
		break;
	case 3:
		edit();
		break;
	case 4:
		report();
		break;
	case 5:
		view_rec_id();
		break;
	case 6:
		exit_function();
		break;
	default:
		printf("\n\t\tAn error occurred while running the program....");
	}
}
//displays title
void welcome()
{
	printf("\n______________________________________________________________________________________________________________________________");
	printf("\n\t\t\tCure 'N Care.");
	printf("\n\tAddress: Cure 'n Care, Devlali-camp, Nashik Rd, Nashik-422 401'");
	printf("\n\t\tContact: 8236945789\tPhone no: 0253 - 2490503.");
	printf("\n______________________________________________________________________________________________________________________________");
}

//for updation of a record
void edit()
{
	FILE *read, *write; // both of them points to same file, but opens them in diff mode
	int choice;
	int patient_id; //for comparison
	system("cls");
	welcome();
	read = fopen("store_data.txt", "r"); //Opens in read mode. And compares the entered patient_id with id's stored in same file
	if (read == NULL)
	{
		printf("\n\t Can not open file!! ");
		getch();
		main_menu();
	}
	printf("\n\n\t\tEdit record.\n");
	printf("\nEnter the ID no. of the Patient : ");
	scanf("%d", &patient_id);
	while (fscanf(read, "\n%d \t%s\t %s\t %d\t %s \t%s \t%s \t%s \t%s \t%s\n", &details.id, details.name, details.last_name, &details.age, details.contact, details.email, details.address, details.symptoms, details.disease, details.doctor) != EOF)
	{
		if (details.id == patient_id)
		{
			printf("\nORIGINAL RECORD OF PATIENT..");
			printf("\n%d %s\t %s\t %d\t %s \t%s \t%s \t%s \t%s \t%s\n", details.id, details.name, details.last_name, details.age, details.contact, details.email, details.address, details.symptoms, details.disease, details.doctor);
			printf("\n\n*Enter new details*"); //gets new details of patients
			printf("\nID: ");				   //Id remains the same ..No need to enter again
			printf("\n%d", details.id);
			printf("\nEnter your name: ");
			scanf("%s", details.name);
			printf("\nLast_name: ");
			scanf("%s", details.last_name);
			printf("\nAge: ");
			scanf("%d", &details.age);
			printf("\nContact: ");
			scanf("%s", details.contact);
			printf("\nE-mail: ");
			scanf("%s", details.email);
			printf("\nAddress: ");
			scanf("%s", details.address);
			printf("\nSymptoms: ");
			scanf("%s", details.symptoms);
			printf("\nDiseases: ");
			scanf("%s", details.disease);
			printf("\nDoctor Consulted: ");
			scanf("%s", details.doctor);
			printf("Enter 1 for updating the record : ");
			scanf("%d", &choice);
			if (choice == 1)
			{
				write = fopen("store_data.txt", "a"); //Opens same file in write mode and stores the data
				if (write == NULL)
				{
					printf("\n Cannot open the file..");
				}
				fprintf(write, "\n%d \t%s\t %s\t %d\t %s \t%s \t%s \t%s \t%s \t%s\n", details.id, details.name, details.last_name, details.age, details.contact, details.email, details.address, details.symptoms, details.disease, details.doctor);
				printf("\n%d %s \t%s \t%d \t%s \t%s \t%s \t%s \t%s \t%s\n", details.id, details.name, details.last_name, details.age, details.contact, details.email, details.address, details.symptoms, details.disease, details.doctor);
				printf("\nRecord updated successfully..");
				goto x;
			}
			else
			{
				printf("\nAn error occurred.");
			}
		}
		//And This else statement isn't working...Even when it has a previous if
		/*else{
				printf("\nRecord not found..:(\n Check your id no. ..");
	        }*/
	}
	x:
	fclose(read);
	fclose(write);
	getch();
	main_menu();
}

//registers new patients
void add_patients()
{
	system("cls");
	welcome();
	int choice;
	FILE *store_info;
registration: //label for goto statement at end of the func.
			  //Inputs details of patients
	printf("\n Enter the following details :");
	printf("\nID: ");
	scanf("%d", &details.id);
	printf("\nFirst_Name: ");
	scanf("%s", details.name);
	printf("\nLast_Name: ");
	scanf("%s", details.last_name);
	printf("\nAge: ");
	scanf("%d", &details.age);
	printf("\nContact no. : ");
	scanf("%s", details.contact);
	if (strlen(details.contact) > 10)
	{
		printf("\nYou can only store 10 digits..\n");
		printf("\n*Please enter again \nContact no. : ");
		scanf("%s", details.contact);
	}
	printf("\nE-mail id: ");
	scanf("%s", details.email);
	printf("\nAddress: ");
	scanf("%s", details.address);
	printf("\nSymptoms: ");
	scanf("%s", details.symptoms);
	printf("\nDisease: ");
	scanf("%s", details.disease);
	printf("\nDoctor Consulted: ");
	scanf("%s", details.doctor);
	//creates & stores the details in "store_data.txt"
	store_info = fopen("store_data.txt", "a");
	fprintf(store_info, " %d \t%s\t %s\t %d\t %s \t%s \t%s \t%s \t%s \t%s\n", details.id, details.name, details.last_name, details.age, details.contact, details.email, details.address, details.symptoms, details.disease, details.doctor);
	fclose(store_info);
	printf("\nDo you want to continue (1 for yes/ 2 for no): ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		goto registration;
	case 2:
		exit_function();
	default:
		printf("Error occurred..:(:(");
	}
}


//displays the list of all patients with their details
void list_all()
{
	int choice;
	system("cls");
	welcome();
	FILE *read_data;
	read_data = fopen("store_data.txt", "r");
	while (fscanf(read_data, "%d %s %s %d %s %s %s %s %s %s\n", &details.id, details.name, details.last_name, &details.age, details.contact, details.email, details.address, details.symptoms, details.disease, details.doctor) != EOF)
	{
		printf("\nID: %d\t", details.id);
		printf("\tName: %s\t", details.name);
		printf("Last_Name: %s\t", details.last_name);
		printf("Age: %d\t", details.age);
		printf("Contacts: %s\t", details.contact);
		printf("Email id: %s\t", details.email);
		printf("Address: %s\n", details.address);
		printf("Symptoms: %s\t", details.symptoms);
		printf("Diseases: %s\t", details.disease);
		printf("Doctor Consulted: %s\t\n", details.doctor);
	}
	fclose(read_data);
	getch();
	main_menu();
}

void view_rec_id()
{
	FILE *read; // both of them points to same file, but opens them in diff mode
	int choice;
	int patient_id; //for comparison
	system("cls");
	welcome();
	read = fopen("store_data.txt", "r"); //Opens in read mode. And compares the entered patient_id with id's stored in same file
	if (read == NULL)
	{
		printf("\n\t Can not open file!! ");
		getch();
		main_menu();
	}
	printf("\n\n\t\tView record by ID.\n");
	printf("\nEnter the ID no. of the Patient : ");
	scanf("%d", &patient_id);
	while (fscanf(read, "\n%d \t%s\t %s\t %d\t %s \t%s \t%s \t%s \t%s \t%s\n", &details.id, details.name, details.last_name, &details.age, details.contact, details.email, details.address, details.symptoms, details.disease, details.doctor) != EOF)
	{
		if (details.id == patient_id)
		{
			printf("Enter 1 for viewing the record : ");
			scanf("%d", &choice);
			if (choice == 1)
			{
				read = fopen("store_data.txt", "a"); //Opens same file in write mode and stores the data
				if (read == NULL)
				{
					printf("\n Cannot open the file..");
				}
				printf("\n\n\n\t\t\t_____________________________________________________________________________________________________\n");
				printf("\t\t\t|  _______________________________________________________________________________________________  |\n");
				printf("\t\t\t| |                                                                                               | |\n");
				printf("\t\t\t| |                               Details of the Patient By Id                                    | |\n");
				printf("\t\t\t| |_______________________________________________________________________________________________| |\n");
				printf("\t\t\t|___________________________________________________________________________________________________|\n");
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    ID: %i                                                                                        \n", details.id);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Name: %s %s                                                                                   \n", details.name, details.last_name);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Age: %i                                                                                        \n", details.age);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Email: %s                                                                                      \n", details.email);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Contact No: %s                                                                                 \n", details.contact);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Address: %s                                                                                    \n", details.address);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Symptoms: %s                                                                                   \n", details.symptoms);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Disease:  %s                                                                                   \n", details.disease);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Doctor Consulted: %s                                                                              \n", details.doctor);
				printf("\t\t\t ___________________________________________________________________________________________________\n");
				printf("\t\t\t|___________________________________________________________________________________________________|\n");
				printf("\n%d %s \t%s \t%d \t%s \t%s \t%s \t%s \t%s \t%s\n", details.id, details.name, details.last_name, details.age, details.contact, details.email, details.address, details.symptoms, details.disease, details.doctor);
				printf("\nRecord Retrievely successfully..");
			}
			else
			{
				printf("\nAn error occurred.");
			}
		}
	}
	fclose(read);
	getch();
	main_menu();
}

void report()
{
	FILE *read; // both of them points to same file, but opens them in diff mode
	int choice;
	int patient_id; //for comparison
	system("cls");
	welcome();
	read = fopen("store_data.txt", "r"); //Opens in read mode. And compares the entered patient_id with id's stored in same file
	if (read == NULL)
	{
		printf("\n\t Can not open file!! ");
		getch();
		main_menu();
	}
	printf("\n\n\t\tView record by ID.\n");
	printf("\nEnter the ID no. of the Patient : ");
	scanf("%d", &patient_id);
	while (fscanf(read, "\n%d \t%s\t %s\t %d\t %s \t%s \t%s \t%s \t%s \t%s\n", &details.id, details.name, details.last_name, &details.age, details.contact, details.email, details.address, details.symptoms, details.disease, details.doctor) != EOF)
	{
		if (details.id == patient_id)
		{
			printf("Enter 1 for viewing the report : ");
			scanf("%d", &choice);
			if (choice == 1)
			{
				read = fopen("store_data.txt", "a");
				if (read == NULL)
				{
					printf("\n Cannot open the file..");
				}
				printf("\n\n\n\t\t\t_____________________________________________________________________________________________________\n");
				printf("\t\t\t|  _______________________________________________________________________________________________  |\n");
				printf("\t\t\t| |                                                                                               | |\n");
				printf("\t\t\t| |                               Generated Report and Bill                                       | |\n");
				printf("\t\t\t| |_______________________________________________________________________________________________| |\n");
				printf("\t\t\t|___________________________________________________________________________________________________|\n");
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Name: %s %s                                                                                   \n", details.name, details.last_name);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Age: %i                                                                                        \n", details.age);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Email: %s                                                                                      \n", details.email);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Contact No: %s                                                                                 \n", details.contact);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Address: %s                                                                                    \n", details.address);
				printf("\t\t\t __________________________________________________________________________________________________\n");
				printf("\t\t\t|__________________________________________________________________________________________________|\n");
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Symptoms: %s                                                                                      \n", details.symptoms);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Disease:  %s                                                                                     \n", details.disease);
				printf("\t\t\t                                                                                                  \n");
				printf("\t\t\t    Doctor Consulted: %s                                                                              \n", details.doctor);
				printf("\t\t\t ___________________________________________________________________________________________________\n");
				printf("\t\t\t|  _______________________________________________   _____________________________________________  |\n");
				printf("\t\t\t| |                                               | |                                             | |\n");
				printf("\t\t\t| |   ########  ##      ##   ########             | |  Treatment Cost                  3000       | |\n");
				printf("\t\t\t| |   ##        ####    ##   ##                   | |  Diagnosis                       2000       | |\n");
				printf("\t\t\t| |   ##        ## ##   ##   ##                   | |  Medicine Cost                   3000       | |\n");
				printf("\t\t\t| |   ##        ##   ## ##   ##                   | |  Consultation                    4000       | |\n");
				printf("\t\t\t| |   ##        ##    ####   ##                   | |  Critical Care                   3000       | |\n");
				printf("\t\t\t| |   ########  ##      ##   ########             | |_____________________________________________| |\n");
				printf("\t\t\t| |   Cure        N          Care      Clinic     | |  Total                           15000/-    | |\n");
				printf("\t\t\t| |_______________________________________________| |_____________________________________________| |\n");
				printf("\t\t\t|___________________________________________________________________________________________________|\n");
				printf("\n%d %s \t%s \t%d \t%s \t%s \t%s \t%s \t%s \t%s\n", details.id, details.name, details.last_name, details.age, details.contact, details.email, details.address, details.symptoms, details.disease, details.doctor);
				printf("\nRecord Retrievely successfully..");
			}
			else
			{
				printf("\nAn error occurred.");
			}
		}
	}
	fclose(read);
	getch();
	main_menu();
}
//Exit fun ..You may improve this one. I haven't work that much on this function..

void exit_function()
{
	system("cls");
	printf("\n\n\n\t\t\t_____________________________________________________________________________________________________\n");
	printf("\t\t\t|  _______________________________________________________________________________________________  |\n");
	printf("\t\t\t| |                                                                                               | |\n");
	printf("\t\t\t| |                                     Thanks for visiting..:)                                   | |\n");
	printf("\t\t\t| |_______________________________________________________________________________________________| |\n");
	printf("\t\t\t|___________________________________________________________________________________________________|\n");
	getch;
	return 0;
}
