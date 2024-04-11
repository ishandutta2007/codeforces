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

const int N = 5005, md = 998244353;

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

int f[N][N], s[N][N];
int a[N], b[N], cnt[N], inv[N], sc[N];
int n, m, ans;

int main() {
    read(m);
    for(register int i = 1; i <= m; i++) inv[i] = fpow(i, md - 2);
    for(register int i = 1; i <= m; i++) {
        int t; read(t);
        ++b[t];
    }
    for(register int i = 1; i <= m; i++) {
        if(b[i]) {
            ++n;
            a[n] = i;
            cnt[n] = b[i];
        }
    }
    for(register int i = n; i >= 1; i--) sc[i] = sc[i + 1] + cnt[i];
    f[n][n] = mul(cnt[n] - 1, inv[m - n]);
    for(register int i = 1; i <= n; i++) s[n][i] = mul(f[n][n], cnt[n]);
    for(register int i = n - 1; i >= 1; i--) {
        for(register int j = n; j >= i; j--) {
            f[i][j] = add(mul(s[i + 1][j + 1], inv[m - i]), mul(cnt[j] - 1, inv[m - i]));
            s[i][j] = add(s[i][j + 1], mul(f[i][j], cnt[j]));
            // fprintf(stderr, "f[%d][%d] = %d\n", i, j, f[i][j]);
        }
    }
    cout << mul(s[1][1], inv[m]) << endl;
    return 0;
}