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
#define maxn 1000100
int n, m, a, b, c;
vector <int> wyn;

bool binary(int x)
{
    while (x > 0) {
        int r = (x % 10);
        if (r > 1) return false;
        x /= 10;
    }
    return 1;
}
int dp[maxn], last[maxn], bin[maxn], DL = 0;
int main()
{
    cin >> n;
    for (int i=1; i<=n; ++i)
      if (binary(i)) bin[++DL] = i;
    dp[0] = 0;
    for (int i=1; i<=n; ++i) dp[i] = inf;

    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=DL; ++j)
        {
            if (bin[j] > i) break;
            int wyn = dp[i - bin[j]] + 1;
            if (wyn < dp[i]) {
                last[i] = bin[j];
                dp[i] = wyn;
            }
        }
    }
    cout << dp[n] << '\n';
    int x = n;
    while (x > 0) {
        printf("%d ", last[x]);
        x = x - last[x];
    }
}