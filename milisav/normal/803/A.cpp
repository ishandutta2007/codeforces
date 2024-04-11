#include <bits\stdc++.h>
using namespace std;
int n,k;
int a[200][200];
int main()
{
	scanf("%d %d",&n,&k);
	if(k>n*n)
	{
		printf("-1");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(k>=1)
		{
			k--;
			a[i][i]=1;
		}
		for(int j=i+1;j<n;j++)
		{
			if(k>=2)
			{
				k=k-2;
				a[i][j]=1;
				a[j][i]=1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}