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
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m;
int dp[maxn], t[maxn];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", &t[i]);
	int wyn = 0;
	for (int i=1; i<=n; ++i)
	{
		int s = sqrt(t[i]), l = 0;
		for (int j=2; j<=s; ++j)
		  if (t[i] % j == 0) l = max(l, dp[j]), l = max(dp[t[i] / j], l);
		l = max(l, dp[t[i]]);
		++l;
		for (int j=1; j<=s; ++j)
		  if (t[i] % j == 0)
		  {
			  dp[j] = max(dp[j], l);
			  dp[t[i] / j] = max(dp[t[i] / j], l);
		  }
	}
	for (int i=2; i<maxn; ++i) wyn = max(wyn, dp[i]);
	cout << max(1, wyn);
	
}