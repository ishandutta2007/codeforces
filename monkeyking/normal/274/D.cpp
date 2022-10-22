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
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
int n,m;
vector <vector<pii> > vec;
vector <int> g[1000005];
int visit[1000005];
vector <int> order;
int p[100005];
int vn;

void dfs(int x)
{
	visit[x]=1;
	for(auto u:g[x])
	{
		if(visit[u]==1) over("-1");
		if(visit[u]==2) continue;
		dfs(u);
	}
	visit[x]=2;
	order.push_back(x);
}

void add_edge(vector <pair<int,int> > vec)
{
	int n=vec.size();
	int vnlast=-1;
	for(int i=0,r=0;i<n;i=r)
	{
		if(vec[i].first==-1)
		{
			r++;
			continue;
		}
		while(r<n && vec[r].first==vec[i].first) r++;
		int vl=vn++,vr=vn++;
		for(int j=i;j<r;j++)
		{
			g[vl].push_back(vec[j].second);
			g[vec[j].second].push_back(vr);
		}
		if(vnlast!=-1) g[vnlast].push_back(vl);
		vnlast=vr;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	vn=n*m;
	vec.resize(n);
	for(int i=0;i<n;i++)
	{
		vec[i].resize(m);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&vec[i][j].first);
			vec[i][j].second=j;
		}
		sort(vec[i].begin(),vec[i].end());
		add_edge(vec[i]);
//		for(int j=0;j<m-1;j++)
//		{
//			if(vec[i][j].first==-1) continue;
//			g[vec[i][j].second].push_back(vec[i][j+1].second);
//		}
	}
//	for(int i=0;i<vn;i++)
//	{
//		for(auto j:g[i])
//		{
//			cout<<i<<' '<<j<<endl;
//		}
//	}
	for(int i=0;i<m;i++)
	{
		if(visit[i]) continue;
		dfs(i);
	}
	reverse(all(order));
	for(int i=0;i<order.size();i++)
	{
		if(order[i]>=m) continue;
		cout<<order[i]+1<<' '; 
//		p[order[i]]=rk--;
	}
//	for(int i=0;i<m;i++)
//	{
//		printf("%d ",p[i]);
//	}
	puts("");
	return 0;
}