#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1010
ll dp[maxn][maxn]; //[lines][bugs]
int n, m, mod, bug, b;
int main()
{
    cin >> n >> m >> b >> mod;
    dp[0][0] = 1;
    for (int i=1; i<=n; ++i) 
    {
        cin >> bug;
        for (int j=1; j<=m; ++j)
          for (int k=0; k<=b; ++k) 
            if (k - bug >= 0) dp[j][k] += dp[j-1][k-bug], dp[j][k] %= mod;
    }
    ll res = 0;
    for (int i=0; i<=b; ++i) res += dp[m][i], res %= mod;
    cout << res;
    
}