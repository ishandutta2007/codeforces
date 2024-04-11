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
#define pb emplace_back
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

int t;
int n;
int a[MAXN];
int mp[MAXN];

int main() {
	scanf("%d", &t);
	memset(mp, -1, sizeof mp);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
		}
		REP (i, 1, n + 1) {
			mp[a[i]] = i;
		}
		ll ans = 0;
		REP (ai, 1, 2 * n + 1) {
			int i = mp[ai];
			if (i == -1) continue;
			for (int aj = ai + 1; (ll) ai * aj <= 2 * n; aj++) {
				int j = ai * aj - i;
				if (j <= 0 || j > n) continue;
				if (a[j] == aj) {
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
		REP (i, 1, n + 1) {
			mp[a[i]] = -1;
		}
	}
	return 0;
}