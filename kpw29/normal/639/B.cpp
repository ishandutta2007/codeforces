#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define OUT(x) { cout << x; return 0; }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;

int n, m, a, b, c,d, k, h;
vector <PII> edges;

int main()
{
	int SET = 2;
	cin >> n >> d >> h;
	if (h + h < d || d < h) OUT("-1");
	if (d == 1 && n == 2) OUT("1 2");
	if (d == 1) OUT("-1");
	if (d == 2) {
		if (h == 1) {
			for (int i=2; i<=n; ++i) printf("%d %d\n", 1, i);
			exit(0);
		}
	}
	
	for (int i=2; i<=h+1; ++i) edges.pb(mp(i-1, i));
	int reszta = d - h;
	int nowy = h + 2;
	if (reszta) reszta--, edges.pb(mp(1, nowy)), ++nowy;
	while (reszta > 0) {
		edges.pb(mp(nowy - 1, nowy));
		++nowy;
		--reszta;
	}
	for (int i=nowy; i <= n; ++i) edges.pb(mp(SET, i));
	for (auto u : edges) printf("%d %d\n", u.e1, u.e2);
	
}