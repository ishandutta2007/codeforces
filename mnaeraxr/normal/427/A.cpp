#include <cstdlib>
#include <stdio.h>
#include <iostream>

using namespace std;


int main()
{
	int total;
	cin >> total;
	int opened = 0;
	int a;
	int crimes = 0;
	for (int i = 0; i < total; i++)
	{
		cin >> a;
		if (a != -1)
			opened += a;
		if (a == -1)
		{
			if (opened == 0)
				crimes ++;
			else
				opened--;
		}
	}
	cout << crimes << "\n";
}