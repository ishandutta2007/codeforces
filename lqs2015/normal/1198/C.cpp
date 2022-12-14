#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,x,y,cnt,m;
vector<pair<int,int> > g[555555];
vector<int> ans;
bool f[555555];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=3*n;i++) g[i].clear();
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			g[x].push_back(make_pair(y,i));
			g[y].push_back(make_pair(x,i));
		}
		ans.clear();
		for (int i=1;i<=3*n;i++) f[i]=0;
		for (int i=1;i<=3*n;i++)
		{
			if (f[i]) continue;
			for (int j=0;j<g[i].size();j++)
			{
				int to=g[i][j].first,id=g[i][j].second;
				if (!f[to])
				{
					f[i]=f[to]=1;
					ans.push_back(id);
					break;
				}
			}
		}
		if ((int)ans.size()>=n)
		{
			printf("Matching\n");
			for (int i=0;i<n;i++) printf("%d ",ans[i]);
			printf("\n");
		}
		else
		{
			printf("IndSet\n");cnt=0;
			for (int i=1;i<=3*n && cnt<n;i++)
			{
				if (!f[i])
				{
					printf("%d ",i);
					cnt++;
				}
			}
			printf("\n");
		}
	}
	return Accepted;
}