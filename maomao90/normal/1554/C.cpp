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
#define MAXL 31

int t;
int n, m;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		int ans = 0;
		RREP (k, MAXL, 0) {
			int a = n >> k & 1, b = m >> k & 1;
			if (a == 0 && b == 0) {
				continue;
			} else if (a == 0 && b == 1) {
				ans += 1 << k;
			} else if (a == 1 && b == 0) {
				ans--;
				break;
			} else if (a == 1 && b == 1) {
				int ones = (1 << k + 1) - 1;
				if ((m & ones) == ones) {
					ans += ones;
					break;
				}
			}
		}
		ans++;
		printf("%d\n", ans);
	}
	return 0;
}