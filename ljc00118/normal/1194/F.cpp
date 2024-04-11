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

const int N = 2e5 + 5, md = 1e9 + 7, inv2 = (md + 1) >> 1;

inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if(x <= md) x += md;
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

ll T, sum;
int t[N], fac[N], inv[N];
int n, now = -1 , res, ans;

inline int C(int n, int m) {
    if(m < 0 || m > n) return 0;
    return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
    read(n); read(T);
    fac[0] = 1;
    for(register int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
    inv[n] = fpow(fac[n], md - 2);
    for(register int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    for(register int i = 1; i <= n; i++) {
        read(t[i]);
        sum += t[i];
        if(sum > T) break;
        res = sub(mul(res, 2), C(i - 1, now));
        if(T - sum >= i) ++ans;
        else {
            while(now < T - sum) res = add(res, C(i, ++now));
            while(now > T - sum) res = sub(res, C(i, now--));
            ans = add(ans, mul(res, fpow(inv2, i)));
        }
        // fprintf(stderr, "ans = %d\n", ans);
    }
    print(ans, '\n');
    return 0;
}