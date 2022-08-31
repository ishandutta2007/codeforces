#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 10;
int n;
int a[maxN];
int k;
bool check(ll x) {
    int need = (n + 1) / 2;
    ll tot = 0;
    for (int i = 1; i <= need; i++) {
        if (a[i] >= x) continue;
        tot += x - a[i];
        if (tot > k) return false;
    }
    return tot <= k;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    ll l = 0;
    ll r = 1e15 + 10;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}