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
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, q, to[2 * MX];
ll a[2 * MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;

	forn (i, n) {
		cin >> a[i];
		a[n + i] = a[i];
	}

	while (q--) {
		ll b;
		cin >> b;

		int i = 0, j = 0, mn = n, ind = 0;
		ll acu = 0;

		while (i < n) {
			while (j < 2 * n && acu + a[j] <= b) {
				acu += a[j];
				j++;
			}

			to[i] = j;
			if (j - i < mn) {
				mn = j - i;
				ind = i;
			}

			acu -= a[i];
			i++;
		}

		int res = n;

		for (int j = ind; j <= to[ind]; j++) {
			int k = j, p = 0;
			acu = 0;

			while (acu < n) {
				k %= n;
				acu += to[k] - k;
				k = to[k];
				p++;
			}

			res = min(res, p);
		}

		cout << res << endl;
	}

	return 0;
}