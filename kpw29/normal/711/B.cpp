#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define x first
#define y second
#define tysiac 1010
#define milion 1000100
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define OUT(x) { cout << x; return 0; }
#define PRINT(x, y) {printf("%d %d\n", x, y); return;} 
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
typedef pair <double, int> PDI;

const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int T, n, m, K, a, b, c, k, d, g, Q, DL;

ll tab[510][510];
ll ix[510], iy[510];

int main() {
	boost;
	cin >> n;
	FOR(i, 1, n)
	  FOR(j, 1, n) {
		  cin >> tab[i][j];
		  a = tab[i][j];
		  ix[i] += a;
		  iy[j] += a;
	  }
	if (n == 1) OUT(1);
	ll wyn = max(ix[1], ix[2]);
	ll ans = 0;
	FOR(i, 1, n)
	  FOR(j, 1, n)
	    if (tab[i][j] == 0) {
			tab[i][j] = wyn - ix[i];
			if (tab[i][j] < 1 || tab[i][j] > (ll)1e18) OUT(-1);
			ans = tab[i][j];
			ix[i] += tab[i][j];
			iy[j] += tab[i][j];
		}
	FOR(i, 1, n)
	  if (ix[i] != wyn || iy[i] != wyn) OUT(-1);
	ll s1 = 0, s2 = 0;
	FOR(i, 1, n)
	  s1 += tab[i][i], s2 += tab[i][n-i+1];
	if (s1 != wyn || s2 != wyn) OUT(-1);
	cout << ans;
}