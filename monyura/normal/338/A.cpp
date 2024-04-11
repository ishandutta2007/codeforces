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

bool check(ll n, ll m,ll k, ll cnt)
{
	m -= cnt*k;
	ll left = n - cnt*k;
	ll can = left/k * (k-1) + left %k;
	return can>=m;
}

const int mod = 1e9+9;

ll toPow(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b&1)
			res = (res*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return res;
}

void run()
{
	ll n,m,k;
	cin>>n>>m>>k;
	ll l = 0, r= m/k;
	ll res = 0;
	while (l<=r)
	{
		ll c = (l+r)>>1;
		if (check(n,m,k,c))
		{
			res = c;
			r = c-1;
		}
		else
			l = c+1;
	}
	ll score = 0;
	if (res>0)
		score = (toPow(2,res+1)-2)* k  % mod;
	score = (score + m - res*k)%mod;
	score = (score+mod)%mod;
	cout<<score<<endl;
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