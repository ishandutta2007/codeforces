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

map<int, int> mp;
vi a;

void solve () {
	mp.clear();
	a.clear();

	int n, p;
	cin >> n;
	forn (i, n) {
		cin >> p;
		mp[p]++;
	}

	for (auto it = mp.begin(); it != mp.end(); it++)
		a.pb(it->se);
	reverse(all(a));

	int acu = 0, i = 0;
	while (i + 1 < n && 2 * (a[0] + acu + a[i + 1]) <= n) {
		i++;
		acu += a[i];
	}

	if (i < 2) {
		cout << "0 0 0" << endl;
		return;
	}

	int s = 0, b = acu;
	for (int j = 1; j < i; j++) {
		b -= a[j];
		s += a[j];

		if (b > a[0] && s > a[0]) {
			cout << a[0] << " " << s << " " << b << endl;
			return;
		}
	}

	cout << "0 0 0" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}