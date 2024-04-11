#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005], b[100005], c[100005];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i], c[b[i]] = i;
    int ans = 0, mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (c[a[i]] < mx) ++ans;
        mx = max(mx, c[a[i]]);
    }
    cout << ans << endl;
    return 0;
}