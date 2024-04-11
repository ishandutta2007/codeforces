
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll a[3], n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a[0] >> a[1] >> a[2] >> n;
        sort(a, a + 3);
        ll m = n - (a[2] - a[0]) - (a[2] - a[1]);
        cout << (m >= 0 && m % 3 == 0 ? "YES" : "NO") << endl;
    }
}