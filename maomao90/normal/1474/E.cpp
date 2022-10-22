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
#define MAXN 100005

int t;
int n;
int a[MAXN];
vii moves;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) a[i] = i;
		ll ans = 0;
		moves.clear();
		REP (i, 1, n) {
			int lft = n - i, rht = i - 1;
			if (lft > rht) {
				swap(a[i], a[n]);
				moves.pb(i, n);
				ans += (ll) lft * lft;
			} else {
				swap(a[i], a[1]);
				moves.pb(i, 1);
				ans += (ll) rht * rht;
			}
		}
		printf("%lld\n", ans);
		REP (i, 1, n + 1) printf("%d ", a[i]);
		printf("\n");
		printf("%d\n", (int) moves.size());
		RREP (i, moves.size() - 1, 0) {
			printf("%d %d\n", moves[i].FI, moves[i].SE);
		}
	}
	return 0;
}