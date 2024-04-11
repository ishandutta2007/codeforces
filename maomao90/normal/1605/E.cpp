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

int n;
int a[MAXN], ta[MAXN], b[MAXN];
int q;
ii x[MAXN];
int taken[MAXN], pls[MAXN];
ll ans[MAXN];
vi e[20000005];

int main() {
	scanf("%d", &n);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
		ta[i] = a[i];
	}
	REP (i, 1, n + 1) {
		scanf("%d", &b[i]);
	}
	b[1] = 1;
	scanf("%d", &q);
	REP (i, 0, q) {
		scanf("%d", &x[i].FI);
		x[i].SE = i;
	}
	sort(x, x + q);
	int cx = 1;
	ll res = 0;
	REP (i, 1, n + 1) {
		int d = b[i] - ta[i];
		// taken[i] is number of + operations
		taken[i] = d;
		debug("%d: %d\n", i, taken[i]);
		res += abs(d);
		for (int j = i; j <= n; j += i) {
			ta[j] += d;
		}
	}
	debug("%lld\n", res);
	REP (i, 1, n + 1) {
		ta[i] = b[i];
	}
	ta[1]--;
	ll delta = 0;
	REP (i, 1, n + 1) {
		int d = b[i] - ta[i];
		// pls[i] is number of + operations after 1 turn
		pls[i] = d;
		debug("%d: %d\n", i, pls[i]);
		for (int j = i; j <= n; j += i) {
			ta[j] += d;
		}
	}
	REP (i, 1, n + 1) {
		int a = taken[i] < 0 ? -1 : 1, b = pls[i] < 0 ? -1 : 1;
		taken[i] = abs(taken[i]), pls[i] = abs(pls[i]);
		if (pls[i] == 0) continue;
		if (taken[i] == 0 || a == b) {
			delta += pls[i];
			continue;
		}
		a = taken[i], b = pls[i];
		delta -= b;
		e[a / b].pb(i);
	}
	debug(" %lld\n", delta);
	REP (i, 0, q) {
		while (cx < x[i].FI) {
			res += delta;
			for (int j : e[cx - 1]) {
				delta += 2 * pls[j];
				int rem = pls[j] - taken[j] % pls[j];
				res += rem * 2;
			}
			cx++;
		}
		ans[x[i].SE] = res;
	}
	REP (i, 0, q) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}