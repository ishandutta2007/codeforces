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
#define MAXN 200005

int n, m, k;
vii adj[MAXN];
int ans;

int md[2] = {998244353, 1000000007};
int x = 200003;
struct hsh {
	int v[2];
	hsh() {
		v[0] = v[1] = 1;
	}
	void insert(int a) {
		REP (i, 0, 2) {
			v[i] = (ll) v[i] * (a + x) % md[i];
		}
	}
	hsh operator+ (const hsh& o) const {
		hsh res;
		REP (i, 0, 2) {
			res.v[i] = (ll) v[i] * o.v[i] % md[i];
		}
		return res;
	}
	bool operator== (const hsh& o) const {
		REP (i, 0, 2) {
			if (v[i] != o.v[i]) return 0;
		}
		return 1;
	}
} h[15][15], des;

void rec(int i, hsh cur) {
	if (i == k + 1) {
		if (cur == des) {
			ans++;
		}
		return;
	}
	REP (j, 0, i) {
		hsh tmp = cur + h[i][j];
		rec(i + 1, tmp);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	REP (i, 0, m) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].pb(MP(w, v));
	}
	REP (i, 1, n + 1) {
		sort(ALL(adj[i]));
	}
	REP (i, 1, n + 1) {
		REP (j, 0, adj[i].size()) {
			int v = adj[i][j].SE;
			debug("%d %d: %d\n", (int) adj[i].size(), j, v);
			h[adj[i].size()][j].insert(v);
		}
		des.insert(i);
	}
	rec(1, hsh());
	printf("%d\n", ans);
	return 0;
}