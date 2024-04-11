
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// all 0 => one way
// all 2 => one way
// all 1 => if bipartite, 2^(components) ways, else 0
// all (0, 1) => number of ind sets
// all (1, 2) => number of ind sets
// all (0, 2) => 2^(components)
// all (0, 1, 2) => 2^n
// count number of ind sets by recursion on each component

const int N = 42;
int n, m;
vi adj[N];
int comp = 0;
bool vis[N], col[N];
bool bip = true;
ll ind = 1;
ll indtmp = 0;
vi l[N];

void dfs(int x, bool c) {
    l[comp].push_back(x);
    vis[x] = true;
    col[x] = c;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y, !c);
        }else if(col[y] == col[x]) {
            bip = false;
        }
    }
}

ll n012() {
    return 1LL << n;
}
ll n01() {
    return ind;
}
ll n02() {
    return 1LL << comp;
}
ll n12() {
    return ind;
}
ll n0() {
    return 1;
}
ll n1() {
    if(bip) return 1LL << comp;
    return 0;
}
ll n2() {
    return 1;
}

void solve(int k, int i) {
    if(i < 0) {
        indtmp++;
        return;
    }
    solve(k, i - 1);
    int u = l[k][i];
    for(int v : adj[u]) {
        if(col[v]) return;
    }
    col[u] = true;
    solve(k, i - 1);
    col[u] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    if(m < 3) {
        // bruh
        cout << "0\n";
        return 0;
    }
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll single = 0;
    rep(i, 1, n + 1) {
        if(sz(adj[i]) == 0) single++;
        else if(!vis[i]) {
            dfs(i, false);
            comp++;
        }
    }
    fill(col, col + n + 1, false);
    rep(c, 0, comp) {
        indtmp = 0;
        solve(c, sz(l[c]) - 1);
        ind *= indtmp;
    }
    n -= single;
    cout << (1LL << single) * (n012() - n01() - n12() - n02() + n0() + n1() + n2()) << '\n';
}