#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[222222];
int main()
{
	cin>>n;
	if (n%2==0)
	{
		printf("NO\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		if (i%2==1)
		{
			a[i]=i*2-1;
			a[i+n]=i*2;
		}
		else
		{
			a[i]=i*2;
			a[i+n]=i*2-1;
		}
	}
	printf("YES\n");
	for (int i=1;i<=2*n;i++) printf("%d ",a[i]);
	printf("\n");
	return Accepted;
}