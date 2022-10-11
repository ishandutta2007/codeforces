#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
	int n,k,i;
	cin >> n >> k;
	for (i=0;i<min(n,k);i++)
	{
		if (min(n,k)==n)
		cout << 'G' << 'B';
		else
		cout << 'B' << 'G';
	}
	for (i=min(n,k);i<max(n,k);i++)
	{
		if (max(n,k)==n)
		cout << 'B';
		else
		cout << 'G';
	}
}