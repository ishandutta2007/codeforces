#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define OUT(x) { cout << x; return 0; }
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
#define maxn 200100
int n, zap;
vector <int> v[maxn];
int dodaj[maxn], wart[maxn], pre[maxn], post[maxn], d[maxn], DL = 0;
bool odw[maxn];

void prep(int x)
{
    odw[x] = true;
    pre[x] = ++DL;
    for (ui i=0; i<v[x].size(); ++i)
      if (!odw[v[x][i]]) 
      {
          d[v[x][i]] = d[x] + 1;
          prep(v[x][i]);
      }
    post[x] = ++DL;
}
bool parent(int x, int y)
{
    if (pre[x] <= pre[y] && post[x] >= post[y]) return true;
    return false;
}
void dfs(int x)
{
    odw[x] = true;
    wart[x] += dodaj[x];
    for (ui i=0; i<v[x].size(); ++i)
      if (!odw[v[x][i]]) 
    {
        dodaj[v[x][i]] -= dodaj[x];
        dfs(v[x][i]);
    }
}
int main()
{
    scanf("%d%d", &n, &zap);
    for (int i=1; i<=n; ++i) scanf("%d", &wart[i]);
    for (int i=1; i<n; ++i)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        v[a].pb(b);
        v[b].pb(a);
    }
    d[1] = 0;
    prep(1);
    int R = sqrt(zap);
    vector <PII> quest;
    quest.clear();
    int a,b;
    for (int help = 1; help <= zap; ++help)
    {
        int type;
        scanf("%d", &type);
        if (type == 1) scanf("%d%d", &a, &b);
        else scanf("%d", &a);
        if (type == 1) quest.pb({a, b});
        else
        {
            int ret = wart[a];
            for (ui i=0; i<quest.size(); ++i)
              if (parent(quest[i].e1, a))
              {
                  int u = quest[i].e1;
                  if ((d[u] - d[a]) % 2 == 0) ret += quest[i].e2;
                  else ret -= quest[i].e2;
              }
             printf("%d\n", ret);
        }
        if (quest.size() > (3 * R)) {
        for (int i = 1; i <= n; ++i) dodaj[i] = 0;
        for (ui i = 0; i<quest.size(); ++i)
        {
            PII x = quest[i];
            dodaj[x.e1] += x.e2;
        }
        fill(odw, odw + n + 1, 0);
        dfs(1);
        quest.clear();
        }
    }
}