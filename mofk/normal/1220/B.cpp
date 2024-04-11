#include <bits/stdc++.h>

using namespace std;

int n;
long long a[1005][1005];
long long ans[1005];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> a[i][j];
    ans[1] = sqrt(a[1][2] * a[1][3] / a[2][3]);
    for (int i = 2; i <= n; ++i) ans[i] = a[1][i] / ans[1];
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}