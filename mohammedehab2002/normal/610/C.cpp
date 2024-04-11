#include <iostream>
#include <set>
using namespace std;
int ans[512][512];
int main()
{
	int k;
	scanf("%d",&k);
	ans[1][1]=1;
	for (int i=2;i<=k;i++)
	{
		int sz=(1<<(i-1));
		for (int x=sz;x<2*sz;x++)
		{
			for (int j=0;j<sz;j++)
			{
				ans[j][x]=ans[j][x-sz];
				ans[x][j]=ans[x-sz][j];
				ans[x][j+sz]=!ans[x][j];
			}
		}
	}
	for (int i=0;i<(1<<k);i++)
	{
		for (int x=0;x<(1<<k);x++)
		printf("%c",ans[i][x]? '*':'+');
		printf("\n");
	}
}