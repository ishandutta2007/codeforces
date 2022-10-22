#include <bits/stdc++.h> 
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
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
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 400005

struct frac {
	ll tp, bt;
	frac() {}
	frac(ll tp, ll bt): tp(tp), bt(bt) {
		ll g = __gcd(tp, bt);
		tp /= g;
		bt /= g;
	}
	bool operator==(const frac& o) const {
		return tp == o.tp && bt == o.bt;
	}
	frac operator+(const frac& o) {
		ll g = __gcd(bt, o.bt);
		ll lcm = bt / g * o.bt;
		ll f = lcm / bt, fo = lcm / o.bt;
		return frac(f * tp + fo * o.tp, lcm);
	}
	bool operator<(const frac& o) const {
		return (ld) tp / bt < (ld) o.tp / o.bt;
	}
	frac operator/(const frac& o) {
		frac inv = frac(o.bt, o.tp);
		return frac(tp * inv.tp, bt * inv.bt);
	}
};

int n;
frac pts;
int id = 0;
map<frac, int> mp;
vii adj[MAXN];
vii ans;

int visited[MAXN];
int dfs(int u) {
	visited[u] = 1;
	int pend = -1;
	for (auto [v, e] : adj[u]) {
		if (visited[v] == 1) continue;
		int cur = e;
		if (!visited[v]) {
			int tmp = dfs(v);
			if (tmp != -1) {
				ans.pb(tmp, cur);
				cur = -1;
			}
		}
		if (cur != -1) {
			if (pend == -1) {
				pend = cur;
			} else {
				ans.pb(pend, cur);
				pend = -1;
			}
		}
	}
	visited[u] = 2;
	return pend;
}

int main() {
	scanf("%d", &n);
	REP (i, 1, n + 1) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		frac x = frac(a, b), y = frac(c, d);
		frac u = (x + frac(1, 1)) / y, v = x / (y + frac(1, 1));
		if (mp.find(u) == mp.end()) {
			//printf("%lld %lld: %d\n", u.tp, u.bt, id);
			mp[u] = id++;
		}
		if (mp.find(v) == mp.end()) {
			//printf("%lld %lld: %d\n", v.tp, v.bt, id);
		   	mp[v] = id++;
		}
		int ui = mp[u], vi = mp[v];
		adj[ui].pb(vi, i);
		adj[vi].pb(ui, i);
	}
	//REP (i, 0, id) {
		//printf("%d:", i);
		//for (auto [v, e] : adj[i]) {
			//printf(" %d", v);
		//}
		//printf("\n");
	//}
	REP (i, 0, id) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	printf("%d\n", ans.size());
	for (auto [f, s] : ans) {
		printf("%d %d\n", f, s);
	}
	return 0;
}