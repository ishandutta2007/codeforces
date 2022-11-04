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

	int n, m, g[1005], s[1005], res = 0;
	char c;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;

			if (c == 'G')
				g[i] = j;
			if (c == 'S')
				s[i] = j;
		}
	}

	for (int i = 0; i < n; i++)
		if (s[i] < g[i]) {
			cout << -1 << endl;
			return 0;
		}

	bool f = true;

	while (f) {
		int mn = 1e9;
		f = 0;

		for (int i = 0; i < n; i++) {
			if (g[i] < s[i]) {
				mn = min(mn, s[i] - g[i]);
			}
		}

		for (int i = 0; i < n; i++) {
			g[i] += mn;
			f |= (g[i] < s[i]);
		}

		res++;
	}

	cout << res << endl;

	return 0;
}