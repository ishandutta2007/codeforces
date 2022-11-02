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
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const ll INF=1e15;

struct vert
{
	vector<int> inc;
	vector<int> cost;
	vector<pii> wait;
	bool close;
	ll dist;
	vert()
	{
		dist=INF;
		close=0;
	}
} g[100100];

ll getDist(int k,ll dist)
{
	int as=1;
	vector<pii>::iterator iter=lower_bound(all(g[k].wait),pii(dist,-1e9));
	if (iter!=g[k].wait.end() && iter->first>=dist && iter->second<=dist)
	{
		return iter->first+1;
	}
	return dist;
}

ll Dejkstra(int st,int f)
{
	priority_queue<pli> q;
	g[st].dist=getDist(st,0);
	q.push(pli(g[st].dist,st));
	while (!q.empty())
	{
		int v=q.top().second;
		ll d=-q.top().first;
		q.pop();
		if (g[v].close) continue;
		g[v].close=true;
		rep(i,0,g[v].inc.size())
		{
			int to=g[v].inc[i];
			if (!g[to].close)
			{
				ll newD=getDist(to,g[v].dist + g[v].cost[i]);
				if (newD<g[to].dist)
				{
					g[to].dist=newD;
					q.push(pli(-newD,to));
				}
			}
		}
	}
	if (g[f].dist==INF)
		return -1;
	return g[f].dist;
}


void run()
{
	int n,m;
	cin>>n>>m;
	rep(i,0,m)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		--a;--b;
		g[a].inc.push_back(b);
		g[a].cost.push_back(c);
		g[b].inc.push_back(a);
		g[b].cost.push_back(c);
	}
	int T[100100];
	rep(i,0,n)
	{
		int k;
		scanf("%d",&k);
		rep(j,0,k)
			scanf("%d",T+j);
		if (i==n-1) continue;
		int st=T[0];
		rep(j,1,k)
		{
			if (T[j]!=T[j-1]+1)
			{
				g[i].wait.push_back(pii(T[j-1],st));
				st=T[j];
			}
		}
		if (k)
			g[i].wait.push_back(pii(T[k-1],st));
		int as=1;
	}
	ll res=Dejkstra(0,n-1);
	cout<<res<<endl;
}



int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
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