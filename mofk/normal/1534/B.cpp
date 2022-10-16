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
        n += 2;
        vector<long long> a(n);
        for (int i = 1; i < n - 1; ++i) cin >> a[i];
        long long ans = 0;
        for (int i = 1; i < n; ++i) ans += abs(a[i] - a[i-1]);
        for (int i = 1; i < n - 1; ++i) if (a[i] > a[i-1] && a[i] > a[i+1]) ans -= a[i] - max(a[i-1], a[i+1]);
        cout << ans << endl;
    }
    return 0;
}