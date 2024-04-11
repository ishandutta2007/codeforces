
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
    pt operator-(const pt &o) const {
        return pt(x - o.x, y - o.y);
    }
    pt normalize() {
        if(x < 0 || (x == 0 && y < 0)) {
            x = -x;
            y = -y;
        }
        ll g = gcd(x, y);
        x /= g;
        y /= g;
        return *this;
    }
    bool operator<(const pt &o) const {
        return pair{x, y} < pair{o.x, o.y};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pt> p(n);
    rep(i, 0, n) {
        cin >> p[i].x >> p[i].y;
    }
    ll ans = 1LL * n * (n - 1) * (n - 2) / 6;
    rep(i, 0, n) {
        map<pt, int> cnt;
        rep(j, i + 1, n) {
            cnt[(p[i] - p[j]).normalize()]++;
        }
        for(auto &pa : cnt) {
            ll num = pa.second;
            ans -= num * (num - 1) / 2;
        }
    }
    cout << ans << '\n';
}