#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        long long ans = 0, m = 1, s = 0;
        for (int i = 0; i < n; ++i) while (a[i] % 2 == 0) a[i] /= 2, m *= 2;
        for (int i = 0; i < n; ++i) s += a[i];
        for (int i = 0; i < n; ++i) ans = max(ans, s - a[i] + a[i] * m);
        cout << ans << '\n';
    }
    return 0;
}