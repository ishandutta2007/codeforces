// Skyqwq
#include <iostream>
#include <cstdio>
#include <map>
#define int long long
#define mp make_pair
using namespace std;

typedef long long LL;

// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 2e3 + 5;
const LL INF = 1e18;

int n, x[N], y[N], w[N], S, T;

// 
namespace MF{
    int n, m, s, t, pre[N], cur[N], q[N];
    LL res, maxflow, d[N];

    int head[N], numE = 1;

    struct E{
        int next, v;
        LL w;
    } e[N * 10];

    void inline add(int u, int v, int w) {
        e[++numE] = (E) { head[u], v, w };
        head[u] = numE;
    }

    void inline init(int v, int a, int b) {
        for (int i = 1; i <= n; i++) head[i] = 0;
        numE = 1;
        n = v, s = a, t = b;
    }

    bool inline bfs() {
        int hh = 0, tt = -1;
        for (int i = 1; i <= n; i++) d[i] = 0;
        q[++tt] = s, d[s] = 1, cur[s] = head[s];
        while (hh <= tt) {
            int u = q[hh++];
            for (int i = head[u]; i; i = e[i].next) {
                int v = e[i].v;
                if (!d[v] && e[i].w) {
                    cur[v] = head[v];
                    q[++tt] = v, d[v] = d[u] + 1;
                    if (v == t) return true;
                }
            }
        }
        return false;
    }

    LL inline dinic(int u, LL flow) {
        if (u == t) return flow;
        LL rest = flow;
        for (int i = cur[u]; i && rest; i = e[i].next) {
            cur[u] = i;
            int v = e[i].v;
            if (e[i].w && d[v] == d[u] + 1) {
                int k = dinic(v, min(e[i].w, rest));
                if (!k) d[v] = 0;
                rest -= k, e[i].w -= k, e[i ^ 1].w += k;
            }
        }
        return flow - rest;
    }
    void inline addE(int u, int v, LL w) {
        add(u, v, w); add(v, u, 0);
    }
    LL inline work() {
        maxflow = 0;
        while (bfs()) 
            while (res = dinic(s, INF)) maxflow += res;
        return maxflow;
    }
}

LL ans;

typedef pair<int, int> PII;


map<PII, int> pos;

int t[N];

void inline add(int i, int j) {
	if (t[i] > t[j]) swap(i, j);
	if (t[i] + 1 == t[j]) {
		MF::addE(i + n, j, INF);
	}
}

signed main() {
	scanf("%lld", &n);
	S = 2 * n + 1, T = 2 * n + 2;
	MF::init(T, S, T);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", x + i, y + i, w + i);
		ans += w[i];
		int u = x[i] & 1, v = y[i] & 1;
		int X = x[i], Y = y[i];
		pos[mp(X, Y)] = i;
		if (u && v) t[i] = 1, MF::addE(S, i, INF);
		else if (v && !u) t[i] = 2;
		else if (u && !v) t[i] = 4, MF::addE(i + n, T, INF);
		else t[i] = 3;
	}
	
	for (int i = 1; i <= n; i++) {
		MF::addE(i, i + n, w[i]);
		if (pos.count(mp(x[i] + 1, y[i]))) add(i, pos[mp(x[i] + 1, y[i])]);
		if (pos.count(mp(x[i], y[i] + 1))) add(i, pos[mp(x[i], y[i] + 1)]);
	}
	ans -= MF::work();
	printf("%lld\n", ans);
	return 0;
}