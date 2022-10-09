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

bool swapped;
int n, m;
int perm[1000100];

int main()
{
	boost;
	cin >> n >> m;
	if (n > m) swap(n, m), swapped = 1;
	int tab[n + 1][m + 1];
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j) tab[i][j] = j;
	int updated = 1;
	if (m > 4) {
		vector <int> xd;
		for (int i=2; i<=m; i += 2) xd.pb(i);
		for (int i=1; i<=m; i += 2) xd.pb(i);
		vector <int> pom;
		pom.clear();
		for (int i=1; i<=n; ++i) {
			pom.clear();
			int cyclic = (i % m);
			for (int start = cyclic; start < m; ++start) pom.pb(xd[start]);
			for (int start = 0; start < cyclic; ++start) pom.pb(xd[start]);
			assert((int)pom.size() == m);
			for (int j=0; j<m; ++j) tab[i][j + 1] = pom[j];
		}
	}
	else if (m == 4) {
		updated = 0;
		if (n == 1) {
			tab[1][1] = 2; tab[1][2] = 4; tab[1][3] = 1; tab[1][4] = 3;
		}
		if (n == 2) {
			tab[1][1] = 5; tab[1][2] = 4; tab[1][3] = 7; tab[1][4] = 2;
			tab[2][1] = 3; tab[2][2] = 6; tab[2][3] = 1; tab[2][4] = 8;
		}
		if (n == 3) {
			tab[1][1] = 5; tab[1][2] = 4; tab[1][3] = 7; tab[1][4] = 2;
			tab[2][1] = 3; tab[2][2] = 6; tab[2][3] = 1; tab[2][4] = 8;
			
			tab[3][1] = 11; tab[3][2] = 9; tab[3][3] = 12; tab[3][4] = 10;
		}
		if (n == 4) {
			tab[1][1] = 5; tab[1][2] = 4; tab[1][3] = 7; tab[1][4] = 2;
			tab[2][1] = 3; tab[2][2] = 6; tab[2][3] = 1; tab[2][4] = 8;
			
			tab[3][1] = 5 + 8; tab[3][2] = 4 + 8; tab[3][3] = 7 + 8; tab[3][4] = 2 + 8;
			tab[4][1] = 3 + 8; tab[4][2] = 6 + 8; tab[4][3] = 1 + 8; tab[4][4] = 8 + 8;
		}
	}
	else {
	if (n == 1) {
		if (m == 1) OUT("YES\n1");
		OUT("NO");
	}
	if (n == 2) {
		OUT("NO");
	}
	if (n == 3) {
		cout << "YES\n";
		cout << "5 1 8\n";
		cout << "9 3 4\n";
		cout << "2 7 6\n";
		exit(0);
	}
	}
	
	if (swapped) {
		cout << "YES\n";
		FOR(i, 1, n)
			FOR(j, 1, m) tab[i][j] += updated * (i - 1) * m;
		
		int nowe[m + 1][n + 1], stare[m + 1][n + 1], elo = 0;
		FOR(i, 1, m) {
			FOR(j, 1, n) nowe[i][j] = ++elo;
		}
		elo = 0;
		FOR(j, 1, n) {
			FOR(i, 1, m) stare[i][j] = ++elo;
		}
		
		FOR(i, 1, m) {
			FOR(j, 1, n) perm[stare[i][j]] = nowe[i][j];
		}

		for (int i=1; i<=m; ++i) {
			for (int j=1; j<=n; ++j) cout << perm[tab[j][i]] << ' ';
			cout << "\n";
		}
	}
	else {
		cout << "YES\n";
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=m; ++j) cout << tab[i][j] + updated * (i - 1) * m << ' ';
			cout << "\n";
		}
	}
}