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

#define INF 2147483647
#define MOD 1000000007
#define MAX 2000

typedef long long ll;
typedef pair<int, int> pii;

bool is_p[2000][2000] = {};
ll dp[2000][2000] = {};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    string str;
    cin >> str;

    int n = str.size();
    for (int i = 0; i < n; i++) {
        dp[i][i] = is_p[i][i] = true;
    }
    for (int i = 1; i < n; i++) {
        is_p[i - 1][i] = (str[i - 1] == str[i]);
        dp[i - 1][i] = 2 + is_p[i - 1][i];
    }
    for (int w = 3; w <= n; w++) {
        for (int l = 0; l + w <= n; l++) {
            dp[l][l + w - 1] += dp[l][l + w - 2];
            dp[l][l + w - 1] += dp[l + 1][l + w - 1];
            dp[l][l + w - 1] -= dp[l + 1][l + w - 2];
            if (is_p[l + 1][l + w - 2] && str[l] == str[l + w - 1]) {
                is_p[l][l + w - 1] = true;
                dp[l][l + w - 1]++;
            }
        }
    }

//    for (int l = 0; l < n; l++) {
//        for (int r = 0; r < n; r++) {
//            cout << dp[l][r] << " ";
//        }
//        cout << endl;
//    }

    ll ret = 0;
    ret += dp[0][0] * dp[1][n - 1];
    for (int m = 1; m + 1 < n; m++) {
        ret += (dp[0][m] - dp[0][m - 1]) * dp[m + 1][n - 1];
    }
    cout << ret << endl;
    return 0;
}