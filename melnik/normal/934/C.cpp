#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
const int maxn = 2050;
const int inf = 1e9;
const double eps = 1e-8;
const int base = 1073676287;

int dp[maxn][4];
int a[maxn];

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf ("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            dp[i + 1][0] = max(dp[i + 1][0], 1 + dp[i][0]);
            dp[i + 1][2] = max(dp[i + 1][2], 1 + dp[i][2]);
            dp[i + 1][2] = max(dp[i + 1][2], 1 + dp[i][1]);
        } else {
            dp[i + 1][3] = max(dp[i + 1][3], 1 + dp[i][3]);
            dp[i + 1][1] = max(dp[i + 1][1], 1 + dp[i][1]);
            dp[i + 1][1] = max(dp[i + 1][1], 1 + dp[i][0]);
            dp[i + 1][3] = max(dp[i + 1][3], 1 + dp[i][2]);
        }
        for (int j = 0; j < 4; ++j)
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    }
    printf("%d\n", max(max(dp[n][0], dp[n][1]), max(dp[n][2], dp[n][3])));
}