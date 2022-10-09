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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m, k, a, b, c, w, h;
ll res = 0;
vector <int> v[maxn];
ll dp[50100][510];

int odl[maxn], parent[maxn];

void dfs(int x)
{
	dp[x][0] = 1;
	for (ui i=0; i<v[x].size(); ++i)
	  if (odl[v[x][i]] == 0 && v[x][i] != 1)
	  {
		  odl[v[x][i]] = odl[x] + 1;
		  parent[v[x][i]] = x;
		  dfs(v[x][i]);
		  for (int j=0; j<k; ++j) dp[x][j + 1] += dp[v[x][i]][j];
	  }
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<n; ++i)
	{
		scanf("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	parent[1] = 0;
	dfs(1);
	for (int i=1; i<=n; ++i)
	{
		int akt = i, o = k, last = 0;
		while (akt != 0 && o >= 0)
		{
			res += dp[akt][o] - dp[last][o - 1];
			last = akt;
			akt = parent[akt];
			o--;
		}
	}
	res /= 2;
	cout << res;
}