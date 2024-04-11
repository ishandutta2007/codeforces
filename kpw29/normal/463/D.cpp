#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18+3;
int tests, n, m, a, b, c, d,k, s, t = -1;

#define maxn 1010
int tab[maxn];
int poz[6][maxn];
vector <int> v[maxn];
int WYN = 0;
int wyn[maxn];
bool odw[maxn];

void dfs(int x)
{
    //printf("ODW: %d\n", x);
    odw[x] = true;
    for (ui i=0; i<v[x].size(); ++i)
    {
      if (!odw[v[x][i]]) dfs(v[x][i]);
      wyn[x] = max(wyn[x], wyn[v[x][i]] + 1);
  }
    wyn[x] = max(wyn[x], 1);
    WYN = max(WYN, wyn[x]);
}
int main()
{
    boost;
    cin >> n >> k;
    for (int z=1; z<=k; ++z)
    {
        for (int i=1; i<=n; ++i) 
        {
            cin >> tab[i];
            poz[z][tab[i]] = i;
        }
    }
    
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=n; ++j)
      {
          if (i == j) continue;
          bool czy = true;
          for (int z=1; z<=k; ++z)
            if (poz[z][i] >= poz[z][j]) czy =false;
          if (czy) v[i].pb(j);
      }
      
    
    for (int i=1; i<=n; ++i)
    {
        if (!odw[i]) dfs(i);
    }

    cout << WYN;
}