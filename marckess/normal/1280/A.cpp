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

const int mod = 1000000007;
ll x, sz;
string s;

void solve () {
	cin >> x >> s;
	sz = s.size();

	for (int i = 0; i < x; i++) {
		string c;

		int sc = sz - (i + 1);

		if (s[i] == '1') continue;

		for (int j = i + 1; j < s.size() && s.size() + c.size() <= x; j++)
			c.pb(s[j]);

		for (int j = 1; j < s[i] - '0'; j++) {
			sz += sc;
			for (int k = 0; k < c.size() && s.size() <= x; k++)
				s.pb(c[k]); 
		}

		sz %= mod;
	}

	cout << MOD(sz, mod) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}