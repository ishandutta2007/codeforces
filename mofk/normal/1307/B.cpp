#include <bits/stdc++.h>

using namespace std;

int n, x;
int a[100005];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + 1 + n);
        int ans = 1e9 + 7;
        for (int i = 1; i <= n; ++i) if (x == a[i]) ans = 1;
        if (ans == 1) {
            cout << ans << '\n';
            continue;
        }
        int hops = x / a[n];
        if (hops <= 1) {
            cout << 2 << '\n';
            continue;
        }
        ans = hops + 1;
        x -= a[n] * (hops - 1);
        for (int i = 1; i <= n; ++i) if (x == a[i]) ans = hops;
        cout << ans << '\n';
    }
    return 0;
}