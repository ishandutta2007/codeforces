#include <bits/stdc++.h>
using namespace std;

int n, k;
long long ans = 0, a[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int cnt = n / k;
        if ((i + k - 1) % k < n % k) {
            cnt++;
        }
        a[1LL * i * i % k] += cnt;
    }
    for (int i = 0; i < k; i++) {
        ans += 1LL * a[i] * a[(k - i) % k];
    }
    cout << ans;
}