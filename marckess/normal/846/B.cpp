#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll n, k, m, t[50], acu = 0;

	cin >> n >>	k >> m;
	for (ll i = 0; i < k; i++) {
		cin >> t[i];
		acu += t[i];
	}

	sort(t, t+k);

	ll res = 0;
	for (ll i = 0; i <= n; i++) {
		ll par = 0, cs;

		if (acu * i <= m) {
			par = i * (k + 1);
			cs = acu * i;

			for (ll j = 0; j < k ; j++) {
				ll x = n - i;

				while (x && cs + t[j] <= m) {
					par++;
					cs += t[j];

					x--;
				}
			}
		}

		res = max (res, par);
	}

	cout << res << endl;

	return 0;
}