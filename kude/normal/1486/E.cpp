#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> to(n);
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        to[u].emplace_back(v, w);
        to[v].emplace_back(u, w);
    }
    constexpr int INF = 1001001001;
    VVI dist(51, VI(n, INF));
    auto my_cmp = [](tuple<ll, int, int>& x, tuple<ll, int, int>& y) {return get<0>(x) > get<0>(y);};
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, decltype(my_cmp)> q(my_cmp);
    auto push = [&](int u, int w, int cost) {
        if (cost < dist[w][u]) {
            dist[w][u] = cost;
            q.emplace(cost, u, w);
        }
    };
    push(0, 0, 0);
    while(!q.empty()) {
        auto [cost, u, last_w] = q.top(); q.pop();
        if (cost != dist[last_w][u]) continue;
        for(auto [v, w]: to[u]) {
            if (last_w) {
                int ws = last_w + w;
                push(v, 0, cost + ws * ws);
            } else {
                push(v, w, cost);
            }
        }
    }
    rep(i, n) {
        int d = dist[0][i];
        if (d == INF) d = -1;
        cout << d << " \n"[i + 1 == n];
    }
}