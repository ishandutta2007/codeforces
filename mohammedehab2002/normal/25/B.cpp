#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int n,m1,m2,i;
	string num;
	cin >> n >> num;
	m2=n%2;
	if (m2==0)
	{
		for (i=0;i<n;i+=2)
		{
			cout << num[i] << num[i+1];
			if (i!=n-2)
			cout << "-";
		}
	}
	else
	{
		for (i=0;i<3;i++)
		cout << num[i];
		if (n!=3)
		cout << "-";
		else
		exit(0);
		for (i=3;i<n;i+=2)
		{
			cout << num[i] << num[i+1];
			if (i!=n-2)
			cout << "-";
		}
	}
}