#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 5;

int n, m, k, dp[N], a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long su = 0;
    for (int pt = n, i = n; i >= 1; i--) {
        su += a[i];
        while (su > k) {
            su -= a[pt--];
        }
        dp[i] = dp[pt + 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i] <= m) {
            return cout << n - i + 1, 0;
        }
    }
}