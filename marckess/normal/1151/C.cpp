#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mod = 1000000007;
ll l, r, in2, res;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll sum (ll a) {
	a %= mod;
	return a * (a + 1) % mod * in2 % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	in2 = pot(2, mod - 2);

	cin >> l >> r;

	ll s = 1, f = 1, x = 1, y = 0, k = 1;

	while (s <= r) {
		ll i = y, j = y + k - 1;
			
		if (s < l && l - s <= k - 1)
			i += l - s;
		if (s + k - 1 > r)
			j = y + r - s;

		if (s + k - 1 >= l) {
			if (f)
				(res += 2 * (sum(j) - sum(i-1)) + (j - i + 1)) %= mod;
			else
				(res += 2 * (sum(j) - sum(i-1))) %= mod;
		}

		s += k;
		y += k;
		k *= 2;
		swap(x, y);
		f = 1 - f;
	}

	cout << MOD(res, mod) << endl;
	
	return 0;
}