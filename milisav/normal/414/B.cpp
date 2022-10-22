#include <iostream>
#include <cstdio>
using namespace std;
int n,k;
int m=1000000007;
int a[4000][2];
int main()
{
	scanf("%d %d",&n,&k);
	int sum=0;
	for(int i=1;i<=n;i++) a[i][0]=1;
	int g=0;
	int g1;
	for(int j=1;j<k;j++)
	{
		g1=g^1;
		for(int i=1;i<=n;i++)
		{
			for(int r=1;r*i<=n;r++)
			{
				a[i*r][g1]+=a[i][g];
				if(a[i*r][g1]>=m) a[i*r][g1]-=m;
			}
		}
		for(int i=1;i<=n;i++) a[i][g]=0;
		g=g1;
	}
	for(int i=1;i<=n;i++)
	{
		sum+=a[i][g];
		if(sum>m) sum-=m;
	}
	printf("%d",sum);
	return 0;
}