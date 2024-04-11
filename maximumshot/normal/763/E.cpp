#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;

int n, k, m, q;
vec< int > g[N];

struct Node {
    int cnt;
    int tl, tr;
    int sz;
    pii edges[12];
} tree[4 * N];

int parent[N];
int used[N], used_count = 1;

int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

int Union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return 0;
    if(rand() % 2) swap(x, y);
    parent[y] = x;
    return 1;
}

int mas[21], mas_sz;
int last[N];

Node merge(Node const & l, Node const & r) {
    Node res;

    res.cnt = l.cnt + r.cnt;
    res.tl = l.tl;
    res.tr = r.tr;

    mas_sz = 0;

    for(int x = l.tl;x <= l.tr && x < l.tl + k;x++) {
        mas[mas_sz++] = x;
    }

    for(int x = r.tl;x <= r.tr && x < r.tl + k;x++) {
        mas[mas_sz++] = x;
    }

    for(int x = l.tr;x >= l.tl && x > l.tr - k;x--) {
        mas[mas_sz++] = x;
    }

    for(int x = r.tr;x >= r.tl && x > r.tr - k;x--) {
        mas[mas_sz++] = x;
    }

    sort(mas, mas + mas_sz);
    mas_sz = unique(mas, mas + mas_sz) - mas;

    for(int x, i = 0;i < mas_sz;i++) {
        x = mas[i];
        parent[x] = x;
        used[x] = used_count;
        last[x] = -1;
    }

    for(int i = 0;i < l.sz;i++) {
        Union(l.edges[i].first, l.edges[i].second);
    }

    for(int i = 0;i < r.sz;i++) {
        Union(r.edges[i].first, r.edges[i].second);
    }

    for(int x, i = 0;i < mas_sz;i++) {
        x = mas[i];
        for(int y : g[x]) {
            if(used[y] != used_count) continue;
            if(l.tl <= x && x <= l.tr &&
                    r.tl <= y && y <= r.tr ||
                l.tl <= y && y <= l.tr &&
                    r.tl <= x && x <= r.tr) {
                if(Union(x, y)) res.cnt--;
            }
        }
    }

    res.sz = 0;

    for(int px, x, i = 0;i < mas_sz;i++) {
        x = mas[i];
        if(x < res.tl || x > res.tr || x >= res.tl + k && x <= res.tr - k) continue;
        px = find(x);
        if(last[px] != -1) {
            res.edges[res.sz++] = make_pair(last[px], x);
        }
        last[px] = x;
    }

    used_count++;

    return res;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        tree[v].cnt = 1;
        tree[v].tl = tl;
        tree[v].tr = tr;
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }
}

Node get(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return tree[v];
    }else {
        int tm = (tl + tr) >> 1;
        if(l <= tm) {
            if(r > tm) {
                return merge(
                    get(v << 1, tl, tm, l, r),
                    get(v << 1 | 1, tm + 1, tr, l, r)
                );
            }else return get(v << 1, tl, tm, l, r);
        }else return get(v << 1 | 1, tm + 1, tr, l, r);
    }
}

int main() {

    srand(time(NULL));

    scanf("%d %d %d", &n, &k, &m);

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    build(1, 1, n);

    scanf("%d", &q);

    for(int l, r, i = 0;i < q;i++) {
        scanf("%d %d", &l, &r);
        Node res = get(1, 1, n, l, r);
        printf("%d\n", res.cnt);
    }

    return 0;
}