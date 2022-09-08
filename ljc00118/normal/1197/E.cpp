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
 
struct ele {
    int in_t, out_t;
    bool operator < (const ele A) const { return out_t < A.out_t; }
} a[N];
 
struct info_t {
    int minn, val;
    info_t (int a = 0, int b = 0) : minn(a), val(b) {}
};
 
info_t operator + (const info_t A, const info_t B) {
    info_t ans;
    ans.minn = min(B.minn, A.minn);
    ans.val = 0;
    if(B.minn == ans.minn) ans.val = B.val;
    if(A.minn == ans.minn) ans.val = add(ans.val, A.val);
    return ans;
}
 
info_t sum[N * 40];
int lc[N * 40], rc[N * 40], f[N], g[N];
int n, tot, root, minn = 2e9, ans, maxn;
 
void change(int &u, int l, int r, int x, info_t y) {
    if(!u) u = ++tot;
    if(l == r) {
        sum[u] = sum[u] + y;
        return;
    }
    int mid = (l + r) >> 1;
    if(mid >= x) change(lc[u], l, mid, x, y);
    else change(rc[u], mid + 1, r, x, y);
    sum[u] = sum[lc[u]] + sum[rc[u]];
}
 
info_t query(int u, int l, int r, int L, int R) {
    if(!u) return info_t(0, 0);
    if(l <= L && R <= r) return sum[u];
    int mid = (L + R) >> 1;
    info_t ans = info_t(0, 0);
    if(mid >= l) ans = ans + query(lc[u], l, r, L, mid);
    if(mid + 1 <= r) ans = ans + query(rc[u], l, r, mid + 1, R);
    return ans;
}
 
int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i].out_t), read(a[i].in_t);
    sort(a + 1, a + n + 1);
    change(root, 0, 1e9, 0, info_t(0, 1));
    for(register int i = 1; i <= n; i++) {
        info_t v = query(root, 0, a[i].in_t, 0, 1e9);
        f[i] = v.val; g[i] = v.minn + a[i].in_t;
        change(root, 0, 1e9, a[i].out_t, info_t(g[i] - a[i].out_t, f[i]));
        // fprintf(stderr, "f[%d] = %d, g[%d] = %d\n", i, f[i], i, g[i]);
    }
    for(register int i = 1; i <= n; i++) maxn = max(maxn, a[i].in_t);
    for(register int i = 1; i <= n; i++) {
        if(a[i].out_t > maxn) {
            if(g[i] < minn) minn = g[i], ans = f[i];
            else if(g[i] == minn) ans = add(ans, f[i]);
        }
    }
    print(ans, '\n');
    return 0;
}