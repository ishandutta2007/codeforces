#include <bits/stdc++.h>
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 105, md = 998244353;

struct ele {
    ll l, r;
    ele (ll a = 0, ll b = 0) : l(a), r(b) {}
    bool operator < (const ele A) const { return l < A.l; }
} aa[N], bb[N], a[N], b[N], ans[N * N * 65 * 8], tmp1[65], tmp2[65], tmp3[65], tmp4[65];

int nn, mm, n, m, len, len1, len2, len3, len4, sum;

inline ll lowbit(ll x) { return x & -x; }

void split(ele a, ele *t1, ele *t2, int &l1, int &l2) {
    l1 = l2 = 0;
    while(a.l <= a.r) {
        if(a.l + lowbit(a.l) - 1 <= a.r) {
            t1[++l1] = ele(a.l, a.l + lowbit(a.l) - 1);
            a.l += lowbit(a.l);
        } else {
            break;
        }
    }
    // while(a.l <= a.r) {
    //     t2[++l2] = ele(a.r - lowbit(a.r) + 1, a.r);
    //     a.r -= lowbit(a.r);
    // }
    for(register ll l = 1ll << 59; a.l <= a.r; l >>= 1) {
        if(a.l + l - 1 <= a.r) {
            t2[++l2] = ele(a.l, a.l + l - 1);
            a.l += l;
        }
    }
    reverse(t2 + 1, t2 + l2 + 1);
}

void getans(ele *t1, ele *t2, int l1, int l2) {
    int now = 1;
    for(register int i = 1; i <= l1; i++) {
        ll Len = t1[i].r - t1[i].l + 1;
        while(now <= l2 && Len > t2[now].r - t2[now].l + 1) ++now;
        if(now <= l2 && Len == t2[now].r - t2[now].l + 1) ans[++len] = ele((t1[i].l ^ t2[now].l) & ((1ll << 60) - Len), ((t1[i].l ^ t2[now].l) & ((1ll << 60) - Len)) + Len - 1);
        if(now > 1) ans[++len] = ele((t1[i].l ^ t2[now - 1].l) & ((1ll << 60) - Len), ((t1[i].l ^ t2[now - 1].l) & ((1ll << 60) - Len)) + Len - 1);
    }
}

void solve(ele a, ele b) {
    split(a, tmp1, tmp2, len1, len2);
    split(b, tmp3, tmp4, len3, len4);
    getans(tmp1, tmp3, len1, len3);
    getans(tmp1, tmp4, len1, len4);
    getans(tmp2, tmp3, len2, len3);
    getans(tmp2, tmp4, len2, len4);
    getans(tmp3, tmp1, len3, len1);
    getans(tmp4, tmp1, len4, len1);
    getans(tmp3, tmp2, len3, len2);
    getans(tmp4, tmp2, len4, len2);
}

inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if(x < 0) x += md;
    return x;
}

inline int s(int x) {
    return 1ll * x * (x + 1) / 2 % md;
}

inline int s(ll l, ll r) {
    return sub(s(r % md), s((l - 1) % md));
}

int main() {
    // freopen("input.txt", "r", stdin);
    read(nn);
    for(register int i = 1; i <= nn; i++) read(aa[i].l), read(aa[i].r);
    read(mm);
    for(register int i = 1; i <= mm; i++) read(bb[i].l), read(bb[i].r);
    sort(aa + 1, aa + nn + 1); sort(bb + 1, bb + mm + 1);
    a[n = 1] = aa[1];
    for(register int i = 2; i <= nn; i++) {
        if(aa[i].l <= a[n].r + 1) {
            a[n].r = max(a[n].r, aa[i].r);
        } else {
            a[++n] = aa[i];
        }
    }
    b[m = 1] = bb[1];
    for(register int i = 2; i <= mm; i++) {
        if(bb[i].l <= b[m].r + 1) {
            b[m].r = max(b[m].r, bb[i].r);
        } else {
            b[++m] = bb[i];
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= m; j++) {
            solve(a[i], b[j]);
        }
    }
    sort(ans + 1, ans + len + 1);
    ll l = ans[1].l, r = ans[1].r;
    for(register int i = 2; i <= len; i++) {
        if(ans[i].l <= r + 1) {
            r = max(r, ans[i].r);
        } else {
            sum = add(sum, s(l, r));
            // fprintf(stderr, "l = %I64d, r = %I64d\n", l, r);
            l = ans[i].l; r = ans[i].r;
        }
    }
    sum = add(sum, s(l, r));
    // fprintf(stderr, "l = %I64d, r = %I64d\n", l, r);
    print(sum, '\n');
    return 0;
}