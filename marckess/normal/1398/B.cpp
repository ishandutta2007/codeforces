#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
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

const int MX = 100005;
string s;

void solve () {
	cin >> s;

	vi v;
	int cn = 0;

	for (char c : s) {
		if (c == '1') cn++;
		else {
			if (cn) v.pb(cn);
			cn = 0;
		}
	}

	if (cn) v.pb(cn);

	sort(all(v));
	reverse(all(v));

	int res = 0;
	forn (i, v.size()) if (i % 2 == 0) res += v[i];

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