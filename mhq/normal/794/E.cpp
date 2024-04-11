#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 100;
int a[maxN];
int n;
int ans[maxN];
int val[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        val[i] = min(a[i], a[i + 1]);
    }
    // n % 2 == k % 2
    for (int i = n % 2; i <= n - 1; i += 2) {
        if (i > 1) ans[i] = ans[i - 2];
        if (n % 2 == 0) {
            ans[i] = max({ans[i], a[(n / 2 - i / 2)], a[(n / 2 + 1 + i / 2)]});
        }
        else {
            ans[i] = max(ans[i], a[(n + 1) / 2]);
            ans[i] = max({ans[i], a[(n + 1) / 2 - (i + 1) / 2], a[(n + 1) / 2 + (i + 1) / 2]});
        }
    }
    // n % 2 != k % 2
    n--;
    for (int i = n % 2; i <= n; i += 2) {
        if (i > 1) ans[i] = ans[i - 2];
        if (n % 2 == 0) {
            ans[i] = max({ans[i], val[(n / 2 - i / 2)], val[(n / 2 + 1 + i / 2)]});
        }
        else {
            ans[i] = max(ans[i], val[(n + 1) / 2]);
            ans[i] = max({ans[i], val[(n + 1) / 2 - (i + 1) / 2], val[(n + 1) / 2 + (i + 1) / 2]});
        }
    }
    for (int i = 1; i <= n + 1; i++) {
        ans[n] = max(ans[n], a[i]);
    }
    for (int i = 0; i <= n; i++) cout << ans[i] << " ";
    return 0;
}