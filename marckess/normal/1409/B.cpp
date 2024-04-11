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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;



int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		ll a, b, x, y, n;

		cin >> a >> b >> x >> y >> n;

		ll d = min(n, a - x);
		ll a1 = a - d;
		ll n1 = n - d;
		d = min(n1, b - y);
		ll b1 = b - d;

		d = min(n, b - y);
		ll b2 = b - d;
		ll n2 = n - d;
		d = min(n2, a - x);
		ll a2 = a - d;

		cout << min(a1 * b1, a2 * b2) << endl;
	}	

	return 0;
}