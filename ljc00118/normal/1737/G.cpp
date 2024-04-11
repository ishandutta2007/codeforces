#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

mt19937 rng(0);

int lc[N], rc[N], siz[N], key[N], val[N], sum[N];

void update(int u) {
    siz[u] = siz[lc[u]] + siz[rc[u]] + 1;
    sum[u] = sum[lc[u]] + sum[rc[u]] + val[u];
}

inline void newNode(int i, int x) {
    key[i] = rng();
    val[i] = sum[i] = x;
    siz[i] = 1;
}

// <= k
void split(int u, int k, int &l, int &r) {
    if (!u) { l = r = 0; return; }
    if (siz[lc[u]] >= k) {
        r = u;
        split(lc[u], k, l, lc[r]);
        update(u);
    } else {
        l = u;
        split(rc[u], k - siz[lc[u]] - 1, rc[l], r);
        update(u);
    }
}

int merge(int u, int v) {
    if (!u || !v) return u | v;
    if (key[u] < key[v]) {
        rc[u] = merge(rc[u], v);
        update(u);
        return u;
    } else {
        lc[v] = merge(u, lc[v]);
        update(v);
        return v;
    }
}

void modify(int u, int x) {
    if (!lc[u]) {
        val[u] = x;
        update(u);
        return;
    }
    modify(lc[u], x);
    update(u);
}

int find(int u, ll x) {
    if (lc[u] && sum[lc[u]] >= x) return find(lc[u], x);
    if (sum[lc[u]] + val[u] >= x) return siz[lc[u]] + 1;
    return siz[lc[u]] + 1 + find(rc[u], x - sum[lc[u]] - val[u]);
}

int find2(int u) {
    if (!lc[u]) return val[u];
    return find2(lc[u]);
}

struct atom {
    int t, k, id;
    bool operator < (const atom A) const { return t < A.t; }
} qq[N];

int a[N], b[N], t1[N], t2[N], l1, l2;
ll ans[N];
char c[N];
int n, m, d, q, rt, rt2;

int main() {
    read(n); read(d); read(q);
    for (int i = 1; i <= n; i++) read(a[i]);
    scanf("%s", c + 1);
    for (int i = 1; i <= n; i++) b[i] = c[i] - '0';
    for (int i = 1, sum = 0; i <= n; i++) {
        if (b[i] == 1) {
            t1[++l1] = a[i] - sum;
        } else {
            t2[++l2] = a[i]; ++sum;
        }
    }
    n = l1; m = l2;
    for (int i = 1; i <= n; i++) a[i] = t1[i];
    for (int i = 1; i <= m; i++) b[i] = t2[i];
    for (int i = 1; i <= q; i++) {
        read(qq[i].t); read(qq[i].k);
        qq[i].id = i;
    }
    sort(qq + 1, qq + q + 1);
    newNode(1, 0); rt = 1;
    int pos = 2;
    while (pos <= n && a[pos] - a[1] - pos + 1 < d) {
        newNode(pos, a[pos] - a[pos - 1]);
        rt = merge(rt, pos); ++pos;
    }
    int tmp = pos;
    while (pos <= n) {
        newNode(pos, a[pos] - a[pos - 1]);
        rt2 = merge(rt2, pos); ++pos;
    }
    ll fir = a[1];
    int nowt = 0, nowq = 1;
    while (nowq <= q) {
        int nxt = qq[nowq].t;
        if (tmp <= n) {
            int las = fir + sum[rt], step = d + tmp - 2, len = a[tmp] - las;
            int round = (len - 1) / step, nfir = fir + step * round;
            // nfir + sum[i] + step >= a[tmp]
            // sum[i] >= a[tmp] - nfir - step
            int k = find(rt, a[tmp] - nfir - step);
            nxt = min(nxt, nowt + round * (tmp - 1) + k - 1);
        }
        int round = (nxt - nowt) / (tmp - 1);
        nowt += round * (tmp - 1);
        fir += 1ll * round * (d + tmp - 2);
        int k = nxt - nowt;
        if (k) {
            ll las = fir + sum[rt];
            int l, r;
            split(rt, k, l, r);
            ll nfir = fir + sum[l] + find2(r);
            int nval = fir + d + tmp - 2 - las;
            modify(l, nval); modify(r, 0);
            rt = merge(r, l);
            fir = nfir;
        }
        while (tmp <= n && fir + d + tmp - 2 >= a[tmp]) {
            ll las = fir + sum[rt];
            int rub;
            split(rt2, 1, rub, rt2);
            newNode(tmp, a[tmp] - las);
            rt = merge(rt, tmp);
            ++tmp;
        }
        if (tmp <= n) {
            ll las = fir + sum[rt];
            modify(rt2, a[tmp] - las);
            rt = merge(rt, rt2);
        }
        nowt = nxt;
        auto calc = [&](ll x) {
            int ret = upper_bound(b + 1, b + m + 1, x) - b - 1;
            if (x - ret - fir >= sum[rt]) ret += siz[rt];
            else ret += find(rt, x - ret - fir + 1) - 1;
            return ret;
        };
        while (nowq <= q && qq[nowq].t == nowt) {
            ll l = 1, r = 1e18 + 1e10, ret = r;
            while (l <= r) {
                ll mid = (l + r) >> 1;
                if (calc(mid) >= qq[nowq].k) ret = mid, r = mid - 1;
                else l = mid + 1;
            }
            ans[qq[nowq].id] = ret; ++nowq;
        }
        split(rt, tmp - 1, rt, rt2);
    }
    for (int i = 1; i <= q; i++) print(ans[i], '\n');
    return 0;
}