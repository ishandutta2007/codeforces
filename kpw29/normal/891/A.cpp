#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <int, PII> PIP;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;
const int maxn = 5010;
int n;
int tab[maxn];

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> tab[i];
	int g = tab[1];
	FOR(i, 2, n) g = __gcd(g, tab[i]);
	if (g > 1) OUT(-1);
	
	int jed = 0;
	FOR(i, 1, n)
		if (tab[i] == 1) ++jed;
	
	if (jed > 0) OUT(n - jed);
	
	int gre = n + 1;
	FOR(i, 1, n)
	{
		int g = tab[i];
		FOR(j, i, n) {
			g = __gcd(g, tab[j]);
			if (g == 1) gre = min(gre, j - i + 1);
		}
	}
	OUT(n - 1 + (gre - 1));
}