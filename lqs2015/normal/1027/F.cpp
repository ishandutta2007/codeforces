#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
int n,x[2222222],y[2222222],cnt,cntv,mx,cnte,val[2222222],mxx,ans;
map<int,int> mp;
vector<int> g[2222222];
bool used[2222222];
void dfs(int i)
{
	cntv++;
	used[i]=1;
	if (val[i]>mx)
	{
		mxx=mx;
		mx=val[i];
	}
	else if (val[i]>mxx) mxx=val[i];
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		cnte++;
		if (!used[to]) dfs(to);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if (mp.find(x[i])==mp.end()) 
		{
			mp[x[i]]=++cnt;
			val[cnt]=x[i];
		}
		if (mp.find(y[i])==mp.end()) 
		{
			mp[y[i]]=++cnt;
			val[cnt]=y[i];
		}
		x[i]=mp[x[i]];
		y[i]=mp[y[i]];
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);  
	}
	for (int i=1;i<=cnt;i++)
	{
		if (!used[i])
		{
			cntv=cnte=mx=mxx=0;
			dfs(i);
			cnte/=2;
			if (cnte>cntv)
			{
				printf("-1\n");
				return 0;
			}
			if (cnte==cntv)
			{
				ans=max(ans,mx);
			}
			else ans=max(ans,mxx);
		}
	}
	printf("%d\n",ans);
	return 0;
}