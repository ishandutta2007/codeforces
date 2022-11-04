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
 
ll n, m;

ll obtRes (ll aum, ll mk) {
	ll res = 0;

	for (int i = 0; i < 9; i++, mk += aum) {
		if (n + 1 >= mk)
			res += mk / 2;
		else if (2 * n - 1 >= mk)
			res += 1 + (2 * n - 1 - mk) / 2;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	if (n < 5) {
		cout << n * (n - 1) / 2 << endl;
		return 0;
	}

	m = 9;

	while (2 * n - 1 >= m * 10 + 9)
		m = m * 10 + 9;

	cout << obtRes(m+1, m) << endl;

	return 0;
}