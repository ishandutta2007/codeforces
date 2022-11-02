#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <bitset>
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
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <bitset>
#include <sstream>
#include <cassert>
#include <utility>
#include <iterator>

using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()


typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;

struct vert
{
	vector<pii> inc;
	vector<pii> incom;
	vector<int> ind;
	ll dist;
	bool close;
} g[300300];


typedef pair<ll, int> pli;

const ll INF = 1e18;

void dijkstra(int st, int n)
{
	rep(i,0,n)
	{
		g[i].dist = INF;
		g[i].close = false;
	}
	g[st].dist = 0;
	priority_queue<pli> q;
	q.push(pli(0, st));
	while (!q.empty())
	{
		int v = q.top().second;
		q.pop();
		if (g[v].close)
			continue;
		g[v].close = true;
		rep(i,0,g[v].inc.size())
		{
			int to = g[v].inc[i].first;
			int w  = g[v].inc[i].second;
			if (g[to].dist > g[v].dist + w)
			{
				g[to].dist = g[v].dist + w;
				q.push(pli(-g[to].dist, to));
			}
		}
	}
	rep(i,0,n)
		rep(j,0,g[i].inc.size())
		{
			int to = g[i].inc[j].first;
			int w  = g[i].inc[j].second;
			if (g[to].dist == g[i].dist + w)
				g[to].incom.push_back(pii(w, g[i].ind[j]));
		}
}

void run()
{
	int n,m;
	cin>>n>>m;
	rep(i,0,m)
	{
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);
		--a;--b;
		g[a].inc.push_back(pii(b,t));
		g[a].ind.push_back(i);
		g[b].inc.push_back(pii(a,t));
		g[b].ind.push_back(i);
	}
	int st;
	cin>>st;
	--st;
	dijkstra(st, n);
	ll res = 0;
	vector<int> ans;
	rep(i,0,n)
	if (g[i].incom.size() > 0)
	{
		auto mn = *min_element(all(g[i].incom));
		res += mn.first;
		ans.push_back(mn.second);
	}

	cout<<res<<endl;
	rep(i,0,ans.size())
		printf("%d ", ans[i]+1);
}

//#define prob "i"

int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	time_t st=clock();
#else
	#ifdef prob
		freopen(prob".in","r",stdin);
		freopen(prob".out","w",stdout);
	#endif
#endif
	run();
#ifdef _MONYURA_
	printf( "\n=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}