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
        int s = 0;
        for (int i = 0; i < n; ++i) s ^= a[i];
        int b = -1;
        while (s) s >>= 1, ++b;
        if (b == -1) {
            cout << "DRAW" << '\n';
            continue;
        }
        int m = 0;
        for (int i = 0; i < n; ++i) m += (a[i] >> b & 1);
        if (m % 4 == 1) cout << "WIN\n";
        else if (n % 2 == 1) cout << "LOSE\n";
        else cout << "WIN\n";
    }
    return 0;
}