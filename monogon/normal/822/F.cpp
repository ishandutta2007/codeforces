
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

using ftype = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vi> g(n + 1);
    map<pii, int> ma;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        ma[{u, v}] = ma[{v, u}] = i + 1;
    }
    cout << n - 1 << '\n';
    cout << fixed << setprecision(8);
    function<void(int, int, ftype)> dfs = [&](int x, int p, ftype ti) {
        int cnt = 0;
        for(int y : g[x]) if(y != p) cnt++;
        ftype inc = 2.0 / (cnt + 1);
        for(int y : g[x]) {
            if(y != p) {
                ti += inc;
                if(ti > 2) ti -= 2;

                cout << 1 << ' ' << ma[{x, y}] << ' ';
                if(ti > 1) {
                    cout << y << ' ' << x << ' ' << ti - 1 << '\n';
                }else {
                    cout << x << ' ' << y << ' ' << ti << '\n';
                }
                dfs(y, x, ti + 1 > 2 ? ti - 1 : ti + 1);
            }
        }
    };
    int idx = 0;
    rep(i, 0, n) if(sz(g[i]) == 1) idx = i;
    dfs(idx, -1, 0);
}