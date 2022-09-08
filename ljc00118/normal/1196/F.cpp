#include <bits/stdc++.h>
#define int long long
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
 
struct ele {
    int fr, u, dis, id, pre;
    ele (int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) : fr(a), u(b), dis(c), id(d), pre(e) {}
    bool operator < (const ele A) const { return dis > A.dis; }
};
 
struct edge_t {
    int v, val;
    bool operator < (const edge_t A) const { return val < A.val; }
};
 
priority_queue <ele> Q;
map <pii, bool> wxw;
vector <edge_t> adj[N];
ele t[N * 3];
int n, m, k, cnt, top;
 
inline void addedge(int u, int v, int val) {
    adj[u].push_back((edge_t) {v, val});
}
 
inline void insert(int id) {
    ele u = t[id]; ++u.id; ++t[id].id;
    if(u.id < (int)adj[u.u].size()) Q.push(ele(u.fr, adj[u.u][u.id].v, u.dis + adj[u.u][u.id].val, -1, id));
}
 
#undef int
int main() {
#define int long long
    read(n); read(m); read(k);
    for(register int i = 1; i <= m; i++) {
        int u, v, val;
        read(u); read(v); read(val);
        addedge(u, v, val);
        addedge(v, u, val);
    }
    for(register int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        wxw[make_pair(i, i)] = 1;
        t[++top] = ele(i, i, 0, -1, 0);
        insert(top);
    }
    while(!Q.empty()) {
        ele u = Q.top(); Q.pop(); insert(u.pre);
        if(!wxw.count(make_pair(u.fr, u.u))) {
            t[++top] = u; insert(top);
            wxw[make_pair(u.fr, u.u)] = 1;
            if(u.fr < u.u) ++cnt;
            // fprintf(stderr, "debug >>> %d %d %d\n", u.fr, u.u, u.dis);
            if(cnt == k) {
                print(u.dis, '\n');
                return 0;
            }
        }
    }
    return 0;
}