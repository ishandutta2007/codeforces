#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const double eps=1e-9;
int n,x,y,sub[555555],a[555555],cnt,top;
vector<int> g[555555];
long long dp[555555],cx,ans;
pair<long long,long long> q[1111111],xx,yy,add;
void dfs(int i,int fa)
{
	sub[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		sub[i]+=sub[to];
	}
}
void dft(int i,int fa)
{
	long long mn=1e18;int mto=-1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dft(to,i);
		if (mn>1ll*(sub[i]-sub[to])*(sub[i]-sub[to])+dp[to]) 
		{
			mn=1ll*(sub[i]-sub[to])*(sub[i]-sub[to])+dp[to];
			mto=to;
		}
	}
	if (!~mto) 
	{
		dp[i]=1;
	}
	else dp[i]=mn;
}
bool cmp(int x,int y)
{
	return (sub[x]>sub[y]);
}
double slope(pair<long long,long long> x,pair<long long,long long> y)
{
	return (double)(x.second-y.second)/(double)(x.first-y.first);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	dft(1,0);
	ans=1e18;
	for (int i=1;i<=n;i++)
	{
		cnt=0;
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			if (sub[to]>=sub[i]) continue;
			a[++cnt]=to;
		}
		if (cnt==1)
		{
			ans=min(ans,dp[a[1]]+1ll*(n-sub[i]+1)*(n-sub[i]+1));
			continue;
		}
		sort(a+1,a+cnt+1,cmp);
		top=0;
		for (int j=1;j<=cnt;j++)
		{
			cx=sub[i]-sub[a[j]]+(n-sub[i]);
			if (top>0)
			{
				while(top>1)
				{
					xx=q[top-1];yy=q[top-2];
					if (-xx.first*cx+xx.second>-yy.first*cx+yy.second) top--;
					else break;
				}
				xx=q[top-1];
				ans=min(ans,-xx.first*cx+xx.second+cx*cx+dp[a[j]]);
			}
			add=make_pair(2ll*sub[a[j]],1ll*sub[a[j]]*sub[a[j]]+dp[a[j]]);
			while(top>1)
			{
				xx=q[top-1];yy=q[top-2];
				if (slope(add,xx)<slope(xx,yy)+eps) top--;
				else break;
			}
			q[top++]=add;
		}
	}
	printf("%lld\n",(2ll*n*n-n-ans)/2);
	return Accepted;
}