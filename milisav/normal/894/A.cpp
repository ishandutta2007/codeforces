#include <bits/stdc++.h>
using namespace std;
int n;
char s[1000];
int l,r;
int sol=0;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='A')
		{
			l=0;
			r=0;
			for(int j=0;j<i;j++) if(s[j]=='Q') l++;
			for(int j=i+1;j<n;j++) if(s[j]=='Q') r++;
			sol+=l*r;
		}
	}
	printf("%d",sol);
	return 0;
}