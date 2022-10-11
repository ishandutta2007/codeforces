#include <bits/stdc++.h>
using namespace std;
bool ans[305][305];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if (k%n)
		puts("2");
		else
		puts("0");
		memset(ans,0,sizeof(ans));
		for (int i=0;i<n && k;i++)
		{
			for (int j=0;j<n && k;j++)
			{
				ans[j][(i+j)%n]=1;
				k--;
			}
		}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			printf("%d",ans[i][j]);
			printf("\n");
		}
	}
}