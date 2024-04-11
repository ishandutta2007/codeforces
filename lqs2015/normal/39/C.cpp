#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int w[4444],dp[4444],n,c,R,l[4444],r[4444],s[4444],cnt;
pair<pair<int,int>,int> a[4444];//(r,-l)
map<int,int> mp;
vector<int> g[4444],wg[4444],ans;
int get(int id)
{
	if (w[id]!=-1) return w[id];
	vector<int> v;
	v.resize(cnt+1);
	for (int i=l[id];i<=r[id];i++)
	{
		v[i]=v[i-1];
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			if (l[to]>=l[id] && to!=id) 
			{
				v[i]=max(v[i],v[l[to]]+get(to));
			}
		}
	}
	if (!v[r[id]])
	{
		wg[id].push_back(id);
		return w[id]=1;
	}
	int pos=r[id];
	while(pos>=l[id])
	{
		while(pos>=l[id] && v[pos]==v[pos-1]) pos--;
		if (pos<l[id]) break;
		for (int j=0;j<g[pos].size();j++)
		{
			int to=g[pos][j];
			if (l[to]>=l[id] && to!=id) 
			{
				if (v[pos]==v[l[to]]+w[to])
				{
					for (int k=0;k<wg[to].size();k++) wg[id].push_back(wg[to][k]); 
					pos=l[to];
					break;
				}
			}
		}
	}
	wg[id].push_back(id);
	return w[id]=v[r[id]]+1; 
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&c,&R);
		l[i]=c-R;r[i]=c+R;
		a[i]=make_pair(make_pair(r[i],-l[i]),i);
		s[++cnt]=l[i];s[++cnt]=r[i];
	}
	sort(a+1,a+n+1);
	sort(s+1,s+cnt+1);
	cnt=unique(s+1,s+cnt+1)-s-1;
	for (int i=1;i<=cnt;i++)
	{
		mp[s[i]]=i;
	}
	for (int i=1;i<=n;i++)
	{
		l[i]=mp[l[i]];r[i]=mp[r[i]];
		g[mp[a[i].first.first]].push_back(a[i].second); 
	}
	memset(w,-1,sizeof(w));
	for (int i=1;i<=cnt;i++)
	{
		dp[i]=dp[i-1];
		for (int j=0;j<g[i].size();j++)
		{
			int id=g[i][j];
			dp[i]=max(dp[i],dp[l[id]]+get(id));
		}
	}
	printf("%d\n",dp[cnt]);
	int pos=cnt;
	while(pos>=1)
	{
		while(pos>=1 && dp[pos]==dp[pos-1]) pos--;
		if (pos<1) break;
		for (int j=0;j<g[pos].size();j++)
		{
			int to=g[pos][j];
			if (dp[pos]==dp[l[to]]+w[to])
			{
				for (int k=0;k<wg[to].size();k++) ans.push_back(wg[to][k]); 
				pos=l[to];
				break;
			}
		}
	}
	sort(ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
}