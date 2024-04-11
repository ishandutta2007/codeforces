#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int N = 100005;

int n;
LL j;

int ax[N], ay[N];

int main() {
	scanf("%d %lld", &n, &j);
	int x, y;
	scanf("%d %d", &x, &y);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &ax[i], &ay[i]);
	j %= (2 * n);
	for  (int k = 1; k <= j; ++k) {
		x = 2 * ax[(k - 1) % n] - x;
		y = 2 * ay[(k - 1) % n] - y;
	}
	printf("%d %d\n", x, y);
}