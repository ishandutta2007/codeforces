#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int pa[2222222],n,k,a,len;
char str[1111111],ans[2222222];
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return;
	pa[rx]=ry;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=2000000;i++) pa[i]=i;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",str);
		scanf("%d",&k);
		int sz=strlen(str);
		for (int j=1;j<=k;j++)
		{
			scanf("%d",&a);
			for (int k=a;k<a+sz;k=root(k))
			{
				ans[k]=str[k-a];
				Union(k,k+1);
			}
			len=max(len,a+sz-1);
		}
	}
	for (int i=1;i<=len;i++)
	{
		if (!ans[i]) printf("a");
		else printf("%c",ans[i]);
	}
	printf("\n");
	return 0;
}