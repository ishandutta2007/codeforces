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

const int N = 2e5 + 5;

multiset <int> adj[N];
int b[N], c[N], ans[N], pre[N];
int n, top, fir = 1, big;

void dfs1(int u) {
    while(adj[u].size()) {
        int now = *adj[u].begin();
        adj[u].erase(adj[u].find(now));
        adj[now].erase(adj[now].find(u));
        dfs1(now);
    }
    ans[++top] = u;
}

int main() {
    read(n);
    for(register int i = 1; i < n; i++) read(b[i]), pre[++big] = b[i];
    for(register int i = 1; i < n; i++) read(c[i]), pre[++big] = c[i];
    sort(pre + 1, pre + big + 1); big = unique(pre + 1, pre + big + 1) - pre - 1;
    for(register int i = 1; i < n; i++) b[i] = lower_bound(pre + 1, pre + big + 1, b[i]) - pre;
    for(register int i = 1; i < n; i++) c[i] = lower_bound(pre + 1, pre + big + 1, c[i]) - pre;
    for(register int i = 1; i < n; i++) {
        adj[b[i]].insert(c[i]);
        adj[c[i]].insert(b[i]);
        if(b[i] > c[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    int cnt = 0;
    for(register int i = 1; i <= big; i++) {
        if(adj[i].size() % 2 == 1) {
            fir = i;
            ++cnt;
        }
    }
    if(cnt > 0 && cnt != 2) {
        cout << -1 << endl;
        return 0;
    }
    dfs1(fir);
    if(top != n) {
        cout << -1 << endl;
        return 0;
    }
    for(register int i = top; i >= 1; i--) print(pre[ans[i]], ' ');
    putchar('\n');
    return 0;
}