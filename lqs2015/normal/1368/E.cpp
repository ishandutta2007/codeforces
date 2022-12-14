#include<bits/stdc++.h>
using namespace std;
int test,n,m,x,y,in[222222],out[222222];
vector<int> g[222222],rg[222222],ans;
bool used[222222];
set<int> s;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
		{
			in[i]=out[i]=0;
			g[i].clear();
			rg[i].clear();
			used[i]=0;
		}
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			rg[y].push_back(x);
		}
		ans.clear();
		for (int i=1;i<=n;i++)
		{
			bool flg=0;
			for (int j=0;j<rg[i].size();j++)
			{
				int to=rg[i][j];
				if (in[to] && used[to])
				{
					flg=1;
					break;
				}
			}
			if (flg) 
			{
				used[i]=0;
				ans.push_back(i);
			}
			else
			{
				used[i]=1;
				for (int j=0;j<rg[i].size();j++)
				{
					int to=rg[i][j];
					if (used[to]) in[i]=1;
				}
			}
		}
		printf("%d\n",(int)ans.size());
		for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}