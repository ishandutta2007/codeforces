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

void run()
{
	int n;
	scanf("%d", &n);
	int wi[1005][2];
	rep(i, 0, n) {
		scanf("%d%d", wi[i], wi[i] + 1);
		if (wi[i][0] > wi[i][1])
			swap(wi[i][0], wi[i][1]);
	}

	ll bestRes = 2e9;

	rep(i, 0, n) {
		rep(j, 0, 2) {
			int tryHeight = wi[i][j];
			int sum = 0;
			bool fail = 0;
			rep(k, 0, n) {
				if (wi[k][0] > tryHeight) {
					fail = 1;
					break;
				}
				else if (wi[k][1] <= tryHeight) {
					sum += wi[k][0];
				}
				else {
					sum += wi[k][1];
				}
			}
			if (!fail) {
				bestRes = min(bestRes, tryHeight * (ll)sum);
			}
		}
	}
	printf("%l""ld\n", bestRes);
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