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
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
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

struct atom { int l, r, lenl, lenr, flag; ll res; } p[N << 2];

atom merge(atom a, atom b) {
    atom ans;
    if (a.r > b.l) {
        ans.flag = 0;
        ans.l = a.l; ans.lenl = a.lenl;
        ans.r = b.r; ans.lenr = b.lenr;
        ans.res = a.res + b.res;
        return ans;
    }
    ans.flag = (a.flag & b.flag);
    ans.l = a.l; ans.r = b.r;
    ans.res = a.res + b.res + 1ll * a.lenr * b.lenl;
    if (a.flag) ans.lenl = a.lenl + b.lenl;
    else ans.lenl = a.lenl;
    if (b.flag) ans.lenr = b.lenr + a.lenr;
    else ans.lenr = b.lenr;
    return ans;
}

void update(int u) {
    p[u] = merge(p[u << 1], p[u << 1 | 1]);
}

void modify(int u, int l, int r, int x, int y) {
    if (l == r) {
        p[u].l = p[u].r = y;
        p[u].lenl = p[u].lenr = p[u].flag = p[u].res = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= x) modify(u << 1, l, mid, x, y);
    else modify(u << 1 | 1, mid + 1, r, x, y);
    update(u);
}

atom query(int u, int L, int R, int l, int r) {
    if (l <= L && R <= r) return p[u];
    int mid = (L + R) >> 1;
    if (mid >= l && mid + 1 <= r) return merge(query(u << 1, L, mid, l, r), query(u << 1 | 1, mid + 1, R, l, r));
    if (mid >= l) return query(u << 1, L, mid, l, r);
    return query(u << 1 | 1, mid + 1, R, l, r);
}

int a[N];
int n, q;

int main() {
    read(n); read(q);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        modify(1, 1, n, i, a[i]);
    }
    while (q--) {
        int opt, x, y;
        read(opt); read(x); read(y);
        if (opt == 1) modify(1, 1, n, x, y);
        else {
            atom ans = query(1, 1, n, x, y);
            print(ans.res, '\n');
        }
    }
    return 0;
}