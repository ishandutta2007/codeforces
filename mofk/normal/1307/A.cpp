#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, d;
        cin >> n >> d;
        int ans = 0, x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (i == 0) ans += x;
            else {
                int go = min(x, d / i);
                d -= go * i;
                ans += go;
            }
        }
        cout << ans << endl;
    }
    return 0;
}