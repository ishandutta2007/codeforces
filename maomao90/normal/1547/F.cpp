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
#define MAXL 20

int t;
int n;
int a[MAXN], na[MAXN];
int sp[MAXL][MAXN];

int query(int s, int e) {
	int k = 31 - __builtin_clz(e - s + 1);
	return __gcd(sp[k][s], sp[k][e - (1 << k) + 1]);
}

bool check(int x) {
	int prv = -1;
	REP (i, 0, n) {
		int s = i, e = i + x;
		int cur;
		if (e < n) {
			cur = query(s, e);
		} else {
			cur = query(s, n - 1);
			cur = __gcd(cur, query(0, e - n));
		}
		if (prv == -1) {
			prv = cur;
		} else if (cur != prv) {
			return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
			sp[0][i] = a[i];
		}
		REP (k, 1, MAXL) {
			REP (i, 0, n) {
				if (i + (1 << k - 1) >= n) continue;
				sp[k][i] = __gcd(sp[k - 1][i], sp[k - 1][i + (1 << k - 1)]);
			}
		}
		int lo = 0, hi = n - 1, mid;
		while (lo < hi) {
			mid = lo + hi >> 1;
			if (check(mid)) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		printf("%d\n", hi);
	}
	return 0;
}