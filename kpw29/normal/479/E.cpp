#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
int n, m, c, k, a, b;

#define maxn 5002
ll dp[maxn][maxn];
ll pref;
ll suf[maxn];
int main()
{
    cin >> n >> a >> b >> k;
    if (k == 0) OUT(1);
    if (a > b)
    {
        //segment from b + 1 to n becomes interesting
        n -= b;
        a-= b;
        a = (n - a + 1);
        b = n + 1;
    }
    n = b - 1;

    dp[a][0] = 1;
    for (int z = 1; z<=k; ++z)
    {
        pref = 0;
        for (int i=1; i<=n; ++i) dp[i][z] = pref, pref += dp[i][z-1],  pref %= mod;
        for (int i=1; i<=n; ++i) suf[i] = 0;
        
        for (int i=n-1; i>0; --i)
        {
            suf[i] += suf[i + 1];
            suf[i] %= mod;
            int dist = ((b - i + 1) -2 );
            if (dist > 0) {
                suf[max(i - dist - 1, 0)] -= (dp[i][z-1]);
                suf[max(i - dist - 1, 0)] += mod;
                suf[max(i - dist - 1, 0)] %= mod;
                suf[i - 1] += dp[i][z-1];
                suf[i-1] %= mod;
            }
            dp[i][z] += suf[i];
            dp[i][z] %= mod;
        }
    
    }
    ll wyn = -1 + 1;
    for (int i=1; i<=n; ++i) wyn += dp[i][k], wyn %= mod;
    cout << wyn;
    
}