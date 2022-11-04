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

ll gcd (ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll n, a, b, p, q, d, res = 0;

	cin >> n >> a >> b >> p >> q;
	d = a * b / gcd (a, b);

	if (p < q) {
		swap (a, b);
		swap (p, q);
	}

	res += (n / a) * p;
	res -= (n / d) * q;
	res += (n / b) * q;

	cout << res << endl;

	return 0;
}