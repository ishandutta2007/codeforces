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
#define MAXN 200005

int n, p, m;
int d[MAXN], t[MAXN];
int ans;

int main() {
	scanf("%d%d%d", &n, &p, &m);
	REP (i, 1, n + 1) {
		scanf("%d%d", &d[i], &t[i]);
	}
	d[0] = 1;
	d[n + 1] = m + 1;
	ll prv = 0;
	REP (i, 1, n + 2) {
		ll cur = prv - (d[i] - d[i - 1]) * (ll) p;
		int neg = min((ll) d[i] - d[i - 1], (-cur - 1) / p + 1);
		if (cur >= 0) neg = 0;
		ans += neg;
		cur += t[i];
		prv = cur;
	}
	printf("%d\n", ans);
	return 0;
}