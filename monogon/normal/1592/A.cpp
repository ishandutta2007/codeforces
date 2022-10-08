
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x).size())
#define rep(i, a, b) for(int i = (a); i < (b); i++)

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; ll h;
    cin >> n >> h;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end(), greater<>());
    ll ans = max(0LL, min(2 * ((h + a[0] + a[1] - 1) / (a[0] + a[1])), 1 + 2 * ((h + a[1] - 1) / (a[0] + a[1]))));
    cout << ans << '\n';
}

int main() {
    int te;
    cin >> te;
    while(te--) solve();
}