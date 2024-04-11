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
        int a[105], b[105];
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl;
        for (int i = 0; i < n; ++i) cout << b[i] << ' '; cout << endl;
    }
    return 0;
}