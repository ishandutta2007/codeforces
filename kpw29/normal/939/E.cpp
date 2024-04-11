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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1e6 + 10;

int ILE = 0;
ll pref[maxn];
ll tab[maxn];
long double f(int wsk)
{
	ll MAX = tab[ILE] + pref[wsk];
	return (long double)tab[ILE] - (long double)MAX / (wsk + 1);
}

int main()
{
	boost;
	int ope;
	cin >> ope;
	int type, x;
	long double ans = 0.0;
	cout << fixed;
	int wsk = 1;
	while (ope--)
	{
		cin >> type;
		if (type == 2) cout << setprecision(15) << ans << "\n";
		else 
		{
			cin >> x;
			ILE++;
			tab[ILE] = x;
			pref[ILE] = pref[ILE - 1] + x;
			while (wsk < ILE && f(wsk) < f(wsk + 1)) ++wsk;
			ans = max(ans, f(wsk));
		}
	}
}