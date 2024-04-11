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

void test() {
	int m, k;
	scanf("%d%d", &m, &k);
	m--;
	vector<int> dish;
	rep(i, 0, k) {
		int cd;
		scanf("%d", &cd);
		dish.push_back(cd);
	}

	bool wasSad = false;
	vector<int> ts, rs;
	rep(j, 0, m) {
		int tj, rj;
		scanf("%d%d", &tj, &rj);
		tj--;
		ts.push_back(tj);
		rs.push_back(rj);
	}
	int zeroCnt = 0;
	vector<int> possTaken(k, 0);
	rep(j, 0, m) {
		int tj = ts[j], rj = rs[j];
		if (rj == 1 && !wasSad) {
			wasSad = true;
			vector<int> futureTaken(k, 0);
			rep(i, j, m) {
				int ti = ts[i];
				if (ti != -1)
					futureTaken[ti] = 1;
			}

			int minVal = 1e9;
			rep(i, 0, k) {
				if (!futureTaken[i]) {
					minVal = min(minVal, dish[i]);
					if (dish[i] <= zeroCnt)
						possTaken[i] = 1;
				}
			}
			
			zeroCnt -= minVal;
		}
		if (tj == -1)
			zeroCnt++;
		else
			dish[tj]--;
	}

	rep(j, 0, k) {
		if (dish[j] <= zeroCnt)
			possTaken[j] = 1;
		if (possTaken[j])
			printf("Y");
		else
			printf("N");
	}
	printf("\n");

}

void run()
{
	int tc;
	scanf("%d", &tc);
	rep(i, 0, tc) {
		test();
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