#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve() {
    int n;
    ll k, c, lo, hi;
    cin >> n >> k;
    bool works = true;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (works) {
            if (i==0) {
                lo=c;
                hi=c;
            } else {
                lo = max(lo-k+1, c);
                hi = min(hi+k-1, c+k-1);
                if (lo>hi) works=false;
            }
        }
    }
    if ((!works) || lo != c) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}