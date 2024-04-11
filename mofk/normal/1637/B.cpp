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
        int ans = 0;
        for (int i = 0; i < n; ++i) ans += (a[i] == 0 ? 2 : 1) * (i + 1) * (n - i);
        cout << ans << '\n';
    }
    return 0;
}