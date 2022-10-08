
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

const int N = 1e5 + 5, M = 1e9 + 7;
int n;
vi adj[N];
ll dp[N];
vector<ll> coef;

void dfs(int x, int p) {
    dp[x] = 1;
    for(int y : adj[x]) {
        if(y != p) {
            dfs(y, x);
            coef.push_back(1LL * dp[y] * (n - dp[y]));
            dp[x] += dp[y];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        cin >> n;
        rep(i, 1, n + 1) adj[i].clear();
        coef.clear();
        rep(i, 0, n - 1) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, -1);

        sort(coef.begin(), coef.end());
        int m;
        cin >> m;
        vector<ll> p(m);
        rep(i, 0, m) {
            cin >> p[i];
        }
        while(sz(p) < n - 1) p.push_back(1);
        sort(p.begin(), p.end());
        ll ans = 0;
        m = sz(p);
        rep(i, 0, n - 2) {
            coef[i] %= M;
            ans = (ans + coef[i] * p[i]) % M;
        }
        ll prod = 1;
        rep(j, n - 2, m) {
            prod = (prod * p[j]) % M;
        }
        coef[n - 2] %= M;
        ans = (ans + prod * coef[n - 2]) % M;
        cout << ans << '\n';
    }
}