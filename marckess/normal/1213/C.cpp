#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll n, m, mk = 0, res = 0, c = 0, s = 0;
		cin >> n >> m;
		n /= m;
		for (int i = 0; i < 10; i++) {
			int x = (m * i) % 10;
			if (mk & (1 << x)) continue;
			mk |= (1 << x);
			c++;
			s += x;
		}
		res += s * (n / c);
		for (ll i = c * (n / c); i <= n; i++)
			res += (m * i) % 10;
		cout << res << endl;
	}

	return 0;
}