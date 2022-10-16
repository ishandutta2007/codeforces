#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}
 
void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e5 + 5, P = 1e9 + 7, L = 17;

int n, m, d[N], ans[N], g[N], A[N], faW[N], B[N], c[N], t, fa[N][L];

bool vis[N];

int head[N], numE = 1;

vector<int> C[N];

struct E{
    int next, v, w;
} e[N << 1];

void add(int u, int v, int w) {
    e[++numE] = (E) { head[u], v, w };
    head[u] = numE;
}

typedef pair<LL, int> PII;
 
priority_queue<PII, vector<PII>, greater<PII> > q;
 
void dijkstra() {
    memset(d, 0x3f, sizeof d); d[0] = 0;
    d[1] = 0; q.push(make_pair(0, 1));
    while(!q.empty()) {
        PII u = q.top(); q.pop();
        if(vis[u.se]) continue;
        vis[u.se] = true;
        c[++t] = u.se;
        for (int i = head[u.se]; i; i = e[i].next) {
            int v = e[i].v;
            if(d[u.se] + e[i].w < d[v]) {
                d[v] = d[u.se] + e[i].w;
                q.push(make_pair(d[v], v));
            }
        }
    }
}

int inline U(int x, int y) {
	return (x * 10ll + y) % P;
}

int inline get(int u, int t, int v, int id) {
	if (d[u] < t) {
		int res = g[u];
		for (int k = 0; k < t - d[u]; k++)
			res = U(res, C[id][k]);
		return res;
	} else {
		for (int i = L - 1; ~i; i--) {
			if (d[fa[u][i]] >= t) u = fa[u][i];
		}
		int res = g[fa[u][0]];
		for (int k = 0; k < t - d[fa[u][0]]; k++)
			res = U(res, C[faW[u]][k]);
		return res;
	}
}

int inline query(int u, int t, int v, int id) {
	if (d[u] < t) {
		return C[id][t - d[u] - 1];
	} else {
		for (int i = L - 1; ~i; i--) {
			if (d[fa[u][i]] >= t) u = fa[u][i];
		}
		return C[faW[u]][t - d[fa[u][0]] - 1];
	}
}

int inline Add(int x, int v) {
	for (int k: C[v])
		x = U(x, k);
	return x;
}

int main() {
	read(n); read(m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", A + i, B + i);
		int p = i;
		while (p) C[i].pb(p % 10), p /= 10;
		reverse(C[i].begin(), C[i].end());
		add(A[i], B[i], C[i].size());
		add(B[i], A[i], C[i].size());
	}
	dijkstra();
	for (int i = 2; i <= n; i++) {
		int v = c[i];
		int f = -1, w;
		for (int i = head[v]; i; i = e[i].next) {
			int u = e[i].v;
			if (d[u] + e[i].w == d[v]) {
				if (f == -1) f = u, w = i >> 1;
				else {
					int l = 0, r = d[v] - 1;
					while (l < r) {
						int mid = (l + r + 1) >> 1;
						if (get(u, mid, v, i >> 1) == get(f, mid, v, w)) l = mid;
						else r = mid - 1; 
					}
					if (query(u, r + 1, v, i >> 1) < query(f, r + 1, v, w)) f = u, w = i >> 1;
				}
			}
		}

		g[v] = Add(g[f], w);
		faW[v] = w;
		fa[v][0] = f;
		for (int i = 1; i < L; i++)
		fa[v][i] = fa[fa[v][i - 1]][i - 1];
	}
	for (int i = 2; i <= n; i++) printf("%d\n", g[i]);
}