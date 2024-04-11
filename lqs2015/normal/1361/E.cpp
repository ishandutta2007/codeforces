#include<bits/stdc++.h>
using namespace std;
int test,n,m,x,y,rt,pa[111111],beg[111111],en[111111],cnt,ff[111111];
vector<int> g[111111],ng[111111];
vector<int> to_add[111111],ans;
bool dp[111111];
multiset<int> s[111111];
int Get(int x)
{
	return ((rand()<<10)+rand())%x+1;
}
void dfs(int i,int fa)
{
	beg[i]=++cnt;pa[i]=fa;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (beg[to]) continue;
		dfs(to,i);
	}
	en[i]=cnt;
}
bool check(int rt)
{
	cnt=0;
	for (int i=1;i<=n;i++) beg[i]=pa[i]=0;
	dfs(rt,0);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			if (pa[to]==i) continue;
			if (beg[to]<=beg[i] && en[to]>=en[i]);
			else return 0;
		}
	}
	return 1;
}
void dft(int i)
{
	int mxp=-1;
	for (int j=0;j<ng[i].size();j++)
	{
		int to=ng[i][j];
		dft(to);
		if (mxp==-1 || (int)s[to].size()>(int)s[mxp].size()) mxp=to;
	}
	if (mxp!=-1) swap(s[i],s[mxp]);
	for (int j=0;j<ng[i].size();j++)
	{
		int to=ng[i][j];
		if (to==mxp) continue;
		for (multiset<int>::iterator it=s[to].begin();it!=s[to].end();it++)
		{
			s[i].insert(*it);
		}
	}
	for (int j=0;j<to_add[i].size();j++) s[i].insert(to_add[i][j]);
	while(s[i].find(i)!=s[i].end()) 
	{
		s[i].erase(s[i].find(i));
	}
	if (s[i].size()>1) ff[i]=0;
	else if (s[i].size()==1) ff[i]=*s[i].begin();
}
void calc(int i)
{
	if (!~ff[i]) 
	{
		dp[i]=1;
		ans.push_back(i);
	}
	else if (ff[i]) 
	{
		dp[i]=dp[ff[i]];
		if (dp[i]) ans.push_back(i);
	}
	else dp[i]=0;
	for (int j=0;j<ng[i].size();j++)
	{
		int to=ng[i][j];
		calc(to);
	}
}
int main()
{
	srand(993217);
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
		}
		rt=0;
		for (int i=1;i<=100;i++)
		{
			x=Get(n);
			if (check(x))
			{
				rt=x;
				break;
			}
		}
		if (!rt)
		{
			printf("-1\n");
			continue;
		}
		ans.clear();
		for (int i=1;i<=n;i++)
		{
			ng[i].clear();
			to_add[i].clear();
			s[i].clear();
		}
		for (int i=1;i<=n;i++)
		{
			if (i!=rt) ng[pa[i]].push_back(i);
			for (int j=0;j<g[i].size();j++)
			{
				int to=g[i][j];
				if (pa[to]==i) continue;
				to_add[i].push_back(to);
			}
		}
		for (int i=1;i<=n;i++) ff[i]=-1;
		dft(rt);
		for (int i=1;i<=n;i++) dp[i]=0; 
		calc(rt);
		if ((int)ans.size()*5<n) 
		{
			printf("-1\n");
			continue;
		}
		sort(ans.begin(),ans.end());
		for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}