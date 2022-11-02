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


void run()
{
	int n,m;
	cin>>n>>m;
	ll H[100100];
	rep(i,0,n)
	{
		scanf("%I64d", H+i);
	}
	ll P[100100];
	rep(i,0,m)
	{
		scanf("%I64d",P+i);
	}
	ll *next[100100];
	rep(i,0,n)
	{
		next[i] = lower_bound(P,P+m,H[i]);
	}
	ll l = 0, r = 1e12;
	ll res = 0;
	while (l<=r)
	{
		ll c = (l+r)>>1;
		int last = 0;
		rep(i,0,n)
		{
			if (last == m)
				break;
			ll left = c;
			ll pos = H[i];
			int st = last;
			int maxLast = last;
			if (P[last]<H[i] && mabs(P[last]-H[i]) <= left)
			{
				left -= 2*mabs(P[last]-H[i]);
				last = next[i] - P;
			}
			while (last < m && mabs(P[last]-pos) <= left)
			{
				left -= mabs(P[last]-pos);
				pos = P[last];
				++last;
			}
			maxLast = last;
			//
			if (P[st] < H[i] && next[i] != P+m)
			{
				last = next[i] - P;
				while (last + 1 < m && 2*mabs(P[last+1] - H[i]) + (H[i]-P[st]) <= c)
					++last;
				if (2*mabs(P[last] - H[i]) + (H[i] - P[st]) <= c)
					maxLast = max(last+1,maxLast);
			}
			//
			last = maxLast;
		}
		if (last == m)
		{
			res = c;
			r = c-1;
		}
		else
			l = c+1;
	}
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