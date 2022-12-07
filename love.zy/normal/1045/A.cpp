#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 5010;

//src 1
//sink 2
//weapon i 2+i
//target i 2+n+i
//segment tree node i 2+n+m+i
//all nodes 2+n+5*m

const int inf = 0x3f3f3f3f;
int n, m;

namespace netflow {
    struct Edge {
        int v, c, x;
    } E[6000010];
    int src, sink;
    int l[10*maxn], e = 0;
    int L[10*maxn], Q[10*maxn];
    inline void addEdge(int u, int v, int f, int invf) {
        E[e].v = v; E[e].x = l[u]; E[e].c = f; l[u] = e++;
        E[e].v = u; E[e].x = l[v]; E[e].c = invf; l[v] = e++;
    }
    int _bfs() {
        for (int i = 1; i < 10*maxn; i++) L[i] = -1;
        int s = 0, t = 0, u;
        Q[t++] = src; L[src] = 0;
        while (s < t) {
            u = Q[s++];
            for (int p = l[u]; p >= 0; p = E[p].x) {
                int v = E[p].v;
                if (L[v] == -1 && E[p].c) {
                    L[Q[t++] = v] = L[u] + 1;
                }
            }
        }
        return L[sink] != -1;
    }
    int _find(int u, int in) {
        if (u == sink) return in;
        int w = 0, t;
        for (int p = l[u]; p >= 0 && w < in; p = E[p].x) {
            int v = E[p].v;
            if (L[v] == L[u] + 1 && E[p].c) {
                if ((t=_find(v, min(in-w, E[p].c)))) {
                    E[p].c -= t;
                    E[p^1].c += t;
                    w += t;
                }
            }
        }
        if (w < in) L[u] = -1;
        return w;
    }
    int dinic() {
        int res = 0, t;
        while (_bfs())
            while ((t=_find(src, 0x3f3f3f3f)))
                res += t;
        return res;
    }
    void init() {
        e = 0; memset(l, -1, sizeof(l));
        src = 1; sink = 2;
    }
}

using namespace netflow;

void build(int l, int r, int rt) {
    if (l == r) {
        addEdge(2+n+m+rt, 2+n+l, 1, 0);
        return;
    }
    int mid = (l+r) >> 1;
    addEdge(2+n+m+rt, 2+n+m+(rt<<1), inf, 0);
    addEdge(2+n+m+rt, 2+n+m+(rt<<1|1), inf, 0);
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
}

void add(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        addEdge(x, 2+n+m+rt, 1, 0);
        return;
    }
    int mid = (l+r) >> 1;
    if (L <= mid) add(L, R, x, l, mid, rt<<1);
    if (R > mid) add(L, R, x, mid+1, r, rt<<1|1);
}

int gettarget(int x) {
    if (x >= 2+n+1 && x <= 2+n+m) {
        return x-2-n;
    }
    for (int p = l[x]; p >= 0; p = E[p].x) {
        if (p&1) continue;
        int v = E[p].v;
        if (E[p^1].c) {
            E[p^1].c --;
            return gettarget(v);
        }
    }
    return -1;
}

int active[maxn];
int frm[maxn];
int T[maxn], A[maxn], B[maxn], C[maxn];

int main() {
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= m; i++) {
        addEdge(2+n+i, 2, 1, 0);
    }
    build(1, m, 1);
    for (int i = 1; i <= n; i++) {
        int typ;
        scanf("%d", &typ);
        if (typ == 0) {
            addEdge(1, 2+i, 1, 0);
            int K = 0;
            scanf("%d", &K);
            for (int j = 1; j <= K; j++) {
                int x = 0;
                scanf("%d", &x);
                addEdge(2+i, 2+n+x, 1, 0);
            }
        } else if (typ == 1) {
            addEdge(1, 2+i, 1, 0);
            int L, R;
            scanf("%d%d", &L, &R);
            add(L, R, 2+i, 1, m, 1);
        } else {
            addEdge(1, 2+i, 2, 0);
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            A[i] = a; B[i] = b; C[i] = c;
            T[i] = 1;
            addEdge(2+i, 2+n+a, 1, 0);
            addEdge(2+i, 2+n+b, 1, 0);
            addEdge(2+i, 2+n+c, 1, 0);
        }
    }
    dinic();
    for (int i = 1; i <= n; i++) {
        int t = gettarget(2+i);
        if (t != -1) {
            frm[t] = i;
        }
        if (T[i]) {
            t = gettarget(2+i);
            if (t != -1) {
                frm[t] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (T[i]) {
            int x = (frm[A[i]] == i)+(frm[B[i]] == i)+(frm[C[i]] == i);
            if (x == 1) {
                if (frm[A[i]] != i) {
                    frm[A[i]] = i;
                } else if (frm[B[i]] != i) {
                    frm[B[i]] = i;
                } else if (frm[C[i]] != i) {
                    frm[C[i]] = i;
                }
            }
        }
    }
    int X = 0;
    for (int i = 1; i <= m; i++) if (frm[i]) ++ X;
    printf("%d\n", X);
    for (int i = 1; i <= m; i++) {
        if (frm[i]) printf("%d %d\n", frm[i], i);
    }
    return 0;
}