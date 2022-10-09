 #include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define scanf(...) scanf(__VA_ARGS__)?:0
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
#define maxn 1500100
int n, m, k, a, b, c;
ll wyn;
vector <int> v[maxn];
int d[maxn];
bool odw[maxn], marked[maxn];
int r[maxn];
void dfs(int x) {
    odw[x] = 1;
    for (int i=0; i<v[x].size(); ++i)
      if (!odw[v[x][i]]) {
          d[v[x][i]] = d[x] + 1;
          dfs(v[x][i]);
      }
}
void DFS(int x, int start) {
    odw[x] = 1;
    if (marked[x]) r[x] = 1;
    for (int i=0; i<v[x].size(); ++i)
      if (!odw[v[x][i]]) {
          d[v[x][i]] = d[x] + 1;
          DFS(v[x][i], start);
          r[x] |= r[v[x][i]];
      }
    if (r[x] && x != start) wyn += 2;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<n; ++i) {
        scanf("%d%d", &a, &b);
        v[a].pb(b);
        v[b].pb(a);
    }
    for (int i=1; i<=m; ++i) {
        scanf("%d", &a);
        marked[a] = 1;
    }
    for (int i=1; i<=n; ++i) {
        if (marked[i]) {
            d[i] = 0;
            dfs(i);
            break;
        }
    }
    fill(odw, odw + n + 1, 0);
    d[0] = -1;
    int MAX = 0;
    for (int i=1; i<=n; ++i)
      if (d[i] > d[MAX] && marked[i]) MAX = i;
    for (int i=1; i<=n; ++i) d[i] = 0;
    d[MAX] = 0;
    
    dfs(MAX);
    int M = 0;
    for (int i=1; i<=n; ++i)
      if (d[i] > d[M] && marked[i]) M = i;
    int alleal = min(MAX, M);
    wyn = 0;
    for (int i=1; i<=n; ++i) odw[i] = 0, d[i] = 0;
    d[alleal] = 0;
    DFS(alleal, alleal);
    int DL = 0;
    for (int i=1; i<=n; ++i)
      if (marked[i]) DL = max(DL, d[i]);
    cout << alleal << endl << wyn - DL;
    
}