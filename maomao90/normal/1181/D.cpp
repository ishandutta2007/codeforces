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
#define LINF 3000000000000000005
#define MOD 1000000007
#define MAXN 500005

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> indexed_set;
indexed_set st;

int n, m, q;
pll h[MAXN];
pll k[MAXN];
int ans[MAXN];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	REP (i, 0, n) {
		int a; scanf("%d", &a);
		h[a].FI++;
	}
	REP (i, 1, m + 1) {
		h[i].SE = i;
	}
	REP (i, 0, q) {
		scanf("%lld", &k[i].FI);
		k[i].FI -= n;
		k[i].SE = i;
	}
	sort(k, k + q);
	sort(h + 1, h + m + 1);
	m++;
	h[m] = MP(LINF / m, m);
	int i = 1;
	ll sum = 0;
	int j = 0;
	while (i < m) {
		int ni = i;
		for (; ni < m && h[ni].FI == h[i].FI; ni++) {
			st.insert(h[ni].SE);
		}
		ll diff = h[ni].FI - h[i].FI;
		ll len = ni - 1;
		ll nsum = sum + diff * len;
		debug("%lld %lld %lld\n", diff, len, sum);
		while (j < q && k[j].FI <= nsum) {
			k[j].FI -= sum + 1;
			debug(" %lld\n", k[j].FI);
			int id = k[j].FI % len;
			ans[k[j].SE] = *st.find_by_order(id);
			j++;
		}
		sum = nsum;
		i = ni;
	}
	assert(j == q);
	REP (i, 0, q) {
		printf("%d\n", ans[i]);
	}
	return 0;
}