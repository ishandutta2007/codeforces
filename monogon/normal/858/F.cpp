
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
    int n, m;
    cin >> n >> m;
    vector<vi> g(n + 1);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi vis(n + 1, 0);
    vector<array<int, 3>> ve;
    function<bool(int, int)> dfs = [&](int x, int p) {
        vi hmm;
        vis[x] = 1;
        for(int y : g[x]) {
            if(y != p && (vis[y] == 1 || (vis[y] == 0 && dfs(y, x)))) hmm.push_back(y);
        }
        bool flag = true;
        if(p != -1 && sz(hmm) % 2 == 1) {
            hmm.push_back(p);
            flag = false;
        }
        for(int i = 0; i + 1 < sz(hmm); i += 2) {
            ve.push_back({hmm[i], x, hmm[i + 1]});
        }
        vis[x] = 2;
        return flag;
    };
    rep(i, 1, n + 1) {
        if(!vis[i]) dfs(i, -1);
    }
    cout << sz(ve) << '\n';
    for(auto &ar : ve) {
        cout << ar[0] << ' ' << ar[1] << ' ' << ar[2] << '\n';
    }
}