#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5;

vector <int> adj[N];
ll f[N], sum[N], w[N], d[N], ans;
int n;

void dfs1(int u, int fa) {
	sum[u] = (ll)w[u];
	for(register int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i]; if(v == fa) continue;
		d[v] = d[u] + 1; dfs1(v, u); sum[u] += sum[v];
	}
}

void dfs2(int u, int fa) {
	for(register int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i]; if(v == fa) continue;
		f[v] = f[u] - sum[v] + sum[1] - sum[v];
		dfs2(v, u);
	}
}

int main() {
	read(n);
	rep(i, 1, n) read(w[i]);
	rep(i, 1, n - 1) {
		int a, b; read(a); read(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1(1, 0);
	rep(i, 1, n) f[1] += (ll)w[i] * d[i];
	dfs2(1, 0);
	rep(i, 1, n) ans = max(ans, f[i]);
	cout << ans << endl;
	return 0;
}