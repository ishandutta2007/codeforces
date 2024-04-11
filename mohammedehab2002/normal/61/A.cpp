#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int i;
	string n1,n2;
	cin >> n1 >> n2;
	for (i=0;i<n1.size();i++)
	{
		if (n1[i]==n2[i])
		cout << 0;
		else
		cout << 1;
	}
}