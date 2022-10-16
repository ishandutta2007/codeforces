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
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            x = abs(x);
            if (i & 1) cout << -x << ' ';
            else cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}