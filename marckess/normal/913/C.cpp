#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

ll n, l, c[35];
ll res = 0, mn = 1e18;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fill(c, c+35, 1e18);

	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> c[i];

	n = 32;
	for (int i = 1; i < n; i++) {
		if (c[i-1] * 2 < c[i]) {
			c[i] = c[i-1] * 2;
		}
	}

	for (int i = 0; i < n; i++) {
		ll x = (1LL << i);
		
		if (l & x) {
			res += c[i];
		} else {
			if (c[i] < res)
				res = c[i];
		}
	}

	cout << min(res, mn) << endl;

	return 0;
}