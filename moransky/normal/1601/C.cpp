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

const int N = 1e6 + 5;

int n, m, a[N], b[N];

PII e[N];
int c[N];

LL ans;

void inline add(int x, int k) {
    for (; x <= n; x += x & -x) c[x] += k;
}

int inline ask(int x) {
    int res = 0;
    for (; x; x -= x & -x) res += c[x];
    return res;
}

#define ls (p << 1)
#define rs (p << 1 | 1)

int dat[N << 2], tag[N << 2];

void inline pushup(int p) {
    dat[p] = min(dat[ls], dat[rs]);
}

void inline Add(int p, int k) {
    dat[p] += k, tag[p] += k;
}

void inline pushdown(int p) {
    if (tag[p]) {
        Add(ls, tag[p]), Add(rs, tag[p]);
        tag[p] = 0;
    }
}


void change(int p, int l, int r, int x, int y, int k) {
    if(x <= l && r <= y) {
        Add(p, k);
        return ;
    }
    int mid = (l + r) >> 1;
    pushdown(p);
    if(x <= mid) change(p << 1, l, mid, x, y, k);
    if(mid + 1 <= y) change(p << 1 | 1, mid + 1, r, x, y, k);
    pushup(p);
}

int query(int p, int l, int r, int x, int y) {
    if(x <= l && r <= y) return dat[p];
    int mid = (l + r) >> 1, s = 0;
    pushdown(p);
    if(x <= mid) chkMin(s, query(p << 1, l, mid, x, y));
    if(mid + 1 <= y) chkMin(s, query(p << 1 | 1, mid + 1, r, x, y));
    return s;
}
 
int main() {
    int T; read(T);
    while (T--) {
        ans = 0;
        read(n), read(m);
        for (int i = 1; i <= n; i++) read(a[i]), e[i] = mp(a[i], i);
        for (int i = 1; i <= m; i++) read(b[i]);
        sort(b + 1, b + 1 + m);
        sort(e + 1, e + 1 + n);
        for (int i = 1; i <= n; i++) {
            ans += i - 1 - ask(e[i].se);
            add(e[i].se, 1);
        }
        for (int i = 1; i <= n; i++) change(1, 0, n, i, n, 1);
        for (int i = 1, j = 1; i <= m; i++) {
            int q = i;
            while (q < m && b[q + 1] == b[i]) q++;
            while (j <= n && e[j].fi <= b[i]) {
                change(1, 0, n, e[j].se, n, -1);
                change(1, 0, n, 0, e[j].se - 1, 1);
                j++;
            }
            int p = j - 1;
            while (p && e[p].fi == b[i]) p--;
            for (int k = j - 1; k > p; k--) {
                change(1, 0, n, 0, e[k].se - 1, -1);
            }
            ans += dat[1] * (q - i + 1ll);
            for (int k = j - 1; k > p; k--) {
                change(1, 0, n, 0, e[k].se - 1, 1);
            }
            i = q;
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= 4 * n; i++) dat[i] = tag[i] = 0; 
        for (int i = 1; i <= n; i++) c[i] = 0;
    }
    return 0;
}