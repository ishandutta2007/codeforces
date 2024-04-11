#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstring>
#include <iomanip>

using ll = long long;
using namespace std;

//#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

void relax(int& a, int b) {
    if (a == -1) a = b;
    else a = max(a, b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(h, -1));
    dp[0][0] = 0;
    forn(i, n) forn(j, h) {
        if (dp[i][j] == -1) continue;
        int t1 = (j + a[i]) % h;
        int t2 = (j + a[i] - 1) % h;
        relax(dp[i + 1][t1], dp[i][j] + (l <= t1 && t1 <= r));
        relax(dp[i + 1][t2], dp[i][j] + (l <= t2 && t2 <= r));
    }
    cout << *max_element(all(dp.back())) << '\n';
}