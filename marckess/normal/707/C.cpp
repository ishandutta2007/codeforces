#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll n;

	cin >> n;

	if (n < 3) {
		cout << -1 << endl;
	} else if (n % 2) {
		cout << (n * n - 1) / 2 << " " << (n * n + 1) / 2 << endl;
	} else {
		ll x = 1;

		while (n % 2 == 0) {
			n /= 2;
			x *= 2;
		}
		x /= 2;

		if (n < x)
			swap(x, n);

		cout << n * n - x * x << " " << n * n + x * x << endl;
	}

	return 0;
}