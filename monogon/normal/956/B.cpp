
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
    ll u;
    cin >> n >> u;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    long double ans = -1;
    int k = 1;
    rep(i, 0, n - 2) {
        while(k + 1 < n && a[k + 1] - a[i] <= u) k++;
        if(k > i + 1) {
            ans = max(ans, (long double) (1.0 * (a[k] - a[i + 1])) / (a[k] - a[i]));
        }
    }
    if(ans < -0.5) {
        cout << "-1\n";
        return 0;
    }
    cout << fixed << setprecision(10);
    cout << ans << '\n';
}