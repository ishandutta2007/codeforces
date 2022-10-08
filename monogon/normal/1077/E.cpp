
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// if x is the number of problems in the first contest
// then x * (1 + 2 + ... + 2^d) problems
// 2^(d + 1) - 1 problems
// so, number of contests is only O(n)

const int N = 2e5 + 5;
int n;
ll a[N];
map<ll, int> ma;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        ma[a[i]]++;
    }
    vector<pair<ll, int>> ve(all(ma));
    for(auto &p : ve) {
        p = {p.se, p.fi};
    }
    sort(ve.rbegin(), ve.rend());
    ll ans = 0;
    for(int d = 1; d < 20 && d <= sz(ve); d++) {
        ll x = 1e9;
        rep(i, 0, d) {
            x = min(x, ve[i].fi / (1LL << (d - i - 1)));
        }
        ans = max(ans, x * ((1LL << d) - 1));
    }
    cout << ans << '\n';
}