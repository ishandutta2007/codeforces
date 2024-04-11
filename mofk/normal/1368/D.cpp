#include <bits/stdc++.h>

using namespace std;

int n;
int a[200005];
int b[25];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) for (int j = 0; j < 20; ++j) if (a[i] >> j & 1) ++b[j];
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x = 0;
        for (int j = 0; j < 20; ++j) if (b[j] >= i) x += (1 << j);
        ans += 1ll * x * x;
    }
    cout << ans << endl;
    return 0;
}