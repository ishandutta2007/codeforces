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

vi v, res;
int n;

void solve () {
	cin >> n;
	res.clear();

	while (n) {
		int j = upper_bound(all(v), n) - v.begin() - 1;
		n -= v[j];
		res.pb(j);
	}

	string s;
	s.pb('1');
	
	for (int i = 1; i < res.size(); i++) {
		forn (kk, res[i-1] - res[i])
			s.pb('3');
		s.pb('1');
	}

	forn(kk, res.back())
		s.pb('3');
	s.pb('7');

	cout << s << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 0; i * (i - 1) / 2 <= 1e9; i++)
		v.pb(i * (i - 1) / 2);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}