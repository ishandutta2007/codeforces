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
const ll mod = 1e9+696969;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1001000;

int tab[maxn];


int main()
{
	boost;
	int n;
	cin >> n;
	int alice;
	cin >> alice;
	vector <int> odp;
	odp.pb(1);
	int sumall = alice;
	int suma = alice;
	FOR(i, 2, n) {
		int b;
		cin >> b;
		sumall += b;
		if (2 * b <= alice) suma += b, odp.pb(i);
	}
	
	if (2 * suma > sumall) {
		cout << (int)odp.size() << endl;
		for (auto u : odp) cout << u << ' ';
	}
	else cout << 0;
}