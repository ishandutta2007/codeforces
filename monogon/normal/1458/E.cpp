
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

struct line {
    ll x, y, len;
    bool operator<(const line &o) const {
        return x < o.x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> vx, vy;
    set<pair<ll, ll>> se;
    rep(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        vx.push_back({a, b});
        vy.push_back({b, a});
        se.insert({a, b});
    }
    sort(all(vx));
    sort(all(vy));
    ll x = 0, y = 0;
    int idx = 0, idy = 0;
    minpq<ll> Qx, Qy;
    vector<line> ve;
    while(true) {
        ll ti = LLONG_MAX;
        int ty = -1;
        if(!Qx.empty()) {
            ll x2 = Qx.top();
            if(x2 - x < ti) {
                ti = x2 - x;
                ty = 0;
            }
        }
        if(!Qy.empty()) {
            ll y2 = Qy.top();
            if(y2 - y < ti) {
                ti = y2 - y;
                ty = 1;
            }
        }
        if(idx < sz(vx)) {
            ll x2 = vx[idx].first;
            if(x2 - x < ti) {
                ti = x2 - x;
                ty = 2;
            }
        }
        if(idy < sz(vy)) {
            ll y2 = vy[idy].first;
            if(y2 - y < ti) {
                ti = y2 - y;
                ty = 3;
            }
        }
        if(ty == -1) {
            ve.push_back({x, y, LLONG_MAX});
            break;
        }
        switch(ty) {
        case 0: {
            // line at x2
            ll x2 = Qx.top(); Qx.pop();
            if(x2 >= x) {
                ve.push_back({x, y, ti});
                x += ti + 1;
                y += ti;
            }
            break;
        }
        case 1: {
            // line at y2
            ll y2 = Qy.top(); Qy.pop();
            if(y2 >= y) {
                ve.push_back({x, y, ti});
                x += ti;
                y += ti + 1;
            }
            break;
        }
        case 2:
            Qy.push(vx[idx].second);
            idx++;
            break;
        case 3:
            Qx.push(vy[idy].second);
            idy++;
            break;
        }
    }
    while(m--) {
        ll a, b;
        cin >> a >> b;
        if(se.count({a, b})) {
            cout << "LOSE\n";
            continue;
        }
        line L = {a, -1, -1};
        int i = upper_bound(all(ve), L) - ve.begin() - 1;
        if(a - ve[i].x < ve[i].len && a - ve[i].x == b - ve[i].y) {
            cout << "LOSE\n";
        }else {
            cout << "WIN\n";
        }
    }
}