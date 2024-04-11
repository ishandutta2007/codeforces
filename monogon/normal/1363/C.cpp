
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

const int N = 1005;
int t, n, x, u, v;
vi adj[N];
// bool vis[N];

// void dfs(int u) {
//     vis[u] = true;
//     for(int v : adj[u]) {
//         if(!vis[v]) {
//             dfs(v);
//         }
//     }
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x;
        // I'm the biggest idiot in the entire world
        rep(i, 1, n + 1) adj[i].clear();
        rep(i, 0, n - 1) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // I'm the biggest idiot in the entire world
        bool win = (sz(adj[x]) <= 1 || (n % 2 == 0));
        cout << (win ? "Ayush" : "Ashish") << '\n';
    }
    // dfs(x);
}