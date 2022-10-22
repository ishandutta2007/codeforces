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
#define MAXN 1000005

int n;
ll a[MAXN];

int pcnt[70];
ll pmx[MAXN];
ll ans;
void dnc(int l, int r) {
	if (l > r) return;
	// if lse, lmn <= rmn, else, lmn < rmn
	int m = l + r >> 1;
	ll lmn = LINF, lmx = -LINF, rmn = LINF, rmx = -LINF;
	int j = m, k = m;
	debug("%d %d %d\n", l, m, r);
	RREP (i, m, l) {
		mnto(lmn, a[i]);
		mxto(lmx, a[i]);
		while (j <= r && min(rmn, a[j]) >= lmn) {
			mnto(rmn, a[j]);
			mxto(rmx, a[j]);
			pmx[j] = rmx;
			pcnt[__builtin_popcountll(rmx)]++;
			j++;
		}
		while (k < j && pmx[k] < lmx) {
			pcnt[__builtin_popcountll(pmx[k])]--;
			k++;
		}
		debug(" %d %d %d\n", i, j, k);
		ans += pcnt[__builtin_popcountll(lmn)];
		debug("  +%d\n", pcnt[__builtin_popcountll(lmn)]);
		if (__builtin_popcountll(lmn) == __builtin_popcountll(lmx)) {
			debug("  +%d\n", k - m);
			ans += k - m;
		}
	}
	rmx = -LINF;
	REP (i, m, r + 1) {
		mxto(rmx, a[i]);
		pcnt[__builtin_popcountll(rmx)] = 0;
	}
	lmn = LINF, lmx = -LINF, rmn = LINF, rmx = -LINF;
	j = m, k = m;
	debug("%d %d %d\n", l, m, r);
	REP (i, m, r + 1) {
		mnto(rmn, a[i]);
		mxto(rmx, a[i]);
		while (j >= l && min(lmn, a[j]) > rmn) {
			mnto(lmn, a[j]);
			mxto(lmx, a[j]);
			pmx[j] = lmx;
			pcnt[__builtin_popcountll(lmx)]++;
			j--;
		}
		while (k > j && pmx[k] < rmx) {
			pcnt[__builtin_popcountll(pmx[k])]--;
			k--;
		}
		debug(" %d %d %d\n", i, j, k);
		ans += pcnt[__builtin_popcountll(rmn)];
		debug("  +%d\n", pcnt[__builtin_popcountll(rmn)]);
		if (__builtin_popcountll(rmn) == __builtin_popcountll(rmx)) {
			debug("  +%d\n", m - k);
			ans += m - k;
		}
	}
	lmx = -LINF;
	RREP (i, m, l) {
		mxto(lmx, a[i]);
		pcnt[__builtin_popcountll(lmx)] = 0;
	}
	dnc(l, m - 1);
	dnc(m + 1, r);
}

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%lld", &a[i]);
	}
	dnc(0, n - 1);
	debug("%lld\n", ans);
	printf("%lld\n", ans);
	return 0;
}