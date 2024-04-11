#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2e6+5, mod = 1e9+7;
int n, a[MX], pw[MX], cn[MX], bs[MX], f = 0;
ll res = 1;
bitset<MX> d;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			bs[i] = i;
			for (ll j = i * i; j < MX; j += i)
				bs[j] = i;
		}

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n, greater<int>());

	for (int i = 0; i < n; i++) {
		if (!pw[a[i]]) pw[a[i]] = 1, cn[a[i]] = 1;
		else {
			int x = a[i] - 1;

			while (x > 1) {
				int p = bs[x], e = 0;
				while (x % p == 0) x /= p, e++;

				if (e > pw[p]) pw[p] = e, cn[p] = 1;
				else if (e == pw[p]) cn[p]++;
			}

			d[i] = 1;
		}
	}

	for (int i = 0; i < n; i++)
		if (d[i]) {
			int x = a[i] - 1, g = 0;

			while (x > 1) {
				int p = bs[x], e = 0;
				while (x % p == 0) x /= p, e++;
				g |= e == pw[p] && cn[p] == 1;
			}

			f |= 1 - g;
		}

	for (int i = 2; i < MX; i++)
		while (pw[i]--)
			res = res * i % mod;

	cout << (res + f) % mod << endl;

	return 0;
}