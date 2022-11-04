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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, q, a[MX], x[MX], y[MX], res[MX], adj[19][19], aux[19];
string yes = "Shi", no = "Fou";
vi pos[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 0; i < q; i++) {
		cin >> x[i] >> y[i];
		pos[x[i]].pb(i);
	}

	forn(i,19) forn(j,19) adj[i][j] = n + 1;

	for (int i = n; i; i--) {
		forn (j, 19) aux[j] = n + 1; 

		for (int j = 0; j < 19; j++)
			if (a[i] & (1 << j)) {
				aux[j] = i;
				for (int k = 0; k < 19; k++)
					aux[k] = min(aux[k], adj[j][k]);
			}

		for (int j = 0; j < 19; j++)
			if (a[i] & (1 << j))
				for (int k = 0; k < 19; k++)
					adj[j][k] = min(adj[j][k], aux[k]);

		for (int c : pos[i]) {
			int to = y[c];

			for (int j = 0; j < 19; j++)
				if (a[i] & (1 << j))
					for (int k = 0; k < 19; k++)
						if (a[to] & (1 << k))
							if (adj[j][k] <= to) {
								res[c] = 1;
								break;
							}
		}
	}

	for (int i = 0; i < q; i++)
		if (res[i]) cout << yes << endl;
		else cout << no << endl;

	return 0;
}