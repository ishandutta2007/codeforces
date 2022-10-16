#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[5005];
map <int, int> mp;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = k; j >= 0; --j) for (int i = 0; i < n; ++i) mp[a[i] * j] = j;
    int q; cin >> q;
    while (q--) {
        int m; cin >> m;
        int ans = k + 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (mp.find(m - a[i] * j) != mp.end()) ans = min(ans, j + mp[m - a[i] * j]);
            }
        }
        if (ans > k) ans = -1;
        cout << ans << '\n';
    }
}