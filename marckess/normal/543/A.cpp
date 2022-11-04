#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, m, b, mod, a[505], dp[2][505][505];

int obtRes (int i, int j, int k) {
    if (k < 0 || i == n)
        return 0;

    if (!j)
        return 1;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    return dp[i][j][k] = (obtRes(i, j-1, k - a[i]) + obtRes(i+1, j, k)) % mod;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> b >> mod;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = n - 1; i >= 0; i--)
    for (int j = 0; j <= m; j++)
    for (int k = 0; k <= b; k++)
    {
        if (j == 0) {
            dp[i%2][j][k] = 1;
        } else {
            dp[i%2][j][k] = dp[1-i%2][j][k];
            if (k - a[i] >= 0)
                dp[i%2][j][k] += dp[i%2][j-1][k - a[i]];
            dp[i%2][j][k] %= mod;
        }
    }

    cout << dp[0][m][b] << endl;

    return 0;
}