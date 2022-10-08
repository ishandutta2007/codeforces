
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 1) {
        cout << "YES\n";
        return 0;
    }
    vi f(2);
    f[0] = f[1] = 1;
    while(f.back() < n) {
        f.push_back(f.back() + f[sz(f) - 2]);
    }
    if(f.back() != n) {
        cout << "NO\n";
        return 0;
    }
    vector<set<int>> g(n + 1);

    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    pii pa = {-1, -1};
    function<int(int, int, int)> dfs = [&](int x, int p, int k) {
        int s = 1;
        for(int y : g[x]) {
            if(y != p) {
                int si = dfs(y, x, k);
                if(si == f[k - 1]) pa = {y, x};
                if(si == f[k - 2]) pa = {x, y};
                s += si;
            }
        }
        return s;
    };
    function<bool(int, int)> solve = [&](int x, int k) {
        pa = {-1, -1};
        if(dfs(x, -1, k) == 1) return true;
        int a, b;
        tie(a, b) = pa;
        if(a == -1) return false;
        g[a].erase(b);
        g[b].erase(a);
        // cout << "Split " << a << ' ' << b << endl;
        return solve(a, k - 1) && solve(b, k - 2);
    };

    int k = sz(f) - 1;
    cout << (solve(1, k) ? "YES" : "NO") << '\n';
}