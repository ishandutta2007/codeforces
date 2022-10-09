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
const ll mod = 1e9 +7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
char s[510][510];
int pref[510][510];
int rows[510][510], col[510][510];
int n, m, a , b, c, d;
int query(int a, int b, int c, int d)
{
    if (a > c || b > d) return 0;
    return pref[c][d] - pref[c][b-1] - pref[a-1][d] + pref[a-1][b-1];
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; ++i) scanf("%s", s[i] + 1);
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=m; ++j)
        if (s[i][j] == '.')
        {
            if (s[i][j-1] == '.') pref[i][j]++;
            if (s[i-1][j] == '.') pref[i][j]++;
            pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
        else pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=m; ++j)
      if (s[i][j] == '.' && s[i-1][j] == '.') col[i][j] = col[i-1][j] + 1;
      else col[i][j] = col[i-1][j];

    for (int i=1; i<=n; ++i)
      for (int j=1; j<=m; ++j)
      if (s[i][j] == '.' && s[i][j-1] == '.') rows[i][j] = rows[i][j-1] + 1;
      else rows[i][j] = rows[i][j-1];
    
    
    int zap = 0;
    scanf("%d", &zap);
    while (zap--)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int f = query(a + 1, b + 1, c, d);
        int f1 = rows[a][d] - rows[a][b];
        int f2 = col[c][b] - col[a][b];
        printf("%d\n", f + f1 + f2);
    }
}