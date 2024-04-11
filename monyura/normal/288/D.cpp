//#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
//#endif

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

const double PI = acos(-1.0);




struct vert
{
	vector<int> inc;
	int s;
	ull b;
	vert()
	{
		b = 0;
		s = 0;
	}
} g[100100];

int n;
int close;
int open;
ull res;
void dfs(int k,int prv,ull bad)
{
	--open;
	g[k].s = 1;
	int cnt=0;
	ll sq = 0;
	rep(i,0,g[k].inc.size())
		if (g[k].inc[i]!=prv)
		{
			++cnt;
			int to = g[k].inc[i];
			dfs(to,k,bad + g[k].b);
			g[k].b+=g[to].b;
			g[k].s+=g[to].s;
			sq += g[to].s * ll(g[to].s);
		}
	++close;
	ll here = (ll(g[k].s+1)*(g[k].s-1) - sq)/2;
	ll up = (n - g[k].s)*ll(n-g[k].s-1)/2 - bad;
	res += here * up;
	g[k].b += here;
}

void run()
{
	cin>>n;
	rep(i,0,n-1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].inc.push_back(b);
		g[b].inc.push_back(a);
	}
	res = 0;
	open = n;
	close = 0;
	dfs(0,-1,0);
	res*=2;
	cout<<res<<endl;
}

int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);	
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf( "=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}