#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        int ans = n + 1;
        int c0 = 0, c1 = 0;
        for (int i = 0; i < n; ++i) if (a[i] != b[i]) {
            if (a[i] == '0') ++c0;
            else ++c1;
        }
        if (c1 == c0) ans = min(ans, c1 + c0);

        c0 = 0, c1 = 0;
        for (int i = 0; i < n; ++i) if (a[i] == b[i]) {
            if (a[i] == '0') ++c0;
            else ++c1;
        }
        if (c1 == c0 + 1) ans = min(ans, c1 + c0);

        if (ans > n) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}