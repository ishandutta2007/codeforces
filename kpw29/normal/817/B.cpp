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
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
int n, k, a, b, c, d, x, y, DL = 0, T;
#define maxn 1000100
ll tab[maxn];

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> tab[i];
	sort(tab+1, tab+n+1);
	if (tab[1] != tab[2] && tab[2] != tab[3])
	{
		//3 different
		int ret = 0;
		FOR(i, 3, n)
			if (tab[i] == tab[3]) ++ret;
		
		OUT(ret);
	}
	if (tab[1] == tab[2] && tab[2] != tab[3])
	{
		int ret = 0;
		FOR(i, 3, n)
			if (tab[i] == tab[3]) ++ret;
		OUT(ret);
	}
	if (tab[1] != tab[2] && tab[2] == tab[3])
	{
		ll ret = 0;
		FOR(i, 2, n)
			if (tab[i] == tab[3]) ++ret;
		OUT(ret * (ret - 1) / 2);
	}
	if (tab[1] == tab[2] && tab[1] == tab[3])
	{
		ll ret = 0;
		FOR(i, 1, n)
			if (tab[i] == tab[3]) ++ret;
		
		OUT(ret * (ret - 1) * (ret - 2) / 6);
	}
	
	
}