#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

ll pot (ll b, ll p, int m) {
	ll res = 1;
	b %= m;

	while (p) {
		if (p & 1) {
			res *= b;
			res %= m;
		}

		b *= b;
		b %= m;
		p /= 2;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll a, b, x, n, m = 1e9+7;

	cin >> a >> b >> n >> x;

	if (a == 1) {
		cout << (
			(pot(a, n, m) * x) % m
			+ (b * (n % m)) % m
			) % m << endl; 
		return 0;
	}

	cout << (
			(pot(a, n, m) * x) % m
			+ (b * ((MOD(pot(a, n, m) - 1, m) * pot(MOD(a - 1, m), m-2, m)) % m)) % m
			) % m << endl;  

	return 0;
}