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
	
	int n, k, a[100005], izq[100005], der[100005];

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		izq[i] = der[i] = a[i];
	}

	if (k == 1) {
		cout << *min_element(a, a+n) << endl;
	} else if (k >= 3) {
		cout << *max_element(a, a+n) << endl;
	} else {

		for (int i = 1; i < n; i++)
			izq[i] = min(izq[i], izq[i-1]);
		for (int i = n - 2; i >= 0; i--)
			der[i] = min(der[i], der[i+1]);

		int res = -1e9;
		for (int i = 0; i < n-1; i++) {
			res = max(res, max(izq[i], der[i+1]));
		}
		cout << res << endl;
	}

	return 0;
}