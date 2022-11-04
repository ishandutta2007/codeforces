#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const int MX = 200005;
int n;
ll a[MX], res;
set<ll> vis;
vi c, f;

void fac (ll n) {
	if (n < 2) return;

	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0) {
			f.pb(i);

			while (n % i == 0)
				n /= i;
		}

	if (n > 1)
		f.pb(n);
}

void solve (ll p) {
	ll acu = 0;

	for (int i = 0; i < n && acu < res; i++) {
		ll r = a[i] % p;
		if (a[i] - r == 0) acu += p - r;
		else acu += min(r, p - r);
	}

	res = min(res, acu);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));

	cin >> n;

	forn (i, n) {
		cin >> a[i];
		//c.pb(a[i]);
		res += a[i] % 2;
	}

	//sort(all(c));
	//c.erase(unique(all(c)), c.end());
	//random_shuffle(all(c));
	random_shuffle(a, a + n);

	for (int i = 0; i < min(n, 30); i++) {
		f.clear();

		fac(a[i]);
		fac(a[i] - 1);
		fac(a[i] + 1);

		for (ll x : f) {
			if (!vis.count(x))
				solve(x);
			vis.insert(x);
		}
	}

	cout << res << endl;

	return 0;
}