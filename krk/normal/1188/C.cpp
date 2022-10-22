#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1005;
const int Maxm = 100005;
const int mod = 998244353;

int n, k;
int a[Maxn];
int lim[Maxn], to[Maxn];
vector <ii> V[Maxm];
int dp[Maxn][Maxn];
int res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        lim[i] = min(n - i, k);
        to[i] = n;
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j > i; j--)
            V[a[j] - a[i]].push_back(ii(i, j));
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        dp[i][0] = 1;
        dp[i][1] = (dp[i + 1][1] + dp[to[i]][0]) % mod;
    }
    int was = 0;
    for (int j = Maxm - 1; j >= 0; j--) if (!V[j].empty()) {
        for (int z = 0; z < V[j].size(); z++) {
            int a = V[j][z].first, b = V[j][z].second;
            to[a] = b;
        }
        if ((k - 1) * j >= Maxm) continue;
        for (int i = n - 1; i >= 0; i--) {
            dp[i][0] = 1;
            for (int j = 1; j <= lim[i]; j++)
                dp[i][j] = (dp[i + 1][j] + dp[to[i]][j - 1]) % mod;
        }
        int cur = dp[0][k];
        int add = (cur - was + mod) % mod;
        res = (res + ll(add) * j) % mod;
        was = cur;
    }
    printf("%d\n", res);
    return 0;
}