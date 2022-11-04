#include <bits/stdc++.h>
 
//#define endl '\n'
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

int n, k, mn;
map<int, int> mp;

ii query (vi &v) {
	cout << "?";
	for (int x : v)
		cout << " " << x;
	cout << endl;

	ii in;
	cin >> in.fi >> in.se;
	return in;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	mn = 2e9;

	for (int i = 1; i <= k + 1; i++) {
		vi a;
		for (int j = 1; j <= k + 1; j++)
			if (i != j)
				a.pb(j);

		ii x = query(a);
		mp[x.se]++;
		mn = min(mn, x.se);
	}

	cout << "! " << k - mp[mn] + 1 << endl;

	return 0;
}