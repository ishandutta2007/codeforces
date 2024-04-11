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
#define maxn 1000100
int n, m, a, b, c;
PII t[maxn];
int zas[maxn], nowe[maxn];
int dp[maxn];

int main()
{
    scanf("%d", &n);
    if (n == 1) OUT(0);
    t[0] = mp(-inf, 0);
    for (int i=1; i<=n; ++i)
      {
          scanf("%d%d", &t[i].e1, &nowe[i]);
          t[i].e2 = i;
      }
      
    sort(t + 1, t + n + 1);
    for (int i=1; i<=n; ++i) zas[i] = nowe[t[i].e2];
    for (int i=1; i<=n; ++i) t[i].e2 = i;
    int wyn = 0;
    for (int i=1; i<=n; ++i)
    {
        int szukaj = t[i].e1 - zas[i];
        PII find = *lower_bound(t, t + n + 1, mp(szukaj, -inf));
        if (find.e2 > 0) dp[i] = dp[find.e2 - 1] + 1;
        else dp[i] = 1;
    }
    for (int i=0; i<=n; ++i) wyn = max(wyn, dp[i]);
    cout << n - wyn;
}