#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 3e5 + 5;

struct Tree {
	vector <int> adj[N];
	int siz[N], d[N], x[N], y[N], maxn, n;
	ll f[N];
	
 	Tree () {
		
	}
	
	void dfs1(int u, int fa) {
		siz[u] = 1;
		for(register int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i]; if(v == fa) continue;
			d[v] = d[u] + 1; dfs1(v, u); siz[u] += siz[v];
		}
	}
	
	void dfs2(int u, int fa) {
		f[u] = f[fa] + n - (siz[u] << 1);
		for(register int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i]; if(v == fa) continue; dfs2(v, u);
		}
	}
	
	void init() {
		for(register int i = 1; i < n; i++) {
			int a, b; read(a); read(b);
			x[i] = a; y[i] = b;
		}
	}
	
	void link() {
		for(register int i = 1; i < n; i++) {
			adj[x[i]].push_back(y[i]);
			adj[y[i]].push_back(x[i]);
		}
	} 
	
	void sol() { 
		dfs1(1, 0); f[1] = 0; for(register int i = 1; i <= n; i++) f[1] += d[i];
		for(register int i = 0; i < adj[1].size(); i++) dfs2(adj[1][i], 1);
		maxn = 1; for(register int i = 2; i <= n; i++) if(f[i] > f[maxn]) maxn = i;
	}
}t1, t2, t3, res;

Tree merge(Tree a, Tree b) {
	Tree ans; ans.n = a.n + b.n;
	a.sol(); b.sol();
	for(register int i = 1; i < a.n; i++) ans.x[i] = a.x[i], ans.y[i] = a.y[i];
	for(register int i = 1; i < b.n; i++) ans.x[i + a.n] = b.x[i] + a.n, ans.y[i + a.n] = b.y[i] + a.n;
	ans.x[a.n] = a.maxn; ans.y[a.n] = b.maxn + a.n; ans.link(); return ans;
}

ll ans = 0;

int main() {
	read(t1.n); read(t2.n); read(t3.n);
	t1.init(); t2.init(); t3.init();
	t1.link(); t2.link(); t3.link();
	ll sum;
	res = merge(t1, merge(t2, t3)); res.sol(); sum = 0; for(register int i = 1; i <= res.n; i++) sum += res.f[i]; ans = max(ans, sum);
	res = merge(t2, merge(t1, t3)); res.sol(); sum = 0; for(register int i = 1; i <= res.n; i++) sum += res.f[i]; ans = max(ans, sum);
	res = merge(t3, merge(t2, t1)); res.sol(); sum = 0; for(register int i = 1; i <= res.n; i++) sum += res.f[i]; ans = max(ans, sum);
	cout << ans / 2 << endl;
	return 0;
}

// Rotate Flower Round.