#include "bits/stdc++.h"

using namespace std;

int main() {
    string n;
    cin >> n;
    string m = n;
    {
        for (char& c : m) {
            c ^= '1' ^ '0';
        }
        int ind = m.size() - 1;
        while (ind >= 0 && m[ind] == '1') {
            m[ind] = '0';
            --ind;
        }
        if (ind == -1) {
            m.insert(m.begin(), '1');
            n.insert(n.begin(), '0');
        } else {
            m[ind] = '1';
        }
    }

    int sz = n.size();

    vector<string> v = {n, m};
    vector<array<int, 2>> dp(sz);

    dp[sz - 1][0] = (v[0].back() == '1');
    dp[sz - 1][1] = (v[1].back() == '1');

    for (int i = sz - 2; i >= 0; --i) {
        for (int b = 0; b < 2; ++b) {
            if (v[b][i] == '0') {
                dp[i][b] = dp[i + 1][b];
            } else {
                dp[i][b] = min(dp[i + 1][b] + 1, dp[i + 1][b ^ 1] + 1);
            }
        }
    }

    cout << dp[0][0] << '\n';

    return 0;
}