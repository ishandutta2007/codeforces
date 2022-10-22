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
typedef vector<pll> vpll;
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

int t;
int n;
ll a[MAXN];
vll v;
vpll e[MAXN];

ll qsm(int s, int e) {
	return a[e] - a[s - 1];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			scanf("%lld", &a[i]);
		}
		reverse(a + 1, a + n + 1);
		REP (i, 1, n + 1) {
			a[i] += a[i - 1];
		}
		v.clear();
		REP (i, 1, n + 2) {
			e[i].clear();
		}
		REP (i, 1, n + 1) {
			int p = min((int) v.size(), n - i);
			int lo = 0, hi = min((int) v.size() - 1, n - i), mid;
			while (lo <= hi) {
				mid = lo + hi >> 1;
				debug(" %d: %lld %lld\n", mid, qsm(i, i + mid), v[mid]);
				if (qsm(i, i + mid) > v[mid]) {
					hi = mid - 1;
					p = mid;
				} else {
					lo = mid + 1;
				}
			}
			debug("%d: %d %lld\n", i, p, qsm(i, i + p));
			if (p == 0 || qsm(i, i + p) < v[p - 1]) {
				e[min(i + p, n)].pb(MP(p, qsm(i, i + p)));
			}
			for (auto [pos, x] : e[i]) {
				if (pos == v.size()) {
					v.pb(x);
				} else {
					assert(pos < v.size());
					mxto(v[pos], x);
				}
			}
		}
		printf("%d\n", (int) v.size());
	}
	return 0;
}