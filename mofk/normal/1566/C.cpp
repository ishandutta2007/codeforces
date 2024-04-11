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
        int ans = 0, last = 1;
        for (int i = 0; i < n; ++i) {
            int v = a[i] - '0' + b[i] - '0';
            if (v == 1) {
                if (last == 0) ans += 1;
                ans += 2;
                last = 1;
            }
            else if (v + last == 2) {
                ans += 2;
                last = 1;
            }
            else {
                if (last == 0) {
                    ans += 1;
                }
                last = v;
            }
        }
        if (last == 0) ans += 1;
        cout << ans << endl;
    }
    return 0;
}