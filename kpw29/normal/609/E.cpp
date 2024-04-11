#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define maxn 200100
typedef long long ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <ll, ll> LONG;
typedef pair <BONG, BONG> DONG;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9 + 696969;
const ll INF = 1e18+3;
int f[maxn];
int ile[maxn];

int _find(int a)
{
    int fa = f[a];
    if (fa == a) return a;
    f[a] = fa;
    return _find(f[a]);
}
bool _union(int a, int b)
{
    int fa = _find(a);
    int fb = _find(b);
    if (fa == fb) return true;
    if (ile[fa] > ile[fb]) f[fb] = fa, ile[fa] += ile[fb];
    else ile[fb] += ile[fa], f[fa] = fb;
    return false;
}

vector <BONG> v[maxn];
bool odw[maxn];
bool w_drzewie[maxn];
int n,m, a,b, c, dl, depth;
BONG skok[maxn][18];
int pre[maxn], post[maxn], d[maxn];
DONG x;
DONG kraw[maxn];
ll WYN[maxn];
void prep(int n)
{
    for (int i=1; i<=n; ++i) odw[i] = false, f[i] = i, ile[i] = 1;
}
inline bool parent(int x, int y) //czy x jest przodkiem y
{ return (pre[x] <= pre[y] && post[x] >= post[y])?true:false;
}

void dfs(int x, int parent)
{
    odw[x] = true;
    d[x] = d[parent] + 1;
    pre[x] = ++dl;
    for (ui i=0; i<v[x].size(); ++i)
      if (!odw[v[x][i].e1])
    {
        dfs(v[x][i].e1, x);
        skok[v[x][i].e1][0] = mp(x, v[x][i].e2);
    }
    post[x] = ++dl;
}

void prep_lca(int n)
{
    skok[1][0] = mp(1, 0);
    for (int j=1; j<=17; ++j)
      for (int i=1; i<=n; ++i)
        skok[i][j] = mp(skok[skok[i][j-1].e1][j-1].e1, max(skok[i][j-1].e2, skok[skok[i][j-1].e1][j-1].e2));
}

int lca(int x, int y)
{
    if (parent(x, y)) return x;
    if (parent(y ,x)) return y;
    for (int j=17; j>=0; --j)
      if (parent(skok[x][j].e1 , y) == false) x = skok[x][j].e1;
    return skok[x][0].e1;
}

int skakanie(int x, int k)
{
    int bits[20];
    int help = k, ret = 0;
    for (int j=0; j<18; ++j)
    {
        if (help & 1) bits[j] = true;
        else bits[j] = false;
        help >>=1;
    }
    for (int j=0; j<18; ++j)
      if (bits[j])
      {
        ret = max(ret, skok[x][j].e2);
        x = skok[x][j].e1;
      }
    return ret;
}
int main()
{
    scanf("%d%d", &n, &m);
    prep(m);
    for (int i=1; i<=m; ++i)
    {
        scanf("%d%d%d", &x.e1.e2, &x.e2.e1, &x.e1.e1);
        kraw[i] = x;
        kraw[i].e2.e2 = i;
    }
    sort(kraw+1, kraw+m+1);
    ll cost = 0;
    for (int i=1; i<=m; ++i)
    {
        a = kraw[i].e1.e2;
        b = kraw[i].e2.e1;
        if (_union(a,b) == false)
        {
            w_drzewie[i] = true;
            cost += kraw[i].e1.e1;
            v[b].pb(mp(a, kraw[i].e1.e1));
            v[a].pb(mp(b, kraw[i].e1.e1));
        }
    }
    d[1] = -1;
    dfs(1, 1);

    prep(m);
    prep_lca(n);

    for (int i=1; i<=m; ++i)
    {
        if (w_drzewie[i]) {
			WYN[kraw[i].e2.e2] = cost;
			continue;
		}
        a = kraw[i].e1.e2;
        b = kraw[i].e2.e1;
        int u = lca(a,b);
        int co = max(skakanie(b, d[b] - d[u]), skakanie(a, d[a] - d[u]));
        WYN[kraw[i].e2.e2] = cost + kraw[i].e1.e1 - co;
    }
	
	for (int i=1; i<=m; ++i) cout << WYN[i] << '\n';
}