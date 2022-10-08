
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
    vector<multiset<int>> g(n + 1);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    vi ve;
    rep(i, 1, n + 1) if(sz(g[i]) % 2 == 1) ve.push_back(i);
    if((m + sz(ve) / 2) % 2 == 1) {
        ve.push_back(1);
        ve.push_back(1);
    }
    for(int i = 0; i < sz(ve); i += 2) {
        g[ve[i]].insert(ve[i + 1]);
        g[ve[i + 1]].insert(ve[i]);
    }
    vi ans;
    function<void(int)> dfs = [&](int x) {
        while(!g[x].empty()) {
            int y = *g[x].begin();
            g[x].erase(g[x].begin());
            g[y].erase(g[y].find(x));
            dfs(y);
        }
        ans.push_back(x);
    };
    dfs(1);
    cout << sz(ans) - 1 << '\n';
    rep(i, 0, sz(ans) - 1) {
        if(i % 2 == 0) {
            cout << ans[i] << ' ' << ans[i + 1] << '\n';
        }else {
            cout << ans[i + 1] << ' ' << ans[i] << '\n';
        }
    }
}