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
	//ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m, c, p, i, xd;
	cin >> n >> m >> c;

	vi res(n+1, -1);
	xd = n;

	while (m--) {
		cin >> p;

		if (p <= c / 2) {
			i = 1;
			while (i <= n && res[i] != -1 && res[i] <= p)
				i++;

		} else {
			i = n;
			while (i > 0 && res[i] != -1 && res[i] >= p)
				i--;
		}

		cout << i << endl;
		fflush(stdout);

		if (res[i] == -1)
			xd--;
		res[i] = p;

		if (xd == 0) {
			exit(0);
		}
	}

	return 0;
}