
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

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    ll dot(const pt &o) const {
        return x * o.x + y * o.y;
    }
    ll cross(const pt &o) const {
        return x * o.y - y * o.x;
    }
    bool upper() const {
        return y > 0 || (y == 0 && x > 0);
    }
    bool operator<(const pt &o) const {
        bool b1 = upper(), b2 = o.upper();
        if(b1 != b2) return b1;
        return cross(o) > 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pt> p(n);
    vector<pair<pt, int>> ve;
    rep(i, 0, n) {
        cin >> p[i].x >> p[i].y;
        ve.push_back({p[i], i + 1});
    }
    sort(all(ve));
    pt best;
    pii idx = {-1, -1};
    rep(i, 0, n) {
        int j = (i + 1) % n;
        pt P(ve[i].first.dot(ve[j].first), ve[i].first.cross(ve[j].first));
        if(idx.first == -1 || P < best) {
            best = P;
            idx = {ve[i].second, ve[j].second};
        }
    }
    cout << idx.first << ' ' << idx.second << '\n';
}