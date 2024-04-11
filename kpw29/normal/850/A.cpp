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
int tab[1010][5];
ll x[5], y[5];
bool spoko[1010];
int n;
int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) {
		FOR(dim, 0, 4) cin >> tab[i][dim];
	}
	FOR(i, 1, n) spoko[i] = 1;
	for (int i=1; i<=n; ++i) {
		if (!spoko[i]) continue;
		for (int j=1; j<=n; ++j) {
			if (!spoko[i]) break;
			for (int k=1; k<=n; ++k) {
				if (i == j || i == k || k == j) continue;
				FOR(h, 0, 4) x[h] = tab[i][h] - tab[j][h];
				ll res = 0;
				FOR(h, 0, 4) {
					y[h] = tab[k][h] - tab[i][h];
					res += x[h] * y[h];
				}
				if (res < 0) {
					spoko[i] = 0;
					break;
				}
			}
		}
	}
	
	int wskaz = 0;
	FOR(i, 1, n) if (spoko[i]) ++wskaz;
	cout << wskaz << endl;
	FOR(i, 1, n) if (spoko[i]) cout << i << ' ';
}