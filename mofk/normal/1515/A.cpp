#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, k, s = 0;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i], s += a[i];
        if (k == s) {
            cout << "NO" << endl;
            continue;
        }
        s = 0;
        for (int i = 0; i < n; ++i) {
            s += a[i];
            if (s == k) swap(a[i], a[i + 1]);
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}