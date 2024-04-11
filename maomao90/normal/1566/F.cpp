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
#define MAXN 200005

struct seg {
	ll l, r;
	bool operator< (const seg& o) const {
		return MP(l, r) < MP(o.l, o.r);
	}
};

int t;
int n, m;
ll a[MAXN];
seg segs[MAXN];
ll dp[MAXN][2];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 1, n + 1) {
			scanf("%lld", &a[i]);
		}
		a[0] = -LINF;
		a[n + 1] = LINF;
		n += 2;
		sort(a, a + n);
		REP (i, 0, m) {
			ll l, r; scanf("%lld%lld", &l, &r);
			segs[i] = {l, r};
		}
		REP (i, 0, n) {
			REP (j, 0, 2) {
				dp[i][j] = LINF;
				if (i == 0) dp[i][j] = 0;
			}
		}
		sort(segs, segs + m);
		int ptr = 0;
		REP (i, 1, n) {
			set<pll> lft, rht;
			for (; ptr < m && segs[ptr].l < a[i]; ptr++) {
				if (segs[ptr].l <= a[i - 1] || segs[ptr].r >= a[i]) continue;
				lft.insert(MP(segs[ptr].l, segs[ptr].r));
				rht.insert(MP(segs[ptr].r, segs[ptr].l));
			}
			lft.insert(MP(a[i - 1], a[i]));
			rht.insert(MP(a[i], -LINF - 1));
			debug("%lld %lld\n", a[i - 1], a[i]);
			for (auto [l, r] : lft) {
				rht.erase(MP(r, l));
				ll pre = min(dp[i - 1][0] + ((ll) l - a[i - 1]) * 2, 
						dp[i - 1][1] + ((ll) l - a[i - 1]));
				debug(" %lld %lld: %lld\n", l, r, pre);
				debug("   %lld\n", a[i] - rht.begin() -> FI);
				mnto(dp[i][0], pre + (a[i] - rht.begin() -> FI));
				mnto(dp[i][1], pre + (a[i] - rht.begin() -> FI) * 2);
			}
		}
		printf("%lld\n", min(dp[n - 1][0], dp[n - 1][1]));
	}
	return 0;
}