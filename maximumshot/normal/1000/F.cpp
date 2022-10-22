#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 5e5 + 5;

int n, q;
int a[N];
int last[N];
int prv[N];
int nxt[N];
int res[N];
vec< pii > pts[N];
vec< pii > op[N], cl[N];
int tree[4 * N];

void add(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        tree[v] = max(tree[v], l);
    }else {
        int tm = (tl + tr) >> 1;
        if(l <= tm) add(v << 1, tl, tm, l, r);
        if(r > tm) add(v << 1 | 1, tm + 1, tr, l, r);
    }
}

int get(int v, int tl, int tr, int pos) {
    if(tl == tr) return tree[v];
    int tm = (tl + tr) >> 1;
    int tres = tree[v];
    int tmp = pos <= tm ? get(v << 1, tl, tm, pos) : get(v << 1 | 1, tm + 1, tr, pos);
    tres = max(tres, tmp);
    return tres;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 1;i <= n;i++) {
        prv[i] = last[a[i]];
        last[a[i]] = i;
    }

    fill(last, last + N, n + 1);

    for(int i = n;i >= 1;i--) {
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }

    scanf("%d", &q);

    for(int iter = 1;iter <= q;iter++) {
        int l, r;
        scanf("%d %d", &l, &r);
        pts[l].push_back({r, iter});
    }

    for(int i = 1;i <= n;i++) {
        int lx, ly, rx, ry;
        lx = prv[i] + 1;
        rx = i;
        ly = i;
        ry = nxt[i] - 1;
        op[lx].push_back({ly, ry});
        cl[rx].push_back({ly, ry});
    }

    for(int x = 1;x <= n;x++) {
//        cout << "# " << x << "\n";
        for(pii seg : op[x]) {
            int l, r;
            tie(l, r) = seg;
//            cout << "open " << l << " .. " << r << "\n";
            add(1, 1, n, l, r);
        }
        for(pii query : pts[x]) {
            int y, id;
            tie(y, id) = query;
//            cout << "ask " << y << ", id = " << id << "\n";
            res[id] = get(1, 1, n, y);
            if(res[id] < x) res[id] = 0;
            else res[id] = a[res[id]];
        }
        for(pii seg : cl[x]) {
            int l, r;
            tie(l, r) = seg;
//            cout << "close " << l << " .. " << r << "\n";
            add(1, 1, n, l, r);
        }
    }

    for(int iter = 1;iter <= q;iter++) {
        printf("%d\n", res[iter]);
    }

    return 0;
}