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
#define MAXN 100005

int n;
int a[MAXN];
int k[MAXN];
int q;
set<int> st;

#define MLR int mid = lo + hi >> 1; int lc = u * 2, rc = u * 2 + 1
ll sm[MAXN * 4], lazy[MAXN * 4];
inline void propo(int u, int lo, int hi) {
	if (lo == hi || lazy == 0) return;
	MLR;
	lazy[lc] += lazy[u];
	lazy[rc] += lazy[u];
	sm[lc] += (mid - lo + 1) * lazy[u];
	sm[rc] += (hi - mid) * lazy[u];
	lazy[u] = 0;
}
void incre(int s, int e, ll x, int u, int lo, int hi) {
	if (lo >= s && hi <= e) {
		lazy[u] += x;
		sm[u] += (ll) (hi - lo + 1) * x;
		return;
	}
	propo(u, lo, hi);
	MLR;
	if (s <= mid) incre(s, e, x, lc, lo, mid);
	if (e > mid) incre(s, e, x, rc, mid + 1, hi);
	sm[u] = sm[lc] + sm[rc];
}
inline void incre(int s, int e, ll x) {
	incre(s, e, x, 1, 1, n);
}
ll qsm(int s, int e, int u, int lo, int hi) {
	if (lo >= s && hi <= e) {
		return sm[u];
	}
	propo(u, lo, hi);
	MLR;
	if (e <= mid) return qsm(s, e, lc, lo, mid);
	else if (s > mid) return qsm(s, e, rc, mid + 1, hi);
	else return qsm(s, e, lc, lo, mid) + qsm(s, e, rc, mid + 1, hi);
}
inline ll qsm(int s, int e) {
	return qsm(s, e, 1, 1, n);
}

int main() {
	scanf("%d", &n);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
		st.insert(i);
		incre(i, i, a[i]);
	}
	REP (i, 1, n) {
		scanf("%d", &k[i]);
	}
	scanf("%d", &q);
	while (q--) {
		char c; scanf(" %c", &c);
		if (c == '+') {
			int p, x; scanf("%d%d", &p, &x);
			st.insert(p);
			auto ptr = st.lower_bound(p);
			int s = p;
			ll add = x;
			do {
				int e = n + 1;
				if (ptr != prev(st.end())) {
					e = *next(ptr);
				}
				debug("%d %d + %d\n", s, e - 1, add);
				incre(s, e - 1, add);
				ptr = st.erase(ptr);
				if (ptr != st.end()) {
					s = *ptr;
					add = qsm(s - 1, s - 1) + k[s - 1] - qsm(s, s);
				}
			} while (ptr != st.end() && add >= 0);
			st.insert(p);
		} else {
			int l, r; scanf("%d%d", &l, &r);
			printf("%lld\n", qsm(l, r));
		}
	}
	return 0;
}