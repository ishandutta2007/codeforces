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
#define MAXN 300005

int n;
int a[MAXN];
ll g[MAXN], s[MAXN];

ll fw[MAXN];
inline void incre(int i, ll x) {
	for (; i < MAXN; i += i & -i) fw[i] += x;
}
inline void incre(int s, int e, ll x) {
	incre(e + 1, -x);
	incre(s, x);
}
inline ll qsm(int i) {
	mnto(i, MAXN - 2);
	ll res = 0;
	for (; i > 0; i -= i & -i) res += fw[i];
	return res;
}
inline ll qsm(int s, int e) {
	return qsm(e) - qsm(s - 1);
}

int main() {
	scanf("%d", &n);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
	}
	REP (i, 1, n + 1) {
		g[i] = g[i - 1] + (ll) a[i] * (i - 1) - qsm(a[i]);
		int k = 1;
		for (int j = a[i]; j < MAXN; j += a[i]) {
			incre(j, j + a[i] - 1, (ll) a[i] * k);
			k++;
		}
		debug("%d: %lld\n", i, g[i]);
	}
	memset(fw, 0, sizeof fw);
	ll sm = 0;
	REP (i, 1, n + 1) {
		s[i] = s[i - 1] + sm;
		int k = 1;
		for (int j = a[i]; j < MAXN; j += a[i]) {
			s[i] -= qsm(j, j + a[i] - 1) * k * a[i];
			k++;
		}
		incre(a[i], 1);
		debug("%d: %lld\n", i, s[i]);
		sm += a[i];
	}
	REP (i, 1, n + 1) {
		printf("%lld ", s[i] + g[i]);
	}
	printf("\n");
	return 0;
}