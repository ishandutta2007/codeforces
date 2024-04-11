#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> cnt;
    for (char c : s)
        cnt[c]++;
    int have = 0;
    for (const auto& kv : cnt)
        have += kv.second / 2;
    int ans = n;
    for (int d = 2; d <= n; d++) {
        if (n % d != 0)
            continue;
        int want = (d / 2) * (n / d);
        if (want <= have)
            ans = n / d;
    }
    cout << ans << "\n";
    int len = n / ans;
    vector<string> res(ans, string(len, '0'));
    vector<char> pairs;
    vector<char> ones;
    for (const auto& kv : cnt) {
        if (kv.second % 2)
            ones.push_back(kv.first);
        for (int i = 0; i < kv.second - kv.second % 2; i++)
            pairs.push_back(kv.first);
    }
    for (int i = 0; i < ans; i++) {
        for (int j = 0; j < len / 2; j++) {
            auto c = pairs.back();
            pairs.pop_back();
            pairs.pop_back();
            res[i][j] = res[i][len - 1 - j] = c;
        }
    }
    if (len % 2) {
        for (int i = 0; i < ans; i++) {
            char c;
            if (pairs.size()) {
                c = pairs.back();
                pairs.pop_back();
            } else {
                c = ones.back();
                ones.pop_back();
            }
            res[i][len / 2] = c;
        }
    }
    for (const auto& part : res)
        cout << part << " ";
    cout << "\n";
}