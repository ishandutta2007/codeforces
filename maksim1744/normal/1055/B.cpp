/*
    12.11.2018 21:47:07
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n, m, l;
    cin >> n >> m >> l;
    ++l;
    vector< int > a(n);
    vector< bool > v(n, false);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= l) {
            v[i] = 1;
            if (i == 0 || v[i - 1] == 0) {
                ++ans;
            }
        }
    }
    for (int ii = 0; ii < m; ++ii) {
        int t;
        cin >> t;
        if (t == 0) {
            cout << ans << '\n';
        } else {
            int p, d;
            cin >> p >> d;
            --p;
            a[p] += d;
            if (v[p] == 1) {
                continue;
            }
            if (a[p] < l) {
                continue;
            }
            v[p] = 1;
            if ((p == 0 || v[p - 1] == 0) && (p == n - 1 || v[p + 1] == 0)) {
                ++ans;
            } else if ((p > 0 && v[p - 1] == 1) && (p < n - 1 && v[p + 1] == 1)) {
                --ans;
            }
        }
    }
    return 0;
}