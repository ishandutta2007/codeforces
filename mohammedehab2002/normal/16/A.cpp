#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int n,m,i,x;
	cin >> n >> m;
	string f[n];
	for (i=0;i<n;i++)
	cin >> f[i];
	for (i=0;i<n;i++)
	{
		for (x=0;x<m-1;x++)
		{
			if (f[i][x]!=f[i][x+1])
			{
				cout << "NO";
				exit(0);
			}
		}
	}
	for (i=0;i<n-1;i++)
	{
		if (f[i][0]==f[i+1][0])
		{
			cout << "NO";
			exit(0);
		}
	}
	cout << "YES";
}