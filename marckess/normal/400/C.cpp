#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m, a, b, c, p, x[100005], y[100005];

	cin >> n >> m >> a >> b >> c >> p;

	for (int i = 0; i < p; i++)
		cin >> x[i] >> y[i];

	a %= 4;
	b %= 2;
	c %= 4;

	while (a--) {
		for (int i = 0; i < p; i++) {
			x[i] = n - x[i] + 1;

			swap(x[i], y[i]);
		}
		swap(n, m);
	}

	while (b--) {
		for (int i = 0; i < p; i++) {
			y[i] = m - y[i] + 1;
		}
	}

	while (c--) {
		for (int i = 0; i < p; i++) {
			y[i] = m - y[i] + 1;
			
			swap(x[i], y[i]);
		}
		swap(n, m);
	}

	for (int i = 0; i < p; i++) {
		cout << x[i] << " " << y[i] << endl;
	}

	return 0;
}