#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

typedef vector<vii> vvii;

int n, m, u, v;
ll w;
vvii adj(2e5+5);
vector<ll> dis(2e5+5, 1e18);

void dijkstra (int u) {
    priority_queue< ii, vii, greater<ii> > pq;
    dis[u] = 0;
    pq.emplace(0, u);

    while (pq.size()) {
        w = pq.top().fi;
        u = pq.top().se;
        pq.pop();

        if (w != dis[u])
            continue;

        for (ii &v : adj[u]) {
            if (dis[u] + v.se < dis[v.fi]) {
                dis[v.fi] = dis[u] + v.se;
                pq.emplace(dis[v.fi], v.fi);
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w*2);
        adj[v].emplace_back(u, w*2);
    }

    for (int i = 1; i <= n; i++) {
        cin >> w;
        adj[0].emplace_back(i, w);
    }

    dijkstra(0);
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    cout << endl;

    return 0;
}