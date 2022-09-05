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

const int N = 2e5 + 5;

struct atom {
    int cnt; ll sum, tmp;
    atom (int a = 0, ll b = 0, ll c = 0) : cnt(a), sum(b), tmp(c) {}
};

atom merge(atom a, atom b) {
    return atom(a.cnt + b.cnt, a.sum + b.sum + a.tmp * b.cnt, a.tmp + b.tmp);
}

struct node_t { int l, r, siz; ll sum; atom ss; } p[N << 3];

ll a[N], b[N * 2], c[N];
int opt[N], cnt[N * 2];
int n, q, len, all;
ll allsum;

void update(int u) {
    p[u].siz = p[u << 1].siz + p[u << 1 | 1].siz;
    p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if (l == r) {
        p[u].siz = cnt[l];
        p[u].sum = cnt[l] * b[l];
        p[u].ss = atom(p[u].siz, p[u].sum, p[u].sum);
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u); p[u].ss = merge(p[u << 1].ss, p[u << 1 | 1].ss);
}

void modify(int u, int x, int y) {
    p[u].siz += y;
    p[u].sum += b[x] * y;
    if (p[u].l == p[u].r) {
        p[u].ss = atom(p[u].siz, p[u].sum, p[u].sum);
        return;
    }
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= x) modify(u << 1, x, y);
    else modify(u << 1 | 1, x, y);
    p[u].ss = merge(p[u << 1].ss, p[u << 1 | 1].ss);
}

ll sumk(int u, int k) {
    if (p[u].l == p[u].r) return b[p[u].l] * k;
    if (p[u << 1].siz < k) return p[u << 1].sum + sumk(u << 1 | 1, k - p[u << 1].siz);
    return sumk(u << 1, k);
}

int posk(int u, int k) {
    if (p[u].l == p[u].r) return p[u].l;
    if (p[u << 1].siz < k) return posk(u << 1 | 1, k - p[u << 1].siz);
    return posk(u << 1, k);
}

atom query(int u, int l, int r) {
    if (l <= p[u].l && p[u].r <= r) return p[u].ss;
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= l && mid + 1 <= r) return merge(query(u << 1, l, r), query(u << 1 | 1, l, r));
    if (mid >= l) return query(u << 1, l, r);
    return query(u << 1 | 1, l, r);
}

ll prek(int k) { return sumk(1, k); }
ll sufk(int k) { return allsum - sumk(1, all - k); }

int main() {
    read(n); read(q);
    for (int i = 1; i <= n; i++) read(a[i]), b[i] = a[i], allsum += a[i];
    len = all = n;
    for (int i = 1; i <= q; i++) {
        read(opt[i]); read(c[i]);
        b[++len] = c[i];
    }
    sort(b + 1, b + len + 1); len = unique(b + 1, b + len + 1) - b - 1;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b, ++cnt[a[i]];
    for (int i = 1; i <= q; i++) c[i] = lower_bound(b + 1, b + len + 1, c[i]) - b;
    build(1, 1, len);
    for (int i = 0; i <= q; i++) {
        if (i) {
            if (opt[i] == 1) {
                modify(1, c[i], 1);
                ++all; allsum += b[c[i]];
            } else {
                modify(1, c[i], -1);
                --all; allsum -= b[c[i]];
            }
        }
        if (all == 0) {
            print(0, '\n');
            continue;
        }
        ll ans = 0;
        {
            int l = 1, r = (all + 1) / 2, res = 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (prek(mid) > sufk(mid - 1) - 1) res = mid, l = mid + 1;
                else r = mid - 1;
            }
            // 1 ~ res - 1
            if (res > 1) {
                int pos = posk(1, res - 1);
                ans -= query(1, 1, pos).sum;
                pos = posk(1, all - (res - 1) + 1);
                ans += (sufk(res - 1) * res - query(1, pos, len).sum);
            }
            // res ~ (all + 1) / 2
            {
                ll _l = prek(res), _r = sufk((all + 1) / 2);
                ans += _r - _l;
            }
            l = (all + 1) / 2 + 1; r = all; res = r;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (prek(mid) > sufk(mid - 1) - 1) res = mid, r = mid - 1;
                else l = mid + 1;
            }
            // res ~ all
            {
                int pos = posk(1, res);
                ans -= (query(1, pos, len).sum + prek(res - 1) * (all - res + 1));
                pos = posk(1, all - res + 1);
                ans += (prek(all - res + 1) * (all - res + 2) - query(1, 1, pos).sum + sufk(res - 1) * (all - res + 1));
            }
            // (all + 1) / 2 + 1 ~ res - 1
            if ((all + 1) / 2 + 1 <= res - 1) {
                ll _l = prek((all + 1) / 2 + 1), _r = sufk(res - 1);
                ans += _r - _l;
            }
            if (all != 1) {
                int _ = (all + 1) / 2;
                ll t1 = prek(_ + 1), t2 = sufk(_);
                if (t1 <= t2 - 1) ans -= t2 - t1;
            }
        }
        print(ans, '\n');
    }
    return 0;
}