#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

int n, q, s;
vec< pii > g[10 * N];

inline void addEdge(int x, int y, int w) {
    g[x].push_back( {y, w} );
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        addEdge(v + n, tl, 0);
        addEdge(tl, v + n, 0);
        addEdge(v + 5 * n, tl, 0);
        addEdge(tl, v + 5 * n, 0);
    }else {
        int ls = v << 1;
        int rs = v << 1 | 1;
        int tm = (tl + tr) >> 1;
        addEdge(v + n, ls + n, 0);
        addEdge(v + n, rs + n, 0);
        addEdge(ls + 5 * n, v + 5 * n, 0);
        addEdge(rs + 5 * n, v + 5 * n, 0);
        build(ls, tl, tm);
        build(rs, tm + 1, tr);
    }
}

void addToSegment(int v, int tl, int tr, int u, int l, int r, int w) {
    if(l <= tl && tr <= r) {
        addEdge(u, v + n, w);
    }else {
        int tm = (tl + tr) >> 1;
        if(l <= tm) {
            addToSegment(v << 1, tl, tm, u, l, r, w);
        }
        if(r > tm) {
            addToSegment(v << 1 | 1, tm + 1, tr, u, l, r, w);
        }
    }
}

void addFromSegment(int v, int tl, int tr, int u, int l, int r, int w) {
    if(l <= tl && tr <= r) {
        addEdge(v + 5 * n, u, w);
    }else {
        int tm = (tl + tr) >> 1;
        if(l <= tm) {
            addFromSegment(v << 1, tl, tm, u, l, r, w);
        }
        if(r > tm) {
            addFromSegment(v << 1 | 1, tm + 1, tr, u, l, r, w);
        }
    }
}

ll dist[10 * N];

void calc() {
    for(int i = 0;i < 10 * N;i++) {
        dist[i] = inf64;
    }
    dist[s] = 0;
    set< pair< ll, int > > H;
    H.insert( {0, s} );
    while(!H.empty()) {
        int v = H.begin()->second;
        H.erase(H.begin());
        for(pii iter : g[v]) {
            int to = iter.first;
            int w = iter.second;
            if(dist[to] > dist[v] + w) {
                H.erase( {dist[to], to} );
                dist[to] = dist[v] + w;
                H.insert( {dist[to], to} );
            }
        }
    }
}

void printResult() {
    for(int i = 1;i <= n;i++) {
        if(dist[i] == inf64) {
            printf("-1 ");
        }else {
//            printf("%lld ", dist[i]);
            printf("%I64d ", dist[i]);
        }
    }
    printf("\n");
}

int main() {

    scanf("%d %d %d", &n, &q, &s);

    build(1, 1, n);

    for(int iter = 0;iter < q;iter++) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            int v, u, w;
            scanf("%d %d %d", &v, &u, &w);
            addEdge(v, u, w);
        }else if(t == 2) {
            int v, l, r, w;
            scanf("%d %d %d %d", &v, &l, &r, &w);
            addToSegment(1, 1, n, v, l, r, w);
        }else { // t == 3
            int v, l, r, w;
            scanf("%d %d %d %d", &v, &l, &r, &w);
            addFromSegment(1, 1, n, v, l, r, w);
        }
    }

    calc();
    printResult();

    return 0;
}