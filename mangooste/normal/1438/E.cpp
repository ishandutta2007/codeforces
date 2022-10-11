#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

vector<int> reversed(vector<int> a) {
    reverse(all(a));
    return a;
}

int largestBit(int x) {
    return 31 - __builtin_clz(x);
}

int solve(vector<int> a) {
    int n = len(a);
    int ans = 0;
    for (int l = 0; l < n - 2; l++) {
        ll sum = 0;
        for (int r = l + 1; r < n - 1; r++) {
            sum += a[r];
            if (largestBit(sum) > largestBit(a[l])) break;
            if (a[r + 1] < a[l] && (a[l] ^ a[r + 1]) == sum) {
                ans++;
            }
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    cout << solve(a) + solve(reversed(a)) << '\n';
}