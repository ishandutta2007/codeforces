
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// of all shops within certain distance, is it possible
// to do r shovels with at most cost a?
// choose cheapest shovel available
// do bfs adding stores to a data structure

// insert shovel of cost C
// query: sum of R cheapest costs?
// initially set sum = 0
// keep shovels in a max heap
// insert shovel, then if size > R, pop the largest cost
// increment sum accordingly
// first time size = R and sum < a, output dist

// num shovels can be very large, so we should actually store
// as a map cost -> amount

const int N = 5005, M = 5005;
int n, m, u, v, w, c, q, g;
ll k, p, r, a;
vector<int> adj[N];
vector<pair<ll, ll>> shovel[N];
map<ll, ll> ma;
bool vis[N];
int dist[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> w;
    for(int i = 0; i < w; i++) {
        cin >> c >> k >> p;
        shovel[c].emplace_back(k, p);
    }
    cin >> q;
    while(q--) {
        cin >> g >> r >> a;
        ma.clear();
        ll sum = 0, price = 0;
        queue<int> Q;
        fill(vis + 1, vis + n + 1, false);
        Q.push(g);
        vis[g] = true;
        dist[g] = 0;
        ll ans = -1;
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            for(auto pa : shovel[x]) {
                auto [k, p] = pa;
                ma[p] += k;
                sum += k;
                price += p * k;
            }
            while(sum > r && !ma.empty()) {
                ll c = ma.rbegin()->first;
                ll dif = min(sum - r, ma[c]);
                sum -= dif;
                price -= dif * c;
                ma[c] -= dif;
                if(ma[c] == 0) {
                    ma.erase(c);
                }
            }
            if(sum == r && price <= a) {
                ans = dist[x];
                break;
            }
            for(int y : adj[x]) {
                if(!vis[y]) {
                    vis[y] = true;
                    Q.push(y);
                    dist[y] = dist[x] + 1;
                }
            }
        }
        cout << ans << '\n';
    }
}