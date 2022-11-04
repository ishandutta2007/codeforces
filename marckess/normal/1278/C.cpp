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

const int MX = 200005;
int n, a[MX], res, s;
map<int, int> mp;

int solve () {
	cin >> n;
	mp.clear();
	s = 0;
	res = 2 * n;

	forn(i, 2 * n) {
		cin >> a[i];
		if (a[i] == 2) a[i] = -1;
		s += a[i];
	}

	mp[0] = 0;
	int acu = 0;
	for (int i = n; i < 2 * n; i++) {
		acu += a[i];
		if (!mp.count(acu)) mp[acu] = i - n + 1;
	}

	acu = 0;
	if (mp.count(s))
		res = mp[s];

	acu = -s;
	for (int i = n - 1; i >= 0; i--) {
		acu += a[i];
		if (mp.count(-acu))
			res = min(res, mp[-acu] + n - i);
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}	

	return 0;
}