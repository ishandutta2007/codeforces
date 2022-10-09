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
const int mod = 1e8;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
#define tys 5010
int n, m, k, a, b, c, w, h;
PPI tab[tys];
int dp[tys], last[tys];
int res = -inf;
int main()
{
	scanf("%d%d%d", &n, &w, &h);
	tab[n+1] = mp(mp(w, h), n + 1);
	for (int i=1; i<=n; ++i)
	{
		scanf("%d%d", &a, &b);
		tab[i] = mp(mp(a, b), i);
	}
	++n;
	sort(tab + 1, tab + n + 1);
	for (int i=1; i<=n; ++i)
	  if (tab[i].e2 == n) dp[i] = 0;
	  else dp[i] = -inf;
	for (int i=1; i<=n; ++i)
	  for (int j=1; j<i; ++j)
	  if (tab[j].e1.e1 < tab[i].e1.e1 && tab[j].e1.e2 < tab[i].e1.e2)
	  {
		  if (dp[j] + 1 > dp[i])
		  {
			  last[i] = j;
			  dp[i] = dp[j] + 1;
		  }
	  }
	int M = 0;
	for (int i=1; i<=n; ++i) M = max(M, dp[i]);
	printf("%d\n", M);
	for (int i=1; i<=n; ++i)
	  if (dp[i] == M)
	  {
		  vector <int> ans;
		  ans.clear();
		  int akt = i;
		  while (tab[akt].e2 != n)
		  {
			  ans.pb(tab[akt].e2);
			  akt = last[akt];
		  }
		  
		  for (int i = ans.size() - 1; i>=0; --i) printf("%d ", ans[i]);
		  exit(0);
	  }
}