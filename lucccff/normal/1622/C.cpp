#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t;
    long long k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        long long s = 0, x, mn = 2e9;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        sort(a, a + n);
        for(int i = 0; i < n; i++) {
            x = s;
            mn = min(mn, max(0ll, (x - k + i) / (i + 1)) + i);
            s -= a[n - i - 1] - a[0];
        }
        cout << mn << endl;
    }
}