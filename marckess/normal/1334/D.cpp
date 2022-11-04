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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
ll n, l, r;

void solve () {
	cin >> n >> l >> r;
	l--, r--;

	ll ini = 1, acu = 0;
	while (ini < n && acu + 2 * (n - ini) <= l) {
		acu += 2 * (n - ini);
		ini++;
	}

	ll se = ini + 1 + (l - acu) / 2;
	if (ini == n) ini = 1;

	while (l <= r) {
		if (l % 2 == 0) {
			cout << ini << " ";
		} else {
			cout << se << " ";

			if (se == n) {
				ini++;
				se = ini + 1;
				if (ini == n) {
					ini = 1;
				}
			} else {
				se++;
			}
		}

		l++;
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