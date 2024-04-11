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
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef pair <PII, ll> PIIL;
typedef pair <int, ll> PIL;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000010

int tab[maxn], a, b, n, m, c, k;
ll dp[maxn];
int main()
{	
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> tab[i];
	dp[0] = 1;
	for (int i=1; i<=n; ++i)
	{
		int nuts = 0;
		for (int j=i; j>0; --j)
		{
			nuts += tab[j];
			if (nuts == 1) dp[i] += dp[j-1];
			
		}
		
	}
	//for (int i=1; i<=n; ++i) cout << dp[i] << ' ';
	cout << dp[n];
}