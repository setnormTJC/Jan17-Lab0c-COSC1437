#include <iostream>
#include <vector>

#include<fstream>

using namespace std;

void print(vector<string> theIngredients)
{
    for (auto& ingredient : theIngredients) //"range-based" for loop 
    {
        cout << ingredient << endl;
    }
}


int main()
{
    srand(time(0)); 

    vector<string> sandwichIngredients =
    {
        "bacon ",
        "tuna ",
        "mayo ",
        "avocado "
    }; 

    std::ifstream ingredientFile{ "ingredients.txt" };
    if (!ingredientFile)
    {
        cout << "File not found!" << endl; 
    }

    else
    {
        cout << "File WAS found!" << endl; 

        while (!ingredientFile.eof())
        {
            string currentIngredient; 

            ingredientFile >> currentIngredient; 

            cout << currentIngredient << endl; 
        }
    }


    sandwichIngredients.push_back("NOT avocado");
    
    string response = ""; 

    while (response != "good")
    {
        int numberOfIngredients = rand() % sandwichIngredients.size() + 1;

        cout << "Number of ingredients: " << numberOfIngredients << endl;
        string sandwich = "";
        for (int i = 0; i < numberOfIngredients; i++)
        {
            sandwich = sandwich + sandwichIngredients[i]; //+ -> means "concatenate" strings
        }

        cout << "The sandwich is: \n" << sandwich << endl;
        cout << "Does that sound good (good to quit)? " << endl; 

        cin >> response; 

        system("pause");
        system("CLS");
    }
 
   // string sandwich = sandwichIngredients[0] + sandwichIngredients[1]; 

    //cout << sandwich << endl; 


    //cout << ""

    //print(sandwichIngredients);



    //string sandwichIngredients[5] = { "1", "2", "bacon", "tuna", "ham" };

    //sandwichIngredients[5] = "mayo";

    //sandwichIngredients[6] = "mayo";

    return 0;
}