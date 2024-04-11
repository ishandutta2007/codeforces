
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

const int N = 1e5 + 5;
ll n;
int m;
ll x[N], y[N];

// 0, .. m - 1 points
// m = start, m + 1 = finish

using edge = pair<ll, int>;
vector<edge> adj[N];
ll dist[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x[m] >> y[m] >> x[m + 1] >> y[m + 1];
    vector<pii> vx, vy;
    // vx.emplace_back(x[m], m);
    // vx.emplace_back(x[m + 1], m + 1);
    // vy.emplace_back(y[m], m);
    // vy.emplace_back(y[m + 1], m + 1);
    rep(i, 0, m) {
        cin >> x[i] >> y[i];
        vx.emplace_back(x[i], i);
        vy.emplace_back(y[i], i);
    }
    sort(all(vx));
    sort(all(vy));
    rep(i, 1, sz(vx)) {
        int idx = vx[i - 1].second;
        int jdx = vx[i].second;
        ll dx = vx[i].first - vx[i - 1].first;
        adj[idx].emplace_back(dx, jdx);
        adj[jdx].emplace_back(dx, idx);
    }
    rep(i, 1, sz(vy)) {
        int idx = vy[i - 1].second;
        int jdx = vy[i].second;
        ll dy = vy[i].first - vy[i - 1].first;
        adj[idx].emplace_back(dy, jdx);
        adj[jdx].emplace_back(dy, idx);
    }
    rep(i, 0, m) {
        adj[m].emplace_back(min(abs(x[i] - x[m]), abs(y[i] - y[m])), i);
        adj[i].emplace_back(abs(x[i] - x[m + 1]) + abs(y[i] - y[m + 1]), m + 1);
    }
    adj[m].emplace_back(abs(x[m] - x[m + 1]) + abs(y[m] - y[m + 1]), m + 1);
    minpq<edge> Q;
    Q.emplace(0, m);
    fill(dist, dist + N, LLONG_MAX);
    dist[m] = 0;
    while(!Q.empty()) {
        ll d;
        int i;
        tie(d, i) = Q.top(); Q.pop();
        if(i == m + 1) {
            cout << d << '\n';
            return 0;
        }
        if(d != dist[i]) continue;
        for(auto e : adj[i]) {
            ll w;
            int j;
            tie(w, j) = e;
            if(d + w < dist[j]) {
                dist[j] = d + w;
                Q.emplace(dist[j], j);
            }
        }
    }
    assert(false);
}