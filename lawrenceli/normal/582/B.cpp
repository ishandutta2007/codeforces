#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;
const int maxa = 350;
const int inf = (1e9) + 5;

int n, t, a[maxn];
int dp[maxn * maxa][maxa];
int freq[maxa];

inline void setmax(int& x, int y) { if (x < y) x = y; }

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]] ++;
    }

    for (int i = 0; i < maxn * maxa; ++i)
        for (int j = 0; j < maxa; ++j)
            dp[i][j] = -inf;
    
    dp[0][0] = 0;
    for (int i = 0; i < n * maxa; ++i) {
        for (int j = 0; j <= 300; ++j) {
            setmax(dp[i+1][j], dp[i][j]);
            if (j <= a[i%n]) setmax(dp[i+1][a[i%n]], dp[i][j] + 1);
        }
    }

    if (t < maxa) {
        int ans = -inf;
        for (int i = 0; i <= 300; ++i)
            ans = max(ans, dp[n * t][i]);
        cout << ans << '\n';
    } else {
        int ans = -inf;
        for (int i = 0; i <= 300; ++i)
            ans = max(ans, dp[n * maxa][i]);

        int ma = 0;
        for (int i = 0; i <= 300; ++i)
            ma = max(ma, freq[i]);

        cout << ans + ma * (t - maxa) << '\n';
    }
}