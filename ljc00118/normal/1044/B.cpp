#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
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

const int N = 1005;

struct Edge {
	int u, v, next;
}G[N << 1];

int head[N], fa[N], vis1[N], vis2[N];
int T, n, tot;

inline void addedge(int u, int v) {
	G[++tot] = (Edge) {u, v, head[u]}, head[u] = tot;
	G[++tot] = (Edge) {v, u, head[v]}, head[v] = tot;
}

void dfs1(int u, int f) {
	for(register int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if(v == f) continue;
		fa[v] = u; dfs1(v, u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> T; while(T--) {
		memset(head, 0, sizeof(head)); tot = 0; cin >> n;
		memset(vis1, 0, sizeof(vis1));
		memset(vis2, 0, sizeof(vis2));
		for(register int i = 1; i < n; i++) {
			int a, b; cin >> a >> b;
			addedge(a, b);
		} int nn, mm, last, last2; cin >> nn;
		for(register int i = 1; i <= nn; i++) { int a; cin >> a; vis1[a] = 1; last = a; } cin >> mm;
		for(register int i = 1; i <= mm; i++) { int a; cin >> a; vis2[a] = 1; last2 = a; } dfs1(last, 0);
		cout << "B " << last2 << endl; int ans; cin >> ans; if(vis1[ans]) { cout << "C " << ans << endl; continue; }
		int now = fa[ans]; while(vis1[now] == 0) now = fa[now]; cout << "A " << now << endl; cin >> ans;
		if(vis2[ans]) { cout << "C " << now << endl; continue; } else cout << "C -1" << endl;
	}
	return 0;
}