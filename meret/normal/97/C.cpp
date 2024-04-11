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

typedef long double LD;

const int ROUNDS = 1000;

const int AD = 100;

LD dp[205];
LD bf[205];

LD p[105];

int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
		scanf("%Lf", &p[i]);
	for (int i = -n; i <= n; ++i)
		dp[AD + i] = -1e10;
	dp[AD] = 0;
	LD result = 0;
	for (int i = 1; i <= ROUNDS; ++i) {
		for (int i = -n; i <= n; ++i)
			bf[AD + i] = -1e10;
		for (int ch = 0; ch <= n; ++ch) {
			int dbal = n - 2 * ch;
			for (int bal = -n + AD; bal <= n + AD; ++bal) {
				if (dp[bal] > -1)
					if (bal + dbal - AD >= -n && bal + dbal - AD <= n) {
						bf[bal + dbal] = max(bf[bal + dbal], dp[bal] + p[ch]);
					}
			}
		}
		memcpy(dp, bf, sizeof(dp));
		result = max(result, dp[AD] / i);
	}
	printf("%.10Lf\n", result);
}