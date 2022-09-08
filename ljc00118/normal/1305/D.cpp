#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1005;

vector <int> adj[N];
int deg[N], used[N];
int n, m;

void dfs1(int u, int fa) {
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa || used[v]) continue;
        dfs1(v, u);
    }
    used[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i]; --deg[v];
    }
}

int ask(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int ans; cin >> ans; return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u]; ++deg[v];
    }
    while (1) {
        bool ok = 1; int u = 0, v = 0, p = 0;
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            if (deg[i] >= 2) ok = 0, p = i;
        }
        if (ok) {
            for (int i = 1; i <= n; i++) {
                if (!used[i]) {
                    if (!u) u = i;
                    else v = i;
                }
            }
            if (u && v) {
                cout << "! " << ask(u, v) << endl;
            } else {
                cout << "! " << u << endl;
            }
            return 0;
        }
        for (int i = 0; i < (int)adj[p].size(); i++) {
            if (!used[adj[p][i]]) {
                if (!u) u = adj[p][i];
                else if (!v) { v = adj[p][i]; break; }
            }
        }
        int ans = ask(u, v);
        if (ans == u) dfs1(p, u);
        else if (ans == v) dfs1(p, v);
        else dfs1(u, p), dfs1(v, p);
    }
    return 0;
}