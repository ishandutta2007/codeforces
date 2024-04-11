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
int n, a[MX];
ll res = 0;
vi v, d;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
		
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i])
			v.pb(i);
	}

	if (v.size() < 2) {
		cout << -1 << endl;
		return 0;
	}

	int m = v.size();
	for (ll i = 2; i * i <= m; i++)
		if (m % i == 0) {
			d.pb(i);
			while (m % i == 0)
				m /= i;
		}

	if (m > 1)
		d.pb(m);

	ll res = 1e18;
	for (int x : d) {
		ll p = 0;
		for (int i = 0; i < v.size(); i += x) {
			int j = i + x / 2;
			for (int k = 0; k < x; k++)
				p += abs(v[j] - v[i+k]);
		}
		res = min(res, p);
	}
	cout << res << endl;

	return 0;
}