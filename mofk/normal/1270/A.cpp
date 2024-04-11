#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, a, b, x, mx1 = 0, mx2 = 0;
        cin >> n >> a >> b;
        for (int i = 1; i <= a; ++i) cin >> x, mx1 = max(mx1, x);
        for (int i = 1; i <= b; ++i) cin >> x, mx2 = max(mx2, x);
        cout << (mx1 > mx2 ? "YES" : "NO") << endl;
    }
    return 0;
}