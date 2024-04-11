#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int n,i,x=1;
	cin >> n;
	for (i=1;i<=500;i+=x)
	{
		x++;
		if (n==i)
		{
			cout << "YES";
			exit(0);
		}
	}
	cout << "NO";
}