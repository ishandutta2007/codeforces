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

const int MX = 10000005;
int n, a[MX], lp[MX], d1[MX], d2[MX];

vi fac (int n) {
	vi res;
	while (n > 1) {
		int p = lp[n];
		res.pb(p);
		while (n % p == 0)
			n /= p;
	}
	sort(all(res));
	return res;
}

void solve () {
	cin >> n;
	forn (i, n) {
		cin >> a[i];

		d1[i] = d2[i] = -1;
		vi v = fac(a[i]);

		if (v.size() < 2) continue;

		if (a[i] % 2) {
			d1[i] = v[0];
			d2[i] = v[1];
		} else {
			int x = a[i];
			
			while (x % 2 == 0)
				x /= 2;
			
			if (__gcd(2 + x, a[i]) == 1) {
				d1[i] = 2;
				d2[i] = x;
			}
		}
	}

	forn (i, n) cout << d1[i] << " "; cout << endl;
	forn (i, n) cout << d2[i] << " "; cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (ll i = 2; i < MX; i++)
		if (!lp[i]) {
			lp[i] = i;
			for (ll j = i * i; j < MX; j += i)
				lp[j]= i;
		}

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}