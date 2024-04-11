#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define MAXM 50000
#define MAXN 5

typedef long long ll;
typedef pair<int, int> pii;

int n, m, t[MAXN][MAXM];

int dp[MAXN][MAXM];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> m >> n;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cin >> t[i][j];
        }
    }

    dp[0][0] = t[0][0];
    for (int i = 1; i < m; i++) {
        dp[0][i] = dp[0][i - 1] + t[0][i];
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + t[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + t[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cout << dp[n - 1][i];
        if (i + 1 == m) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    return 0;
}