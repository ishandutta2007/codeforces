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

#ifdef LOCAL_DEBUG
const int SZ = 100;
#else
const int SZ = 200005;
#endif

ll maxLeft[SZ], maxRight[SZ];

void run()
{
	int n;
	scanf("%d", &n);
	vector<ll> ws;
	vector<ll> hs;
	ll sumWidth = 0;
	rep(i, 0, n) {
		int cw, ch;
		scanf("%d%d", &cw, &ch);
		hs.push_back(ch);
		ws.push_back(cw);
		sumWidth += cw;
	}

	maxLeft[0] = maxRight[n] = 0;
	rep(i, 0, n) {
		maxLeft[i + 1] = std::max(maxLeft[i], hs[i]);
		maxRight[n - i - 1] = std::max(maxRight[n - i], hs[n - i - 1]);
	}

	rep(i, 0, n) {
		ll mh = std::max(maxLeft[i], maxRight[i + 1]);
		ll cw = sumWidth - ws[i];
		ll res = cw * mh;
		printf("%I64d ", res);
	}
	printf("\n");
}

//#define prob "fence"

int main()
{
#ifdef LOCAL_DEBUG
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

#ifdef LOCAL_DEBUG
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}