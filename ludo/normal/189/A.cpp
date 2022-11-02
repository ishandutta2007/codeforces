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

#define MAXN 4000

typedef long long ll;
typedef pair<int, int> pii;

int dp[MAXN + 1];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    int n, a,b,c;
    cin >> n >> a>>b>>c;

    dp[0] = 0;

    for (int i = 0; i + a <= n; i++) dp[i + a] = max((dp[i] == 0 && i != 0) ? 0 : dp[i] + 1, dp[i + a]);
    for (int i = 0; i + b <= n; i++) dp[i + b] = max((dp[i] == 0 && i != 0) ? 0 : dp[i] + 1, dp[i + b]);
    for (int i = 0; i + c <= n; i++) dp[i + c] = max((dp[i] == 0 && i != 0) ? 0 : dp[i] + 1, dp[i + c]);

//    for (int i = 0; i <= n; i++) {
//        cout << i << ": " << dp[i] << endl;
//    }
    cout << dp[n] << endl;
    return 0;
}