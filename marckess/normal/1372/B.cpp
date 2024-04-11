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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll n, a, b, mn;

void go (ll x, ll y) {
	ll lcm = x * y / __gcd(x, y);
	if (lcm < mn) {
		mn = lcm;
		a = x;
		b = y;
	}
}

void solve () {
	cin >> n;

	a = n - 1, b = 1, mn = n - 1;

	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0) {
			go(i, n - i);
			go(n / i, n - n / i);
		}

	cout << a << " " << b << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}