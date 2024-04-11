#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
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
queue <int> q;
int deg[N], vis[N];
int n, ans = 1, cnt1, cnt2;

void dfs1(int u) {
	vis[u] = 1; if(deg[u] == 1) q.push(u), ++cnt2; ++cnt1;
	for(register unsigned i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(!vis[v]) dfs1(v);
	}
}

const int md = 1e9 + 7;

inline int mul(int x, int y) { return (ll)x * y % md; }

inline int sub(int x, int y) {
	x -= y;
	if(x < 0) x += md;
	return x;
}

inline int fpow(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) {
		int to; read(to);
		adj[i].push_back(to);
		adj[to].push_back(i);
		++deg[i]; ++deg[to];
	}
	for(register int i = 1; i <= n; i++) {
		if(!vis[i]) {
			cnt1 = cnt2 = 0; dfs1(i);
			while(!q.empty()) {
				int u = q.front(); q.pop();
				for(register unsigned j = 0; j < adj[u].size(); j++) {
					int v = adj[u][j];
					if(deg[v] > 1) {
						--deg[v];
						if(deg[v] == 1) q.push(v), ++cnt2;
					}
				}
			}
			ans = mul(ans, mul(fpow(2, cnt2), sub(fpow(2, cnt1 - cnt2), 2)));
		}
	}
	print(ans, '\n');
    return 0;
}