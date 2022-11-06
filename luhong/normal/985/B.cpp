#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
bitset<2001> a[2010],b[2010],c[2010],d;char s[2001];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=1;j<=m;j++)a[i][j]=s[j-1]-'0';
	}
	for(int i=1;i<=n;i++)b[i]=b[i-1]|a[i];
	for(int i=n;i>=1;i--)c[i]=c[i+1]|a[i];
	bool ok=0;
	for(int i=1;i<=n;i++)
	{
		d=b[i-1]|c[i+1];
		ok|=(d.count()==m);
	}
	if(ok)puts("YES");else puts("NO");return 0;
}