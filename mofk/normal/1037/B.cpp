#include <bits/stdc++.h>

using namespace std;

int n, s;
int a[200005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int m = (n + 1) / 2;
    long long ans = 0;
    if (a[m] < s) {
        for (int i = m; i <= n; ++i) ans += max(0, s - a[i]);
    }
    else {
        for (int i = 1; i <= m; ++i) ans += max(0, a[i] - s);
    }
    cout << ans << endl;
    return 0;
}