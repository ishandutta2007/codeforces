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

int t;
int n, c;
int a[MAXN], b[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &c);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
		}
		REP (i, 0, n - 1) {
			scanf("%d", &b[i]);
		}
		ll days = 0, cur = 0;
		ll ans = LINF;
		REP (i, 0, n) {
			mnto(ans, ceil((c - cur) / (double) a[i]) + days);
			ll jmp = ceil((b[i] - cur) / (double) a[i]);
			days += jmp + 1;
			cur += jmp * a[i];
			cur -= b[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}