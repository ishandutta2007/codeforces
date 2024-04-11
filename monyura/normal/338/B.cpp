#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <iomanip>
#include <cstdio>
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
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;

struct vert
{
	vector<int> inc;
	bool bad;
	pii mx[2];
	vert()
	{
		bad = false;
		mx[0] = pii(-1e9,-1);
		mx[1] = mx[0];
	}
	
} g[100100];

void update(int k,const pii &val)
{
	if (val>=g[k].mx[0])
	{
		g[k].mx[1] = g[k].mx[0];
		g[k].mx[0] = val;
	}
	else if (val>g[k].mx[1])
		g[k].mx[1] = val;
}

void dfs(int k,int prev)
{
	if (g[k].bad)
		g[k].mx[0] = pii(0,k);
	rep(i,0,g[k].inc.size())
	{
		int to = g[k].inc[i];
		if (to!=prev)
		{
			dfs(to,k);
			update(k, pii(g[to].mx[0].first+1,to));
		}
	}
}

int res=0;
int rad;
void dfs2(int k,int prev,int dist)
{
	if (max(dist,g[k].mx[0].first)<=rad)
		++res;
	rep(i,0,g[k].inc.size())
	{
		int to = g[k].inc[i];
		if (to!=prev)
		{	
			int next = g[k].mx[0].second == to ? g[k].mx[1].first : g[k].mx[0].first;
			next = max(next, dist);
			dfs2(to,k,next+1);
		}
	}

}

void run()
{
	int n,m;
	cin>>n>>m>>rad;
	rep(i,0,m)
	{
		int a;
		scanf("%d",&a);
		--a;
		g[a].bad = true;
	}
	rep(i,0,n-1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].inc.push_back(b);
		g[b].inc.push_back(a);
	}
	int st = 0;
	dfs(st ,-1);
	dfs2(st ,-1,-1e9);
	cout<<res<<endl;
	/*rep(i,0,n)
		cout<<g[i].mx[0].first<<' '<<g[i].mx[0].second<<' '<<g[i].mx[1].first<<' '<<g[i].mx[1].second<<endl;*/
}

//#define prob "fibsubseq"

int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(prob".in","r",stdin);
	//freopen(prob".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf( "\n=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}