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
#define MAXN 400005

int t;
int n;
int p[2][MAXN];
int mp[MAXN];
int nxt[MAXN];
bool visited[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (_, 0, 2) {
			REP (i, 0, n) {
				scanf("%d", &p[_][i]);
			}
		}
		REP (i, 0, n + 5) {
			visited[i] = 0;
		}
		REP (i, 0, n) {
			mp[p[1][i]] = i;
		}
		bool pos = 1;
		REP (i, 0, n) {
			nxt[i] = mp[p[0][i]];
			if (nxt[i] == i) pos = 0;
			debug("%d: %d\n", i, nxt[i]);
		}
		if (!pos) {
		   	printf("0\n");
			continue;
		}
		ll ans = 1;
		REP (i, 0, n) {
			if (!visited[i]) {
				ans = ans * 2 % MOD;
				int u = i;
				visited[i] = 1;
				while (!visited[nxt[u]]) {
					u = nxt[u];
					visited[u] = 1;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}