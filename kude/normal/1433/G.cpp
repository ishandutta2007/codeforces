#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,ll>;
using VI = vector<int>;
using VVI = vector<VI>;

const ll inf = 1002003004005006007LL;

vector<vector<ll>> compute_dist(int n, vector<vector<P>>& to) {
    vector<vector<ll>> dp(n, vector<ll>(n, inf));
    rep(s, n) {
        priority_queue<pair<ll,int>, vector<pair<ll,int>>,greater<pair<ll,int>>> q;
        q.emplace(0, s);
        dp[s][s] = 0;
        while(!q.empty()) {
            ll c;
            int u;
            tie(c, u) = q.top(); q.pop();
            if (c > dp[s][u]) continue;
            for(auto p: to[u]) {
                int v = p.first;
                ll nc = p.second + c;
                if (nc < dp[s][v]) {
                    dp[s][v] = nc;
                    q.emplace(nc, v);
                }
            }
        }
    }
    return dp;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<P>> to(n);
    rep(i, m) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x--; y--;
        to[x].emplace_back(y, w);
        to[y].emplace_back(x, w);
    }
    vector<vector<ll>> dist = compute_dist(n, to);
    vector<P> qs(k);
    rep(i, k) {
        cin >> qs[i].first >> qs[i].second;
        --qs[i].first;
        --qs[i].second;
    }
    ll ans = inf;
    rep(u, n) for(auto p: to[u]) {
        int v = p.first;
        ll now = 0;
        rep(i, k) {
            int a, b;
            tie(a, b) = qs[i];
            if (a == b) continue;
            ll toAdd = min(dist[a][u] + dist[v][b], dist[a][v] + dist[u][b]);
            chmin(toAdd, dist[a][b]);
            if (a == u) chmin(toAdd, dist[v][b]);
            if (a == v) chmin(toAdd, dist[u][b]);
            if (b == u) chmin(toAdd, dist[a][v]);
            if (b == v) chmin(toAdd, dist[a][u]);
            now += toAdd;
        }
        chmin(ans, now);
    }
    cout << ans << endl;
}