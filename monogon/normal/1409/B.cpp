
#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

ll solve(ll a, ll b, ll x, ll y, ll n) {
    ll ti = min(n, a - x);
    a -= ti;
    n -= ti;
    ti = min(n, b - y);
    b -= ti;
    n -= ti;
    return a * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll ans = min(solve(a, b, x, y, n), solve(b, a, y, x, n));
        cout << ans << '\n';
    }
}