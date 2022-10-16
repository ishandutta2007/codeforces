#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 215;

typedef pair<int, int> PII;

int n, m, dx[N], t1;

int dy[N], t2;

int inline getX(int x) {
	return lower_bound(dx + 1, dx + 1 + t1, x) - dx;
}

int inline getY(int y) {
	return lower_bound(dy + 1, dy + 1 + t2, y) - dy;
}

PII L[N], R[N];

const int INF = 1e9;

// 
namespace MF{
    int n, m, s, t, pre[N], cur[N], q[N];
    LL res, maxflow, d[N];

    int head[N], numE = 1;

    struct E{
        int next, v, w;
    } e[N * N * 2];

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
                int k = dinic(v, min((LL)e[i].w, rest));
                if (!k) d[v] = 0;
                rest -= k, e[i].w -= k, e[i ^ 1].w += k;
            }
        }
        return flow - rest;
    }
    void inline addE(int u, int v, int w) {
        add(u, v, w); add(v, u, 0);
    }
    LL inline work() {
        maxflow = 0;
        while (bfs()) 
            while (res = dinic(s, INF)) maxflow += res;
        return maxflow;
    }
}

bool st[N][N];

int S, T;

int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(L[i].fi), read(L[i].se);
		read(R[i].fi), read(R[i].se);
		R[i].fi++, R[i].se++;
		dx[++t1] = L[i].fi;
		dx[++t1] = R[i].fi;
		dy[++t2] = L[i].se;
		dy[++t2] = R[i].se;
	}
	dx[++t1] = n + 1, dy[++t1] = n + 1;
	sort(dx + 1, dx + 1 + t1);
	t1 = unique(dx + 1, dx + 1 + t1) - dx - 1;
	sort(dy + 1, dy + 1 + t2);
	t2 = unique(dy + 1, dy + 1 + t2) - dy - 1;
	for (int i = 1; i <= m; i++) {
		int x1 = getX(L[i].fi), y1 = getY(L[i].se);
		int x2 = getX(R[i].fi), y2 = getY(R[i].se);
		for (int u = x1; u < x2; u++)
			for (int v = y1; v < y2; v++)
				st[u][v] = 1;
	}
	S = t1 + t2 + 1, T = S + 1;
	MF::init(T, S, T);
	for (int i = 1; i < t1; i++) {
		MF::addE(S, i, dx[i + 1] - dx[i]);
	}
	for (int i = 1; i < t2; i++) {
		MF::addE(i + t1, T, dy[i + 1] - dy[i]);
	}
	for (int i = 1; i < t1; i++) {
		for (int j = 1; j < t2; j++) {
			if (st[i][j]) MF::addE(i, j + t1, INF);
		}
	}
	printf("%lld\n", MF::work());
}