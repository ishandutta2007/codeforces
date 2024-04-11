#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int p[200010], dis[200010], a[200010], S, T, n;
int que[200010], qcnt;
struct segtree {
    pair <int, int> val[800010];
    void build(int x, int l, int r, int *a) {
        if (l == r) val[x] = {a[l], l};
        else {
            int mid = l + r >> 1;
            build(x << 1, l, mid, a);
            build(x << 1 | 1, mid + 1, r, a);
            val[x] = max(val[x << 1], val[x << 1 | 1]);
        }
    }
    pair <int, int> query(int x, int l, int r, int L, int R) {
        if (l > R || L > r) return {-inf, -1};
        if (L <= l && r <= R) return val[x];
        int mid = l + r >> 1;
        return max(query(x << 1, l, mid, L, R), query(x << 1 | 1, mid + 1, r, L, R));
    }
    void rmv(int x, int l, int r, int k) {
        if (l == r) return val[x] = {-inf, -1}, void();
        int mid = l + r >> 1;
        if (k <= mid) rmv(x << 1, l, mid, k);
        else rmv(x << 1 | 1, mid + 1, r, k);
        val[x] = max(val[x << 1], val[x << 1 | 1]);
    }
} t1, t2;
void rmain() {
    qcnt = 0;
    scanf("%d%d%d", &n, &S, &T);
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    for (int i = 1; i <= n; i++) a[i] = i + p[i];
    t1.build(1, 1, n, a);
    for (int i = 1; i <= n; i++) a[i] = p[i] - i;
    t2.build(1, 1, n, a);
    memset(dis, -1, sizeof dis);
    dis[S] = 0;
    que[qcnt = 1] = S;
    t1.rmv(1, 1, n, S);
    t2.rmv(1, 1, n, S);
    for (int i = 1; i <= qcnt; i++) {
        int u = que[i];
        while (1) {
            auto cur = t1.query(1, 1, n, u - p[u], u);
            if (cur.first >= u) {
                int v = cur.second;
                dis[v] = dis[u] + 1;
                t1.rmv(1, 1, n, v);
                t2.rmv(1, 1, n, v);
                que[++qcnt] = v;
            }
            else break;
        }
        while (1) {
            auto cur = t2.query(1, 1, n, u, u + p[u]);
            if (cur.first >= -u) {
                int v = cur.second;
                dis[v] = dis[u] + 1;
                t1.rmv(1, 1, n, v);
                t2.rmv(1, 1, n, v);
                que[++qcnt] = v;
            }
            else break;
        }
    }
    printf("%d\n", dis[T]);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}