#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
ll ans = 0;
const int maxN = 3 * (int)1e5 + 100;
ll a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll le = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ll cur = min(a[i] / 2, le);
        le -= cur;
        ans += cur;
        a[i] -= 2 * cur;
        ans += a[i] / 3;
        le += a[i] % 3;
    }
    cout << ans;
    return 0;
}