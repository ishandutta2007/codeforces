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
const int maxn = 500100;
int tab[maxn], n, u;

int main()
{
	boost;
	cin >> n >> u;
	FOR(i, 1, n) cin >> tab[i];
	tab[n + 1] = inf + inf;
	int k = 3;
	long double ans = 0.0;
	bool ok = 0;
	FOR(i, 1, n - 2)
	{
		while (tab[k] - tab[i] <= u) ++k;
		--k;
		if (k >= i + 2) ok = 1, ans = max(ans, (long double)(tab[k] - tab[i + 1]) / (long double)(tab[k] - tab[i]));
	}
	
	cout << fixed;
	cout << setprecision(15);
	if (ok) cout << ans;
	else cout << -1;
}