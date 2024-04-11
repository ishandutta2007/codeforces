#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = (1 << 14) + 5;
int n, m, p[2 * MX], res, ex[2 * MX], x[MX], y[MX], f[256];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

int join (int a, int b) {
	a = parent(a), b = parent(b);
	if (a == b) return 0;
	p[a] = b;
	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	forn (i, 10) f['0' + i] = i;
	forn (i, 6) f['A' + i] = i + 10;

	cin >> n >> m;

	forn (i, n) {
		int in, k = 1;
		
		forn (j, m) {
			if (j % 4 == 0) {
				char c;
				cin >> c;
				in = f[c];
			}

			if (in & (1 << 3 - (j & 3))) {
				while (ex[k]) k++;
				
				x[j] = k;
				p[k] = k;
				ex[k] = 1;
				res++; 

				if (j && x[j - 1]) res -= join(x[j - 1], x[j]);
				if (y[j]) res -= join(y[j], x[j]);
			} else x[j] = 0;
		}

		forn (j, m) y[j] = parent(x[j]);

		memset(ex, 0, sizeof(ex));
		forn (j, m) ex[y[j]] = 1;

		memset(x, 0, sizeof(x));
	}

	cout << res << endl;

	return 0;
}