#include<bits/stdc++.h>
using namespace std;
int test,n,x,ans;
vector<int> v[222222];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			v[i].clear();
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			v[x].push_back(i);
		}
		ans=1e9;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<(int)v[i].size()-1;j++)
			{
				ans=min(ans,v[i][j+1]-v[i][j]+1);
			}
		}
		if (ans>1e8) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}