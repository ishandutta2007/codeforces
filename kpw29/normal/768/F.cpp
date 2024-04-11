#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false);}
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector <int> vi;
const int mod = 1e9+7;
const int inf = 1e9+10;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 500100
ll silnia[maxn];
ll licznik, mianownik;

inline ll potmod(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a)%mod;
		a = (a * a)%mod;
		b /= 2;
	}
	return res;
}

inline ll mdiv(ll a, ll b) {
	return a * potmod(b, mod -2 ) %mod;
}

inline ll dwumian(ll n, ll k) {
	ll gora = silnia[n];
	ll dol = silnia[k] * silnia[n - k] % mod;
	return mdiv(gora, dol);
}
inline ll policz(int stosow, ll elementow)
{
	if (elementow < 0) return 0;
	if (elementow == 0) return 1;
	return dwumian(stosow + elementow - 1, elementow);
}
int food, wine, h;
inline void zlicz(int stosow, int zaczyna)
{
	//najpierw jedzenie, potem wino
	int stosjed = stosow / 2, stoswin = stosow / 2;
	if (zaczyna == 0 && stosow % 2 == 1) ++stosjed;
	if (zaczyna == 1 && stosow % 2 == 1) ++stoswin;
	if (stoswin == 0 && wine > 0) return;
	if (stosjed == 0 && food > 0) return;
	//cout << "L : " << stosjed << ' ' << stoswin << endl;
	ll jedzenie = policz(stosjed, food - stosjed);
	ll winoDobre = policz(stoswin, (ll)wine - (ll)stoswin * (h + 1));
	ll winoWszystkie = policz(stoswin, wine - stoswin);
	//cout << jedzenie << ' ' << winoWszystkie << endl;
	licznik += jedzenie * winoDobre;
	mianownik += jedzenie * winoWszystkie;
	licznik %= mod;
	mianownik %= mod;
}

int main()
{
	silnia[0] = 1;
	FOR(i, 1, maxn - 10) silnia[i] = silnia[i-1] * i % mod;
	cin >> food >> wine >> h;
	FOR(starter, 0, 1)
		FOR(stacks, 0, food + wine) zlicz(stacks, starter);
	//cout << licznik << ' ' << mianownik << endl;
	cout << licznik * potmod(mianownik, mod - 2) % mod;
}