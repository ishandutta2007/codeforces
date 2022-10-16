#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        if (n == 1) cout << -1 << '\n';
        else {
            for (int i = 1; i < n; ++i) cout << 9;
            cout << 8 << '\n';
        }
    }
    return 0;
}