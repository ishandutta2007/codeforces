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

const int md = 1e9 + 6, md2 = 1e9 + 7;

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

inline int mul2(int x, int y) { return 1ll * x * y % md2; }

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

inline int fpow2(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul2(ans, x);
        y >>= 1; x = mul2(x, x);
    }
    return ans;
}

ll n;
int f1, f2, f3, c, ans = 1;

struct mat { int a[5][5], n; } a;

mat operator * (const mat a, const mat b) {
    mat ans; memset(ans.a, 0, sizeof(ans.a)); ans.n = a.n; int n = a.n - 1;
    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) ans.a[i][j] = add(ans.a[i][j], mul(a.a[i][k], b.a[k][j]));
    return ans;
}

mat fpow(mat a, ll n) {
    mat ans; memset(ans.a, 0, sizeof(ans.a)); ans.n = a.n;
    rep(i, 0, a.n - 1) ans.a[i][i] = 1;
    while(n) {
        if(n & 1) ans = ans * a;
        n >>= 1; a = a * a;
    }
    return ans;
}

int main() {
    cin >> n >> f1 >> f2 >> f3 >> c;
    a.n = 3; a.a[0][0] = a.a[0][1] = a.a[0][2] = a.a[1][0] = a.a[2][1] = 1;
    a = fpow(a, n - 3);
    ans = 1ll * fpow2(f1, a.a[0][2]) * fpow2(f2, a.a[0][1]) % md2 * fpow2(f3, a.a[0][0]) % md2;
    a.n = 5; memset(a.a, 0, sizeof(a.a)); a.a[0][0] = a.a[0][1] = a.a[0][2] = a.a[0][3] = a.a[0][4] = a.a[1][0] = a.a[2][1] = a.a[3][3] = a.a[3][4] = a.a[4][4] = 1;
    a = fpow(a, n - 3);
    ans = 1ll * ans * fpow2(c, mul(a.a[0][4], 2)) % md2;
    print(ans, '\n');
    return 0;
}