#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define MAX 2000

typedef long long ll;
typedef pair<int, int> pii;

ll dp[MAX + 1][MAX + 1] = {};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1;
    }
    k--;
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 1; j * l <= n; l++) {
                dp[i + 1][j * l] = (dp[i + 1][j * l] + dp[i][j]) % MOD;
            }
        }

//        for (int j = 1; j <= n; j++) {
//            cerr << dp[i][j] << " ";
//        }
//        cerr << endl;
    }
    ll sum = 0L;
    for (int i = 1; i <= n; i++) {
        sum = (sum + dp[k][i]) % MOD;
    }

//    for (int j = 1; j <= n; j++) {
//        cerr << dp[k][j] << " ";
//    }
//    cerr << endl;

    cout << sum << endl;
    return 0;
}