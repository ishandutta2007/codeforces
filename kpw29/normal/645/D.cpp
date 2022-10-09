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
typedef pair <ll, int> PLI;
typedef vector <int> vi;
typedef unsigned int ui;
const int inf = 2e9+9091203;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const int BASE=10000;
int n, m, a, b, c, k;
#define maxn 100100
vector <int> v[maxn];
bool odw[maxn];
int A[maxn], B[maxn], wlot[maxn];

void dfs(int x) {
	if (!x) return;
	odw[x] = 1;
	int nxt = 0;
	for (int i=0; i<v[x].size(); ++i)
	  if (!odw[v[x][i]])
	  {
	  	 int u = v[x][i];
	  	 wlot[u]--;
	  	 if (wlot[u] == 0 && !odw[u]) nxt = u;
	  }
	dfs(nxt);	  
}
bool check(int x)
{
	for (int i=1; i<=n; ++i) v[i].clear(), wlot[i] = 0;
	for (int i=1; i<=x; ++i)
	{
		a = A[i]; b = B[i];
		v[a].pb(b);
		wlot[b]++;
	}
	fill(odw, odw + n + 2, 0);
	int D = 0;
	for (int i=1; i<=n; ++i)
	  if (wlot[i] == 0 && !D) dfs(i), D = 1;
	for (int i=1; i<=n; ++i)
	  if (!odw[i]) return 0;
	return 1;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=k; ++i)
	{
		scanf("%d%d", &a, &b);
		A[i] = a; B[i] = b;
	}
	int x = 0, y = k + 1;
	while (x < y) {
		int sr = (x + y) >> 1;
		if (check(sr)) y = sr;
		else x = sr + 1;
	}
	if (x == k + 1) OUT("-1");
	cout << x;
}