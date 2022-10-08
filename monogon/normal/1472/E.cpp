
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
    int i;
    pt(ll x, ll y, int i) : x(x), y(y), i(i) {}
    bool operator<(const pt &o) const {
        if(x == o.x) return y > o.y;
        return x < o.x;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pt> ve;
    rep(i, 0, n) {
        ll w, h;
        cin >> w >> h;
        ve.push_back(pt(w, h, i));
        ve.push_back(pt(h, w, i));
    }
    vi ans(n, -2);
    sort(all(ve));
    pt bestpt(2e9, 2e9, -2);
    for(pt &p : ve) {
        if(bestpt.y < p.y) {
            ans[p.i] = bestpt.i;
        }
        if(p.y < bestpt.y) {
            bestpt = p;
        }
    }

    rep(i, 0, n) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}