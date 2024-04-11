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
typedef vector<iii> viii;

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
#define LINF 10000000000000
#define MOD 1000000007
#define MAXN 2005

struct thing {
	ll v, i, j;
	bool operator< (const thing& o) const {
		return v < o.v;
	}
};

int n;
int a[MAXN];
ll sa;
int m;
ll sb;
int b[MAXN];
vector<thing> va, vb;
vii v;

int main() {
	scanf("%d", &n);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
		sa += a[i];
	}
	REP (i, 1, n + 1) {
		REP (j, i + 1, n + 1) {
			va.pb({(ll) (a[i] + a[j]) * 2, i, j});
		}
	}
	scanf("%d", &m);
	REP (i, 1, m + 1) {
		scanf("%d", &b[i]);
		sb += b[i];
	}
	REP (i, 1, m + 1) {
		REP (j, i + 1, m + 1) {
			vb.pb({(ll) (b[i] + b[j]) * 2, i, j});
		}
	}
	ll ans = abs(sa - sb);
	REP (i, 1, n + 1) {
		REP (j, 1, m + 1) {
			if (mnto(ans, abs(sa - sb + 2 * (ll) (b[j] - a[i])))) {
				v.clear();
				v.pb(MP(i, j));
			}
		}
	}
	sort(ALL(va));
	sort(ALL(vb));
	int j = 0;
	REP (i, 0, va.size()) {
		while (j < vb.size() && sa - sb - va[i].v + vb[j].v < 0) {
			j++;
		}
		REP (k, j - 1, j + 2) {
			if (k < 0 || k >= vb.size()) continue;
			if (mnto(ans, abs(sa - sb - va[i].v + vb[k].v))) {
				debug("%lld %lld: %lld\n", va[i].v, vb[k].v, sa - sb - va[i].v + vb[k].v);
				debug("%d %d %d %d\n", va[i].i, va[i].j, vb[k].i, vb[k].j);
				v.clear();
				v.pb(MP(va[i].i, vb[k].i));
				v.pb(MP(va[i].j, vb[k].j));
			}
		}
	}
	printf("%lld\n", ans);
	printf("%d\n", (int) v.size());
	for (ii &i : v) {
		printf("%d %d\n", i.FI, i.SE);
	}
	return 0;
}