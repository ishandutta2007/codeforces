#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 1e5 + 10;
int n, m, k;
vector<int> g[N];
int used[N], vis[N], dep[N], pa[N];
vector<int> ind, cir;
void adde(int u, int v) { g[u].push_back(v); }

void Dfs(int u, int fa) {
	used[u] = 1;
	dep[u] = dep[fa] + 1;
	pa[u] = fa;
	for(int &v : g[u]) {
		if(v == fa || used[v]) continue;
		Dfs(v, u);
		if(SZ(cir)) return;
	}
	if(!vis[u]) {
		ind.push_back(u);
		for(int &v : g[u]) {
			vis[v] = 1;
			if(v == fa || dep[v] > dep[u]) continue;
			if(dep[u] - dep[v] >= k - 1) {
				for(int x = u; x != v; x = pa[x]) cir.push_back(x);
				cir.push_back(v);
				return;
			}
		}
	}
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	k = ceil(sqrt(n));
	for(int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		adde(u, v), adde(v, u);
	}
	Dfs(1, 0);
	if(SZ(cir)) {
		printf("2\n%d\n", SZ(cir));
		for(int i = 0; i < SZ(cir); i++) printf("%d ", cir[i]);
		printf("\n");
		return 0;
	}
	printf("1\n");
	for(int i = 1; i <= k; i++) printf("%d%c", ind[i - 1], " \n"[i == k]);
	return 0;
}