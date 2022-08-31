#include <bits/stdc++.h>
using namespace std;
int n;
long long k, x;
long long a[(int)1e5 + 5];
long long b[(int)1e5 + 5];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = -a[i];
    }
    long long ans = 0;
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        int l = lower_bound(a, a + n, max(x * ((a[i] + x - 1) / x) + (k - 1) * x, a[i])) - a;
        //cout << l << " ";
        int r = upper_bound(b, b + n, (-1 * (x * ((a[i] + x - 1) / x) + (k) * x))) - b;
        //cout << r << " " << '\n';
        ans += max(n - r - l, 0);
     }
    cout << ans;
    return 0;
}