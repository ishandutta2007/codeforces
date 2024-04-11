#include<bits/stdc++.h>
using namespace std;
int n,test;
char a[222],b[222],c[222];
bool f;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s%s%s",a,b,c);
		n=strlen(a);f=0;
		for (int i=0;i<n;i++)
		{
			if (a[i]==c[i] || b[i]==c[i]);
			else f=1;
		}
		if (!f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}