
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

void solve() {
    ll W, H, x1, y1, x2, y2, w1, h1, w2, h2;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w2 >> h2;
    w1 = x2 - x1;
    h1 = y2 - y1;
    auto check = [&](ll x2, ll y2) {
        ll left = min(x1, x2 - w1), right = max(x1, x2 + w2);
        ll up = min(y1, y2 - h1), down = max(y1, y2 + h2);
        ll ans = LLONG_MAX;
        if(left >= 0) ans = min(ans, x1 - left);
        if(up >= 0) ans = min(ans, y1 - up);
        if(right + w1 <= W) ans = min(ans, right - x1);
        if(down + h1 <= H) ans = min(ans, down - y1);
        return ans;
    };
    ll ans = min({check(0, 0), check(W - w2, 0), check(0, H - h2), check(W - w2, H - h2)});
    if(ans == LLONG_MAX) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}