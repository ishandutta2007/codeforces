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

const int md = 998244353;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 2e5 + 5;

int ls[N], rs[N], key[N], siz[N]; ll val[N];
int root, tot;

void update(int u) { siz[u] = siz[ls[u]] + siz[rs[u]] + 1; }

inline int newNode(ll x) {
    ++tot; siz[tot] = 1; val[tot] = x; key[tot] = rand(); ls[tot] = rs[tot] = 0;
    return tot;
}

void split(int u, ll x, int &l, int &r) {
    if (!u) { l = r = 0; return; }
    if (val[u] >= x) {
        r = u; split(ls[u], x, l, ls[r]); update(u);
    } else {
        l = u; split(rs[u], x, rs[l], r); update(u);
    }
}

int merge(int l, int r) {
    if (!l || !r) return l ^ r;
    if (key[l] <= key[r]) {
        rs[l] = merge(rs[l], r); update(l); return l;
    } else {
        ls[r] = merge(l, ls[r]); update(r); return r;
    }
}

void insert(ll x) {
    int l, r; split(root, x, l, r);
    root = merge(merge(l, newNode(x)), r);
}

int find(int u, ll x) {
    if (!u) return 0;
    if (val[u] < x) return find(rs[u], x) + siz[ls[u]] + 1;
    return find(ls[u], x);
}

ll s[N];
int a[N], opt[N];
int T, n;

ll solve(int o) {
    for (int i = 1; i <= n; i++) opt[i] = (i & 1) ^ o;
    root = tot = 0;
    ll all = 0, ans = 0;
    for (int i = n; i >= 1; i--) {
        if (opt[i] == 1) {
            all -= a[i];
            if (i == n) insert(-a[i] - all);
            else {
                insert(a[n] - (s[n - 1] - s[i - 1]) - all);
                insert(-(s[n] - s[i - 1]) - all);
            }
            if (i == 1) ans += find(root, -all);
            if (i == 2) ans += find(root, -a[1] - all);
            if (i >= 3) {
                if (i != 3) ans += find(root, -((s[i - 1] - s[1]) - a[1]) - all);
                ans += find(root, -s[i - 1] - all);
            }
            // fprintf(stderr, "o = %d, i = %d, ans = %lld\n", o, i, ans);
        } else {
            all += a[i];
        }
    }
    return ans;
}

int main() {
    srand(time(0));
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] + a[i];
        ll ans = solve(0) + solve(1);
        for (int i = 1; i <= n - 2; i++) {
            if (s[i] > s[n] - s[i]) ++ans;
        }
        print(ans % md, '\n');
    }
    return 0;
}