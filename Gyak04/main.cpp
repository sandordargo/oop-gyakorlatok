#include "stdafx.h"
#include "avltree.h"
#include <vector>
#include <iostream>


int main()
{
	AvlTree mytree;
	std::vector<int> numbersToInsert = {
		10, 5, 15, 7, 3, 3, 2, 8, 1, 14, 16, 17, 18, 19, 20
		// adding these numbers shows we really need to implement
		// balancing in all 4 cases!!
	};

	for (std::vector<int>::const_iterator i = numbersToInsert.begin();
		i != numbersToInsert.end();
		i++) {
		mytree.insert(*i);
	}

	std::cout << "Here is the tree, hopefully in sorted order:" << std::endl;
	mytree.printTreeAsList();
	std::cout << std::endl;
	mytree.printTree();

	AvlTree mytree2 = mytree; //also uses copy constructor! not assignment! - at least in visual studio...
	AvlTree mytree3(mytree2);
	AvlTree mytree4;
	mytree4 = mytree2; // mytree4 mar letezik, ezert ez assignment
	//we need copy assignment, not just copy constructor
	// ha van destruktor, DE copy assignment meg nincs, akkor
	// kilepeskor exception-t dob (read access violation), mert
	// mytree2-t elobb torli, tehat, a mytree4-nek mar nincsenek valid pointerei!
	// mytree4 = AvlTree(); //csak akkor mukodik, ha operator= const referenciat var, mert bal oldali referencia nem lehet jobb oldali ertek!

	mytree2.insert(66);
	mytree.printTreeAsList();
	mytree2.printTreeAsList();
	mytree3.printTreeAsList();
	mytree4.printTreeAsList();

	// what if
	int mytreeInt = 5;
	int mytreeInt2 = mytreeInt;
	int mytreeInt3(mytreeInt2);

	mytreeInt2 = 6;
	std::cout << "mytreeInt = " << mytreeInt << std::endl;
	std::cout << "mytreeInt2 = " << mytreeInt2 << std::endl;
	std::cout << "mytreeInt3 = " << mytreeInt3 << std::endl;

	char c;
	std::cin >> c;
	return 0;
}
