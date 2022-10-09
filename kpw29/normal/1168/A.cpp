#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1001010;
int n, m;
int tab[maxn];

int opt(int a, int b) {
	if (a <= b) return 0;
	return m - b + a;
}
int dp[maxn];

int upd(int start, int x, int y) {
	assert(x <= y);
	if (start >= x && start <= y) return start;
	if (start < x) return x;
	return m;
}

bool check(int k) {
	dp[0] = 0;
	FOR(i, 1, n) {
		int a = tab[i];
		int MAX = a + k; //tyle moze byc maksymalnie 
		if (MAX >= m) {
			dp[i] = min(upd(dp[i-1], a, m-1), upd(dp[i-1], 0, MAX - m));
		}
		else dp[i] = upd(dp[i - 1], a, MAX);
	}

	return dp[n] < m;
}

int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 1, n) cin >> tab[i];
	if (n == 1) OUT(0);
	int x = 0, y = maxn;
	while (x < y) {
		int sr = (x + y) / 2;
		if (!check(sr)) x = ++sr;
		else y = sr;
	}
	
	cout << x;
}