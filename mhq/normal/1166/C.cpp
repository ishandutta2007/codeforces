#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int a[maxN];
int n;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    sort(a + 1, a + n + 1);
    int l = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        while (2 * a[l] < a[i]) l++;
        ans += (i - l);
    }
    cout << ans;
    return 0;
}