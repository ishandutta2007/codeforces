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
 
const int N = 2e5 + 5;
 
vector <int> g[N];
int x[N], y[N], a[N], b[N], f[N], vis[N];
int n;
ll ans;
 
inline int lowbit(int x) { return x & -x; }
 
inline void add(int x) {
    for(register int i = x; i <= n; i += lowbit(i)) ++f[i];
}
 
inline int query(int x) {
    int ans = 0;
    for(register int i = x; i; i -= lowbit(i)) ans += f[i];
    return ans;
}
 
int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        read(x[i]); read(y[i]);
        a[i] = x[i]; b[i] = y[i];
    }
    sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
    for(register int i = 1; i <= n; i++) {
        x[i] = lower_bound(a + 1, a + n + 1, x[i]) - a;
        y[i] = lower_bound(b + 1, b + n + 1, y[i]) - b;
        g[y[i]].push_back(x[i]);
    }
    for(register int i = n; i >= 1; i--) {
        if(g[i].size() == 0) continue;
        sort(g[i].begin(), g[i].end());
        for(register int j = 0; j < (int)g[i].size() - 1; j++) {
            int cnt = query(g[i][j + 1] - 1) - query(g[i][j]);
            ans -= 1ll * cnt * (cnt + 1) / 2;
        }
        int cntl = query(g[i][0] - 1);
        int cntr = query(n) - query(g[i][g[i].size() - 1]);
        ans -= 1ll * cntl * (cntl + 1) / 2;
        ans -= 1ll * cntr * (cntr + 1) / 2;
        for(register int j = 0; j < (int)g[i].size(); j++) {
            if(!vis[g[i][j]]) {
                vis[g[i][j]] = 1;
                add(g[i][j]);
            }
        }
        int cnt = query(n);
        ans += 1ll * cnt * (cnt + 1) / 2;
    }
    print(ans, '\n');
    return 0;
}