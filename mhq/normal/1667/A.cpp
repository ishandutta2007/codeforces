#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5005;
ll a[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll best = 1e18;
    for (int i = 1; i <= n; i++){
        ll prv = 0;
        ll cur = 0;
        for (int j = i - 1; j >= 1; j--) {
            prv = ((prv / a[j])  + 1) * a[j];
            cur += (prv / a[j]);
        }
        prv = 0;
        for (int j = i + 1; j <= n; j++) {
            prv = ((prv / a[j])  + 1) * a[j];
            cur += (prv / a[j]);
        }
        best = min(best, cur);
    }
    cout << best << '\n';
    return 0;
}