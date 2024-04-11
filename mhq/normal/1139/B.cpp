#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int a[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ans = a[n];
    int lim = a[n];
    for (int i = n - 1; i >= 1; i--) {
        int nlim = max(0, min(a[i], lim - 1));
        ans += nlim;
        lim = nlim;
    }
    cout << ans;
    return 0;
}