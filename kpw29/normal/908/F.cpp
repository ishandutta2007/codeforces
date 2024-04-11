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
const int maxn = 300100;
PII tab[maxn];

int apply(vector <int> res) {
	int sz = res.size();
	vector <int> help;
	FOR(i, 0, sz-2) help.pb(res[i + 1] - res[i]);
	sort(help.begin(), help.end());
	int pis = 0;
	for (auto u : help) pis += u;
	pis -= help.back();
	return pis;
}
int n;

int main()
{
	boost;
	cin >> n;
	int g = 0, r = 0, b = 0;
	FOR(i, 1, n) 
	{
		char zn;
		cin >> tab[i].e1 >> zn;
		int x = 0; if (zn == 'B') x = 1; if (zn == 'R') x = 2;
		tab[i].e2 = x;
		if (!x) ++g;
		if (x == 1) ++b;
		if (x == 2) ++r;
	}
	sort(tab+1, tab+n+1);
	int result = 0;
	if (g == 0)
	{
		if (r) {
			int st = 1, kon = n;
			while (tab[st].e2 != 2) ++st;
			while (tab[kon].e2 != 2) --kon;
			result += tab[kon].e1 - tab[st].e1;
		}
		if (b) {
			int st = 1, kon = n;
			while (tab[st].e2 != 1) ++st;
			while (tab[kon].e2 != 1) --kon;
			result += tab[kon].e1 - tab[st].e1;
		}
		OUT(result);
	}
	int poczatek = 1, koniec = n;
	while (tab[poczatek].e2) ++poczatek;
	while (tab[koniec].e2) --koniec;
	//we have greens
	if (r) {
		int st = 1, kon = n;
		while (tab[st].e2 != 2) ++st;
		while (tab[kon].e2 != 2) --kon;
		if (poczatek > st) result += tab[poczatek].e1 - tab[st].e1;
		if (koniec < kon) result += tab[kon].e1 - tab[koniec].e1;
	}
	if (b) {
		int st = 1, kon = n;
		while (tab[st].e2 != 1) ++st;
		while (tab[kon].e2 != 1) --kon;
		if (poczatek > st) result += tab[poczatek].e1 - tab[st].e1;
		if (koniec < kon) result += tab[kon].e1 - tab[koniec].e1;
	}

	for (int i=1; i<=n; ++i) {
		if (!tab[i].e2 && i != poczatek) {
			//czas napierdolitsch
			vector <int> blue, red;
			int j = i - 1;
			while (tab[j].e2) --j;
			blue.pb(tab[j].e1); red.pb(tab[j].e1);
			//cout << j << ' ' << i << endl;
			for (int k = j + 1; k < i; ++k)
				if (tab[k].e2 == 1) blue.pb(tab[k].e1);
				else {
					red.pb(tab[k].e1);
					assert(tab[k].e2 == 2);
				}
			
			blue.pb(tab[i].e1); red.pb(tab[i].e1);
			int mn = 2 * (tab[i].e1 - tab[j].e1);
			mn = min(mn, tab[i].e1 - tab[j].e1 + apply(blue) + apply(red));
			result += mn;
		}
	}
	cout << result;
}