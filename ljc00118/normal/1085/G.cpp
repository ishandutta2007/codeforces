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

const int N = 2005, md = 998244353;

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

struct fenwick {
    int f[N], n;
    inline int lowbit(int x) { return x & -x; }
    void add(int x, int y) { for(register int i = x; i <= n; i += lowbit(i)) f[i] += y; }
    int query(int x) { int ans = 0; for(register int i = x; i; i ^= lowbit(i)) ans += f[i]; return ans; }
} tr1, tr2;

int a[N][N], f[N][N], vis1[N], vis2[N];
int n, ans;

int main() {
    read(n); tr1.n = tr2.n = n;
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= n; j++) read(a[i][j]);
    }
    f[0][0] = 1;
    for(register int i = 1; i <= n; i++) {
        f[i][0] = mul(f[i - 1][1], i - 1);
        for(register int j = 1; j <= i; j++) f[i][j] = add(mul(f[i - 1][j - 1], j), mul(f[i - 1][j], i - j));
    }
    for(register int i = 2; i <= n; i++) {
        memset(vis1, 0, sizeof(vis1)); memset(vis2, 0, sizeof(vis2));
        for(register int j = 1; j <= n; j++) tr1.add(j, 1);
        int cnt = 0, sum = 0;
        for(register int j = 1; j <= n; j++) {
            vis1[a[i - 1][j]] = 1;
            if(!vis2[a[i - 1][j]]) tr1.add(a[i - 1][j], -1), ++cnt;
            sum = add(sum, add(mul(tr1.query(a[i][j] - 1), f[n - j][cnt]), mul(tr2.query(a[i][j] - 1), f[n - j][cnt - 1])));
            // fprintf(stderr, "i = %d, j = %d, tr1.query(%d) = %d, tr2.query(%d) = %d\n", i, j, a[i][j] - 1, tr1.query(a[i][j] - 1), a[i][j] - 1, tr2.query(a[i][j] - 1));
            if(!vis2[a[i - 1][j]]) tr2.add(a[i - 1][j], 1);
            vis2[a[i][j]] = 1;
            if(vis1[a[i][j]]) --cnt;
            if(vis1[a[i][j]]) tr2.add(a[i][j], -1); else tr1.add(a[i][j], -1);
        }
        ans = add(ans, mul(sum, fpow(f[n][0], n - i)));
    }
    // cout << ans << endl;
    for(register int i = n, now = fpow(f[n][0], n - 1); i >= 1; i--, now = mul(now, n - i)) {
        ans = add(ans, mul(tr1.query(a[1][i] - 1), now));
        tr1.add(a[1][i], 1);
    }
    print(ans, '\n');
    return 0;
}