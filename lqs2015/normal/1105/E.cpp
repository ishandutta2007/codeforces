#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,tp,ed[111],ans,ct[1111111],s,fuck[1111111],dp[1111111],ed1[111],ed2[111];
bool f[111][111];
map<string,int> mp;
string ss;
vector<int> g;
int get(string &s)
{
	if (mp.find(s)==mp.end()) mp[s]=cnt++;
	return mp[s];
}
void dfs2(int i,int cnt,int msk,int cur)
{
	if (i==m-s)
	{
		dp[cur]=cnt;
		return;
	}
	if (!(msk&(1<<i))) dfs2(i+1,cnt+1,msk|ed2[i],cur|(1<<i));
	dfs2(i+1,cnt,msk,cur);
}
void dfs1(int i,int cnt,int msk,int cur)
{
	if (i==s)
	{
		ans=max(ans,cnt+dp[(1<<(m-s))-1-fuck[cur]]);
		return;
	}
	if (!(msk&(1<<i))) dfs1(i+1,cnt+1,msk|ed1[i],cur|(1<<i));
	dfs1(i+1,cnt,msk,cur);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>tp;
		if (tp==1)
		{
			sort(g.begin(),g.end());
			g.resize(unique(g.begin(),g.end())-g.begin());
			for (int i=0;i<g.size();i++)
			{
				for (int j=i+1;j<g.size();j++)
				{
					f[g[i]][g[j]]=f[g[j]][g[i]]=1;
				}
			}
			g.clear();
		}
		else
		{
			cin>>ss;
			g.push_back(get(ss)); 
		}
	}
	sort(g.begin(),g.end());
	g.resize(unique(g.begin(),g.end())-g.begin());
	for (int i=0;i<g.size();i++)
	{
		for (int j=i+1;j<g.size();j++)
		{
			f[g[i]][g[j]]=f[g[j]][g[i]]=1;
		}
	}
	s=m/2;
	for (int i=0;i<s;i++)
	{
		for (int j=s;j<m;j++)
		{
			if (f[i][j]) ed[i]|=(1<<(j-s));
		}
	}
	for (int i=0;i<(1<<20);i++)
	{
		for (int j=0;j<20;j++)
		{
			if (i&(1ll<<j)) ct[i]++;
		}
	}
	for (int i=0;i<(1<<s);i++)
	{
		for (int j=0;j<s;j++)
		{
			if (i&(1<<j)) fuck[i]|=ed[j];
		}
	}
	for (int i=0;i<s;i++)
	{
		for (int j=0;j<s;j++)
		{
			if (f[i][j]) ed1[i]|=(1<<j);
		}
	}
	for (int i=s;i<m;i++)
	{
		for (int j=s;j<m;j++)
		{
			if (f[i][j]) ed2[i-s]|=(1<<(j-s));
		}
	}
	dfs2(0,0,0,0);
	for (int i=0;i<(1<<(m-s));i++)
	{
		for (int j=0;j<m-s;j++)
		{
			if (i&(1<<j)) dp[i]=max(dp[i],dp[i^(1<<j)]);
		}
	}
	dfs1(0,0,0,0);
	printf("%d\n",ans);
	return 0;
}