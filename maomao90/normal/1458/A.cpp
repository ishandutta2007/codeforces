#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) y = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
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
#define LINF 100000000000000005
#define MOD 1000000007
#define MAXN 200005

int n, m;
ll a[MAXN], b[MAXN];
ll ans[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, n) scanf("%lld", &a[i]);
	REP (i, 0, m) scanf("%lld", &b[i]);
	ll allGcd = 0;
	REP (i, 1, n) {
		allGcd = __gcd(allGcd, abs(a[i] - a[i - 1]));
	}
	REP (i, 0, m) {
		ll gcd = __gcd(a[0] + b[i], allGcd);
		printf("%lld ", gcd);
	}
	printf("\n");
	return 0;
}