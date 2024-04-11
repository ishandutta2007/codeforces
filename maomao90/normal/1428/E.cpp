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
#define debug(args...) _debug(args)
void _debug(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

struct thing {
	ll v; int k, i;
	ll prv;
	bool operator< (const thing& o) const {
		return v < o.v;
	}
};

int n, k;
int a[MAXN];
priority_queue<thing> pq;
ll ans;

vii split(int a, int b) {
	int lo = a / b; int hi = lo + 1;
	int hic = a % b;
	int loc = b - hic;
	vii res = {MP(lo, loc), MP(hi, hic)};
	return res;
}

int main() {
	scanf("%d%d", &n, &k);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
		ans += (ll) a[i] * a[i];
		if (a[i] >= 2) {
			vii v = split(a[i], 2);
			ll cur = (ll) a[i] * a[i];
			ll mn = 0;
			for (ii j : v) {
				mn += (ll) j.FI * j.FI * j.SE;
			}
			cur -= mn;
			debug("%lld %d %d %lld\n", cur, 2, i, mn);
			pq.push({cur, 2, i, mn});
		}
	}
	k -= n;
	debug("%lld\n", ans);
	while (k--) {
		thing tp = pq.top(); pq.pop();
		debug("%lld %d %d %lld\n", tp.v, tp.k, tp.i, tp.prv);
		ans -= tp.v;
		tp.k++;
		if (a[tp.i] >= tp.k) {
			vii v = split(a[tp.i], tp.k);
			ll cur = tp.prv;
			ll mn = 0;
			for (ii j : v) {
				mn += (ll) j.FI * j.FI * j.SE;
			}
			cur -= mn;
			debug(" %lld %d %d %lld\n", cur, tp.k, tp.i, mn);
			pq.push({cur, tp.k, tp.i, mn});
		}
	}
	printf("%lld\n", ans);
	return 0;
}