#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[105][5];
int n,Ans,b[105];
bool check(int i)
{
	for (int j=1;j<=n;j++)
		for (int k=j+1;k<=n;k++)
			if (i!=j&&i!=k)
			{
				ll tmp=0;
				for (int l=1;l<=5;l++) 
					tmp+=(a[j][l]-a[i][l])*(a[k][l]-a[i][l]);
				if (tmp>0) return 0;
			}
	return 1;
}
int main()
{
	scanf("%d",&n);
	if (n>66)
	{
		puts("0");
	}
	else
	{
		for (int i=1;i<=n;i++)
		for (int j=1;j<=5;j++)
			scanf("%I64d",&a[i][j]);
		for (int i=1;i<=n;i++)
		{
			Ans+=b[i]=check(i);
		}
		printf("%d\n",Ans);
		for (int i=1;i<=n;i++)
		if (b[i])
		{
			printf("%d\n",i);
		}
	}
}