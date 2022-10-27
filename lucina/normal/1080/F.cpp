#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
const int pool = 400001 * 18;
struct segment {
    int l, r, p;
 
    inline bool operator <(const segment& other) const {
        return r < other.r;
    }
}in[nax];
int lc[pool];
int rc[pool];
int sg[pool];
int root[nax];
int cnt;
int n, m, k;
/// I hate persistent ds~~
 
void update (int &v, int x, int y, int pos, int val) {
    ++ cnt;
    sg[cnt] = sg[v];
    lc[cnt] = lc[v];
    rc[cnt] = rc[v];
    v = cnt;
    if (x == y) {
        sg[v] = max(sg[v], val);
    } else {
        int mid = x + y >> 1;
        if (pos <= mid) update(lc[v], x, mid, pos, val);
        else update(rc[v], mid + 1, y, pos, val);
        sg[v] = min(sg[lc[v]], sg[rc[v]]);
    }
}
 
int query (int v, int x, int y, int l, int r) {
 
    if (l == x && r == y) {
        return sg[v];
    } else {
        int mid = x + y >> 1;
        if (l > mid) return query(rc[v], mid + 1, y, l, r);
        else if (r <= mid) return query(lc[v], x, mid, l, r);
        else return min(query(lc[v], x, mid, l, mid), query(rc[v], mid + 1, y, mid + 1, r));
    }
}
 
void build (int &v, int l, int r) {
    ++ cnt;
    sg[cnt] = sg[v];
    lc[cnt] = lc[v];
    rc[cnt] = rc[v];
    v = cnt;
    if (l != r) {
        int mid = l + r >> 1;
        build(lc[v], l, mid);
        build(rc[v], mid + 1, r);
    }
}
 
int main () {
    
    scanf("%d%d%d", &n, &m, &k);
 
    for (int i = 1 ; i <= k ; ++ i)
        scanf("%d%d%d", &in[i].l, &in[i].r, &in[i].p);
 
    sort(in + 1, in + 1 + k);
 
    for (int i = 1 ; i <= k ; ++ i) {
        root[i] = root[i - 1];
        update(root[i], 1, n, in[i].p, in[i].l);
    }
 
    for (int i = 1 ; i <= m ; ++ i) {
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        segment v = segment{0, y, 0};
        int pos = upper_bound(in + 1, in + 1 + k, v) - in - 1;
 
        int f = query(root[pos], 1, n, a, b);
 
        puts(f >= x ? "yes" : "no");
        fflush(stdout);
    }
}