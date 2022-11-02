#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ios>
#include <cassert>

using namespace std;

const int maxn = 100100;

int n, a[maxn], dp[maxn];

int main() {
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = dp[a[i] - 1] + 1;
        ans = max(ans, dp[a[i]]);
    }

    cout << n - ans << '\n';
}