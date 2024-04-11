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
        int ans = n - 1;
        for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
            vector<int> b(n);
            int d = a[j] - a[i];
            for (int k = 0; k < n; ++k) b[k] = a[i] * (j - i) + d * (k - i);
            int op = 0;
            for (int k = 0; k < n; ++k) if (a[k] * (j - i) != b[k]) ++op;
            ans = min(ans, op);
        }
        cout << ans << '\n';
    }
    return 0;
}