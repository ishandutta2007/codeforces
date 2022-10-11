#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

bitset<int(1e6) + 4> dp;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        x--;
    }

    vector<int> lens;
    vector<bool> used(n);

    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;

        lens.push_back(0);
        for (int j = i; !used[j]; j = a[j]) {
            used[j] = true;
            lens.back()++;
        }
    }

    int later = 0, left = k, max_answer = 0;
    for (auto length : lens) {
        later += length & 1;
        int take = min(left, length / 2);
        max_answer += 2 * take;
        left -= take;
    }
    max_answer += min(later, left);

    vector<int> cnt(n + 1);
    for (auto length : lens)
        cnt[length]++;

    vector<int> things;
    for (int i = 1; i <= n; i++) {
        if (!cnt[i])
            continue;

        for (int j = 0; (1 << j) <= cnt[i]; j++) {
            cnt[i] -= (1 << j);
            things.push_back(i * (1 << j));
        }
        if (cnt[i] != 0)
            things.push_back(i * cnt[i]);
    }

    dp[0] = 1;
    for (auto x : things)
        dp |= dp << x;

    cout << k + 1 - dp[k] << ' ' << max_answer << '\n';
}