#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int n,i,x;
	cin >> n;
	int p[n],s[n],ps[n];
	for (i=0;i<n;i++)
	{
		cin >> p[i] >> s[i];
		ps[i]=p[i]+s[i];
	}
	for (i=0;i<n;i++)
	{
		for (x=i+1;x<n;x++)
		{
			if (ps[i]==p[x] && ps[x]==p[i])
			{
				cout << "YES";
				exit(0);
			}
		}
	}
	cout << "NO";
}