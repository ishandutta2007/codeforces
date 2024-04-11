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

int t;
int n, m;
int cnt[MAXN];
int p[MAXN];
vi ans;

int a[MAXN];
bool visited[MAXN];
int solve() {
	REP (i, 0, n) {
		visited[i] = 0;
	}
	int res = n;
	REP (i, 0, n) {
		debug("%d ", a[i]);
		if (visited[i]) continue;
		res--;
		visited[i] = 1;
		int u = i;
		while (a[u] != i) {
			u = a[u];
			visited[u] = 1;
		}
	}
	debug("\n");
	return res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 0, n + 5) {
			cnt[i] = 0;
		}
		REP (i, 0, n) {
			scanf("%d", &p[i]);
			p[i]--;
			cnt[(p[i] - i + n) % n]++;
		}
		ans.clear();
		RREP (i, n, 1) {
			if (cnt[i % n] < n / 3) continue;
			REP (j, 0, n) {
				a[(j + i) % n] = p[j];
			}
			if (solve() <= m) {
				ans.pb(n - i);
			}
		}
		printf("%d", (int) ans.size());
		for (int i : ans) {
			printf(" %d", i);
		}
		printf("\n");
	}
	return 0;
}