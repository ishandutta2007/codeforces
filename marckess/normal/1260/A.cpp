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

#define sq(n) (ll(n)*(n))

void solve () {
	int c, sum;
	ll res = 1e18;
	cin >> c >> sum;

	int x = sum / c;
	for (int i = 0; i <= c; i++)
		if (x * i + (x + 1) * (c - i) == sum)
			res = min(res, sq(x) * i + sq(x + 1) * (c - i));

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	while (n--)
		solve();	

	return 0;
}