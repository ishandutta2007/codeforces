
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 2e5 + 5;
int n, m, k;
ll ta, tb;

// it's best to cancel the earliest flights
// (unless it's possible to prevent the trip altogether).
// Substitution argument proves this.
// We must cancel j flights from A to B and k-j flights from B to C.
// test each one in O(k) time to see if one of them makes it
// impossible or choose the maximum earliest arrival

int main() {
    cin >> n >> m >> ta >> tb >> k;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    if(k >= n || k >= m) {
        cout << -1 << endl;
        return 0;
    }
    ll best = -1;
    for(int j = max(0, k - m + 1); j < n && j <= k; j++) {
        auto it = upper_bound(b.begin(), b.end(), a[j] + ta - 1);
        if(b.end() - it <= k - j) {
            cout << -1 << endl;
            return 0;
        }else {
            best = max(best, *(it + k - j) + tb);
        }
    }
    cout << best << endl;
}