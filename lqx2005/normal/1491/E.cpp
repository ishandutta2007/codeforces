#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef pair<int, int> par;
typedef long long LL;
typedef double db;
const int N = 2e5 + 10, M = 30;
struct edge {
	int to, nxt, vis;
}e[N << 1];
int head[N], tot = 1;
int siz[N], f[M];
int n;
int flag = 0;

void adde(int u, int v) {
	e[++tot] = edge{v, head[u]};
	head[u] = tot;
}

void dfs(int u, int fa, int id, int &cut, int k) {
	siz[u] = 1;
	for(int i = head[u]; i; i = e[i].nxt) {
		if(e[i].vis) continue;
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v, u, i, cut, k);
		siz[u] += siz[v];
	}
	if(siz[u] == f[k] || siz[u] == f[k - 1]) cut = id;
	return;
}

void Solve(int rt, int k) {
	if(k <= 1) return;
	k--;
	int cut = -1;
	dfs(rt, 0, 0, cut, k);
	if(cut == -1) return flag = 1, void();
	e[cut].vis = 1, e[cut ^ 1].vis = 1;
	int u = e[cut].to, v = e[cut ^ 1].to;
	if(siz[u] == f[k]) Solve(u, k), Solve(v, k - 1);
	else Solve(u, k - 1), Solve(v, k);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	f[0] = f[1] = 1;
	rep(i, 1, M - 1) f[i] = f[i - 1] + f[i - 2];
	cin >> n;
	int k = -1;
	rep(i, 1, M - 1) if(f[i] == n) k = i;
	rep(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adde(u, v), adde(v, u);
	}
	if(k == -1) return cout << "NO\n", 0;
	Solve(1, k);
	if(flag) cout << "NO\n";
	else cout << "YES\n";
	return 0;
}