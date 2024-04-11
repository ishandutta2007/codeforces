#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
typedef vector <int> vi;
const ll mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
ll k;
int n;
#define maxn 110
int tab[maxn];
inline ll Koszt(ll d, ll x) {
	ll r = (x % d);
	if (r == 0) return 0;
	return d - r;
} 

inline ll licz(ll x) {
	ll res = 0;
	FOR(i, 1, n) res += Koszt(x, tab[i]);
	return res;
}
void binsearch(ll x, ll y)
{
	while (x < y)
	{
		ll sr = ((x + y) / 2)+1;
		if (licz(sr) > k) y = --sr;
		else x = sr;
	}
	if (licz(x) <= k) OUT(x);
}
ll LAST;
inline void check(ll d) {
	ll g = licz(d);
	if (g > k) return;
	//cout << "Checking: " << d << ' ' << g << endl;
	//tutaj na pewno bedzie wynik
	binsearch(d, LAST);
}

const int C = 1000000;
//const int C = 0;
vector <int> szukaj;



int main()
{
	boost;
	cin >> n >> k;
	int MAX = 0;
	FOR(i, 1, n) 
	{
		cin >> tab[i];
		MAX = max(MAX, tab[i]);
		for (int j=1; j*j<=tab[i]; ++j)
			{
				if (tab[i] / j > C) {
					szukaj.pb(tab[i] / j);
					szukaj.pb(tab[i] / j + 1);
				}
			}
	}
	
	LAST = 150000000000000LL;
	sort(szukaj.begin(), szukaj.end());
	for (int val = szukaj.size() - 1; val >= 0; --val) 
	{
		check(szukaj[val]);
		LAST = szukaj[val] - 1;
	}
	
	check(C + 1);
	for (int val = C; val >= 1; --val)
		if (licz(val) <= k) OUT(val);
}