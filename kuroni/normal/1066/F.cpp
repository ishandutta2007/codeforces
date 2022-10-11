#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, x, y;
long long ans = 0, f[2][2];
pair<int, int> le = {0, 0}, ri = {0, 0};
map<int, vector<pair<int, int>>> ma;

long long distance(pair<int, int> x, pair<int, int> y) {
    return abs(x.fi - y.fi) + abs(x.se - y.se);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        ma[max(x, y)].push_back({x, y});
    }
    int cur = 0;
    for (pair<int, vector<pair<int, int>>> u : ma) {
        cur ^= 1;
        vector<pair<int, int>> &ve = u.second;
        pair<int, int> mi = {0, 0}, mx = {0, 0};
        for (pair<int, int> &v : ve) {
            if ((mi.fi == 0 && mi.se == 0) || (v.se > mi.se || (v.se == mi.se && v.fi < mi.fi))) {
                mi = v;
            }
            if ((mx.fi == 0 && mx.se == 0) || (v.se < mx.se || (v.se == mx.se && v.fi > mx.fi))) {
                mx = v;
            }
        }
        ans += distance(mi, mx);
        f[cur][0] = min(f[cur ^ 1][0] + distance(le, mx), f[cur ^ 1][1] + distance(ri, mx));
        f[cur][1] = min(f[cur ^ 1][0] + distance(le, mi), f[cur ^ 1][1] + distance(ri, mi));
        le = mi;
        ri = mx;
        // cout << u.fi << ": " << "(" << mi.fi << " " << mi.se << ") (" << mx.fi << " " << mx.se << ") -> " << f[cur][0] << " " << f[cur][1] << '\n';
    }
    cout << ans + min(f[cur][0], f[cur][1]);
}