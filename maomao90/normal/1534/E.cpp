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
#define MAX 500

int n, k;
vi adj[MAXN];
int dist[MAXN];
int p[MAXN];
queue<int> q;
int ans;
deque<int> yes, no;

int main() {
	scanf("%d%d", &n, &k);
	REP (i, 0, n + 1) {
		REP (l, 0, k + 1) {
			int u = i;
			if (l <= i && k - l <= n - i) {
				u -= l;
				u += k - l;
				adj[i].pb(u);
			}
		}
	}
	REP (i, 0, n + 1) {
		dist[i] = INF;
	}
	memset(p, -1, sizeof p);
	dist[n] = 0;
	q.push(n);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (mnto(dist[v], dist[u] + 1)) {
				debug(" %d -> %d\n", v, u);
				p[v] = u;
				q.push(v);
			}
		}
	}
	REP (i, 1, n + 1) {
		no.pb(i);
	}
	if (dist[0] > MAX) {
		printf("-1\n");
		return 0;
	}
	int u = 0;
	int cnt = 0;
	while (p[u] != -1) {
		u = p[u];
		int diff = u - cnt;
		vi q;
		if (diff >= 0) {
			int neutral = (k - diff) / 2;
			REP (i, 0, neutral) {
				int a = yes.front(), b = no.front();
				debug(" %d %d\n", a, b);
				yes.pop_front();
				no.pop_front();
				q.pb(a);
				q.pb(b);
				no.pb(a);
				yes.pb(b);
			}
			REP (i, 0, diff) {
				int a = no.front(); no.pop_front();
				debug("%d\n", a);
				q.pb(a);
				yes.pb(a);
			}
		} else {
			diff = -diff;
			int neutral = (k - diff) / 2;
			REP (i, 0, neutral) {
				int a = yes.front(), b = no.front();
				yes.pop_front();
				no.pop_front();
				q.pb(a);
				q.pb(b);
				no.pb(a);
				yes.pb(b);
			}
			REP (i, 0, diff) {
				int a = yes.front(); yes.pop_front();
				q.pb(a);
				no.pb(a);
			}
		}
		printf("?");
		for (int &i : q) {
			printf(" %d", i);
		}
		printf("\n");
		fflush(stdout);
		int x; scanf("%d", &x);
		ans ^= x;
		cnt = u;
	}
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}