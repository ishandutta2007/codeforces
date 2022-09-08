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

const int N = 1e5 + 5;

struct edge_t {
    int u, v, val, id;
    bool operator < (const edge_t &A) { return val < A.val; }
} p[N];

vector <int> res;
vector <int> adj[N];
queue <int> q;
int g[N], id[N];
int n, m, tot;

bool check(int mid) {
    memset(g, 0, sizeof(g));
    for(register int i = 1; i <= n; i++) adj[i].clear();
    int cnt = 0;
    for(register int i = mid; i <= m; i++) {
        int u = p[i].u, v = p[i].v;
        adj[u].push_back(v); g[v]++;
    }
    for(register int i = 1; i <= n; i++) {
        if(!g[i]) {
            ++cnt;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(register unsigned i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i]; --g[v];
            if(!g[v]) { ++cnt; q.push(v); }
        }
    }
    return cnt == n;
}

int main() {
    read(n); read(m);
    for(register int i = 1; i <= m; i++) {
        read(p[i].u); read(p[i].v);
        read(p[i].val); p[i].id = i;
    }
    sort(p + 1, p + m + 1);
    int l = 1, r = m, ans = m;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) ans = mid, r = mid - 1; else l = mid + 1;
    }
    memset(g, 0, sizeof(g));
    for(register int i = 1; i <= n; i++) adj[i].clear();
    for(register int i = ans; i <= m; i++) {
        int u = p[i].u, v = p[i].v;
        adj[u].push_back(v); g[v]++;
    }
    for(register int i = 1; i <= n; i++) {
        if(!g[i]) q.push(i);
    }
    while(!q.empty()) {
        int u = q.front(); q.pop(); id[u] = ++tot;
        for(register unsigned i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i]; --g[v];
            if(!g[v]) q.push(v);
        }
    }
    if(ans == 1) { cout << 0 << " " << 0 << endl; return 0; }
    for(register int i = ans - 1; i >= 1; i--) {
        int u = p[i].u, v = p[i].v;
        if(id[u] > id[v]) {
            swap(u, v);
            res.push_back(p[i].id);
        }
    }
    sort(res.begin(), res.end());
    cout << p[ans - 1].val << " " << res.size() << endl;
    for(register unsigned i = 0; i < res.size(); i++) {
        print(res[i], ' ');
    }
    if(res.size()) putchar('\n');
	return 0;
}