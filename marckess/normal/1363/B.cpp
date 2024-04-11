#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 1005;
string s;
int acu[MX], n;

void solve () {
	cin >> s;
	n = s.size();
	
	for (int i = 0; i <= n; i++) {
		acu[i] = s[i] - '0';
		if (i) acu[i] += acu[i - 1];
	}

	int res = n;
	for (int i = 0; i <= n; i++) {
		int x = 0;

		if (i) x = acu[i - 1];
		x += (n - i) - (acu[n - 1] - (i ? acu[i - 1] : 0));

		res = min({res, x, n - x});
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}