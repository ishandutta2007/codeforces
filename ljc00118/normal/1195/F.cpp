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
 
const int N = 3e5 + 5;
 
map <pii, int> wxw;
vector <pii> q[N];
int l[N], r[N], pre[N], x[N], y[N], ans[N], f[N];
int n, Q, now, cnt, res;
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

inline int lowbit(int x) { return x & -x; }

inline void add(int x) {
    ++x;
    for(register int i = x; i <= now; i += lowbit(i)) ++f[i];
}

inline int query(int x) {
    ++x;
    int ans = 0;
    for(register int i = x; i; i ^= lowbit(i)) ans += f[i];
    return ans;
}
 
int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        int m; read(m); l[i] = now + 1; r[i] = now + m;
        for(register int j = 1; j <= m; j++) read(x[j]), read(y[j]);
        for(register int j = 1; j <= m; j++) {
            int fr = j == 1 ? m : j - 1;
            int _x = x[j] - x[fr], _y = y[j] - y[fr];
            // if(_x < 0) _x = -_x, _y = -_y;
            int d = gcd(abs(_x), abs(_y));
            _x /= d; _y /= d;
            if(!wxw.count(make_pair(_x, _y))) wxw[make_pair(_x, _y)] = now + j;
            else pre[now + j] = wxw[make_pair(_x, _y)], wxw[make_pair(_x, _y)] = now + j;
        }
        now += m;
    }
    read(Q);
    for(register int i = 1; i <= Q; i++) {
        int l, r;
        read(l); read(r);
        l = ::l[l]; r = ::r[r];
        q[r].push_back(make_pair(l, i));
    }
    for(register int i = 1; i <= now; i++) {
        add(pre[i]);
        for(register int j = 0; j < (int)q[i].size(); j++) ans[q[i][j].second] = query(q[i][j].first - 1) - q[i][j].first + 1;
    }
    for(register int i = 1; i <= Q; i++) print(ans[i], '\n');
    return 0;
}