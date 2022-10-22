#include <bits/stdc++.h> 
using namespace std;

#define int ll

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
#define pb emplace_back
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
#define LINF 2000000000000000005
#define MOD 1000000007
#define MAXN 200005

int n;
pll ab[MAXN];
ll sum;

ll take[MAXN];
bool isPos(ll x) {
	ll items = x - sum;
	REP (i, 0, n + 5) {
		take[i] = 0;
	}
	ll ti = items;
	RREP (i, n - 1, 0) {
		ll tmp = min(ti, ab[i].FI);
		take[i] = tmp;
		ti -= tmp;
	}
	REP (i, 0, n) {
		if (take[i] == ab[i].FI) continue;
		if (ab[i].SE <= items) {
			items += ab[i].FI - take[i];
		} else {
			return 0;
		}
	}
	return 1;
}

main() {
	scanf("%lld", &n);
	REP (i, 0, n) {
		scanf("%lld%lld", &ab[i].FI, &ab[i].SE);
		sum += ab[i].FI;
	}
	sort(ab, ab + n, [&] (pll l, pll r) {
			if (l.SE == r.SE) return l.FI < r.FI;
			return l.SE < r.SE;
			});
	ll lo = sum, hi = LINF, mid;
	while (lo < hi) {
		mid = lo + hi >> 1;
		if (isPos(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	printf("%lld\n", hi);
	return 0;
}