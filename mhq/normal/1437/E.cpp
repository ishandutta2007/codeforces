#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = 5e5 + 12;
int a[maxN];
int b[maxN];
int d[maxN];
int solve(int l, int r) {
    if (a[l] > a[r]) {
        cout << -1;
        exit(0);
    }
    int ans = 0;
    int len = r - l + 1;
    d[0] = -1e9 - 228;
    for (int i = 1; i <= len + 1; i++) {
        d[i] = 1e9 + 228;
    }
    for (int j = l + 1; j <= r - 1; j++) {
        if (a[j] < a[l] || a[j] > a[r]) {
            ans++;
        }
        else {
            ans++;
            int pos = upper_bound(d, d + len + 1, a[j]) - d;
            d[pos] = a[j];
        }
    }
    for (int i = 0; i <= len + 1; i++) {
        if (d[i] > 1e9 + 10) return ans - i + 1;
    }
    assert(false);
    return -228;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }
    a[0] = -1e9;
    a[n + 1] = 1e9 + 10;
    b[0] = 0;
    b[k + 1] = n + 1;
    for (int i = 0; i <= k; i++) {
        ans += solve(b[i], b[i + 1]);
    }
    cout << ans;
    return 0;
}