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

typedef long double ldb;

const int N = 1005, M = 1005;

ldb dp[N][M];

ldb firstCoef[M], nextCoef[M], add[M];

int n, m;

int startY, startX;

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d", &startY, &startX);
	if (m == 1 || startY == n) {
		printf("%.8Lf\n", ldb(n - startY) * 2);
		return 0;
	}
	firstCoef[1] = 1.0;
	nextCoef[1] = 0.0;
	for (int j = 2; j < m; ++j) {
		nextCoef[j] = 1.0 / 4.0 / (1.0 - nextCoef[j - 1] / 4.0 - 1.0 / 4.0);
		firstCoef[j] = 1.0 / 4.0 * firstCoef[j - 1] / (1.0 - nextCoef[j - 1] / 4.0 - 1.0 / 4.0);
	}
	nextCoef[m] = 0;
	firstCoef[m] = 1.0 / 3.0 * firstCoef[m - 1] / (1.0 - nextCoef[m - 1] / 3.0 - 1.0 / 3.0);
	nextCoef[1] = 1.0 / 3.0;
	firstCoef[1] = 1.0 / 3.0;
	for (int j = m - 1; j >= 1; --j)
		firstCoef[j] += nextCoef[j] * firstCoef[j + 1];
	for (int i = n - 1; i >= startY; --i) {
		add[1] = 0.0;
		nextCoef[1] = 0.0;
		for (int j = 2; j < m; ++j)
			add[j] = (1.0 / 4.0) * (4.0 + add[j - 1] + dp[i + 1][j]) / (1.0 - nextCoef[j - 1] / 4.0 - 1.0 / 4.0);
		add[m] = (1.0 / 3.0) * (3.0 + add[m - 1] + dp[i + 1][m]) / (1.0 - nextCoef[m - 1] / 3.0 - 1.0 / 3.0);
		add[1] = 1.0 / 3.0 * dp[i + 1][1] + 1.0;
		nextCoef[1] = 1.0 / 3.0;
		for (int j = m - 1; j >= 1; --j)
			add[j] += nextCoef[j] * add[j + 1];
		dp[i][1] = add[1] / (1.0 - firstCoef[1]);
		for (int j = 2; j <= m; ++j)
			dp[i][j] = add[j] + firstCoef[j] * dp[i][1];
	}
	printf("%.8Lf\n", dp[startY][startX]);
}