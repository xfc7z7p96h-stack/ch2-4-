#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <map>
class Potion;
Potion MixIngredients(int first, int second);

class Potion
{
protected:
	std::string name;
	std::string FirstIngredients;
	std::string SecondIngredients;
public:
	Potion() {};
	Potion(std::string n, std::string f, std::string s) : name(n), FirstIngredients(f) , SecondIngredients(s) {};
	std::string GetName()
	{
		return name;
	}
	std::string GetFirstIngredients()
	{
		return FirstIngredients;
	}
	std::string GetSecondIngredients()
	{
		return SecondIngredients;
	}
};
class PotionManager
{

	std::vector<Potion> potionInventory;

public:

	PotionManager() 
	{
		potionInventory.reserve(10u);
	};
	void AddPotion(const Potion& potion)
	{
		if (potionInventory.size() < potionInventory.capacity())
		{
			potionInventory.push_back(potion);
			std::cout << "potion created!!";
		}
	}
	void PrintInventoryInfo()
	{
		if (potionInventory.size() != 0)
		{
			for (int i = 0; i < potionInventory.size(); ++i)
			{
				std::cout << std::endl << i + 1 << "." << "PotionName:" << potionInventory[i].GetName() << " //" << "FirstIngredients:" << potionInventory[i].GetFirstIngredients() << " //" << "SecondIngredients:" << potionInventory[i].GetSecondIngredients();
			}
		}
		else
		{
			std::cout << std::endl << "There's no Potion yet";
		}
	}

};
class Ingredients
{
protected:
	int ingredientsNumber;
	std::string name;
public:
	std::string GetName()
	{
		return name;
	}
	int GetIngredientsNumber()
	{
		return ingredientsNumber;
	}

};
class ButterFlyWing : public Ingredients
{
public:
	ButterFlyWing() 
	{
		name = "ButterFlyWing";
		ingredientsNumber = 1;
	}
};
class MoleFur : public Ingredients
{
public:
	MoleFur()
	{
		name = "MoleFur";
		ingredientsNumber = 2;
	}
};
class RainbowInk : public Ingredients
{
public:
	RainbowInk()
	{
		name = "RainbowInk";
		ingredientsNumber = 3;
	}
};
class DriedDarkColuds : public Ingredients
{
public:
	DriedDarkColuds()
	{
		name = "DriedDarkColuds";
		ingredientsNumber = 4;
	}
};


Potion PotionCombinationTable()
{
	Potion pResult;
	int manager = 1;
	int firstItem;
	int secondItem;
	do {
		std::cout << std::endl << "=======================================================================" << std::endl;
		std::cout << "Choose the ingredient to put in your potion twice !!using numbers!!" << std::endl;
		std::cout << "1.ButterFlyWing " << "//" << "2.MoleFur " << "//" << "3.RainbowInk " << "4.DriedDarkColuds " << std::endl;
		std::cout << "firstItem:";
		std::cin >> firstItem;
		if (firstItem > 4 || firstItem < 1)
		{
			std::cout << "wrong number try again!! ex)firstItem:1  ";
			std::cin.ignore(1000, '\n');
		}
		else
		{
			manager = 0;
			std::cin.ignore(1000, '\n');
		}
	} while (manager);
	do {
		manager = 1;
		std::cout << std::endl << "=======================================================================" << std::endl;
		std::cout << "Choose the ingredient to put in your potion twice !!using numbers!!" << std::endl;
		std::cout << "1.ButterFlyWing " << "//" << "2.MoleFur " << "//" << "3.RainbowInk " << "4.DriedDarkColuds " << std::endl;
		std::cout << "SecondItem:";
		std::cin >> secondItem;
		if (firstItem == secondItem)
		{
			std::cout << std::endl << "firstItem and SecondItem can't be same!!";
		}
		else
		{
			if (secondItem > 4 || secondItem < 1)
			{
				std::cout << "wrong number try again!! ex)SecondtItem:1  ";
			}
			else
			{
				manager = 0;
			}
		}
		
	} while (manager);
	pResult = MixIngredients(firstItem, secondItem);
	return pResult;
	
}

Potion MixIngredients(int first, int second)
{
	Potion Result;
	if (first == 1 && second == 2)
	{
		Potion HpPotion("HpPotion", "ButterFlyWing", "MoleFur");
		Result = HpPotion;
	}
	else if (first == 2 && second == 1)
	{
		Potion HpPotion("HpPotion", "MoleFur", "ButterFlyWing");
		Result = HpPotion;
	}
	else if (first == 1 && second == 3)
	{
		Potion PoisonPotion("PoisonPotion", "ButterFlyWing", "RainbowInk");
		Result = PoisonPotion;
	}
	else if (first == 3 && second == 1)
	{
		Potion PoisonPotion("PoisonPotion", "RainbowInk", "ButterFlyWing");
		Result = PoisonPotion;
	}
	else if (first == 1 && second == 4)
	{
		Potion MpPotion("MpPotion", "ButterFlyWing", "DriedDarkColuds");
		Result = MpPotion;
	}
	else if (first == 4 && second == 1)
	{
		Potion MpPotion("MpPotion", "DriedDarkColuds", "ButterFlyWing");
		Result = MpPotion;
	}
	else if (first == 2 && second == 3)
	{
		Potion VampireBloodPotion("VampireBloodPotion", "MoleFur", "RainbowInk");
		Result = VampireBloodPotion;
	}
	else if (first == 3 && second == 2)
	{
		Potion VampireBloodPotion("VampireBloodPotion", "RainbowInk", "MoleFur");
		Result = VampireBloodPotion;
	}
	else if (first == 2 && second == 4)
	{
		Potion HarshDustPotion("HarshDustPotion", "MoleFur", "DriedDarkColuds");
		Result = HarshDustPotion;
	}
	else if (first == 4 && second == 2)
	{
		Potion HarshDustPotion("HarshDustPotion", "DriedDarkColuds", "MoleFur");
		Result = HarshDustPotion;
	}
	else if (first == 3 && second == 4)
	{
		Potion SildentDawn("SildentDawn", "RainbowInk", "DriedDarkColuds");
		Result = SildentDawn;
	}
	else if (first == 4 && second == 3)
	{
		Potion SildentDawn("SildentDawn", "DriedDarkColuds", "RainbowInk");
		Result = SildentDawn;
	}
	return Result;
}


	

