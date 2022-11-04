#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m, op, q, x, y;

	cin >> n >> m >> q;

	vi cf(n+1), tf(n+1);
	vi cc(m+1), tc(m+1);

	for (int i = 1; i <= q; i++) {
		cin >> op >> x >> y;

		if (op == 1) {
			cf[x] = y;
			tf[x] = i;
		} else {
			cc[x] = y;
			tc[x] = i;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (tf[i] > tc[j])
				cout << cf[i];
			else
				cout << cc[j];
			cout << " ";
		}
		cout << endl;
	}

	return 0;
}