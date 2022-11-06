#include<iostream>
#include<cstdio>
using namespace std;
int q[101000],h=0,t=0;
int c[101000],a[101010];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int j=1;j<=m;j++)scanf("%d",&a[j]);
	int i=1,j=1,s=0;
	while(i<=n&&j<=m)
	{
		if(c[i]<=a[j])i++,j++,s++;
		else i++;
	}
	printf("%d",s);return 0;
 }