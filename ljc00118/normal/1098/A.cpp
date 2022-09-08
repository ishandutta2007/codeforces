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

const int N = 1e5 + 5, INF = 0x7fffffff;

vector <int> adj[N];
int s[N], minn[N], a[N], n; ll ans; 

void dfs(int u) {
	if(s[u] == -1) minn[u] = INF;
	else minn[u] = s[u];
	
	for(register int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i]; dfs(v);
		minn[u] = min(minn[u], minn[v]);
	}
	
	if(s[u] != -1 && minn[u] < s[u]) {
		cout << -1 << endl;
		exit(0);
	}
}

void dfs2(int u, int now) {
	if(s[u] != -1) a[u] = s[u] - now, ans += a[u];
	else if(minn[u] == INF) { a[u] = 0; }
	else a[u] = minn[u] - now, ans += a[u];
	for(register int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		dfs2(v, now + a[u]);
	}
}

int main() {
	read(n);
	for(register int i = 2; i <= n; i++) {
		int a; read(a);
		adj[a].push_back(i);
	}
	for(register int i = 1; i <= n; i++) read(s[i]);
	dfs(1); dfs2(1, 0); cout << ans << endl;
	return 0;
}

// Rotate Flower Round.
// qaq qwq qaq