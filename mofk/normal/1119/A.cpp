#include <bits/stdc++.h>

using namespace std;

int n;
int a[300005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (a[i] != a[1]) ans = max(ans, i - 1);
    for (int i = 1; i <= n; ++i) if (a[i] != a[n]) ans = max(ans, n - i);
    cout << ans << endl;
    return 0;
}