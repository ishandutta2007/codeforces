#include <bits/stdc++.h>
using namespace std;
char f[20];
char s[20];
bool p,d;
int n,m;
int main()
{
	scanf("%s %s",f,s);
	n=strlen(f);
	m=strlen(s);
	int k=0,l=0;
	while(!p || !d)
	{
		while(!p || (k<n && f[k]<s[l]))
		{
			p=true;
			cout<<f[k];
			k++;
		}
		d=true;
		cout<<s[l];
		l++;
	}
	return 0;
}