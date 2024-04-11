#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 14;
int n, adj[MX][MX], sza, szb, mk;
ll res[(1 << MX) + 5];
int izq[(1 << (MX / 2)) + 5][MX][2], der[(1 << (MX / 2)) + 5][MX];
vi l, r;

void goizq () {
	do {
		int x = 0;
		forn (i, sza - 1)
			x |= adj[l[i]][l[i + 1]] << i;

		for (int p : r)
			izq[x][p][adj[l.back()][p]]++;
	} while (next_permutation(all(l)));
}

void goder () {
	do {
		int x = 0;
		forn (i, szb - 1)
			x |= adj[r[i]][r[i + 1]] << i;
		der[x][r[0]]++;
	} while (next_permutation(all(r)));
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) forn (j, n) {
		char c;
		cin >> c;
		adj[i][j] = c - '0';
	}

	sza = n / 2;
	szb = n - sza;
	mk = (1 << n) - 1;

	for (int i = 0; i < (1 << n); i++)
		if (__builtin_popcount(i) == sza) {
			int j = i ^ mk;
			memset(izq, 0, sizeof(izq));
			memset(der, 0, sizeof(der));

			l.clear(), r.clear();

			forn (k, n) if (i & (1 << k)) l.pb(k);
			forn (k, n) if (j & (1 << k)) r.pb(k);

			goizq();
			goder();

			forn (a, 1 << sza - 1) forn (b, 1 << szb - 1) for (int p : r) {
				int x = a + (b << sza);
				res[x] += izq[a][p][0] * der[b][p];
				res[x | (1 << sza - 1)] += izq[a][p][1] * der[b][p];
			}
		}


	forn (i, 1 << n - 1) cout << res[i] << " ";
	cout << endl;

	return 0;
}