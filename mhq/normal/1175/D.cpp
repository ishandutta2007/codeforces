#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = 3 * (int)1e5 + 100;
ll pref[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> pref[i];
        pref[i] += pref[i - 1];
    }
    ll ans = k * pref[n];
    sort(pref + 1, pref + (n - 1) + 1);
    for (int i = 1; i <= k - 1; i++) ans -= pref[i];
    cout << ans;
    return 0;
}