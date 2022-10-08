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

// len | lastLucky
int dp[1005][1005];

const int MD = int(1e9) + 7;

int k;

void ad(int& a, int b) {
	a += b;
	if (a >= MD)
		a -= MD;
}

int calc(int* d, int n, bool leq) {
	int lastLucky = k + 1;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int dig = 0; dig < d[i]; ++dig) {
			int nextLucky = lastLucky;
			if (nextLucky != 0) {
				if (dig == 4 || dig == 7) {
					if (lastLucky <= k)
						nextLucky = 0;
					else
						nextLucky = 1;
				} else {
					nextLucky = min(nextLucky + 1, k + 1);
				}
			}
			ad(res, dp[n - i][nextLucky]);
		}
		if (lastLucky != 0) {
			if (d[i] == 4 || d[i] == 7) {
				if (lastLucky <= k)
					lastLucky = 0;
				else
					lastLucky = 1;
			} else {
				lastLucky = min(lastLucky + 1, k + 1);
			}
		}
	}
	if (leq && lastLucky == 0)
		ad(res, 1);
	return res;
}

int d[1005];

char a[1005], b[1005];

int main() {
	int t;
	scanf("%d %d", &t, &k);
	dp[0][0] = 1;
	for (int len = 1; len <= 1000; ++len) {
		for (int lastLucky = 0; lastLucky <= k + 1; ++lastLucky) {
			for (int dig = 0; dig <= 9; ++dig) {
				int nextLucky = lastLucky;
				if (nextLucky != 0) {
					if (dig == 4 || dig == 7) {
						if (lastLucky <= k)
							nextLucky = 0;
						else
							nextLucky = 1;
					} else {
						nextLucky = min(nextLucky + 1, k + 1);
					}
				}
				ad(dp[len][lastLucky], dp[len - 1][nextLucky]);
			}
		}
	}
	for (int i = 1; i <= t; ++i) {
		scanf("%s %s", a, b);
		int n;
		n = strlen(b);
		for (int i = 1; i <= n; ++i)
			d[i] = b[i - 1] - '0';
		int res = calc(d, n, true);
		n = strlen(a);
		for (int i = 1; i <= n; ++i)
			d[i] = a[i - 1] - '0';
		res -= calc(d, n, false);
		res += MD;
		if (res >= MD)
			res -= MD;
		printf("%d\n", res);
	}
}