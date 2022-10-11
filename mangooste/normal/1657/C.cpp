#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename T>
std::pair<std::vector<int>, std::vector<int>> manacher(const T &str) {
    int n = str.size();
    std::vector<int> odd(n), even(n);
    for (int rot : {0, 1}) {
        auto &current = rot == 0 ? odd : even;
        for (int i = 0, l = 0, r = 0; i < n; i++) {
            if (i < r - rot)
                current[i] = std::min(r - i - rot, current[l + (r - i - 1) - rot]);

            while (i - current[i] >= 0 && i + current[i] + rot < n && str[i - current[i]] == str[i + current[i] + rot])
                current[i]++;

            if (i + current[i] + rot > r) {
                l = i - current[i] + 1;
                r = i + current[i] + rot;
            }
        }
    }
    return {odd, even};
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    auto [odd, even] = manacher(s);
    int ans = 0;
    for (int st = 0;;) {
        if (st >= n - 1) {
            cout << ans << ' ' << max(0, n - st) << '\n';
            return;
        }
        if (s[st] == '(') {
            ans++;
            st += 2;
            continue;
        }

        for (int pos = st;; pos++) {
            if (pos == n) {
                cout << ans << ' ' << max(0, n - st) << '\n';
                return;
            }
            if (pos != st && odd[pos] - 1 >= pos - st) {
                ans++;
                st = pos + (pos - st) + 1;
                break;
            }
            if (even[pos] >= pos - st + 1) {
                ans++;
                st = pos + (pos - st + 1) + 1;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}