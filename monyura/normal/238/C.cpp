#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <cmath>
#include <queue>
#include <ctime>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const double PI=acos(-1.0);

struct vert
{
	vector<int> inc;
	vector<int> cost;
	int sum;
	vector<int> s;
	int toMe;
	int fromMe;
} g[3002];

void dfsSet(int k,int prev)
{
	g[k].sum=0;
	if (g[k].s.empty())
		g[k].s.assign(g[k].inc.size(),0);
	rep(i,0,g[k].inc.size())
	{
		int v=g[k].inc[i];
		if (v!=prev)
		{
			dfsSet(v,k);
			g[k].s[i]=g[v].sum;
			g[k].sum+=g[v].sum + g[k].cost[i];
		}
	}
}

int res=1e9;

void dfs(int k,int prev,int sum,int cost)
{
	if (prev!=-1)
	{
		g[k].toMe = g[prev].toMe + cost;
		g[k].fromMe = min(g[prev].fromMe,g[prev].toMe)+!cost;
	}
	else
	{
		g[k].toMe=g[k].fromMe = 0;
	}
	int curr=sum + min(g[k].fromMe,g[k].toMe) + g[k].sum;	
	res=min(res,curr);
	rep(i,0,g[k].inc.size())
	{
		int v=g[k].inc[i];
		if (v!=prev)
		{
			dfs(v,k,sum + g[k].sum - g[k].s[i] - g[k].cost[i],g[k].cost[i]);
		}
	}
}

void run()
{
	int n;
	cin>>n;
	rep(i,0,n-1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].inc.push_back(b);
		g[a].cost.push_back(0);
		g[b].inc.push_back(a);
		g[b].cost.push_back(1);
	}
	rep(i,0,n)
	{
		dfsSet(i,-1);
		dfs(i,-1,0,-1);
	}
	cout<<res<<endl;
}


int main()
{
	srand(time(0));
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("final.in","r",stdin);
	//freopen("final.out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*

*/