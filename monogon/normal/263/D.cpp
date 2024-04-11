
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

const int N = 1e5 + 5;
int n, m, k;
vi adj[N];
bool vis[N];

void solve(vi &v) {
    vi ve;
    ve.push_back(v.back());
    for(int i = sz(v) - 2; i >= 0; i--) {
        if(v[i] == v.back()) break;
        ve.push_back(v[i]);
    }
    reverse(all(ve));
    cout << sz(ve) << '\n';
    for(int x : ve) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int u = 1;
    set<int> se;
    vi ve;
    while(true) {
        vis[u] = true;
        ve.push_back(u);
        se.insert(u);
        if(sz(se) > k) se.erase(ve[sz(ve) - k - 1]);
        for(int v : adj[u]) {
            if(!se.count(v)) {
                if(vis[v]) {
                    ve.push_back(v);
                    solve(ve);
                    return 0;
                }
                u = v;
                break;
            }
        }
    }
}