#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int A = 0, B = 0;
        for (int i = n / 4; i < n; ++i) A += a[i];
        for (int i = n / 4; i < n; ++i) B += b[i];
        int m = n, pa = n / 4, pb = n / 4 - 1;
        while (A < B) {
            ++m;
            A += 100;
            if (m % 4 == 0) {
                A -= pa < n ? a[pa] : 100;
                pa++;
            }
            else {
                B += pb >= 0 ? b[pb] : 0;
                pb--;
            }
        }
        cout << m - n << '\n';
    }
    return 0;
}