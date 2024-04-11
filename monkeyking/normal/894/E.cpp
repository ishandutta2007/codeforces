#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,m;
vector <pair<int,int> > vec[1000005];
vector <int> rvec[1000005];
vector <int> order;
bool visit[1000005];
vector <int> scc[1000005];
int p;
int col[1000005];
vector <pair<int,int> >nvec[1000005];
ll cost[1000005];
ll dp[1000005];
ll save[20005];

void rdfs(int x)
{
	visit[x]=true;
	for(auto u:rvec[x])
	{
		if(visit[u]) continue;
		rdfs(u);
	}
	order.push_back(x);
}

void dfs(int x,int color)
{
	visit[x]=true;
	col[x]=color;
	scc[color].push_back(x);
	for(auto u:vec[x])
	{
		if(visit[u.first]) continue;
		dfs(u.first,color);
	}
}


inline ll calc(int x)
{
//	ll res=0;
//	int pe=0;
//	while(x>=0)
//	{
//		res+=x;
//		x-=++pe;
//	}
//	return res;
	int l=0,r=2e4,mid,res;
	while(l<=r)
	{
		mid=l+r>>1;
		if(mid*(mid+1)/2>x)
		{
			r=mid-1;
		}
		else
		{
			res=mid;
			l=mid+1;
		}
	}
	ll ans=1LL*(res+1)*x;
	ans-=save[res];
//	ans-=res*(res+1)/2;
	return ans;
}

void tpdfs(int x)
{
	visit[x]=true;
	for(int i=0;i<nvec[x].size();i++)
	{
		if(visit[nvec[x][i].first]) continue;
		tpdfs(nvec[x][i].first);
	}
	order.push_back(x);
}

int main()
{
	save[0]=0;
	save[1]=1;
	for(int i=2;i<=2e4+1;i++)
	{
		save[i]=save[i-1]+1LL*i*i;
	}
	for(int i=0;i<=2e4+1;i++)
	{
		save[i]=1LL*(i+1)*(i)*(i+1)/2-save[i];
	}
//	for(int i=0;i<4;i++)
//	{
//		cout<<save[i]<<' ';
//	}
//	cout<<endl;
//	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&m);
	int x,y,z;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		x--;
		y--;
		vec[x].push_back(mp(y,z));
		rvec[y].push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		if(!visit[i]) rdfs(i);
	}
	memset(visit,0,sizeof(visit));
//	for(int i=n-1;i>=0;i--)
//	{
//		cout<<order[i]<<' ';
//	}
//	cout<<endl;
	for(int i=n-1;i>=0;i--)
	{
		if(!visit[order[i]]) dfs(order[i],p++);
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<col[i]<<' ';
//	}
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			if(col[i]==col[vec[i][j].first])
			{
				cost[col[i]]+=calc(vec[i][j].second);
			}
			else
			{
				nvec[col[i]].push_back(mp(col[vec[i][j].first],vec[i][j].second));
			}
		}
	}
	order.clear();
	memset(visit,0,sizeof(visit));
	for(int i=0;i<p;i++)
	{
		if(visit[i]) continue;
		tpdfs(i);
	}
	reverse(all(order));
	for(int i=0;i<p;i++)
	{
		dp[i]=-1LL*inf*inf;
	}
	int st;
	cin>>st;
	st--;
	dp[col[st]]=cost[col[st]];
//	for(int i=0;i<p;i++)
//	{
//		cout<<order[i]<<' ';
//	}
//	cout<<endl;
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<nvec[order[i]].size();j++)
		{
			dp[nvec[order[i]][j].first]=max(dp[nvec[order[i]][j].first],dp[order[i]]+nvec[order[i]][j].second+cost[nvec[order[i]][j].first]);
		}
	}
	ll res=0;
//	for(int i=0;i<n;i++)
//	{
//		cout<<col[i]<<' ';
//	}
//	cout<<endl;
//	for(int i=0;i<p;i++)
//	{
//		cout<<dp[i]<<' ';
//	}
//	cout<<endl;
	for(int i=0;i<p;i++)
	{
		res=max(res,dp[i]);
	}
	cout<<res<<endl;
	return 0;
}