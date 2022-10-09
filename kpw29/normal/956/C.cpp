#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REYNA(i, a, b) for (int i=(a); i<(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int maxn = 100100;
int tab[maxn], dp[maxn], n;

int main()
{
	boost;
	cin >> n;
	ll sum = 0;
	FOR(i, 1, n) 
	{
		cin >> tab[i];
	}
	
	dp[0] = 0;
	FOR(i, 1, n)
	{
		dp[i] = dp[i-1];
		dp[i] = max(dp[i], tab[i] + 1);
	}
	
	for (int i=n; i>0; --i)
	{
		dp[i] = max(dp[i], dp[i + 1] - 1);
	}
	
	FOR(i, 1, n)
	{
		if (dp[i] == dp[i-1]) //mozemy wstawic w jedno takie samo
		{
			sum += dp[i] - tab[i] - 1;
		}
		else sum += dp[i] - tab[i]; //musimy uzyc nowego dynksa
	}
	
	cout << sum - dp[n];
}