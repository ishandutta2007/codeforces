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
#define MAX 100

typedef long long ll;
typedef pair<int, int> pii;

ll dp[MAX + 1][MAX + 1] = {};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    int n, k, d;
    cin >> n >> k >> d;

    for (int i = 1; i <= k && i <= n; i++) {
        dp[i][i] = 1;
    }

    // we have a sum i
    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= i; l++) {
            // add 1, 2, ... k
            for (int j = 1; j <= k && i + j <= n; j++) {
                // new sum = (i + j)
                dp[i + j][max(l, j)] = (dp[i + j][max(l, j)] + dp[i][l]) % MOD;
            }
        }
    }

    ll sum = 0;
    for (int i = d; i <= k; i++) {
        sum = (sum + dp[n][i]) % MOD;
    }
    cout << sum << endl;
    return 0;
}