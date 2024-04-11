#include <iostream>
#include <cstdio>
using namespace std;
int n,k;
int a[200000];
int main()
{
	scanf("%d",&n);
	k=0;
	for(int i=2;i<=n+1;i++) a[i]=0;
	for(int i=2;i<=n+1;i++)
	{
		if(a[i]==0)
		{
			a[i]=1;
			if(k==0) k++;
			for(int j=i+i;j<=n+1;j=j+i)
			{
				if(k==1) k++;
				a[j]=2;
			}
		}
	}
	printf("%d\n",k);
	for(int i=2;i<=n+1;i++) printf("%d ",a[i]);
	return 0;
}