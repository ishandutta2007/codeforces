#include <bits/stdc++.h>
#define int long long
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

const int N = 10005, INF = 0x7fffffffffffff;

struct Edge {
	int u, v, next, cap, flow;
}G[N];

int head[N], a[N], nowhead[N], d[N];
int n, m, s, t, tot = 1;

inline void addedge(int u, int v, int cap) {
	G[++tot] = (Edge) {u, v, head[u], cap, 0}, head[u] = tot;
	G[++tot] = (Edge) {v, u, head[v], 0, 0}, head[v] = tot;
}

int bfs() {
    memset(d, 0, sizeof(d));
    queue <int> q;
    d[s] = 1; q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = head[u]; i; i = G[i].next) {
            int v = G[i].v;
            if(G[i].cap > G[i].flow && d[v] == 0) {
                d[v] = d[u] + 1;
                q.push(v); 
            }
        }
    }
    return d[t];
}

int dfs(int u, int Flow) {
    if(u == t || Flow == 0) return Flow;
    int flow = 0, f;
    for(int &i = nowhead[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(d[v] == d[u] + 1 && (f = dfs(v, min(G[i].cap - G[i].flow, Flow))) > 0) {
            G[i].flow += f, G[i ^ 1].flow -= f;
            flow += f, Flow -= f;
            if(!Flow) break;
        }
    }
    return flow;
}

int dinic() {
    int ans = 0;
    while(bfs()) {
    	memcpy(nowhead, head, sizeof(nowhead));
        ans += dfs(s, INF);
    }
    return ans;
}

int sum;

signed main() {
	read(n); read(m); s = 0; t = n + m + 1;
	for(register int i = 1; i <= n; i++) read(a[i]), addedge(s, i, a[i]);
	for(register int i = 1; i <= m; i++) {
		int a, b, c;
		read(a); read(b); read(c);
		sum += max(c, 0ll);
		addedge(a, i + n, INF);
		addedge(b, i + n, INF);
		addedge(i + n, t, c);
	}
	cout << sum - dinic() << endl;
	return 0;
}