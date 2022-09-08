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

const int N = 5e5 + 5;

struct ele {
    int u, v, val;
    bool operator < (const ele A) const { return val < A.val; }
} E[N];

vector < pair < vector <int> , int > > Q[N];
vector < int > tmp[N], edg[N], G;
int fa[N], siz[N], st[N], ans[N], used[N], a[N];
int n, m, q, top;

int find(int x) { return fa[x] == x ? x : find(fa[x]); }

void merge(int x, int y) {
    if(siz[x] > siz[y]) swap(x, y);
    fa[x] = y;
    siz[y] += siz[x];
    st[++top] = x;
}

void del() {
    int x = st[top--];
    siz[fa[x]] -= siz[x];
    fa[x] = x;
}

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
    for(register int i = 1; i <= m; i++) {
        read(E[i].u), read(E[i].v), read(E[i].val);
        edg[E[i].val].push_back(i);
    }
    read(q);
    for(register int i = 1; i <= q; i++) {
        ans[i] = 1;
        int t; read(t);
        vector <int> id;
        for(register int j = 1; j <= t; j++) {
            read(a[j]);
            if(!used[E[a[j]].val]) {
                used[E[a[j]].val] = 1;
                id.push_back(E[a[j]].val);
            }
            tmp[E[a[j]].val].push_back(a[j]);
        }
        for(register unsigned j = 0; j < id.size(); j++) {
            int now = id[j];
            Q[now].push_back(make_pair(tmp[now], i));
            tmp[now].clear();
            used[now] = 0;
        }
    }
    for(register int i = 1; i <= 500000; i++) {
        for(register unsigned j = 0; j < Q[i].size(); j++) {
            int res = 1;
            G = Q[i][j].first;
            for(register unsigned k = 0; k < G.size(); k++) {
                ele now = E[G[k]];
                int x = find(now.u), y = find(now.v);
                if(x == y) {
                    res = 0;
                    for(register int t = k - 1; t >= 0; t--) del();
                    break;
                }
                merge(x, y);
            }
            if(!res) ans[Q[i][j].second] = 0;
            else for(register unsigned k = 0; k < G.size(); k++) del();
        }
        for(register unsigned j = 0; j < edg[i].size(); j++) {
            int x = find(E[edg[i][j]].u), y = find(E[edg[i][j]].v);
            if(x != y) merge(x, y);
        }
    }
    for(register int i = 1; i <= q; i++) printf("%s\n", ans[i] ? "YES" : "NO");
    return 0;
}