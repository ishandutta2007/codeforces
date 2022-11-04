#include <bits/stdc++.h>
 
//#define endl '\n'
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
 
const int MX = 100005;
const ll lim = 1000000000000000000ll;
vi pri;
int bs[MX];

void pre () {
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			pri.pb(i);
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 1;
		}
}

void solve () {
	int cn = 0, hq = 0;
	vi p, pw;

	for (int i = 0, j = 0; i < 22 - cn; i++) {
		__int128 x = 1;
		
		while (x * pri[j] <= lim) {
			x *= pri[j];
			j++;
		}

		cout << "? " << ll(x) << endl;
		hq++;

		ll res;
		cin >> res;

		forn (k, j)
			if (res % pri[k] == 0) {
				p.pb(pri[k]);
				pw.pb(0);
				cn++;
			}
	}

	forn (i, cn) {
		ll k = p[i];
		if (hq == 22) break;

		__int128 x = 1;

		while (x * k <= lim)
			x *= k;

		cout << "? " << ll(x) << endl;
		hq++;

		ll res;
		cin >> res;

		while (res > 1) {
			pw[i]++;
			res /= k;
		}
	}

	ll res = 1;
	for (ll k : pw)
		res *= max(1ll, k) + 1;
	cout << "! " << 2 * res << endl;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	pre();
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}