#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> suf;
    int answer = 0, last = -1;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        vector<pair<int, int>> new_suf{{i, value}};
        for (auto &[pos, cur_gcd] : suf) {
            int new_gcd = gcd(cur_gcd, value);
            if (new_gcd != new_suf.back().second)
                new_suf.emplace_back(pos, new_gcd);
        }
        suf = new_suf;

        for (int j = 0; j < len(suf); j++) {
            int left = j == len(suf) - 1 ? 0 : suf[j + 1].first + 1, pos = i - suf[j].second + 1;
            if (left <= pos && pos <= suf[j].first && last < pos) {
                last = i;
                answer++;
            }
        }

        cout << answer << " \n"[i == n - 1];
    }
}