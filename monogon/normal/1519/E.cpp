
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
    map<pair<ll, ll>, int> ma;
    int k = 0;
    auto get = [&](ll x, ll y) {
        if(ma.count({x, y}) == 0) ma[{x, y}] = k++;
        return ma[{x, y}];
    };
    vector<vector<pii>> g(2 * n);
    rep(i, 0, n) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        // (a/b + 1, c/d) = ((a + b) / b, c / d) parallel to ((a + b) * d, c * b)
        // (a/b, c/d + 1) parallel to (a * d, (c + d) * b)
        ll x = (a + b) * d, y = c * b;
        ll X = a * d, Y = (c + d) * b;
        {
            ll g = gcd(x, y);
            ll G = gcd(X, Y);
            x /= g; y /= g; X /= G; Y /= G;
        }
        int u = get(x, y);
        int v = get(X, Y);
        g[u].push_back({i + 1, v});
        g[v].push_back({i + 1, u});
    }
    g.resize(k);
    vi vis(k, 0);
    vector<pii> ve;
    function<bool(int, int)> dfs = [&](int x, int p) {
        vis[x] = 1;
        vi hmm;
        for(auto &e : g[x]) {
            int i, y;
            tie(i, y) = e;
            if(i != p && (vis[y] == 1 || (vis[y] == 0 && dfs(y, i)))) {
                hmm.push_back(i);
            }
        }
        bool flag = true;
        if(p != -1 && sz(hmm) % 2 == 1) {
            hmm.push_back(p);
            flag = false;
        }
        for(int i = 0; i + 1 < sz(hmm); i += 2) {
            ve.push_back({hmm[i], hmm[i + 1]});
        }
        vis[x] = 2;
        return flag;
    };
    rep(i, 0, k) {
        if(!vis[i]) {
            dfs(i, -1);
        }
    }
    cout << sz(ve) << '\n';
    for(auto &pa : ve) {
        cout << pa.first << ' ' << pa.second << '\n';
    }
}