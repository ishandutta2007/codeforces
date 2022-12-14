#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int maxn=1005;
int n,cnt,ans[maxn][maxn];
int main()
{
    scanf("%d",&n);
    for(int j=1;j<=n;j+=4)
	{
		for(int i=1;i<=n;i++)
		{
			ans[i][j]=cnt++;
			ans[i][j + 1]=cnt++;
			ans[i][j + 2]=cnt++;
			ans[i][j + 3]=cnt++;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}