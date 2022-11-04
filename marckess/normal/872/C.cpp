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
	
	int q, n;

	cin >> q;

	while (q--) {
		cin >> n;

		if (n % 4 == 0) {
			if (n >= 4)
				cout << n / 4 << endl;
			else
				cout << endl;
		} else if (n % 4 == 1) {
			if (n >= 9)
				cout << (n - 9) / 4 + 1 << endl;
			else
				cout << -1 << endl;
		} else if (n % 4 == 2) {
			if (n >= 6)
				cout << n / 4 << endl;
			else
				cout << -1 << endl;
		} else {
			if (n >= 15)
				cout << (n - 15) / 4 + 2 << endl;
			else
				cout << -1 << endl;
		}
	}

	return 0;
}