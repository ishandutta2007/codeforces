#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &el : a)
            cin >> el;
        vector<int> dp(n, 1);
        for (int i = 1; i <= n; i++)
            for (int j = i * 2; j <= n; j += i)
                if (a[j - 1] > a[i - 1])
                    dp[j - 1] = max(dp[j - 1], dp[i - 1] + 1);
        cout << *max_element(all(dp)) << '\n';
    }
}