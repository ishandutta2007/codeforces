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

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int n, m, k;
vi adj[MAXN];
vi cur;
vector<vi> ans;

vi stk;
bool visited[MAXN];
void dfs(int u) {
	for (int v : adj[u]) {
		if (visited[v]) continue;
		visited[v] = 1;
		stk.pb(u);
		dfs(v);
	}
	stk.pb(u);
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	REP (i, 0, m) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	visited[1] = 1;
	dfs(1);
	int mx = (2 * n - 1) / k + 1;
	for (int i : stk) {
		if (cur.size() + 1 <= mx) {
			cur.pb(i);
		} else {
			ans.pb(cur);
			cur.clear();
			cur.pb(i);
		}
	}
	ans.pb(cur);
	REP (i, 0, k) {
		if (i >= ans.size() || ans[i].empty()) {
			printf("1 1\n");
		} else {
			printf("%d", (int) ans[i].size());
			for (int j : ans[i]) {
				printf(" %d", j);
			}
			printf("\n");
		}
	}
	return 0;
}