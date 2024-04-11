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
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 1005

int n, d;
bool visited[MAXN];

int p[MAXN], rnk[MAXN], comp[MAXN];
int findSet(int u) {
	if (p[u] == u) return u;
	return p[u] = findSet(p[u]);
}
bool join(int a, int b) {
	int pa = findSet(a), pb = findSet(b);
	if (pa == pb) return 0;
	if (rnk[pa] < rnk[pb]) swap(pa, pb);
	if (rnk[pa] == rnk[pb]) rnk[pa]++;
	p[pb] = pa;
	comp[pa] += comp[pb];
	return 1;
}

int main() {
	scanf("%d%d", &n, &d);
	REP (i, 1, n + 1) {
		p[i] = i;
		comp[i] = 1;
		rnk[i] = 1;
	}
	int k = 1;
	while (d--) {
		int x, y; scanf("%d%d", &x, &y);
		if (!join(x, y)) {
			k++;
		}
		memset(visited, 0, sizeof visited);
		vi v;
		REP (i, 1, n + 1) {
			int u = findSet(i);
			if (visited[u]) {
				continue;
			}
			visited[u] = 1;
			v.pb(comp[u]);
		}
		sort(ALL(v), greater<int>());
		int ans = 0;
		REP (i, 0, k) {
			ans += v[i];
		}
		ans--;
		printf("%d\n", ans);
	}
	return 0;
}