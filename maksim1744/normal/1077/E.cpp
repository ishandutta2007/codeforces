/*
    16.11.2018 22:21:28
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector< int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector< int > v;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i] != a[i - 1]) {
            v.push_back(1);
        } else {
            ++v.back();
        }
    }
    sort(v.begin(), v.end());
    int m = v.size();
    vector< vector< int > > dp(m);
    vector< int > mx(m, 0);
    for (int i = 0; i < m; ++i) {
        dp[i].resize(v[i] + 1);
    }
    for (int i = 0; i <= v.back(); ++i) {
        dp.back()[i] = i;
    }
    mx.back() = v.back();
    for (int i = m - 2; i >= 0; --i) {
        dp[i][0] = mx[i + 1];
        mx[i] = mx[i + 1];
        for (int j = 1; j <= v[i]; ++j) {
            int l = i, r = m;
            while (r - l > 1) {
                int c = (l + r) / 2;
                if (v[c] < j * 2) {
                    l = c;
                } else {
                    r = c;
                }
            }
            if (r == m) {
                dp[i][j] = j;
            } else {
                dp[i][j] = j + dp[r][j * 2];
            }
            mx[i] = max(mx[i], dp[i][j]);
        }
    }
    cout << *max_element(mx.begin(), mx.end()) << '\n';
    return 0;
}