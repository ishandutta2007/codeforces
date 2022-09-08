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

const int N = 1e5 + 5;

vector <int> adj[N];
int in[N], d[N], x[N], y[N];
int n, s, cnt;

void dfs(int u, int fa) {
	for(register int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i], val = (in[u] == 1 || in[v] == 1);
		if(v == fa) continue; d[v] = d[u] + val; dfs(v, u);
	}
}

int main() {
	read(n); read(s);
	for(register int i = 1; i < n; i++) {
		int a, b; read(a); read(b);
		adj[a].push_back(b); in[a]++;
		adj[b].push_back(a); in[b]++;
		x[i] = a; y[i] = b;
	}
	int maxn = 1; dfs(1, 0);
	for(register int i = 1; i < n; i++) if(in[x[i]] == 1 || in[y[i]] == 1) cnt++;
	for(register int i = 2; i <= n; i++) if(d[i] > d[maxn]) maxn = i;
	d[maxn] = 0; dfs(maxn, 0); maxn = 1; 
	for(register int i = 2; i <= n; i++) if(d[i] > d[maxn]) maxn = i;
	printf("%.10lf\n", (double)s / cnt * d[maxn]);
	return 0;
}