void RecipeSearch()
{
	int answer;
	int manager = 0;
	do
	{
		std::cout << std::endl << "[Potion list: " << "1.HpPotion " << " |" << "2.PoisonPotion " << " |" << "3.MpPotion " << std::endl
			<< "4.VampireBloodPotion " << " |" << "5.HarshDustPotion " << " |" << "6.SildentDawn]" << std::endl
			<< std::endl << "[Ingredients list: " << "7.ButterFlyWing " << " |" << "8.MoleFur " << " |" << "9.RainbowInk " << "10.DriedDarkColuds]";
		std::cout << std::endl << "answer: ";
		std::cin >> answer;
		if (answer < 0 && answer > 10)
		{
			manager = 1;
		}
	} while (manager);
	switch (answer)
	{
	case 1:
		std::cout << std::endl << "[1.HpPotion:" << std::endl << "First Ingredients: ButterFlyWing(ItemNumber.1)" << " |" << "Second Ingredients: MoleFur(ItemNumber.2) ]";
		break;
	case 2:
		std::cout << std::endl << "[2.PoisonPotion:" << std::endl << "First Ingredients: ButterFlyWing(ItemNumber.1)" << " |" << "Second Ingredients: RainbowInk(ItemNumber.3) ]";
		break;
	case 3:
		std::cout << std::endl << "[3.MpPotion:" << std::endl << "First Ingredients: DriedDarkColuds(ItemNumber.4)" << " |" << "Second Ingredients: ButterFlyWing(ItemNumber.1) ]";
		break;
	case 4:
		std::cout << std::endl << "[4.VampireBloodPotion:" << std::endl << "First Ingredients: MoleFur(ItemNumber.2)" << " |" << "Second Ingredients: RainbowInk(ItemNumber.3) ]";
		break;
	case 5:
		std::cout << std::endl << "[5.HarshDustPotion:" << std::endl << "First Ingredients: MoleFur(ItemNumber.2)" << " |" << "Second Ingredients: DriedDarkColds(ItemNumber.4) ]";
		break;
	case 6:
		std::cout << std::endl << "[6.SildentDawn:" << std::endl << "First Ingredients: RainbowInk(ItemNumber.3)" << " |" << "Second Ingredients: DriedDarkColds(ItemNumber.4) ]";
		break;
	case 7:
		std::cout << std::endl << "[7.ButterFlyWing(ItemNumber.1):" << std::endl << "First Potion: HpPotion: ButterFlyWing(1) + MoleFur(2)"
			<< std::endl << "Second Potion: PosionPotion: ButterFlyWing(1) + RainbowInk(3)"
			<< std::endl << "third Potion: MpPotion: ButterFlywing(1) + DriedDarkColuds(4) ]";
		break;
	case 8:
		std::cout << std::endl << "[8.MoleFur(ItemNumber.2):" << std::endl << "First Potion: HpPotion: MoleFur(2) + ButterFlyWing(1)"
			<< std::endl << "Second Potion: VampireBloodPotion: MoleFur(2) + RainbowInk(3)"
			<< std::endl << "third Potion: HarshDustPotion: MoleFur(2) + DriedDarkColuds(4) ]";
		break;
	case 9:
		std::cout << std::endl << "[9.RainbowInk(ItemNumber.3):" << std::endl << "First Potion: PoisonPotion: RainbowInk(3) + ButterFlyWing(1)"
			<< std::endl << "Second Potion: VampireBloodPotion: MoleFur(2) + RainbowInk(3)"
			<< std::endl << "third Potion: SildentDawn: RainbowInk(3) + DriedDarkColuds(4) ]";
		break;
	case 10:
		std::cout << std::endl << "[10.DriedDarkColuds(ItemNumber.4):" << std::endl << "First Potion: MpPotion: ButterFlyWing(1) + DriedDarkColuds(4)"
			<< std::endl << "Second Potion: HarshDustPotion: MoleFur(2) + DriedDarkColuds(4)"
			<< std::endl << "third Potion: sildentDawn: RainbowInk(3) + DriedDarkColuds(4) ]";
		break;
	}
	
	
}





int main(void)
{
	PotionManager pM;
	int answer = 1;
	while (answer != 4)
	{
		
			std::cout << std::endl << "[1. Potion Inventory" << " |" << "2.Going to make Potion" << " |" << "3.Potion Dictionary" << " |" << "4.End Game]" << std::endl;
			std::cout << "answer:";
			std::cin >> answer;
			switch (answer)
			{
			case 1:
				pM.PrintInventoryInfo();
				
				break;
			case 2:
				pM.AddPotion(PotionCombinationTable());
				
				break;
			case 3:
				RecipeSearch();
				break;
			case 4:
				break;
			default:
				std::cout << std::endl << "Choose only 1~4";
				break;
			}
		

	}
	




	return 0;
}
