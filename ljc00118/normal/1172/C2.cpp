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

const int N = 3005, MAXN = 2e5 + 5, md = 998244353;

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

int f[N][N], g[N][N];
int a[MAXN], w[MAXN], inv[N << 1];
int n, m, s1, s2, sum;

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) read(a[i]);
    for(register int i = 1; i <= n; i++) {
        read(w[i]);
        if(a[i] == 1) s1 += w[i]; else s2 += w[i];
        sum += w[i];
    }
    for(register int i = 0; i <= m * 2; i++) inv[i] = fpow(sum + i - m, md - 2);
    f[0][0] = g[0][0] = 1;
    for(register int s = 0; s < m; s++) {
        for(register int i = 0; i <= s; i++) {
            int j = s - i;
            // fprintf(stderr, "f[%d][%d] = %d, g[%d][%d] = %d\n", i, j, f[i][j], i, j, g[i][j]);
            f[i + 1][j] = add(f[i + 1][j], mul(f[i][j], mul(s1 + i + 1, inv[m + i - j])));
            // if(i == 1 && j == 0) fprintf(stderr, "debug : %d %d\n", s1 + i + 1, inv[m + i - j]);
            if(j + 1 <= s2) f[i][j + 1] = add(f[i][j + 1], mul(f[i][j], mul(s2 - j, inv[m + i - j])));
            g[i + 1][j] = add(g[i + 1][j], mul(g[i][j], mul(s1 + i, inv[m + i - j])));
            if(j + 1 <= s2) g[i][j + 1] = add(g[i][j + 1], mul(g[i][j], mul(s2 - j - 1, inv[m + i - j])));
        }
    }
    s1 = s2 = 0;
    for(register int i = 0; i <= m; i++) s1 = add(s1, f[i][m - i]), s2 = add(s2, g[i][m - i]);
    for(register int i = 1; i <= n; i++) {
        if(a[i] == 1) print(mul(s1, w[i]), '\n');
        else print(mul(s2, w[i]), '\n');
    }
    return 0;
}