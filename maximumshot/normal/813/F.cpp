#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

vec< pair< int*, int > > buffer;
vec< int > cps;

inline void checkPoint() {
    cps.push_back((int)buffer.size());
}

inline void rollBack() {
    int last = cps.back();
    cps.pop_back();
    while(buffer.size() > last) {
        *buffer.back().first = buffer.back().second;
        buffer.pop_back();
    }
}

inline void put(int * ptr, int val) {
    buffer.push_back(make_pair(ptr, *ptr));
    *ptr = val;
}

struct DSU {
    int n;
    vec< int > p;
    vec< int > c;
    vec< int > h;
    DSU() {
        n = 0;
    }
    DSU(int _n) : n(_n) {
        p.resize(n + 1);
        c.resize(n + 1);
        h.resize(n + 1);
        for(int i = 1;i <= n;i++) {
            p[i] = i;
        }
    }
    int find(int x) {
        if(x == p[x]) {
            return x;
        }else {
            int t = find(p[x]);
            put(&c[x], c[x] ^ c[p[x]]); // color[x] ^= color[p[x]];
            put(&p[x], t); // p[x] = t;
            return t;
        }
    }
    int parity(int x) {
        find(x);
        return c[x];
    }
    void show() {
        for(int i = 1;i <= n;i++) {
            cout << i << " -> " << p[i] << "\n";
        }
    }
};

struct query {
    int u, v;
    int l, r;
    query() {
        u = v = l = r = 0;
    }
    query(int _u, int _v, int _l, int _r) {
        u = _u;
        v = _v;
        l = _l;
        r = _r;
    }
};

int const N = 1e5 + 5;

int n, q;
char Type[N];
pii Edge[N];
int Link[N];
int result[N];
DSU dsu;

bool addEdge(int u, int v) {
    int pu = dsu.find(u);
    int pv = dsu.find(v);
    if(pu == pv) {
        if(dsu.parity(u) == dsu.parity(v)) {
            return 0;
        }else {
            return 1;
        }
    }
    if(dsu.h[pu] < dsu.h[pv]) {
        swap(u, v);
        swap(pu, pv);
    }
    put(&dsu.c[pv], dsu.c[pv] ^ dsu.parity(u) ^ dsu.parity(v) ^ 1);
    if(dsu.h[pu] == dsu.h[pv]) {
        put(&dsu.h[pu], dsu.h[pu] + 1);
    }
    put(&dsu.p[pv], pu);
    return 1;
}

void solve(int L, int R, vec< query > mas, bool good) {
    checkPoint();
    for(query cur : mas) {
        if(cur.l <= L && cur.r > R) {
            good &= addEdge(cur.u, cur.v);
        }
    }
    if(L == R) {
        result[L] = good;
    }else {
        int M = (L + R) / 2;
        vec< query > tol, tor;
        for(query cur : mas) {
            if(cur.l <= L && cur.r > R) continue;
            if(cur.l > R || cur.r <= L) continue;
            if(cur.l <= M && cur.r > L) {
                tol.push_back(cur);
            }
            if(cur.l <= R && cur.r > M + 1) {
                tor.push_back(cur);
            }
        }
        solve(L, M, tol, good);
        solve(M + 1, R, tor, good);
    }
    rollBack();
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    map< pii, int > H;
    for(int x, y, iter = 0;iter < q;iter++) {
        scanf("%d %d", &x, &y);
        Edge[iter] = make_pair(x, y);
        assert(x < y);
        if(H.count(make_pair(x, y))) {
            Type[iter] = '-';
            Link[iter] = H[make_pair(x, y)];
            Link[Link[iter]] = iter;
            H.erase(make_pair(x, y));
        }else {
            Type[iter] = '+';
            H[make_pair(x, y)] = iter;
        }
    }

    vec< query > mas;

    for(int iter = 0;iter < q;iter++) {
        if(Type[iter] == '-') {
            mas.push_back(query(Edge[iter].first, Edge[iter].second, Link[iter], iter));
        }
    }

    for(pair< pii, int > iter : H) {
        int u, v, l;
        tie(u, v) = iter.first;
        l = iter.second;
        mas.push_back(query(u, v, l, q));
    }

    dsu = DSU(n);

    solve(0, q - 1, mas, 1);

    for(int iter = 0;iter < q;iter++) {
        if(result[iter]) {
            puts("YES");
        }else {
            puts("NO");
        }
    }

    return 0;
}