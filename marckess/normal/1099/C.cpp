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

int k, a, b, n;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> k;
	n = s.size();

	for (int c : s) {
		if (c == '?') a++;
		if (c == '*') b++;
	}

	if (k < n - 2 * a - 2 * b || n - a + k * b < k) {
		cout << "Impossible" << endl;
		return 0;
	}

	string res;
	int x = k - (n - 2 * a - 2 * b);
	for (int i = 0; i < n; i++) {
		if (s[i] == '?' || s[i] == '*') continue;

		if (i + 1 < n && s[i + 1] == '?') {
			if (x) {
				res.pb(s[i]);
				x--;
			}
		} else if (i + 1 < n && s[i + 1] == '*') {
			while (x) {
				res.pb(s[i]);
				x--;
			}
		} else {
			res.pb(s[i]);
		}
	}

	cout << res << endl;

	return 0;
}