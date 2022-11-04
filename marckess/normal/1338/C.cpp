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
typedef double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005;
ll n;

void solve () {
	cin >> n;
	
	ll i = 0, x = --n / 3;

	while ((1ll << i) <= x) {
		x -= 1ll << i;
		i += 2;
	}

	x += (n % 3 + 1) << i;

	for (int j = 0; j < i; j += 2) {
		ll y = (x & (3ll << j)) >> j;
		x &= ~(3ll << j);
		if (y) y = (y - 1 + n % 3) % 3 + 1;
		x += y << j;
	}

	cout << x << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}