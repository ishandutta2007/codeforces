#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,k=6;
	cin >> n;
	string s[n];
	for (int i=0;i<n;i++)
	{
		cin >> s[i];
		for (int x=0;x<i;x++)
		{
			int a=0;
			for (int j=0;j<6;j++)
			a+=s[i][j]!=s[x][j];
			k=min(k,(a-1)/2);
		}
	}
	cout << k;
}