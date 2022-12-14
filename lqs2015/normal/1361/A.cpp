#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,col[555555],pos;
bool used[555555];
vector<int> g[555555];
pair<int,int> a[555555];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++) scanf("%d",&col[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<g[i].size();j++)
		{
			used[col[g[i][j]]]=1;
		}
		pos=1;
		while(used[pos]) pos++;
		if (pos!=col[i])
		{
			printf("-1\n");
			return 0;
		}
		for (int j=0;j<g[i].size();j++)
		{
			used[col[g[i][j]]]=0;
		}
	}
	for (int i=1;i<=n;i++) a[i]=make_pair(col[i],i);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) printf("%d ",a[i].second);
	printf("\n");
	return 0;
}