#include <bits/stdc++.h>
using namespace std;
int n, k;
long long x[5];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    x[4] = 9 * (1LL * n * (n - 1) * (n - 2) * (n - 3)) / 24;
    x[3] = 2 * (1LL * n * (n - 1) * (n - 2)) / 6;
    x[2] = 1 * (1LL * n * (n - 1)) / 2;
    x[1] = 1;
    long long ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += x[i];
    }
    cout << ans;
    return 0;
}