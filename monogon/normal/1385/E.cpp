
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
int n, m, ty[N], u[N], v[N];
vi adj[N];
int vis[N], ti[N], T = 0;
bool cyc = false;

void dfs(int x) {
    vis[x] = 1;
    for(int y : adj[x]) {
        if(vis[y] == 0) {
            dfs(y);
        }else if(vis[y] == 1) {
            cyc = true;
        }
    }
    vis[x] = 2;
    ti[x] = T++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        rep(i, 1, n + 1) {
            adj[i].clear();
        }
        rep(i, 0, m) {
            cin >> ty[i] >> u[i] >> v[i];
            if(ty[i] == 1) {
                adj[u[i]].push_back(v[i]);
            }
        }
        cyc = false;
        T = 0;
        fill(vis + 1, vis + n + 1, 0);
        rep(i, 1, n + 1) {
            if(vis[i] == 0) {
                dfs(i);
            }
        }
        if(cyc) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        rep(i, 0, m) {
            if(ti[u[i]] < ti[v[i]]) swap(u[i], v[i]);
            cout << u[i] << ' ' << v[i] << '\n';
        }
    }
}