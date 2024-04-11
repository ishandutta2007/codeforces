#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)2e6;
int n;
ll f[maxN];
const int SHIFT = (int)1e6;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        f[i - x + SHIFT] += x;
        ans = max(ans, f[i - x + SHIFT]);
    }
    cout << ans;
    return 0;
}