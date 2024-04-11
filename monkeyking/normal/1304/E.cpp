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
vector <int> vec[100005];
int n,q;
const int N=1e5+5;
const int LOGN=19;

#include <vector>
using namespace std;
struct Graph
{
	vector <int> *edges;
	int n;
	void init(int _n)
	{
		n=_n;
		edges=new vector <int> [n];
	}
	void feedEdges(vector <int> _edges[])
	{
		for(int i=0;i<n;i++)
		{
			edges[i]=_edges[i];
		}
	}
};

namespace getParArraySpace
{
	void dfs(int x,int p,int arr[],Graph &g)
	{
		arr[x]=p;
		for(auto &u:g.edges[x])
		{
			if(u==p) continue;
			dfs(u,x,arr,g);
		}
	}
	void getParArray(Graph &g,int rt,int arr[])
	{
		dfs(rt,-1,arr,g);
	}
};
using getParArraySpace::getParArray;
namespace getDepArraySpace
{
	void dfs(int x,int p,int depth,int arr[],Graph &g)
	{
		arr[x]=depth;
		for(auto &u:g.edges[x])
		{
			if(u==p) continue;
			dfs(u,x,depth+1,arr,g);
		}
	}
	void getDepArray(Graph &g,int rt,int arr[])
	{
		dfs(rt,-1,0,arr,g);
	}
};
using getDepArraySpace::getDepArray;
namespace LCASpace
{
	int depth[N];
	int par[LOGN][N];
	void init(Graph &g)
	{
		getDepArray(g,0,depth);
		getParArray(g,0,par[0]);
		for(int k=0;k<LOGN-1;k++)
		{
			for(int i=0;i<n;i++)
			{
				if(par[k][i]==-1)
				{
					par[k+1][i]=-1;
				}
				else
				{
					par[k+1][i]=par[k][par[k][i]];
				}
			}
		}
	}
	int lca(int a,int b)
	{
		if(depth[a]<depth[b]) swap(a,b);
		int t=depth[a]-depth[b];
		for(int i=0;i<LOGN;i++)
		{
			if((t & (1<<i))) a=par[i][a];
		}
		if(a==b) return a;
		for(int i=LOGN-1;i>=0;i--)
		{
			if(par[i][a]!=par[i][b])
			{
				a=par[i][a];
				b=par[i][b];
			}
		}
		return par[0][a];
	}
};



using LCASpace::lca;
using LCASpace::depth;
using LCASpace::par;

inline int dis(int x,int y)
{
	int z=lca(x,y);
	return depth[x]+depth[y]-depth[z]*2;
}

inline bool test(int x,int k)
{
	if(x>k) return false;
	if((x-k)&1) return false;
	return true;
}

Graph g;
int main()
{
//	freopen("input.txt","r",stdin);
	int x,y;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	g.init(n);
	g.feedEdges(vec);
	LCASpace::init(g);
	cin>>q;
	int a,b,k;
	while(q--)
	{
		scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
		x--;
		y--;
		a--;
		b--;
//		cout<<dis(a,b)<<endl;
		bool flag=false; 
		flag|=(test(dis(a,b),k));
		flag|=(test(dis(a,x)+dis(y,b)+1,k));
		flag|=(test(dis(a,y)+dis(x,b)+1,k));
		if(flag)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}