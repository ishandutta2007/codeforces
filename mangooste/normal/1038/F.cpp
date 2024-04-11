#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    ll answer = 0;
    for (int pos = 0; pos < n; pos++) {
        string ss(n, '?');
        for (int i = 0; i < len(s); i++)
            ss[(pos + i) % n] = s[i];

        auto check = [&](int start, int last) {
            for (int i = 0; i < len(s); i++) {
                int j = (start + i) % n;
                if (ss[j] != '?' && ss[j] != s[i])
                    return false;

                if (start + i >= last && s[i] != s[start + i - last])
                    return false;
            }
            return true;
        };

        vector<array<ll, 2>> dp(pos + 1);
        dp.back() = {1, 0};
        for (int i = pos - 1; i >= 0; i--)
            for (int j : {0, 1})
                for (int prev = i + 1; prev <= pos; prev++)
                    if (check(i, prev))
                        dp[i][j] += dp[prev][j ^ 1] * (1ll << max(0, prev - i - len(s)));

        ll total = 0;
        int power = 0;
        for (int i = 0; i <= pos; power += ss[i++] == '?') {
            total += (1ll << power) * dp[i][0];
            total -= (1ll << power) * dp[i][1];
        }
        answer += total * (1ll << max(0, n - pos - len(s)));
    }

    cout << answer << '\n';
}