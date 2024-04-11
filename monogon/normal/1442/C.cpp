
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

const int N = 2e5 + 5, M = 998244353;
int n, m;
vi adj[2][N];
bool vis[N][22];

struct orz {
    int u;
    int k, dist;
    orz(int u, int k, ll dist) : u(u), k(k), dist(dist) {}
    bool operator<(const orz &o) const {
        if(k == o.k) return dist > o.dist;
        if(k >= 20 || o.k >= 20) return k > o.k;
        return (1 << k) + dist > (1 << o.k) + o.dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }
    priority_queue<orz> Q;
    Q.emplace(1, 0, 0);
    while(!Q.empty()) {
        orz x = Q.top(); Q.pop();
        bool b = x.k % 2;
        int kk = (x.k >= 20 ? b ? 19 : 20 : x.k);
        if(vis[x.u][kk]) continue;
        vis[x.u][kk] = true;
        if(x.u == n) {
            ll pow2 = 1;
            rep(i, 0, x.k) pow2 = (pow2 * 2) % M;
            ll ans = pow2 + x.dist - 1;
            ans = (ans % M + M) % M;
            cout << ans << '\n';
            return 0;
        }
        for(int v : adj[b][x.u]) {
            Q.emplace(v, x.k, x.dist + 1);
        }
        Q.emplace(x.u, x.k + 1, x.dist);
    }
    cout << "oops" << endl;
}