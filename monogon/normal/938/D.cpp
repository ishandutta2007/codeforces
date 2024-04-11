
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
int n, m, u[N], v[N];
ll w[N], a[N], dist[N];
using edge = pair<ll, int>;
vector<edge> adj[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        cin >> u[i] >> v[i] >> w[i];
        adj[u[i]].emplace_back(2 * w[i], v[i]);
        adj[v[i]].emplace_back(2 * w[i], u[i]);
    }
    rep(i, 1, n + 1) {
        cin >> a[i];
        adj[0].emplace_back(a[i], i);
    }
    minpq<edge> Q;
    dist[0] = 0;
    fill(dist + 1, dist + n + 1, LLONG_MAX);
    Q.emplace(0, 0);
    while(!Q.empty()) {
        ll d;
        int x;
        tie(d, x) = Q.top(); Q.pop();
        if(d != dist[x]) continue;
        for(edge &e : adj[x]) {
            ll w;
            int y;
            tie(w, y) = e;
            if(d + w < dist[y]) {
                dist[y] = d + w;
                Q.emplace(dist[y], y);
            }
        }
    }
    rep(i, 1, n + 1) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}