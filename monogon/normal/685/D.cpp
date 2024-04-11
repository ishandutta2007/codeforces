
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

struct event {
    int x, y1, y2, d;
    bool operator<(const event &e) const {
        return x < e.x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n), vx, vy;
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
        vx.push_back(x[i]);
        vx.push_back(x[i] - k);
        vy.push_back(y[i]);
        vy.push_back(y[i] - k);
    }
    sort(all(vx));
    sort(all(vy));
    vx.erase(unique(all(vx)), vx.end());
    vy.erase(unique(all(vy)), vy.end());
    auto get = [&](const ll x, const vector<ll> &v) {
        return lower_bound(all(v), x) - v.begin();
    };
    vector<event> e;
    rep(i, 0, n) {
        int x1 = get(x[i] - k, vx);
        int y1 = get(y[i] - k, vy);
        int x2 = get(x[i], vx);
        int y2 = get(y[i], vy);
        e.push_back({x1, y1, y2, +1});
        e.push_back({x2, y1, y2, -1});
    }
    sort(all(e));
    vi sum(sz(vy), 0), px(sz(vy), -1);
    vector<vector<pii>> ve(sz(vy));
    vector<ll> ans(n + 1, 0);
    for(auto &ev : e) {
        rep(i, ev.y1, ev.y2) {
            if(sum[i] > 0) ans[sum[i]] += (vx[ev.x] - vx[px[i]]) * (vy[i + 1] - vy[i]);
            sum[i] += ev.d;
            px[i] = ev.x;
        }
    }

    rep(i, 1, n + 1) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}