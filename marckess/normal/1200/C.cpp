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
typedef vector<ll> vl;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll n, m, q;
	cin >> n >> m >> q;
	ll g = __gcd(n, m);

	while (q--) {
		ll x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		y1--, y2--;
		
		if (x1 == 1) y1 = y1 / (n / g);
		else y1 = y1 / (m / g);
		if (x2 == 1) y2 = y2 / (n / g);
		else y2 = y2 / (m / g);

		if (y1 == y2) cout << "YES" << endl;
		else cout << "NO" << endl; 
	}
 
	return 0;
}