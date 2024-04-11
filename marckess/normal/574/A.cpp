#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
#define MOD(n,k) ((((n) % (k)) + (k)) % (k))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, a[105];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int res = 0;
	bool f = 1;
	while (f) {
		f = 0;

		int mx = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] >= a[mx]) {
				mx = i;
				f = 1;
			}
		}

		if (mx)
			res++;
		a[mx]--;
		a[0]++;
	}

	cout << res << endl;

	return 0;
}