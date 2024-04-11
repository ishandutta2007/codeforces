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

const int N = 1e5 + 5;

struct info {
    ll maxn, minn, sum;
    info (ll a = 0, ll b = 0, ll c = 0) : maxn(a), minn(b), sum(c) {}
};

info merge(info a, info b) {
    info ans;
    ans.sum = a.sum + b.sum;
    ans.maxn = max(a.maxn, a.sum + b.maxn);
    ans.minn = min(a.minn, a.sum + b.minn);
    return ans;
}

info p[N << 2];
int a[N], b[N];
int n, q;

void build(int u, int l, int r) {
    if (l == r) {
        p[u].maxn = p[u].minn = p[u].sum = b[l] - a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    p[u] = merge(p[u << 1], p[u << 1 | 1]);
}

info query(int u, int L, int R, int l, int r) {
    if (l <= L && R <= r) return p[u];
    int mid = (L + R) >> 1;
    if (mid >= l && mid + 1 <= r) return merge(query(u << 1, L, mid, l, r), query(u << 1 | 1, mid + 1, R, l, r));
    if (mid >= l) return query(u << 1, L, mid, l, r);
    return query(u << 1 | 1, mid + 1, R, l, r);
}

int main() {
    read(n); read(q);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) read(b[i]);
    build(1, 1, n);
    while (q--) {
        int l, r;
        read(l); read(r);
        info ans = query(1, 1, n, l, r);
        if (ans.minn < 0 || ans.sum != 0) {
            print(-1, '\n');
            continue;
        }
        print(ans.maxn, '\n');
    }
    return 0;
}