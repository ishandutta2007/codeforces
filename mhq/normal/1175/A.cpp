#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        while (n) {
            ans += (n % k);
            if (n >= k) {
                ans++;
            }
            n /= k;
        }
        cout << ans << '\n';
    }
    return 0;
}