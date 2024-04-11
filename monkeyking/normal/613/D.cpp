#include <numeric>
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
#include <assert.h>
#include <bitset>
#include <time.h>
#define Endl endl
#define mp make_pair
#define mt make_tuple
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int gmod=3;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
using namespace std;
int n,q;
vector<int> edges[100005];
int par[100005];
int dfn[100005];
int depth[100005];

int pos[100005];
vector<pii> eulerOrder;
pii st[20][200005];
int lg[200005];

void go(int x,int p,int d=0)
{
	static int T=0;
	dfn[x]=T++;
	pos[x]=eulerOrder.size();
	eulerOrder.push_back(mp(d,x));
	par[x]=p;
	depth[x]=d;
	for(auto u:edges[x])
	{
		if(u==p) continue;
		go(u,x,d+1);
		eulerOrder.push_back(mp(d,x));
	}
}

void init()
{
	int n=eulerOrder.size();
	for(int i=0;i<n;i++) st[0][i]=eulerOrder[i];
	for(int k=1;k<=18;k++)
	{
		for(int i=0;i<n-(1<<k)+1;i++)
		{
			st[k][i]=min(st[k-1][i],st[k-1][i+(1<<(k-1))]);
		}
	}
	lg[1]=0;
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
}

inline int lca(int x,int y)
{
	x=pos[x];
	y=pos[y]+1;
	if(x>y) swap(x,y);
	int k=lg[y-x];
	return min(st[k][x],st[k][y-(1<<k)]).second;
}

vector<int> vec[100005];
int stk[100005],top;
int iskey[100005];

pii dfs(int x) //
{
	if(vec[x].size()==0)
	{
		assert(iskey[x]);return mp(inf,0);
	}
	// if(vec[x].size()==1)
	// {
	// 	int u=vec[x][0];
	// 	pii o=dfs(u);
	// 	if(iskey[x]) return mp(o.first+1,o.first);else return mp(min(o.first,o.second+1),o.second);
	// }
	if(iskey[x])
	{
		int res=0;
		for(auto u:vec[x])
		{
			res+=dfs(u).first;
			if(res>=inf) res=inf;
		}
		return mp(inf,res);
	}
	else //
	{
		ll res=0,r2=0;
		ll maxDelta=0;
		for(auto u:vec[x])
		{
			pii o=dfs(u);
			chmin(o.second,o.first);
			res+=o.second;
			chmax(maxDelta,o.first-o.second);
			r2+=o.first;
		}
		res=min(res+1,r2);
		r2=r2-maxDelta;
		chmin(res,inf);
		chmin(r2,inf);
		return mp(int(res),int(r2));
	}
}

void solve()
{
	int n,x;vector<int> points;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		x--;
		points.push_back(x);
		if(x) points.push_back(par[x]);
		iskey[x]=1;
	}
	n=points.size();
	sort(all(points),[](const int &x,const int &y){return dfn[x]<dfn[y];});
	for(int i=0;i<n-1;i++)
	{
		points.push_back(lca(points[i],points[i+1]));
	}
	sort(all(points),[](const int &x,const int &y){return dfn[x]<dfn[y];});
	points.insert(points.begin(),0);
	points.erase(unique(all(points)),points.end());
	top=0;
	for(auto &x:points)
	{
		while(top>0)
		{
			int z=lca(stk[top-1],x);
			if(z==stk[top-1]) break;
			assert(top>=2);
			vec[stk[top-2]].push_back(stk[top-1]);
			top--;
		}
		stk[top++]=x;
	}
	while(top>=2)
	{
		vec[stk[top-2]].push_back(stk[top-1]);
		top--;
	}
	// for(auto x:points)
	// {
	// 	debug(x,vec[x],iskey[x]);
	// }
	pii o=dfs(0);
	int res=min(o.first,o.second);
	assert(res>=0);
	printf("%d\n",(res>=inf?-1:res));
	for(auto x:points)
	{
		iskey[x]=false;
		vec[x].clear();
	}
}

int main()
{
	// freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	scanf("%d",&q);
	go(0,-1);
	init();
	for(int i=0;i<q;i++)
	{
		solve();
	}
	return 0;
}