#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

VI fib{1, 1};
VVI to;
int sz[300000];

bool solve(int r, int n) {
    if (n == 1) return true;
    int fsz = fib.size();
    int k;
    rep(i, fsz) {
        if (fib[i] > n) return false;
        if (fib[i] == n) {
            k = i;
            break;
        }
    }
    bool found = false;
    int x, y;
    auto dfs = [&](auto&& self, int u, int p) -> void {
        int s = 1;
        for(int v: to[u]) {
            if (v == p) continue;
            self(self, v, u);
            s += sz[v];
        }
        sz[u] = s;
        if (s == fib[k-1] || s == fib[k-2]) {
            found = true;
            if (s == fib[k-1]) x = u, y = p;
            else y = u, x = p;
        }
    };
    dfs(dfs, r, -1);
    if (!found) return false;
    {
        int sz = to[x].size();
        rep(i, sz) if (to[x][i] == y) {
            to[x].erase(to[x].begin() + i);
            break;
        }
    }
    {
        int sz = to[y].size();
        rep(i, sz) if (to[y][i] == x) {
            to[y].erase(to[y].begin() + i);
            break;
        }
    }
    //cout << n << endl;
    return solve(x, fib[k-1]) && solve(y, fib[k-2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 2; fib.back() < n; i++) {
        fib.push_back(fib[i-1] + fib[i-2]);
    }
    to.resize(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    cout << (solve(0, n) ? "YES\n" : "NO\n");
}