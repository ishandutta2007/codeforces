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

int p[N], sz[N];

int gp(int x) {
	if (p[x] != x)
		p[x] = gp(p[x]);
	return p[x];
}

void un(int a, int b) {
	a = gp(a);
	b = gp(b);
	if (a != b) {
		sz[a] += sz[b];
		p[b] = a;
	}
}

bool isLucky(int x) {
	while (x) {
		int d = x % 10;
		if (d != 4 && d != 7)
			return false;
		x /= 10;
	}
	return true;
}

int cnt[N];

int n, m;

int dp[N];

const int INF = int(1e9);

PII q[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		sz[i] = 1;
	}
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		un(a, b);
	}
	for (int i = 1; i <= n; ++i)
		if (i == p[i])
			++cnt[sz[i]];
	for (int i = 1; i <= n; ++i)
		dp[i] = INF;
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] > 0) {
			for (int r = 0; r < i; ++r) {
				int ql = 0, qr = -1;
				for (int u = 0; u * i + r <= n; ++u) {
					int c = u * i + r;
					while (ql <= qr && q[ql].ST == u)
						++ql;
					while (ql <= qr && q[qr].ND >= dp[c] - u)
						--qr;
					if (dp[c] < INF)
						q[++qr] = MP(u + cnt[i] + 1, dp[c] - u);
					if (ql <= qr)
						dp[c] = min(dp[c], q[ql].ND + u);
				}
			}
		}
	}
	int result = INF;
	for (int i = 1; i <= n; ++i)
		if (isLucky(i))
			result = min(result, dp[i]);
	if (result == INF)
		printf("%d\n", -1);
	else
		printf("%d\n", result - 1);
}