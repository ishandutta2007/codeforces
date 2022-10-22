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

int n;
int b[MAXN], c[MAXN];
int rl[MAXN];
vii adj[MAXN];
bool visited[MAXN];
vii v;
vi ans;

void dfs(int u) {
	while (!adj[u].empty()) {
		auto [v, i] = adj[u].back();
		adj[u].pop_back();
		if (visited[i]) continue;
		visited[i] = 1;
		dfs(v);
	}
	ans.pb(u);
}

int main() {
	scanf("%d", &n);
	REP (i, 1, n) {
		scanf("%d", &b[i]);
		v.pb(b[i], i);
	}
	REP (i, 1, n) {
		scanf("%d", &c[i]);
		v.pb(c[i], i);
	}
	REP (i, 1, n) {
		if (b[i] > c[i]) {
			printf("-1\n");
			return 0;
		}
	}
	sort(ALL(v));
	int i = 0, cnt = 0;
	while (i < v.size()) {
		int cur = v[i].FI;
		for (; i < v.size() && v[i].FI == cur; i++) {
			int u = v[i].SE;
			if (b[u] == cur) {
				b[u] = cnt;
			} else {
				c[u] = cnt;
			}
		}
		rl[cnt] = cur;
		cnt++;
	}
	REP (i, 1, n) {
		adj[b[i]].pb(c[i], i);
		adj[c[i]].pb(b[i], i);
		//printf("%d %d\n", b[i], c[i]);
	}
	vi odd;
	REP (i, 0, cnt) {
		if (adj[i].size() % 2 == 1) {
			odd.pb(i);
		}
	}
	if (odd.size() != 0 && odd.size() != 2) {
		printf("-1\n");
		return 0;
	}
	if (!odd.empty()) {
		dfs(odd[0]);
	} else {
		dfs(0);
	}
	reverse(ALL(ans));
	if (ans.size() < n) {
		printf("-1\n");
		return 0;
	}
	for (int i : ans) {
		printf("%d ", rl[i]);
	}
	printf("\n");
	return 0;
}