
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

int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        cin >> n >> m >> k;
        vector<vi> adj(n + 1);
        vi deg(n + 1, 0);
        vi e;
        rep(i, 0, m) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
            e.push_back((u-1) * n + (v-1));
            e.push_back((v-1) * n + (u-1));
        }
        sort(all(e));
        vector<bool> del(n + 1, false), vis(n + 1, false);
        queue<int> Q;
        rep(i, 1, n + 1) {
            if(deg[i] < k) {
                vis[i] = true;
                Q.push(i);
            }
        }
        vi ve;
        auto ins = [&](int ed) {
            auto it = lower_bound(all(e), ed);
            return (it != e.end() && *it == ed);
        };
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            del[x] = true;
            if(deg[x] == k - 1 && k * (k - 1) / 2 <= m) {
                vi a;
                a.push_back(x);
                for(int y : adj[x]) {
                    if(!del[y]) a.push_back(y);
                }
                assert(sz(a) == k);
                bool flag = true;
                rep(i, 0, k) rep(j, i + 1, k) {
                    if(!ins((a[i]-1) * n + (a[j]-1))) {
                        flag = false;
                        goto hell;
                    }
                }
                if(flag) {
                    cout << 2 << '\n';
                    for(int y : a) cout << y << ' ';
                    cout << '\n';
                    goto endtest;
                }
                hell:;
            }
            for(int y : adj[x]) {
                deg[y]--;
                if(!vis[y] && deg[y] < k) {
                    vis[y] = true;
                    Q.push(y);
                }
            }
        }
        rep(i, 1, n + 1) if(!del[i]) ve.push_back(i);
        if(ve.empty()) {
            cout << -1 << '\n';
        }else {
            cout << 1 << ' ' << sz(ve) << '\n';
            for(int x : ve) {
                cout << x << ' ';
            }
            cout << '\n';
        }
        endtest:;
    }
}