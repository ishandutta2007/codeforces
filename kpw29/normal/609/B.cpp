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
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 2001000
int a, b, c, n, m, k;
int dp[200010];

inline ll f(ll x){ 
    return x * (x - 1) / 2;
}
int main()
{
    boost;
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        cin >> a;
        dp[a]++;
    }
    ll res = f(n);
    for (int i=1; i<=m; ++i) res -= f(dp[i]);
    cout << res;
}