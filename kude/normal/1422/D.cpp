#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

struct iml {
    int i, x, y;
};

int distance_(int x, int y, iml t) {
    return min(abs(x - t.x), abs(y - t.y));
}

int main() {
    int n, m;
    cin >> n >> m;
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    vector<iml> a(m);
    rep(i, m) {
        a[i].i = i;
        cin >> a[i].x >> a[i].y;
    }
    const int INF = 2001001001;
    VI dp(m, 2001001001);
    priority_queue<P, vector<P>, greater<P>> q;
    rep(i, m) {
        q.emplace(distance_(sx, sy, a[i]), i);
        dp[i] = distance_(sx, sy, a[i]);
    }
    set<P> xset, yset;
    rep(i, m) {
        xset.emplace(a[i].x, i);
        yset.emplace(a[i].y, i);
    }
    while(!q.empty()) {
        auto p = q.top(); q.pop();
        int u = p.second;
        int cost = p.first;
        if (dp[u] > cost) continue;
        int x = a[u].x, y = a[u].y;
        {
            auto it = xset.lower_bound({x, u});
            auto it2 = it;
            it2++;
            if (it2 != xset.end()) {
                int v = it2->second;
                ll ncost = cost + a[v].x - x;
                if (ncost < dp[v]) {
                    dp[v] = ncost;
                    q.emplace(ncost, v);
                }
            }
            if (it != xset.begin()) {
                it--;
                int v = it->second;
                ll ncost = cost + x - a[v].x;
                if (ncost < dp[v]) {
                    dp[v] = ncost;
                    q.emplace(ncost, v);
                }
            }
        }
        {
            auto it = yset.lower_bound({y, u});
            auto it2 = it;
            it2++;
            if (it2 != yset.end()) {
                int v = it2->second;
                ll ncost = cost + a[v].y - y;
                if (ncost < dp[v]) {
                    dp[v] = ncost;
                    q.emplace(ncost, v);
                }
            }
            if (it != yset.begin()) {
                it--;
                int v = it->second;
                ll ncost = cost + y - a[v].y;
                if (ncost < dp[v]) {
                    dp[v] = ncost;
                    q.emplace(ncost, v);
                }
            }
        }
    }
    ll ans = abs(sx - fx) + abs(sy - fy);
    //rep(i, m) cout << i << ' ' << dp[i] << endl;
    rep(i, m) chmin(ans, ll(dp[i]) + abs(a[i].x - fx) + abs(a[i].y - fy));
    cout << ans << endl;
}