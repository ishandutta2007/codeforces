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
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const int BASE=10000;
int n, m, b, c, k;
#define maxn 2000100
char s[maxn];
set <PII> lett;
int ile[27];
int slowo[maxn];
ll sum[maxn], dp[maxn], last[maxn];
int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	int dl = 1;
	while (s[dl]) ++dl; --dl;
	for (int i=1; i<=dl; ++i) {
		ile[s[i] - 'a'] = i;
		slowo[i] = s[i] - 'a';
	}
	
	for (int i=0; i<k; ++i) lett.insert(mp(ile[i],  i));
	for (int i=0; i<n; ++i)
	{
		PII ff = * (lett.begin());
		lett.erase(lett.begin());
		swap(ff.e1, ff.e2);
		slowo[++dl] = ff.e1;
		ile[ff.e1] = dl;
		lett.insert(mp(ile[ff.e1], ff.e1));
	}

	dp[0] = sum[0] = 1;
	for (int i = 1; i <= dl; i++) 
	{
    	dp[i] = (dp[i - 1] * 2LL)%mod;
    	if (last[slowo[i]] != 0) dp[i] = (dp[i] - dp[last[slowo[i]] - 1] + mod)%mod;
    	last[slowo[i]] = i;
	}

	cout << dp[dl]% mod;
}