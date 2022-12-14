#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>
using namespace std;
int a[222],b[222],c[222],n;
int main()
{
	scanf("%d",&n);
	a[0]=1;
	for (int i=1;i<=n;i++)
	{
		c[0]=0;
		for (int j=1;j<=n;j++) c[j]=a[j-1];
		for (int j=0;j<=n;j++) c[j]=(c[j]+b[j])%2;
		for (int j=0;j<=n;j++) b[j]=a[j];
		for (int j=0;j<=n;j++) a[j]=c[j];
	}
	/*if (a[n]==-1) 
	{
		for (int i=0;i<=n;i++) a[i]=-a[i];
	}
	if (b[n-1]==-1)
	{
		for (int i=0;i<=n;i++) b[i]=-b[i];
	}*/
	printf("%d\n",n);
	for (int i=0;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	printf("%d\n",n-1);
	for (int i=0;i<n;i++) printf("%d ",b[i]);
	return 0;
}