#include <bits/stdc++.h>
#include <string>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 103

int n, m, a, b, c, d, T, st;
PII tab[maxn];

int dp[maxn][maxn][10001];

int main()
{
	cin >> n;
	int all = 0;
	FOR(i, 1, n) {
		cin >> tab[i].e2;
		all += tab[i].e2;
	}
	
	FOR(i, 1, n) cin >> tab[i].e1;
	sort(tab + 1, tab + n + 1);
	int kk = 0, sum = 0;
	for (int i=n; i>0; --i) {
		sum += tab[i].e1;
		if (sum >= all)  {
			kk = i;
			break;
		}
		
	}
	
	kk = n - kk + 1;
	FOR(i, 0, n) dp[i][0][0] = 1;
	
	FOR(i, 1, n)
	  FOR(j, 1, kk) {
	    FOR(l, 0, 10000) {
		  if (l >= tab[i].e1 && dp[i-1][j-1][l - tab[i].e1] > 0) dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][l - tab[i].e1] + tab[i].e2);
		  dp[i][j][l] = max(dp[i][j][l], dp[i-1][j][l]);
	  }
		for (int l=10000; l>=0; --l) dp[i][j][l] = max(dp[i][j][l], dp[i][j][l + 1]);
		}
		
	int MAKS = 0;
	FOR(i, all, 10000) MAKS = max(MAKS, dp[n][kk][i]);
	//cout << MAKS << endl;
	cout << kk << ' ' << all - (MAKS - 1);
}