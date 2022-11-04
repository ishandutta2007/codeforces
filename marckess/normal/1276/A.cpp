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

int n;
string s;
vi res;

void solve () {
	cin >> s;
	n = s.size();
	res.clear();

	for (int i = 0; i < n; i++) {
		if ((i + 2 < n && s.substr(i, 3) == "one") && (i - 2 >= 0 && s.substr(i - 2, 3) == "two")) {
			s[i] = 0;
			res.pb(i);
		} else if ((i + 2 < n && s.substr(i, 3) == "one")) {
			s[i+1] = 0;
			res.pb(i+1);
		} else if ((i - 2 >= 0 && s.substr(i - 2, 3) == "two")) {
			s[i-1] = 0;
			res.pb(i-1);
		}
	}

	cout << res.size() << endl;
	for (int x : res)
		cout << x + 1 << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}