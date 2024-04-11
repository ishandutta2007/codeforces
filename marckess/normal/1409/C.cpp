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


int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n, x, y;

		cin >> n >> x >> y;

		int ri = 1, rj = 2, mx = 1e9;

		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				if ((y - x) % (j - i) == 0) {
					int d = (y - x) / (j - i);
					int ini = x - d * (i - 1);
					int fin = y + d * (n - j);

					if (ini >= 1 && fin < mx) {
						ri = i;
						rj = j;
						mx = fin;
					}
				}
			}

		int d = (y - x) / (rj - ri);
		int ini = x - d * (ri - 1);

		for (int i = 1; i <= n; i++, ini += d)
			cout << ini << " ";
		cout << endl;
	}	

	return 0;
}