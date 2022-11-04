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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, k, a[MX], cn[MX], bs[MX];
ll res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			bs[i] = i;
			for (ll j = i * i; j < MX; j += i)
				bs[j] = i;
		}

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

		ll x = 1, y = 1;
		while (a[i] > 1) {
			int p = bs[a[i]];
			int pw = 0;

			while (a[i] % p == 0) {
				a[i] /= p;
				pw++;
			}

			pw %= k;
			forn (kk, pw)
				x *= p;

			if (y == -1)
				continue;

			pw = (k - pw) % k;
			forn (kk, pw) {
				y *= p;
				if (y >= MX) {
					y = -1;
					break;
				}
			}
		}

		if (y != -1) {
			res += cn[y];
		}

		cn[x]++;
	}

	cout << res << endl;

	return 0;
}