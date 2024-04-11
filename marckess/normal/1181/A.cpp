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

	ll x, y, z, a, b, r;
	cin >> x >> y >> z;
	r = x / z + y / z;
	a = x % z;
	b = y % z;
	if (a + b >= z) {
		cout << r + 1 << " " << z - max(a, b) << endl;
	} else {
		cout << r << " " << 0 << endl;
	}

	return 0;
}