
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
    vi a(n + 1), ainv(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
        ainv[a[i]] = i;
    }
    vector<vi> g(n + 1);
    vi par(n + 1), dep(n + 1), ti(n + 1), tout(n + 1), post;
    post.push_back(-1);
    int t = 1;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        par[v] = u;
    }
    rep(i, 1, n + 1) {
        sort(all(g[i]), [&](int u, int v) { return a[u] < a[v]; });
    }
    function<void(int)> dfs = [&](int x) {
        ti[x] = t++;
        for(int y : g[x]) {
            dep[y] = 1 + dep[x];
            dfs(y);
        }
        tout[x] = t;
        post.push_back(x);
    };
    dfs(1);

    ll k = 0;
    int sad = n + 1;
    rep(i, 1, n + 1) {
        k += dep[ainv[i]];
        if(ainv[i] != post[i]) {
            sad = i;
            int x = ainv[i];
            if(ti[ainv[i]] > ti[post[i]] || tout[post[i]] > tout[ainv[i]]) {
                cout << "NO\n";
                return 0;
            }
            while(x != 1) {
                swap(ainv[a[x]], ainv[a[par[x]]]);
                swap(a[x], a[par[x]]);
                x = par[x];
            }
            break;
        }
    }
    rep(i, sad, n) {
        if(ti[ainv[i]] > ti[ainv[i + 1]]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    cout << k << '\n';
    rep(i, 1, n + 1) cout << ti[i] << ' ';
    cout << '\n';
}