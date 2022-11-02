#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, L;
    cin >> n >> k >> L;

    int l = 0, r = 2*k;

    string ans = "Yes";

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d; 

        if (d > L) {
            ans = "No";
            continue;
        }

        int xl = max(0, k - (L - d));
        int xr = min(2*k, k + (L - d) + 1);

        if( l == 0 && r == 2*k )
            l = xl, r = xr;
        else if( xl == 0 && xr == 2*k )
            l = xl, r = xr; 
        else {
            l = max(l+1, xl);
            r = min(min(2*k, r+1), xr);
        }

        if (l >= r) {
            ans = "No";
            continue;
        }

    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int t;
    cin >> t;
    while(t--)
        solve();
}