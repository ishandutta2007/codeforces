#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
 
const int MX = 100005, mod = 1000000007, mod2 = 1000000021;
int n, m, s, t, u[MX], v[MX];
ll dist[2][MX], cn[2][MX], cn2[2][MX], w[MX], csp, csp2, mn;
vii adj[2][MX];
priority_queue<ii, vii, greater<ii>> pq; 

void dijkstra (int s, int t, vii adj[], ll dist[], ll cn[], ll cn2[]) {
    fill(dist, dist+MX, 1e18);
    dist[s] = 0;
    cn[s] = 1;
    cn2[s] = 1;
    pq.emplace(0, s);

    while (pq.size()) {
        ii front = pq.top(); pq.pop();
        ll d = front.fi;
        int u = front.se;

        if (d > dist[u])
            continue;

        for (ii &v : adj[u]) {
            if (dist[u] + v.se < dist[v.fi]) {
                dist[v.fi] = dist[u] + v.se;
                cn[v.fi] = cn[u];
                cn2[v.fi] = cn2[u];
                pq.emplace(dist[v.fi], v.fi);
            } else if (dist[u] + v.se == dist[v.fi]) {
                cn[v.fi] += cn[u];
                cn[v.fi] %= mod;

                cn2[v.fi] += cn2[u];
                cn2[v.fi] %= mod2;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        adj[0][u[i]].emplace_back(v[i], w[i]);
        adj[1][v[i]].emplace_back(u[i], w[i]);
    }

    dijkstra(s, t, adj[0], dist[0], cn[0], cn2[0]);
    dijkstra(t, s, adj[1], dist[1], cn[1], cn2[1]);
    csp = cn[0][t];
    csp2 = cn2[0][t];
    mn = dist[0][t];

    for (int i = 0; i < m; i++) {
        if (dist[0][u[i]] + dist[1][v[i]] + w[i] == mn && (cn[0][u[i]] * cn[1][v[i]]) % mod == csp && (cn2[0][u[i]] * cn2[1][v[i]]) % mod2 == csp2) {
            cout << "YES" << endl;
        } else {
            ll d = dist[0][u[i]] + dist[1][v[i]] + w[i] - mn + 1;
            if (d < w[i])
                cout << "CAN" << " " << d << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}