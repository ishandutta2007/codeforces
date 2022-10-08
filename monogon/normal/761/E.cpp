
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

const int N = 35;
int n, u, v;
vi adj[N];
ll px[N], py[N];
bool vis[N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int opp[4] = {1, 0, 3, 2};

void dfs(int x, ll dif, int dd) {
    vis[x] = true;
    int d = 0;
    for(int y : adj[x]) {
        if(!vis[y]) {
            if(d == dd) {
                d++; d %= 4;
            }
            px[y] = px[x] + dif * dx[d];
            py[y] = py[x] + dif * dy[d];
            dfs(y, dif / 2 - 1, opp[d]);
            d++; d %= 4;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n - 1) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i, 1, n + 1) {
        if(sz(adj[i]) > 4) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    dfs(1, (ll) 1e9, -1);
    rep(i, 1, n + 1) {
        cout << px[i] << ' ' << py[i] << '\n';
    }
}