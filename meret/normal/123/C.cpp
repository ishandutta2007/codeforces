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
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

LL k;

LL dp[205][205];

char mask[205];

int z;

LL go() {
	ZERO(dp);
	dp[0][0] = 1;
	for (int i = 1; i <= z; ++i) {
		for (int sum = 0; sum <= i; ++sum) {
			if (mask[i] != ')' && sum > 0) {
				dp[i][sum] += dp[i - 1][sum - 1];
			}
			if (mask[i] != '(' && sum < i) {
				dp[i][sum] += dp[i - 1][sum + 1];
			}
			dp[i][sum] = min(dp[i][sum], k + 1);
		}
	}
	return dp[z][0];
}

vector<PII> pr;

int main() {
	int n, m;
	cin >> n >> m >> k;
	z = n + m - 1;
	for (int i = 1; i <= z; ++i) {
		mask[i] = '*';
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int c;
			scanf("%d", &c);
			pr.PB(MP(c, i + j - 1));
		}
	}
	sort(ALL(pr));
	FORE (it, pr) {
		if (mask[it->ND] == '*') {
			mask[it->ND] = '(';
			LL cur = go();
			if (cur < k) {
				k -= cur;
				mask[it->ND] = ')';
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			putchar(mask[i + j - 1]);
		}
		putchar('\n');
	}
}