#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define db double
#define x first
#define y second
#define vi vector<int>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> sum;
    FOR(i, 0, n - 1) {
        ll res = 0;
        FOR(j, 0, m - 1) {
            ll x;
            cin >> x;
            res += x * j;
        }
        sum.emplace_back(res);
    }
    ll mx = sum[0], mn = sum[0];
    FOR(i, 1, n - 1) mx = max(mx, sum[i]), mn = min(mn, sum[i]);
    FOR(i, 0, n - 1) if(sum[i] == mx) cout << i + 1 << " ";
    cout << mx - mn << "\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}