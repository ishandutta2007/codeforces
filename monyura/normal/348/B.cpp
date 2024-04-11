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

ll gcd(ll a,ll b)
{
	while (b)
	{
		ll c = b;
		b = a % b;
		a = c;
	}
	return a;
}

ll nok(ll a,ll b)
{
	if (a==0 && b==0)
		return 0;
	a/=gcd(a,b);
	if (a*double(b)>1e18)
		return 2e18;
	return a*b;
}

struct vert
{
	vector<int> inc;
	int val;
	ll N;
	ll sum;
} g[100100];

ll res = 0;
void dfs(int k,int prev)
{
	ll nk = 1;
	g[k].sum = g[k].val;
	ll mn = 2e18;
	rep(i,0,g[k].inc.size())
		if (g[k].inc[i]!=prev)
		{
			dfs(g[k].inc[i],k);
			nk = nok(nk, g[g[k].inc[i]].N);
			g[k].sum += g[g[k].inc[i]].sum;
			mn = min(mn, g[g[k].inc[i]].sum);
		}
	mn = mn - (mn%nk);
	rep(i,0,g[k].inc.size())
	{
		int to = g[k].inc[i];
		if (to!=prev)
		{
			ll here = g[to].sum - mn;
			res += here;
			g[k].sum -= here;
		}
	}
	g[k].N = 1;
	if (g[k].inc.size()-(prev!=-1)!= 0)
	{
		if (double(nk)* (g[k].inc.size()-(prev!=-1)) > 1e18)
			g[k].N = 2e18;
		else
			g[k].N = nk * (g[k].inc.size()-(prev!=-1));
	}
	/*rep(i,0,g[k].inc.size())
		if (g[k].inc[i]!= prev)
			g[k].N *= g[g[k].inc[i]].N;*/
}



void run()
{
	int n;
	cin>>n;
	rep(i,0,n)
		scanf("%d",&g[i].val);
	rep(i,0,n-1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].inc.push_back(b);
		g[b].inc.push_back(a);
	}
	res = 0;
	dfs(0,-1);
	cout<<res<<endl;
	
}

//#define prob "tria"

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
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