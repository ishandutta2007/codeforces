#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, x, y;
        long long ans = 0;
        cin >> n >> x;
        for (int i = 1; i < n; ++i) {
            cin >> y;
            if (y < x) ans += x - y;
            x = y;
        }
        cout << ans << endl;
    }
    return 0;
}