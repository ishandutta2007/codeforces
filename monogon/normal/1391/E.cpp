
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

const int N = 5e5 + 5;
int n, m, depth[N], par[N];
vi adj[N];
bool vis[N];

void dfs(int x) {
    vis[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            depth[y] = depth[x] + 1;
            par[y] = x;
            dfs(y);
        }
    }
}

void path(int x) {
    cout << "PATH\n" << depth[x] + 1 << '\n';
    while(x != 1) {
        cout << x << ' ';
        x = par[x];
    }
    cout << "1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        cin >> n >> m;
        rep(i, 1, n + 1) adj[i].clear();
        rep(i, 0, m) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        fill(vis + 1, vis + n + 1, false);
        dfs(1);
        vi ve;
        vector<pii> pairs;
        rep(i, 1, n + 1) {
            if(depth[i] + 1 == (n + 1) / 2) {
                path(i);
                goto hell;
            }
        }
        rep(i, 1, n + 1) {
            ve.push_back(i);
        }
        sort(all(ve), [&](int a, int b) { return depth[a] < depth[b]; });
        rep(i, 1, n) {
            if(depth[ve[i]] == depth[ve[i - 1]]) {
                pairs.emplace_back(ve[i], ve[i - 1]);
                i++;
            }
        }
        cout << "PAIRING\n";
        cout << sz(pairs) << '\n';
        for(auto &pa : pairs) {
            cout << pa.first << ' ' << pa.second << '\n';
        }
        hell:;
    }
}