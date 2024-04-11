#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int t, n, a[N], dp[N][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0, lst = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] > lst) {
                ans++;
                lst = a[i];
            } else if (a[i] == lst) {
                ans++;
                lst = a[i] + 1;
            }
        }
        cout << ans << '\n';
    }
}