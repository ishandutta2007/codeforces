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

	int n, t, k, a[200005], ini[200005], fin[200005], x[200005], y[200005], m = 0;

	cin >> n >> t >> k;
	a[0] = 1;
	for (int i = 1; i <= t; i++)
		cin >> a[i];

	ini[0] = fin[0] = 1;
	for (int i = 1; i <= t; i++) {
		ini[i] = ini[i-1] + a[i-1];
		fin[i] = ini[i] + a[i] - 1;
	}

	k -= a[t];
	for (int i = 1; i < t; i++) {
		if (a[i] > a[i+1]) {
			fin[i] = ini[i] + a[i+1] - 1;
			k -= a[i] - a[i+1];
		}
	}

	if (k < 0) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = t; i; i--) {
		if (k > 0) {
			int q = min(k, fin[i-1] - ini[i-1]);
			k -= q;
			fin[i-1] -= q;
		}

		for (int l = 0, j = ini[i-1]; l < a[i]; l++) {
			x[m] = ini[i] + l;
			y[m] = j;
			m++;

			if (j < fin[i-1])
				j++;
		}
	}

	if (k != 0) {
		cout << -1 << endl;
	} else {
		cout << n << endl;
		for (int i = 0; i < m; i++)
			cout << x[i] << " " << y[i] << endl;
	}

	return 0;
}