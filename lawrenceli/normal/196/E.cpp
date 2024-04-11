#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <ios>
#include <cstring>

using namespace std;

#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 100100;
const ll inf = 1e18;

int n, m, k;
vector<pii> adj[maxn];
vector<pll> vadj[maxn];
bool por[maxn];

ll dist[maxn];
int near[maxn];
bool vis[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(pii(b, c));
        adj[b].push_back(pii(a, c));
    }

    priority_queue<pll, vector<pll>, greater<pll> > pq;
    cin >> k;
    for (int i = 1; i <= n; i++) dist[i] = inf;
    for (int i = 0; i < k; i++) {
        int p; cin >> p;
        por[p] = 1;
        pq.push(pll(0, p));
        near[p] = p;
        dist[p] = 0;
    }

    while (!pq.empty()) {
        ll d = pq.top().A;
        int x = pq.top().B;
        pq.pop();

        if (vis[x]) continue;
        vis[x] = 1;

        for (pii p : adj[x])
            if (d + p.B < dist[p.A])
                dist[p.A] = d + p.B, near[p.A] = near[x], pq.push(pll(d + p.B, p.A));
    }

    for (int i = 1; i <= n; i++)
        for (pii p : adj[i])
            if (near[i] != near[p.A])
                vadj[near[i]].push_back(pll(near[p.A], dist[i] + dist[p.A] + p.B));

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        if (por[i]) {
            pq.push(pll(0, i));
            break;
        }

    memset(vis, 0, sizeof(vis));
    while (!pq.empty()) {
        ll d = pq.top().A;
        int x = pq.top().B;

        pq.pop();

        if (vis[x]) continue;
        vis[x] = 1;
        ans += d;

        for (pll p : vadj[x])
            pq.push(pll(p.B, p.A));
    }

    cout << ans + dist[1] << '\n';
}