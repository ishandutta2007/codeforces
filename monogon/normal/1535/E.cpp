
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
    int q;
    cin >> q;
    vector<ll> a(q + 1), c(q + 1);
    vector<array<int, 20>> go(q + 1);
    cin >> a[0] >> c[0];
    rep(i, 0, 20) go[0][0] = 0;
    rep(i, 1, q + 1) {
        int ty;
        cin >> ty;
        if(ty == 1) {
            int p;
            cin >> p >> a[i] >> c[i];
            go[i][0] = p;
            rep(l, 1, 20) go[i][l] = go[go[i][l - 1]][l - 1];
        }else {
            int v; ll w;
            cin >> v >> w;
            ll cost = 0, tot = 0;
            while(w > 0) {
                int u = v;
                for(int l = 19; l >= 0; l--) {
                    if(a[go[u][l]] > 0) u = go[u][l];
                }
                ll amt = min(w, a[u]);
                cost += amt * c[u];
                a[u] -= amt;
                tot += amt;
                w -= amt;
                if(u == v) break;
            }
            cout << tot << ' ' << cost << endl;
        }
    }
    // vi tin(q + 1), tinv(q + 1);
    // int ti = 0;
    // function<void(int)> dfs = [&](int x) {
    //     tin[x] = ti++;
    //     tinv[tin[x]] = x;
    //     for(int y : g[x]) {
    //         dfs(y);
    //     }
    // };
    // dfs(0);
    // set<int> s;
    // s.insert(tin[0]);
    // for(auto &pa : qu) {
    //     int v; ll w;
    //     tie(v, w) = pa;
    //     ll cost = 0, tot = 0;
    //     while(w > 0) {
    //         int u = tinv[*prev(s.lower_bound(tin[v] + 1))];
    //         ll amt = min(w, a[u]);
    //         cost += amt * c[u];
    //         a[u] -= amt;
    //         tot += amt;
    //         w -= amt;
    //         if(u == v) break;
    //         if(a[u] == 0) {
    //             for(int x : g[u]) {
    //                 s.insert(tin[x]);
    //             }
    //         }
    //     }
    //     cout << tot << ' ' << cost << '\n';
    // }
}