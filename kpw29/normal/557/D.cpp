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
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c,k, w;

#define maxn 500100
vector <int> v[maxn];
bool odw[maxn];
int d[maxn],D[3];
int A[maxn], B[maxn];
void dfs(int x)
{
    odw[x] = true;
    D[(d[x] & 1)]++;
    for (ui i=0; i<v[x].size(); ++i)
      if (!odw[v[x][i]])
      {
          d[v[x][i]] = d[x] + 1;
          dfs(v[x][i]);
      }
}
ll f(ll x)
{
    ll ret = x * (x-1);
    ret /= 2;
    return ret;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; ++i) 
    {
        scanf("%d%d", &A[i], &B[i]);
        a = A[i]; b = B[i];
        v[a].pb(b);
        v[b].pb(a);
    }
    long long wyn;
    if (m == 0)
    {
        ll help = n;
        wyn = (help * (help - 1) * (help - 2)) / 6;
        cout << "3 " << wyn;
        return 0;
    }
    for (int i=1; i<=n; ++i)
    if (!odw[i])
    {
        d[i] = 0;
        dfs(i);
    }
    //for (int i=1; i<=n; ++i) printf("%d ", d[i]);
    for (int i=1; i<=m; ++i)
        if ((d[A[i]] & 1) == (d[B[i]] & 1) ) OUT("0 1");
        
    //case 3 and case 0 already beaten
    fill(d, d+n+1, 0);
    fill(odw, odw+n+1, false);
    ll av = 0;

    for (int i=1; i<=n; ++i)
    if (!odw[i])
    {
        D[0] = 0, D[1] = 0;
        d[i] =0;
        dfs(i);
        av += f(D[1]);
        av += f(D[0]);
    }   

    if (av) cout << "1 " << av;
    else
    {
        av = m;
        ll help = n-2;
        av *= help;
        cout << "2 " << av;
    }
    
}