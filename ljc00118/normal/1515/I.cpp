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
const ll INF = 4e18;

ll ta[N]; int tw[N], tv[N];
ll a[N]; int w[N], v[N], id[N], pre[N];
int n, q;

struct seg_t {
    struct node_t {
        int l, r;
        ll sumv, sumw, minv, minval;
    } p[N << 2];

    int liml, limr;

    void update(int u) {
        p[u].sumv = p[u << 1].sumv + p[u << 1 | 1].sumv;
        p[u].sumw = p[u << 1].sumw + p[u << 1 | 1].sumw;
        p[u].minv = min(p[u << 1].minv, p[u << 1 | 1].minv);
        p[u].minval = min(p[u << 1].minval, p[u << 1].sumv + p[u << 1 | 1].minval);
    }

    void gen_node(int u, int l) {
        if (v[l] > limr) {
            p[u].sumv = p[u].sumw = 0;
            p[u].minval = p[u].minv = INF;
        } else if (v[l] >= liml) {
            p[u].sumv = p[u].sumw = 0;
            if (a[l]) p[u].minval = p[u].minv = v[l];
            else p[u].minval = p[u].minv = INF;
        } else {
            p[u].sumv = 1ll * v[l] * a[l];
            p[u].sumw = 1ll * w[l] * a[l];
            p[u].minval = p[u].minv = INF;
        }
    }

    void build(int u, int l, int r) {
        p[u].l = l; p[u].r = r;
        if (l == r) {
            gen_node(u, l);
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        update(u);
    }

    void modify(int u, int x) {
        if (p[u].l == p[u].r) {
            gen_node(u, x);
            return;
        }
        int mid = (p[u].l + p[u].r) >> 1;
        if (mid >= x) modify(u << 1, x);
        else modify(u << 1 | 1, x);
        update(u);
    }

    ll lasc;
    int getpos(int u, int l, int r) {
        // fprintf(stderr, "u = %d, l = %d, r = %d\n", u, l, r);
        if (l <= p[u].l && p[u].r <= r) {
            if (p[u].minval == INF || p[u].minval > lasc) {
                lasc -= p[u].sumv;
                return -1;
            }
            if (p[u].l == p[u].r) return p[u].l;
            int ans = getpos(u << 1, l, r);
            if (ans != -1) return ans;
            return getpos(u << 1 | 1, l, r);
        }
        int mid = (p[u].l + p[u].r) >> 1;
        if (mid >= l) {
            int ans = getpos(u << 1, l, r);
            if (ans != -1) return ans;
        }
        return getpos(u << 1 | 1, l, r);
    }

    ll ansv, answ;
    void query(int u, int l, int r) {
        if (l <= p[u].l && p[u].r <= r) {
            ansv += p[u].sumv;
            answ += p[u].sumw;
            return;
        }
        int mid = (p[u].l + p[u].r) >> 1;
        if (mid >= l) query(u << 1, l, r);
        if (mid + 1 <= r) query(u << 1 | 1, l, r);
    }

    void query(int l, int r) {
        ansv = answ = 0;
        if (l <= r) query(1, l, r);
    }

    int binary_search(int u, int l, int r) {
        if (l <= p[u].l && p[u].r <= r) {
            if (lasc >= p[u].sumv) {
                lasc -= p[u].sumv;
                ansv += p[u].sumv;
                answ += p[u].sumw;
                return -1;
            }
            if (p[u].l == p[u].r) return p[u].l;
            int ans = binary_search(u << 1, l, r);
            if (ans != -1) return ans;
            return binary_search(u << 1 | 1, l, r);
        }
        int mid = (p[u].l + p[u].r) >> 1;
        if (mid >= l) {
            int ans = binary_search(u << 1, l, r);
            if (ans != -1) return ans;
        }
        return binary_search(u << 1 | 1, l, r);
    }
} tr[18];

bool cmp(int i, int j) {
    if (w[i] != w[j]) return w[i] > w[j];
    return v[i] < v[j];
}

int main() {
    for (int i = 0; i <= 17; i++) tr[i].liml = (1 << i), tr[i].limr = (1 << (i + 1)) - 1;
    read(n); read(q);
    for (int i = 1; i <= n; i++) read(a[i]), read(v[i]), read(w[i]), id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    for (int i = 1; i <= n; i++) ta[i] = a[id[i]], tw[i] = w[id[i]], tv[i] = v[id[i]], pre[id[i]] = i;
    for (int i = 1; i <= n; i++) a[i] = ta[i], w[i] = tw[i], v[i] = tv[i]; //, fprintf(stderr, "%d : a = %lld, w = %d, v = %d\n", i, a[i], w[i], v[i]);
    for (int i = 0; i <= 17; i++) tr[i].build(1, 1, n);
    while (q--) {
        int opt; read(opt);
        if (opt == 1 || opt == 2) {
            int pos, x;
            read(x); read(pos); pos = pre[pos];
            if (opt == 1) a[pos] += x;
            else a[pos] -= x;
            for (int i = 0; i <= 17; i++) tr[i].modify(1, pos);
        }
        if (opt == 3) {
            ll c, ans = 0; read(c);
            int pos = 1;
            for (int i = 17; i >= 0; i--) {
                if (pos == n + 1) break;
                if (c < (1 << i)) continue;
                tr[i].lasc = c;
                int new_pos = tr[i].getpos(1, pos, n);
                // fprintf(stderr, "i = %d, pos = %d, new_pos = %d\n", i, pos, new_pos);
                if (new_pos != -1) {
                    tr[i].query(pos, new_pos - 1);
                    c -= tr[i].ansv; ans += tr[i].answ;
                    c -= v[new_pos]; ans += w[new_pos];
                    pos = new_pos + 1;
                    continue;
                }
                tr[i].lasc = c - (1 << i) + 1;
                new_pos = tr[i].binary_search(1, pos, n);
                if (new_pos == -1) {
                    tr[i].query(pos, n);
                    ans += tr[i].answ;
                    break;
                }
                tr[i].query(pos, new_pos - 1);
                c -= tr[i].ansv; ans += tr[i].answ;
                // fprintf(stderr, "i = %d, c = %lld, ans = %lld\n", i, c, ans);
                // fprintf(stderr, "new_pos = %d\n", new_pos);
                ll cnt = min(a[new_pos], c / v[new_pos]);
                c -= cnt * v[new_pos]; ans += cnt * w[new_pos];
                pos = new_pos + 1;
            }
            print(ans, '\n');
        }
    }
    return 0;
}