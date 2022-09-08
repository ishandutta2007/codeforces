#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
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

const int N = 3e5 + 5;
const int base1 = 103, base2 = 107;
const int md1 = 998244353, md2 = 98765431;

inline int fpow(int x, int y, int md) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % md;
        x = 1ll * x * x % md; y >>= 1;
    }
    return ans;
}

struct fenwick {
    int f[N], n, md;

    inline int lowbit(int x) { return x & -x; }

    void add(int x, int y) {
        for(register int i = x; i <= n; i += lowbit(i))
            f[i] = (f[i] + y) % md;
    }

    int query(int x) {
        int ans = 0;
        for(register int i = x; i; i -= lowbit(i))
            ans = (ans + f[i]) % md;
        return ans;
    }
} tr[2][2];

int pw1[N], pw2[N], inv1[N], inv2[N], a[N];
int n;

int main() {
    read(n);
    tr[0][0].n = tr[0][1].n = tr[1][0].n = tr[1][1].n = n;
    tr[0][0].md = tr[0][1].md = md1;
    tr[1][0].md = tr[1][1].md = md2;
    pw1[0] = pw2[0] = inv1[0] = inv2[0] = 1;
    for(register int i = 1; i <= n; i++) {
        pw1[i] = 1ll * pw1[i - 1] * base1 % md1;
        pw2[i] = 1ll * pw2[i - 1] * base2 % md2;
        inv1[i] = fpow(pw1[i], md1 - 2, md1);
        inv2[i] = fpow(pw2[i], md2 - 2, md2);
        read(a[i]);
    }
    for(register int i = 1; i <= n; i++) {
        int big = min(a[i], n - a[i] + 1);
        int l1 = a[i] - big + 1, r1 = a[i];
        int l2 = a[i], r2 = a[i] + big - 1;
        int ans[2][2];
        ans[0][0] = 1ll * (tr[0][0].query(r1) - tr[0][0].query(l1 - 1) + md1) * inv1[l1 - 1] % md1;
        ans[1][0] = 1ll * (tr[1][0].query(r1) - tr[1][0].query(l1 - 1) + md2) * inv2[l1 - 1] % md2;
        ans[0][1] = 1ll * (tr[0][1].query(r2) - tr[0][1].query(l2 - 1) + md1) * inv1[n - r2] % md1;
        ans[1][1] = 1ll * (tr[1][1].query(r2) - tr[1][1].query(l2 - 1) + md2) * inv2[n - r2] % md2;
        if(ans[0][0] != ans[0][1] || ans[1][0] != ans[1][1]) {
            cout << "YES" << endl;
            return 0;
        }
        tr[0][0].add(a[i], pw1[a[i]]); tr[1][0].add(a[i], pw2[a[i]]);
        tr[0][1].add(a[i], pw1[n - a[i] + 1]); tr[1][1].add(a[i], pw2[n - a[i] + 1]);
    }
    cout << "NO" << endl;
    return 0;
}