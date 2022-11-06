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

	int t;
	string s;

	cin >> t;

	while (t--) {
		cin >> s;

		vi res;

		for (int i = 1; i <= 12; i++) {
			if (12 % i)
				continue;

			bool ep = false;
			for (int j = 0; j < 12 / i; j++) {
				bool f = true;

				for (int k = 0; k < 12; k += 12 / i)
					f &= s[j+k] == 'X';

				ep |= f;
			}

			if (ep)
				res.push_back(i);
		}

		cout << res.size();
		for (int x : res)
			cout << " " << x << "x" << 12 / x;
		cout << endl;
	}

	return 0;
}