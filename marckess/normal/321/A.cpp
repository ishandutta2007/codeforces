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

const int MX = 105;
int a, b, x[MX], y[MX], n;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> b >> s;
	n = s.size();

	if (!a && !b) {
		cout << "Yes" << endl;
		return 0;
	}

	forn (i, n) {
		x[i + 1] = x[i];
		y[i + 1] = y[i];

		if (s[i] == 'U') y[i + 1]++;
		if (s[i] == 'D') y[i + 1]--;
		if (s[i] == 'L') x[i + 1]--;
		if (s[i] == 'R') x[i + 1]++;

		if (x[i + 1] == a && y[i + 1] == b) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	if (x[n] && y[n]) forn (i, n + 1)
		if ((a - x[i]) % x[n] == 0 && (a - x[i]) / x[n] >= 0)
			if ((b - y[i]) % y[n] == 0 && (b - y[i]) / y[n] >= 0)
				if ((a - x[i]) / x[n] == (b - y[i]) / y[n]) {
					cout << "Yes" << endl;
					return 0;
				}

	if (x[n] && !y[n]) forn (i, n + 1)
		if ((a - x[i]) % x[n] == 0 && (a - x[i]) / x[n] >= 0)
			if (b == y[i]) {
				cout << "Yes" << endl;
				return 0;
			}

	if (!x[n] && y[n]) forn (i, n + 1)
		if (a == x[i])
			if ((b - y[i]) % y[n] == 0 && (b - y[i]) / y[n] >= 0) {
				cout << "Yes" << endl;
				return 0;
			}

	cout << "No" << endl;

	return 0;
}