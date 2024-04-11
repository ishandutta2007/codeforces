#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

void solve() {
    ll n;
    cin >> n;
    ll c = n-1;
    vector<int> x, y;
    int ans = 0;
    while (n>2) {
        while (ceil((double)ceil((double)n/(c-1))/(c-1))<=1) {
            x.pb(c);
            y.pb(n);
            ans++;
            c--;
        }
        x.pb(n); y.pb(c); x.pb(n); y.pb(c);
        n = c;
        c--;
        ans += 2;
    }
    cout << ans << endl;
    for (int i = 0; i < ans; i++) {
        cout << x[i] << " " << y[i] << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}