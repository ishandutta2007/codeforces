#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        vector<int> c(n + 1);
        for (int i = 0; i < n; ++i) c[a[i]] = b[i];
        int ans = 1;
        for (int i = 1; i <= n; ++i) if (c[i]) {
            ans = ans * 2 % mod;
            int u = c[i]; c[i] = 0;
            while (u != i) {
                int v = c[u];
                c[u] = 0;
                u = v;
            }
        }
        cout << ans << endl;
    }
    return 0;
}