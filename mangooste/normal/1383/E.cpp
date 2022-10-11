#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "/home/lesha/codes/Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, l, r) for (int i = int(l); i < int(r); i++)

const int P = int(1e9) + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    int n = len(str);
    if (str == string(n, '0')) return cout << n << '\n', 0;

    int s = 0;
    while (str[s] == '0') s++;
    int f = n - 1;
    while (str[f] == '0') f--;

    vector<int> zeroes;
    forn (i, s, f) {
        int j = i;
        while (str[j + 1] == '0') j++;

        zeroes.push_back(j - i);
        i = j;
    }

    int zero = len(zeroes) + 1;
    vector<int> dp(zero);
    dp[0] = 1;
    int sum = 1;

    forn (i, 1, zero) {
        dp[i] = 1ll * dp[i - 1] * (zeroes[i - 1] + 1) % P;

        int sufMax = INT_MIN;
        for (int j = i - 2; j >= 0; j--) {
            sufMax = max(sufMax, zeroes[j]);
            if (sufMax >= zeroes[i - 1]) break;

            dp[i] += 1ll * (zeroes[i - 1] - sufMax) * dp[j] % P;
            if (dp[i] >= P) dp[i] -= P;
        }
        sum += dp[i];
        if (sum >= P) sum -= P;
    }

    cout << 1ll * sum * (s + 1) % P * (n - f) % P << '\n';
}