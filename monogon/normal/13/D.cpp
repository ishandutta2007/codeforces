
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

// choose base uv
// sort all points by angle to u
// blue event: gives limit on where the third point can be
// red event: check with limit, if OK add the triangle to the count

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    pt operator-(const pt &o) const {
        return pt(x - o.x, y - o.y);
    }
    ll cross(const pt &o) const {
        return x * o.y - y * o.x;
    }
    bool upper() const {
        return y > 0 || (y == 0 && x > 0);
    }
    bool operator<(const pt &o) const {
        if(upper() != o.upper()) return upper();
        return cross(o) > 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pt> r(n), b(m);
    rep(i, 0, n) cin >> r[i].x >> r[i].y;
    rep(i, 0, m) cin >> b[i].x >> b[i].y;
    ll cnt = 0;
    rep(i, 0, n) {
        vector<pair<pt, bool>> ve;
        rep(j, i + 1, n) ve.push_back({r[j] - r[i], true});
        rep(j, 0, m) ve.push_back({b[j] - r[i], false});
        sort(all(ve));
        int si = sz(ve);
        rep(j, 0, si) {
            if(ve[j].second) {
                pt base = ve[j].first, blue = base;
                for(int k = (j + 1) % si; k != j; k = (k + 1) % si) {
                    if(base.cross(ve[k].first) < 0) break;
                    if(ve[k].second) {
                        if(blue.cross(ve[k].first - base) > 0) cnt++;
                    }else if(blue.cross(ve[k].first - base) > 0) {
                        blue = ve[k].first - base;
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
}