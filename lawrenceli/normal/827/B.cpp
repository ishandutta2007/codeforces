#include <bits/stdc++.h>

using namespace std;

int ans(int m, int k) {
    if (m == 1) return 2;
    else if (m == 2) return 3;
    else if (m <= k + 1) return 4;
    else return ans(m - k, k) + 2;
}

int n, k, last[200100];

int main() {
    cin >> n >> k;
    int m = n - k;
    cout << ans(m, k) << '\n';
    for (int i = 0; i < k; i++) last[i] = 1;
    for (int i = 2; i <= m + 1; i++) {
        cout << i << ' ' << last[i % k] << '\n';
        last[i % k] = i;
    }

    for (int i = m + 2; i <= n; i++)
        cout << i << ' ' << last[i % k] << '\n';
}