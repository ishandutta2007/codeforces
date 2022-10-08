
#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), v(n);
    rep(i, 0, n) cin >> a[i];
    ll mx = -1e9;
    for(int i = n - 1; i >= 0; i--) {
        mx = max(mx - 1, a[i] + 1);
        v[i] = mx;
    }
    ll sum = 0;
    rep(i, 0, n) {
        if(i > 0) v[i] = max(v[i], v[i - 1]);
        sum += v[i] - a[i] - 1;
    }
    cout << sum << '\n';
}