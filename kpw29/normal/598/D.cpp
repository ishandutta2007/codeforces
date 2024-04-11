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
int n, m, k, a, b, c, p, q, T, steps;
#define maxn 1000100
inline int numer(int i, int j) {
    return (i-1)*m + j;
}
char s[1010][1010];
vector <int> akt;
vector <int> v[maxn];
bool odw[maxn];

void dfs(int x)
{
    odw[x] = 1;
    for (ui i=0; i<v[x].size(); ++i)
      if (!odw[v[x][i]]) dfs(v[x][i]);
    akt.push_back(x);
}
int wartosc[maxn], wynall[maxn];

int main()
{
    scanf("%d%d%d", &n, &m, &T);
    for (int i=1; i<=n; ++i) scanf("%s", s[i] + 1);
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=m; ++j)
        if (s[i][j] == '.')
        {
            int nr = numer(i, j);
            if (s[i-1][j] == '.') v[nr].pb(numer(i-1, j));
            if (s[i+1][j] == '.') v[nr].pb(numer(i+1, j));
            if (s[i][j+1] == '.') v[nr].pb(numer(i, j+1));
            if (s[i][j-1] == '.') v[nr].pb(numer(i, j-1));
            if (s[i-1][j] == '*') wartosc[nr]++;
            if (s[i+1][j] == '*') wartosc[nr]++;
            if (s[i][j+1] == '*') wartosc[nr]++;
            if (s[i][j-1] == '*') wartosc[nr]++;
        }
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=m; ++j)
      {
          int nr = numer(i, j);
          if (!odw[nr])
          {
              akt.clear();
              dfs(nr);
              int wyn = 0;
              for (ui h=0; h<akt.size(); ++h) wyn += wartosc[akt[h]];
              for (ui h=0; h<akt.size(); ++h) wynall[akt[h]] = wyn;
          }
      }
    while (T--)
    {
        scanf("%d%d", &a, &b);
        int nr = numer(a, b);
        printf("%d\n", wynall[nr]);
    }
}