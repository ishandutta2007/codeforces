#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;
int const F = 10005;

vec< pii > a[F];

pii get(int f, int lx, int rx) {
    if(a[f].empty()) return make_pair(-1, -1);
    int l, r;
    {
        int bl, br, bm;
        bl = 0;
        br = (int)a[f].size() - 1;
        while(br - bl > 1) {
            bm = (bl + br) / 2;
            if(a[f][bm].first >= lx) br = bm;
            else bl = bm + 1;
        }
        if(bl < br && a[f][bl].first >= lx) l = bl;
        else if(a[f][br].first >= lx) l = br;
        else return make_pair(-1, -1);
    }
    {
        int bl, br, bm;
        bl = 0;
        br = (int)a[f].size() - 1;
        while(br - bl > 1) {
            bm = (bl + br) / 2;
            if(a[f][bm].first <= rx) bl = bm;
            else br = bm - 1;
        }
        if(bl < br && a[f][br].first <= rx) r = br;
        else if(a[f][bl].first <= rx) r = bl;
        else return make_pair(-1, -1);
    }
    if(l > r) return make_pair(-1, -1);
    else return make_pair(l, r);
}

vec< vec< int > > tree[F];

void up(int f, int v) {
    auto & l = tree[f][v * 2 + 1];
    auto & r = tree[f][v * 2 + 2];
    int ls = (int)l.size();
    int rs = (int)r.size();
    int i = 0, j = 0;
    tree[f][v].reserve(ls + rs);
    while(i < ls && j < rs) {
        if(l[i] < r[j]) {
            tree[f][v].push_back(l[i++]);
        }else {
            tree[f][v].push_back(r[j++]);
        }
    }
    while(i < ls) tree[f][v].push_back(l[i++]);
    while(j < rs) tree[f][v].push_back(r[j++]);
}

inline int bp(int f, int v, int x) {
    return tree[f][v].end() - lower_bound(ALL(tree[f][v]), x);
}

void build(int f, int v, int tl, int tr) {
    if(tl == tr) {
        tree[f][v] = { a[f][tl].second };
    }else {
        int tm = (tl + tr) / 2;
        build(f, v * 2 + 1, tl, tm);
        build(f, v * 2 + 2, tm + 1, tr);
        up(f, v);
    }
}

int get(int f, int v, int tl, int tr, int l, int r, int x) {
    if(l <= tl && tr <= r) {
        return bp(f, v, x);
    }else {
        int res = 0, tm = (tl + tr) / 2;
        if(l <= tm) res += get(f, v * 2 + 1, tl, tm, l, r, x);
        if(r > tm) res += get(f, v * 2 + 2, tm + 1, tr, l, r, x);
        return res;
    }
}

int main() {

    int n, k;

    scanf("%d %d", &n, &k);

    vec< pair< int, pii > > arr(n);

    for(int xx, rr, ff, i = 0;i < n;i++) {
        scanf("%d %d %d", &xx, &rr, &ff);
        a[ff].push_back( { xx, xx + rr } );
        arr[i] = { xx, { rr, ff } };
    }

    for(int f = 0;f < F;f++) {
        if(a[f].empty()) continue;
        sort(ALL(a[f]));
        tree[f].resize( (int)a[f].size() * 4 );
        build(f, 0, 0, (int)a[f].size() - 1);
    }

    ll res = 0;

    for(int xx, rr, ff, i = 0;i < n;i++) {
        xx = arr[i].first;
        rr = arr[i].second.first;
        ff = arr[i].second.second;
        int fl = max(0, ff - k);
        int fr = min(F - 1, ff + k);
        for(int ql, qr, f2 = fl;f2 <= fr;f2++) {
            if(a[f2].empty()) continue;
            tie(ql, qr) = get(f2, xx - rr, xx - 1);
            if(ql == -1) continue;
            res += get(f2, 0, 0, (int)a[f2].size() - 1, ql, qr, xx);
        }
    }

    cout << res << "\n";

    return 0;
}