#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const int MX = 26 * 205;
const int INF = 100000;
int n, k;
int dp[205][MX];
vector<pair<int, int> > vv;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        int c1 = 0, c2 = 0;
        while (x % 2 == 0)
            ++c1, x /= 2;
        while (x % 5 == 0)
            ++c2, x /= 5;
        vv.push_back(make_pair(c1, c2));
    }
    for (int i = 0; i <= k; ++i)
        for (int j = 1; j < MX; ++j)
            dp[i][j] = -INF;
    for (int i = 0; i < n; ++i) {
        int x = vv[i].second;
        int y = vv[i].first;
        for (int j = min(k - 1, i); j >= 0; --j)
            for (int l = 0; l + x < MX; ++l)
                dp[j + 1][l + x] = max(dp[j + 1][l + x], dp[j][l] + y);
    }
    int ans = 0;
    for (int i = 0; i < MX; ++i)
        ans = max(ans, min(dp[k][i], i));
    cout << ans << "\n";
    return 0;
}