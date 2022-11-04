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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

ll n, p;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> p;

	for (ll i = 0;; i++) {
		ll d = n - p * i;

		if (p > 0 && d < 0) {
			cout << -1 << endl;
			return 0;
		}
		if (d < 0) continue;

		int cn = 0, x = 1, y = 0;
		while (d) {
			if (d & 1) {
				cn += x;
				y++;
			}
			x++;
			d /= 2;
		}

		if (y <= i && i <= cn) {
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}