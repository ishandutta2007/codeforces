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

int a, b, q, acu[205 * 205], cn;
ll l, r, k;

void pre () {
	memset(acu, 0, sizeof(acu));
	cn = 0;

	k = a * b;

	for (int i = 1; i <= k; i++) {
		ll x = (i % a) % b;
		ll y = (i % b) % a;

		if (x != y) {
			acu[i] = 1;
			cn++;
		}
		acu[i] += acu[i - 1];
	}
}

ll f (ll n) {
	return (n / k) * cn + acu[n % k];
}

void solve () {
	cin >> a >> b >> q;

	pre();

	while (q--) {
		cin >> l >> r;
		cout << f(r) - f(l - 1) << " "; 
	}

	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}