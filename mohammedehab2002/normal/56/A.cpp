#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
int main()
{
	string s,a[]={"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
	int n,i,x,ans=0;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> s;
		if (isdigit(s[0]))
		{
			if (atoi(s.c_str())<18)
			ans++;
		}
		else
		{
			for (x=0;x<11;x++)
			{
				if (a[x]==s)
				ans++;
			}
		}
	}
	cout << ans;
}