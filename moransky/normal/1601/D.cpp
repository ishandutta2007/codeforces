// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 5e5 + 5;

int m, n, d, gx, f[N], ans, pr[N];

struct E{
    int s, a, id;
    bool operator < (const E &b) const {
        if (a != b.a) return a < b.a;
        return s < b.s;
    }
} e[N];
 

#define ls (p << 1)
#define rs (p << 1 | 1)

vector<int> t[N << 2];

void build(int p, int l, int r) {
    if (l > r) return ;
    for (int i = l; i <= r; i++)
        t[p].pb(e[i].s);
    sort(t[p].begin(), t[p].end());
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
}

int query(int p, int l, int r, int x, int y, int k) {
    if (x > y) return 0;
    if (x <= l && r <= y) {
        if (t[p].back() < k) return 0;
        else return t[p].size() - (lower_bound(t[p].begin(), t[p].end(), k) - t[p].begin());
    }
    int mid = (l + r) >> 1, s = 0;
    if (x <= mid) s += query(p << 1, l, mid, x, y, k);
    if (mid + 1 <= y) s += query(p << 1 | 1, mid + 1, r, x, y, k);
    return s;
}

int main() {
    read(m), read(d);
    while (m--) {
        int s, a; read(s), read(a);
        if (s < d) continue;
        if (a > d) {
            e[++n] = (E) { s, a };
        } else if (s >= d) gx++;
    }
    sort(e + 1, e + 1 + n);
    for (int i = 1; i <= n; i++) e[i].id = i;
    e[0].a = d;
    build(1, 1, n);
    for (int i = 1, k = 1; i <= n; i++) {
        int l = 0, r = i - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (e[mid].a <= e[i].s) l = mid;
            else r = mid - 1;
        }
        int p = r;
        f[i] = pr[p] + query(1, 1, n, p + 1, i - 1, e[i].a) + 1;
        chkMax(ans, f[i]);
        pr[i] = max(pr[i - 1], f[i]);
    }
    printf("%d\n", ans + gx);
    return 0;
}