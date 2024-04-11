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
#define MAXN 1000

int t;
int n;
int a[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool done = 1;
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
			if (i != a[i]) {
				done = 0;
			}
		}
		if (done) {
			printf("0\n");
			continue;
		}
		int ans = 1;
		while (1) {
			for (int i = ans % 2; i < n; i += 2) {
				if (i == 0) continue;
				if (a[i] > a[i + 1]) {
					swap(a[i], a[i + 1]);
				}
			}
			bool done = 1;
			REP (i, 1, n + 1) {
				if (i != a[i]) {
					done = 0;
				}
			}
			if (done) break;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}