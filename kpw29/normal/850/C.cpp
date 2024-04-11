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
int n, a;
#define maxn 1000100

map <vector <int>, int> wynik;
map <int, vector <int> > primes;

vector <int> norm(vector <int> v) {
	vector <int> nowy = v;
	sort(nowy.begin(), nowy.end());
	v.clear();
	for (auto u : nowy)
		if (u) v.pb(u);
	
	return v;
}
int licz(vector <int> v) {
	v = norm(v);
	if (v.empty()) return 1;
	if (wynik[v]) return wynik[v];
	int k = v.back();
	int jest[35];
	FOR(j, 1, 34) jest[j] = 0;
	vector <int> nowy;
	for (int i = 1; i <= k; ++i) {
		nowy = v;
		for (auto &u : nowy)
			if (u >= i) u -= i;
		int en = licz(nowy);
		//for (auto u : nowy) cout << u << ' '; cout << endl;
		//cout << "Val: " << en << endl;
		jest[en]++;
	}
	
	int ret = 1;
	while (jest[ret]) ++ret;
	wynik[v] = ret;
	return ret;
}

int main()
{
	wynik.clear();
	boost;
	cin >> n;
	//n = 100;
	FOR(i, 1, n) {
		//a = (1 << 29);
		cin >> a;
		for (int j=2; j<=40000; ++j) {
			int cnt = 0;
			while (a % j == 0) ++cnt, a /= j;
			if (cnt > 0) primes[j].pb(cnt);
		}
if(a>1) primes[a].pb(1);
	}
	
	int nim = 0;
	for (auto &vv : primes) {
		vector <int> u = vv.e2;
		u = norm(u);
		wynik[u] = licz(u);
		nim ^= (wynik[u] - 1);
	}
	
	if (nim > 0) cout << "Mojtaba";
	else cout << "Arpa";
}