#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 1000005
#define MAXM 105

int n, l, m;
int c[3][MAXN];
ll ways[MAXM], ans[MAXM];

ll res[MAXM];
void combine(ll* a, ll* b) {
	memset(res, 0, sizeof res);
	REP (i, 0, m) {
		REP (j, 0, m) {
			res[(i + j) % m] += a[i] * b[j] % MOD;
			res[(i + j) % m] %= MOD;
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &l, &m);
	l -= 2;
	REP (i, 0, 3) {
		REP (j, 0, n) {
			scanf("%d", &c[i][j]);
		}
	}
	REP (i, 0, n) {
		c[2][i] += c[1][i];
		c[2][i] %= m;
	}
	REP (i, 0, n) {
		ways[c[1][i]]++;
		ans[c[0][i]]++;
	}
	while (l) {
		if (l & 1) {
			combine(ans, ways);
			copy(res, res + m, ans);
		}
		l >>= 1;
		combine(ways, ways);
		copy(res, res + m, ways);
	}
	memset(ways, 0, sizeof ways);
	REP (i, 0, n) {
		ways[c[2][i]]++;
	}
// 	REP (i, 0, m) {
// 		printf("%d ", ans[i]);
// 	}
// 	printf("\n");
	combine(ans, ways);
	copy(res, res + m, ans);
	printf("%lld\n", ans[0]);
	return 0;
}