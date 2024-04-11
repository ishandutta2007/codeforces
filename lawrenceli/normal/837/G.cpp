#include <bits/stdc++.h>

using namespace std;

#define PRINT_I64d true

typedef long long ll;

const int maxn = 1<<17;
const int mod = 1e9;

struct Func {
    int x1, x2, y1, a, b, y2;
};

//bit inside 2d seg tree
struct Tree {
    vector<int> v, bit2;
    vector<ll> bit1;
    ll sum;

    void upd1(int i, int va) {
        for (i++; i < bit1.size(); i += i & -i) bit1[i] += va;
    }

    void upd2(int i, int va) {
        for (i++; i < bit2.size(); i += i & -i) bit2[i] += va;
    }

    ll qry1(int i) {
        ll ret = 0;
        for (i++; i > 0; i -= i & -i) ret += bit1[i];
        return ret;
    }

    int qry2(int i) {
        int ret = 0;
        for (i++; i > 0; i -= i & -i) ret += bit2[i];
        return ret;
    }

    void init(int lt, int rt, Func * f) {
        v.resize(2 * (rt - lt));
        for (int i = 0; i < rt - lt; i++) {
            v[2 * i] = f[i + lt].x1;
            v[2 * i + 1] = f[i + lt].x2;
        }
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        bit1.resize(v.size() + 3, 0);
        bit2.resize(v.size() + 3, 0);

        sum = 0;
        for (int i = lt; i < rt; i++) {
            sum += f[i].y1;
            int p1 = lower_bound(v.begin(), v.end(), f[i].x1) - v.begin();
            upd1(p1 + 1, f[i].b - f[i].y1);
            upd2(p1 + 1, f[i].a);
            int p2 = lower_bound(v.begin(), v.end(), f[i].x2) - v.begin();
            upd1(p2 + 1, f[i].y2 - f[i].b);
            upd2(p2 + 1, -f[i].a);
        }
    }

    ll qry(int x) {
        int p = lower_bound(v.begin(), v.end(), x) - v.begin();
        return sum + qry1(p) + ll(qry2(p)) * x;
    }

};

//2d seg tree
struct Tree2 {
    Tree tree[2 * maxn];
    int n;

    void init(int cur, int lt, int rt, Func * f) {
        tree[cur].init(lt, rt, f);
        if (lt + 1 < rt) {
            int mid = (lt + rt) / 2;
            init(2 * cur, lt, mid, f);
            init(2 * cur + 1, mid, rt, f);
        }
    }

    ll qry(int cur, int lt, int rt, int ql, int qr, int x) {
        if (rt <= ql || lt >= qr) return 0;
        else if (lt >= ql && rt <= qr) return tree[cur].qry(x);
        else {
            int mid = (lt + rt) / 2;
            return qry(2 * cur, lt, mid, ql, qr, x) + qry(2 * cur + 1, mid, rt, ql, qr, x);
        }
    }

} tree;

int n, m;
Func f[maxn];

int main() {
    scanf("%d", &n);
    tree.n = n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d %d", &f[i].x1, &f[i].x2, &f[i].y1, &f[i].a, &f[i].b, &f[i].y2);
    }

    tree.init(1, 0, n, f);

    scanf("%d", &m);
    int last = 0;
    for (int i = 0; i < m; i++) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        l--;
        x = (x + last) % mod;
        ll ans = tree.qry(1, 0, n, l, r, x);
        if (PRINT_I64d) printf("%I64d\n", ans);
        else printf("%lld\n", ans);
        last = ans % mod;
    }
}