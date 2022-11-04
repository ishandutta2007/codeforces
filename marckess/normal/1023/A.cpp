#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, m, f = 0;
string s, t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> s >> t;

	for (int i = 0; i < n; i++) f |= s[i] == '*';

	if (!f) {
		if (s == t) cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}

	if ((int)s.size()-1 > t.size()) {
		cout << "NO" << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (s[i] == '*') break;
		if (s[i] != t[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	reverse(ALL(s));
	reverse(ALL(t));

	for (int i = 0; i < n; i++) {
		if (s[i] == '*') break;
		if (s[i] != t[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}