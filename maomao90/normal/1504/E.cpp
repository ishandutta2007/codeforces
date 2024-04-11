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

int n;
ii ac[MAXN];
ll ans;

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		int a, c; scanf("%d%d", &a, &c);
		ac[i] = MP(a, c);
		ans += c;
	}
	sort(ac, ac + n);
	int mx = 0;
	REP (i, 0, n) {
		if (i != 0) ans += max(0, ac[i].FI - mx);
		mxto(mx, ac[i].FI + ac[i].SE);
	}
	printf("%lld\n", ans);
	return 0;
}