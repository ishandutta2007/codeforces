#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, x, y, ans;
        cin >> n >> x;
        ans = n;
        for (int i = 1; i < n; ++i) {
            cin >> y;
            if (y != x) ans = 1;
        }
        cout << ans << endl;
    }
    return 0;
}