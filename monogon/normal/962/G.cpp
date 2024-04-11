
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

const int N = 15005;
ll X1, X2, Y1, Y2;
int n;
ll x[N], y[N];

struct event {
    ll x, y1, y2;
    bool wall;
    event(ll x, ll y1, ll y2, bool wall = false) : x(x), y1(y1), y2(y2), wall(wall) {}
    bool operator<(const event &o) const {
        if(x == o.x) return !wall;
        return x < o.x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> X1 >> Y1 >> X2 >> Y2 >> n;
    if(X1 > X2) swap(X1, X2);
    if(Y1 > Y2) swap(Y1, Y2);
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
    }
    vector<event> ve;
    rep(i, 0, n) {
        int j = (i + 1) % n;
        if(x[i] != x[j]) continue;
        ve.emplace_back(x[i], y[i], y[j]);
    }
    ve.emplace_back(X1, Y1, Y2, true);
    ve.emplace_back(X2, Y1, Y2, true);
    sort(all(ve));
    set<ll> se;
    ll ans = 0;
    auto upd = [&](int i) {
        if(se.count(i)) se.erase(i);
        else se.insert(i);
    };
    for(event &e : ve) {
        if(e.wall) {
            if(e.x == X1) {
                ans = sz(se) / 2;
                continue;
            }else break;
        }
        if(min(e.y1, e.y2) >= Y2 || max(e.y1, e.y2) <= Y1) continue;
        int s = sz(se) / 2;
        upd(clamp(e.y1, Y1, Y2));
        upd(clamp(e.y2, Y1, Y2));
        int s2 = sz(se) / 2;
        if(e.x >= X1 && e.x < X2) {
            if(e.y1 > e.y2 && s2 > s) ans++;
            if(e.y1 > e.y2 && s2 < s) ans--;
        }
        // else if(e.y1 > e.y2 && s2 < s) ans--;
        // if(e.x >= X1 && e.x < X2) {
        //     ans += max(0, s2 - s);
        // }
    }
    cout << ans << '\n';
}