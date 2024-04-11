#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,x,j,e=8;
	string s,a[]={"vaporeon","jolteon","flareon","espeon","umbreon","leafeon","glaceon","sylveon"};
	cin >> n >> s;
	for (i=0;i<e;i++)
	{
		if (a[i].size()!=n)
		{
			e--;
			for (x=i;x<e;x++)
			a[x]=a[x+1];
			i--;
		}
	}
	for (i=0;i<s.size() && e>1;i++)
	{
		for (x=0;x<e;x++)
		{
			if (a[x][i]!=s[i] && s[i]!='.')
			{
				e--;
				for (j=x;j<e;j++)
				a[j]=a[j+1];
				x--;
			}
		}
	}
	cout << a[0];
}