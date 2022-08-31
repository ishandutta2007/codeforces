/*
    20.12.2018 17:06:10
*/

#include <bits/stdc++.h>

using namespace std;

bool good(long long x) {
    if (x <= 1) {
        return false;
    }
    if (x % 4 == 2) {
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    n /= 2;
    vector< long long > d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        if (!good(d[i])) {
            cout << "No\n";
            return 0;
        }
    }
    vector< long long > ans;
    long long x = 0;
    for (int i = 0; i < n; ++i) {
        long long l = 0, r = d[i] + 1;
        while (r - l > 1) {
            long long c = (l + r) / 2;
            if (c * (c + (x + 1) * 2) > d[i]) {
                r = c;
            } else {
                l = c;
            }
        }
        long long k = l;
        while (k > 0 && (d[i] % k != 0 || d[i] / k % 2 != k % 2)) {
            --k;
        }
        if (k == 0) {
            cout << "No\n";
            return 0;
        }
        // cout << "k = " << k << '\n';
        long long nx = (d[i] / k - k) / 2;
        ans.push_back(nx * nx - x * x);
        ans.push_back(d[i]);
        x = nx + k;
        // cout << x << '\n';
    }
    cout << "Yes\n";
    for (int i = 0; i < n * 2; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}