#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
void translate(int osn, int chislo)
{
	int a[100];
	int k=0;
	while (chislo>0)
	{
		a[k]=chislo%osn;
		k++;
		chislo/=osn;
	}
	for (int i=k-1; i>=0; i--)
		cout<<a[i];
	cout<<' ';
}



int main()
{
	int n;
	cin>>n;
	for (int i=1; i<n; i++)
	{
		for (int j=1; j<n; j++)
		{
			translate(n, i*j);
		}
		cout<<endl;
	}

}