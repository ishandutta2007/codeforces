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

int noms[5005];

void run()
{
	int n, k;
	scanf("%d%d", &n, &k);
	//srand(time(0));
	rep(i, 0, n) {
		scanf("%d", noms + i);
		//noms[i] = rand() * RAND_MAX + rand();
		//noms[i] %= (int)1e7;
	}
	sort(noms, noms + n);
	int q = 20;
	scanf("%d", &q);

	map<int, int> secondVals;
	secondVals[0] = 0;
	rep(i, 0, n) {
		rep(j, 1, k + 1) {
			int curNum = noms[i] * j;
			secondVals[curNum] = j;
		}
	}
	rep(i, 0, q) {
		int toGet;
		toGet = rand() * RAND_MAX + rand();
		toGet %= (int)2e8;
		scanf("%d", &toGet);

		int lb = -1, ub = -1;
		rep(i, 0, n) {
			if (noms[i] * k >= toGet && lb == -1)
				lb = i;
			if (noms[i] > toGet)
				break;
			ub = i;

		}

		int bestVal = k + 1;
		int maxLower = lb;
		for(int j1 = ub; j1 >= maxLower; j1--) {
			rep(k1, 0, bestVal) {
				int cSum = k1 * noms[j1];
				if (cSum > toGet)
					break;
				int left = toGet - cSum;
				/*int leftTries = bestVal - k1;
				int lc = left / leftTries;
				int start = lower_bound(noms, noms + ub, lc) - noms;
				rep(j2, start, n) {
					if (noms[j2] > left)
						break;
					int tr = left / noms[j2];
					int lt = left - tr * noms[j2];
					if (lt == 0) {
						maxLower = max(maxLower, j2);
						int cRes = tr + k1;
						bestVal = min(bestVal, cRes);
					}
				}*/

				auto it = secondVals.find(left);
				if (it == secondVals.end())
					continue;
				int curVal = k1 + it->second;
				bestVal = min(bestVal, curVal);
			}
		}
		if (bestVal > k)
			bestVal = -1;
		printf("%d\n", bestVal);
	}
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