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

string s;
void solve () {
	cin >> s;
	int p = 0, c = 0, sum = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			c++;
			p++;
		} else if ((s[i] - '0') % 2 == 0) {
			p++;
		}
		sum += s[i] - '0';
	}

	if (c && p > 1 && sum % 3 == 0) {
		cout << "red" << endl;
	} else {
		cout << "cyan" << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}