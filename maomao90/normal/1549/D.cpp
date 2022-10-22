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
ll a[MAXN], b[MAXN];
ll sp[MAXL][MAXN];

ll qsp(int s, int e) {
	int k = 31 - __builtin_clz(e - s + 1);
	return __gcd(sp[k][s], sp[k][e - (1 << k) + 1]);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%lld", &a[i]);
		}
		if (n == 1) {
			printf("1\n");
			continue;
		}
		REP (i, 0, n - 1) {
			b[i] = abs(a[i + 1] - a[i]);
			sp[0][i] = b[i];
		}
		n--;
		REP (k, 1, MAXL) {
			REP (i, 0, n - (1 << k - 1)) {
				sp[k][i] = __gcd(sp[k - 1][i], sp[k - 1][i + (1 << k - 1)]);
			}
		}
		int j = 0;
		int ans = 1;
		REP (i, 0, n) {
			mxto(j, i);
			while (j < n && qsp(i, j) != 1) {
				j++;
			}
			j--;
			if (qsp(i, j) != 1) {
				mxto(ans, j - i + 2);
			}
			j++;
		}
		printf("%d\n", ans);
	}
	return 0;
}


/*
1
20
16 15 17 8 30 23 20 28 27 6 1 18 24 2 10 5 14 29 12 7
*/