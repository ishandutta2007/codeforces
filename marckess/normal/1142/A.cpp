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

ll n, k, a, b, x = 1e18, y = 0;

void go (ll l) {
	for (ll t = 0; l + t * k <= n * k; t++) {
		ll d = n * k / __gcd(n * k, l + t * k);
		x = min(x, d);
		y = max(y, d);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k >> a >> b;

	go(MOD(b-a, k));
	go(MOD(b+a, k));
	go(MOD(a-b, k));
	go(MOD(-a-b, k));
	
	cout << x << " " << y << endl;

	return 0;
}