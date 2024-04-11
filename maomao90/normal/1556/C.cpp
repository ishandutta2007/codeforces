#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
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
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 1005

int n;
int c[MAXN];
ll ans;

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%d", &c[i]);
		if (i & 1) c[i] *= -1;
	}
	for (int i = 0; i < n; i += 2) {
		ll sm = 0;
		debug("%d\n", i);
		ll mx = 1;
		REP (j, i, n) {
			sm += c[j];
			if (j % 2 == 0) continue;
			debug(" %d: %lld\n", j, sm);
			if (sm < 0) {
				ll f = -c[j];
				if (f >= -sm) {
					f -= -sm;
					ll range = min(f, c[i] - mx + 1);
					debug("  %lld %lld\n", f, range);
					ans += range;
				} else {
					assert(0);
				}
				break;
			}
			ll f = c[i];
			if (f >= sm) {
				f -= sm;
				ll range = min(f - mx + 1, -(ll) c[j]);
				debug("  %lld %lld\n", f, range);
				if (range >= 0) {
					ans += range;
				}
			}
			mxto(mx, c[i] - sm);
		}
	}
	printf("%lld\n", ans);
	return 0;
}