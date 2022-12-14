#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,k,cnt[222222],x[222222],y[222222],all,idx[222222],idy[222222],ans[222222];
bool used[222222];
vector<pair<int,int> > g[222222];
void upd(int i)
{
	used[i]=1;
	all--;
	for (int j=0;j<g[i].size();j++)
	{
		if (!g[i][j].second) continue;
		cnt[g[i][j].first]--;
		if (used[g[i][j].first]) continue;
		if (cnt[g[i][j].first]<k) upd(g[i][j].first);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		idx[i]=g[x[i]].size();
		idy[i]=g[y[i]].size();
		g[x[i]].push_back(make_pair(y[i],1));
		g[y[i]].push_back(make_pair(x[i],1));  
	}
	all=n;
	for (int i=1;i<=n;i++) cnt[i]=g[i].size();
	for (int i=1;i<=n;i++)
	{
		if (!used[i] && cnt[i]<k) upd(i);
	}
	ans[m]=all;
	for (int i=m;i>=2;i--)
	{
		g[x[i]][idx[i]].second=0;
		g[y[i]][idy[i]].second=0;
		if (used[x[i]]|used[y[i]])
		{
			ans[i-1]=all;
			continue;
		}
		cnt[x[i]]--;cnt[y[i]]--;
		if (cnt[x[i]]<k) upd(x[i]);
		if (!used[y[i]] && cnt[y[i]]<k) upd(y[i]);
		ans[i-1]=all;
 	}
 	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
 	return 0;
}