#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
#define milion 1000100
#define tysiac 1010
#define dwa_tysiace 2010
#define sto_tysiecy 100100
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b;
#define maxn 200100
int A[maxn], B[maxn];
int skok[maxn][21];
vector <int> v[maxn];
bool odw[maxn]; 
int pre[maxn], post[maxn];
int dl;
int wage[maxn];
map <BONG, int> mapka;
void dfs(int x, int parent)
{
    odw[x] = true;
    pre[x] = ++dl;
    skok[x][0] = parent;
    for (ui i=0; i<v[x].size(); ++i)
      if (!odw[v[x][i]]) dfs(v[x][i], x);
    post[x] = ++dl;
}
bool pater(int x, int y) //czy x jest ojcem y
{
    if (pre[x] <= pre[y] && post[x] >= post[y]) return true;
    return false;
}

void prep_lca()
{
    for (int j=1; j<=20; ++j)
      for (int i=1; i<=n; ++i) 
      skok[i][j] = skok[skok[i][j-1]][j-1];   
}

int lca(int x, int y)
{
    if (pater(x,y)) return x;
    if (pater(y,x)) return y;
    for (int i=20; i>=0; --i)
    {
        if (pater(skok[x][i], y) == false) x = skok[x][i];
    }
    return skok[x][0];
}

void wynik(int x)
{
    odw[x] = true;
    for (ui i=0; i<v[x].size(); ++i)
      if (!odw[v[x][i]])
      {
          wynik(v[x][i]);
          mapka[mp(x, v[x][i])] = wage[v[x][i]];
          wage[x] += wage[v[x][i]];
      }
}
int main()
{
    boost;
    cin >> n;
    for (int i=1; i<n; ++i)
    {
        cin >> A[i] >> B[i];
        v[A[i]].pb(B[i]);
        v[B[i]].pb(A[i]);
    }
    dfs(1, 1);
    prep_lca();
    int k;
    cin >> k;
    for (int i=1; i<=k; ++i)
    {
        cin >> a >> b;
        int u = lca(a,b);
        //cout << u << endl;
        wage[u]--; wage[u]--;
        wage[a]++; wage[b]++;
    }
    //for (int i=1; i<=n; ++i) cout << wage[i] << ' ';
    cout << endl;
    fill(odw, odw+n+1, false);
    wynik(1);
    for (int i=1; i<n; ++i)
    {
        int tmp_wyn = 0;
        BONG tmp = mp(A[i], B[i]);
        if (mapka[tmp] != NULL) tmp_wyn = mapka[tmp];
        swap(tmp.e1, tmp.e2);
        if (mapka[tmp] != NULL) tmp_wyn = mapka[tmp];
        cout << tmp_wyn << ' ';
    }
}