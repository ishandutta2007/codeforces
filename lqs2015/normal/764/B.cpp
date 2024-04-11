#include<iostream>
#include<cstdio>
using namespace std;
int n,a[222222];
bool f;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n/2;i++)
	{
		if (!f) swap(a[i],a[n-i+1]);
		f=!f;
	}
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}