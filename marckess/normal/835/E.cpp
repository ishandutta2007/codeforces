#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int query (vi v) {
	cout << "? " << v.size();
	for (int x : v) cout << " " << x;
	cout << endl;
	fflush(stdout);

	int r;
	cin >> r;
	return r;
} 

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	int n, x, y, d = 0, res = -1;

	cin >> n >> x >> y;

	for (int i = 0; i < 10; i++) {
		vi v;

		for (int j = 1; j <= n; j++)
			if (!(j & (1 << i)))
				v.pb(j);

		if (query(v) != x * (v.size() % 2)) {
			d |= (1 << i);

			if (res == -1) {
				int i = 0, j = v.size(), rep = 9;

				while (rep--) {
					int m = (i+j)/2;
					vi aux;
					for (int l = 0; l <= m; l++) aux.pb(v[l]);

					if (query(aux) != x * (aux.size() % 2)) j = m;
					else i = m;
				}

				res = v[j];
			}
		}
	}

	if (res > (res ^ d)) res ^= d;
	cout << "! " << res << " " << (res ^ d) << endl;
	fflush(stdout);

	return 0;
}