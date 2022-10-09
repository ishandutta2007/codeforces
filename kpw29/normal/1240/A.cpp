#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); }
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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1001000;
string s;
int n, m, a, b, c;
ll k;

ll cena1, okres1, cena2, okres2;
ll both = 0;
ll tab[maxn];

ll jed = 0, dwa = 0;
bool check(ll tickets) {
	both = (ll)tickets / (okres1 * okres2 / __gcd(okres1, okres2));
	jed = tickets / okres1;
	dwa = tickets / okres2;
	ll special_contrib = 0, used = 0;
	FOR(i, 1, min(tickets, both)) special_contrib += (cena1 + cena2) * tab[++used];
	tickets -= min(tickets, both);
	//cout << special_contrib << endl;
	
	FOR(i, 1, min(tickets, jed-both)) special_contrib += (cena1 * tab[++used]);
	tickets -= min(tickets, jed-both);
	//cout << special_contrib << ' ' << tickets << endl;
	FOR(i, 1, min(tickets, dwa-both)) special_contrib += (cena2 * tab[++used]);
	tickets -= min(tickets, dwa-both);

	//cout << special_contrib << ' ' << k * 100 << ' ' << jed << ' ' << dwa << ' ' << both << endl;
	if (special_contrib >= k * 100LL) return true;
	else return false;
}

int main()
{
	boost;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		FOR(i, 1, n) cin >> tab[i];
		sort(tab+1, tab+n+1, greater<ll>());
		cin >> cena1 >> okres1 >> cena2 >> okres2;
		cin >> k;
		if (cena2 > cena1) {
			swap(cena1, cena2);
			swap(okres1, okres2);
		}

		ll x = 0, y = n;
		while (x < y) {
			//cout << x << ' ' << y << endl;
			ll sr = (x + y) / 2;
			if (!check(sr)) x = ++sr;
			else y = sr;
		}

		if (check(x)) cout << x << "\n";
		else cout << "-1\n";
	}
}