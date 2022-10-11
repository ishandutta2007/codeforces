#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    vector<int> part_sums(n + 1);
    for (int i = 0; i < n; i++)
        part_sums[i + 1] = part_sums[i] + (str[i] == '0');

    auto solve = [&](int blocked) -> string {
        vector<bool> any((1 << blocked), false);
        for (int right = k - 1; right < n; right++) {
            if (part_sums[right - blocked + 1] - part_sums[right - k + 1])
                continue;
            int mask = 0;
            for (int i = 0; i < blocked; i++)
                mask <<= 1, mask += str[right - blocked + 1 + i] - '0';
            any[mask] = true;
        }

        for (int mask = 0; mask < (1 << blocked); mask++) {
            int bad = ((1 << blocked) - 1) ^ mask;
            if (any[bad])
                continue;

            string good(k - blocked, '0');
            for (int i = blocked - 1; i >= 0; i--)
                good.push_back('0' + (mask >> i) % 2);
            return good;
        }
        return "";
    };

    int zeroes = k;
    while (zeroes >= 0 && solve(k - zeroes).empty())
        zeroes--;

    if (zeroes == -1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        cout << solve(k - zeroes) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}