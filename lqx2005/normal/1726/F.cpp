#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define sz(a) int((a).size())
#define ll long long
#define db double
#define vi vector<int>
using namespace std;
const int N = 2e5 + 10;
int n;
ll t, g[N], c[N], l[N], r[N], d[N];
set<pair<ll, ll>> ans;
ll s = 0, delta = 0;
// ?????
void del(ll l, ll r) {
    // cout << l <<" " << r << endl;
    ll mn = 1e18;
    if(l > r) {
        auto itl = ans.lower_bound({r, -1}), itr = ans.lower_bound({l, -1});
        for(auto it = itl; it != itr; it++) mn = min(mn, it -> second + (l - it -> first + t) % t + delta);
        ans.erase(itl, itr);
        if(mn < 1e18) ans.insert({l, mn - delta});
    } else {
        auto itl = ans.lower_bound({r, -1}), itr = ans.lower_bound({l, -1});
        for(auto it = itl; it != ans.end(); it++) mn = min(mn, it -> second + (l - it -> first + t) % t + delta);
        for(auto it = ans.begin(); it != itr; it++) mn = min(mn, it -> second + (l - it -> first + t) % t + delta);
        ans.erase(ans.begin(), itr);
        ans.erase(itl, ans.end());
        if(mn < 1e18) ans.insert({l, mn - delta});
    }
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> t;
    FOR(i, 1, n) cin >> g[i] >> c[i], l[i] = (t - c[i]) % t, r[i] = (t - c[i] + g[i]) % t;
    FOR(i, 1, n - 1) cin >> d[i];
    s = 0;
    FOR(i, 1, n) {
        ans.insert({(l[i] + s) % t, 0});
        ans.insert({(r[i] + s + t - 1) % t, 0});
        s = (s - d[i] % t + t) % t;
    }
    s = 0;
    del(l[1], r[1]);
    FOR(i, 1, n - 1) {
        s = (s - d[i] % t + t) % t;
        delta += d[i];
        int l = ::l[i + 1], r = ::r[i + 1];
        l = (l + s) % t, r = (r + s) % t;
        del(l, r);
    }
    ll res = 1e18;
    for(auto p : ans) res = min(res, p.second + delta);
    cout << res << "\n";
}