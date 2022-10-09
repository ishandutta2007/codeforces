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
const ll P = 29;
const int mod = 1e9+696969;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int a, b;
vector <int> v[maxn];
int n, m;
int dp[maxn];
ll wyn = 0;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; ++i)
    {
        scanf("%d%d", &a, &b);
        v[a].pb(b);
        v[b].pb(a);
    }
    
    for (int i=1; i<=n; ++i)
      sort(v[i].begin(), v[i].end());
    for (int i=1; i<=n; ++i)
    {
        for (int j=0; j<v[i].size(); ++j)
        {
          if (v[i][j] > i) break;
          dp[i] = max(dp[i], dp[v[i][j]]);
        }
        dp[i]++;
        wyn = max(wyn, (ll)dp[i] * (ll)(v[i].size()));
    }
    cout << wyn;
}