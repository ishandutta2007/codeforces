#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
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

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    void clear() { *this = hash_map_t(mod); }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 2e5 + 5, md = 1e9 + 7;

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

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

int l[N], r[N], inv[N], p[N];
int n, ans, ans1, ans2;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(l[i]);
    for(register int i = 1; i <= n; i++) read(r[i]), inv[i] = fpow(r[i] - l[i] + 1, md - 2);
    for(register int i = 1; i < n; i++) {
        int L = max(l[i], l[i + 1]);
        int R = min(r[i], r[i + 1]);
        if(L > R) L = R + 1;
        p[i] = sub(1, mul(R - L + 1, mul(inv[i], inv[i + 1])));
        ans1 = add(ans1, p[i]);
    }
    for(register int i = 1; i < n - 1; i++) {
        int L = max(l[i], max(l[i + 1], l[i + 2]));
        int R = min(r[i], min(r[i + 1], r[i + 2]));
        if(L > R) L = R + 1;
        ans2 = add(ans2, sub(1, add(sub(1, p[i]), sub(1, p[i + 1]))));
        ans2 = add(ans2, mul(R - L + 1, mul(inv[i], mul(inv[i + 1], inv[i + 2]))));
    }
    // fprintf(stderr, "ans1 = %d, ans2 = %d\n", ans1, ans2);
    ans = add(add(mul(ans1, 3), mul(ans2, 2)), 1);
    for(register int i = 1; i < n; i++) {
        int now = ans1;
        if(i != 1) now = sub(now, p[i - 1]);
        now = sub(now, p[i]);
        if(i != n - 1) now = sub(now, p[i + 1]);
        ans = add(ans, mul(now, p[i]));
    }
    print(ans, '\n');
    return 0;
}