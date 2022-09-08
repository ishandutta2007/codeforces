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

const int N = 1e6 + 5, md = 1e9 + 7, one = md - 1;

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

int fac[N], inv[N], s1[N], s2[N], pw[N], pri[N], isp[N];
int n, k, y, ans, len;

void sieve() {
    pw[1] = 1;
    for(register int i = 2; i <= k + 2; i++) {
        if(!isp[i]) { pri[++len] = i; pw[i] = fpow(i, k); }
        for(register int j = 1; j <= len && i * pri[j] <= k + 2; j++) {
            isp[i * pri[j]] = 1;
            pw[i * pri[j]] = mul(pw[i], pw[pri[j]]);
            if(i % pri[j] == 0) break;
        }
    }
}

int main() {
    read(n); read(k);
    sieve();
    fac[0] = 1;
    for(register int i = 1; i <= k + 1; i++) fac[i] = mul(fac[i - 1], i);
    inv[k + 1] = fpow(fac[k + 1], md - 2);
    for(register int i = k + 1; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    s1[0] = 1; for(register int i = 1; i <= k + 1; i++) s1[i] = mul(s1[i - 1], sub(n, i));
    s2[k + 3] = 1; for(register int i = k + 2; i >= 2; i--) s2[i] = mul(s2[i + 1], sub(n, i));
    for(register int i = 1; i <= k + 2; i++) {
        y = add(y, pw[i]);
        int A = mul(y, mul(s1[i - 1], s2[i + 1]));
        int B = mul(inv[i - 1], ((k + 2 - i) & 1) ? sub(0, inv[k + 2 - i]) : inv[k + 2 - i]);
        // fprintf(stderr, "A = %d, B = %d, y = %d, s1[i - 1] = %d, s2[i + 1] = %d\n", A, B, y, s1[i - 1], s2[i + 1]);
        ans = add(ans, mul(A, B));
    }
    print(ans, '\n');
    return 0;
}