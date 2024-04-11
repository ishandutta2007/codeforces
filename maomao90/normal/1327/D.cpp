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

int t;
int n;
int p[MAXN], c[MAXN];
vi fact[MAXN];
bool visited[MAXN];
vector<vi> v;

int main() {
	scanf("%d", &t);
	REP (i, 1, MAXN) {
		vi tmp;
		int j;
		for (j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				tmp.pb(j);
			}
		}
		for (; j >= 1; j--) {
			if (j * j == i) continue;
			if (i % j == 0) {
				tmp.pb(i / j);
			}
		}
		fact[i] = tmp;
	}
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			scanf("%d", &p[i]);
		}
		REP (i, 1, n + 1) {
			scanf("%d", &c[i]);
		}
		REP (i, 1, n + 1) {
			visited[i] = 0;
		}
		v.clear();
		REP (i, 1, n + 1) {
			if (visited[i]) continue;
			vi tmp;
			tmp.pb(c[i]);
			int u = i;
			visited[u] = 1;
			while (p[u] != i) {
				u = p[u];
				visited[u] = 1;
				tmp.pb(c[u]);
			}
			v.pb(tmp);
		}
		int ans = INF;
		for (vi& vt : v) {
			int n = vt.size();
			for (int d : fact[n]) {
				REP (i, 0, n) {
					visited[i] = 0;
				}
				bool pos = 0;
				REP (i, 0, n) {
					if (visited[i]) continue;
					visited[i] = 1;
					int u = i;
					int curc = vt[u];
					while ((u + d) % n != i) {
						u = (u + d) % n;
						visited[u] = 1;
						if (vt[u] != curc) curc = -1;
					}
					if (curc != -1) {
						pos = 1;
						break;
					}
				}
				if (pos) {
					mnto(ans, d);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}