
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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    ll w;
    cin >> n >> m >> w;
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }
    auto encode = [&](int x, int y) {
        return m * x + y;
    };
    auto decode = [&](int idx) {
        return make_pair(idx / m, idx % m);
    };
    auto ins = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    };
    queue<int> Q;
    vector<int> vis(n * m, false);
    vector<ll> dis(n * m, LLONG_MAX), dis2(n * m, LLONG_MAX);

    vis[0] = true;
    dis[0] = 0;
    Q.push(0);
    while(!Q.empty()) {
        int idx = Q.front(); Q.pop();
        int x, y;
        tie(x, y) = decode(idx);
        rep(d, 0, 4) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            int e = encode(xx, yy);
            if(ins(xx, yy) && a[xx][yy] != -1 && !vis[e]) {
                Q.push(e);
                vis[e] = true;
                dis[e] = dis[idx] + w;
            }
        }
    }
    
    fill(all(vis), false);
    vis[encode(n - 1, m - 1)] = true;
    dis2[encode(n - 1, m - 1)] = 0;
    Q.push(encode(n - 1, m - 1));
    while(!Q.empty()) {
        int idx = Q.front(); Q.pop();
        int x, y;
        tie(x, y) = decode(idx);
        rep(d, 0, 4) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            int e = encode(xx, yy);
            if(ins(xx, yy) && a[xx][yy] != -1 && !vis[e]) {
                Q.push(e);
                vis[e] = true;
                dis2[e] = dis2[idx] + w;
            }
        }
    }

    ll ans = dis[encode(n - 1, m - 1)];
    ll A = LLONG_MAX, B = LLONG_MAX;
    rep(i, 0, n) rep(j, 0, m) {
        if(a[i][j] > 0) {
            if(dis[encode(i, j)] < LLONG_MAX) A = min(A, dis[encode(i, j)] + a[i][j]);
            if(dis2[encode(i, j)] < LLONG_MAX) B = min(B, dis2[encode(i, j)] + a[i][j]);
        }
    }
    if(A < LLONG_MAX && B < LLONG_MAX) ans = min(ans, A + B);

    cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}