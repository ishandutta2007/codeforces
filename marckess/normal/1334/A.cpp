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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, p[MX], c[MX];

void solve () {
	cin >> n;
	forn (i, n) cin >> p[i] >> c[i];

	if (p[0] < c[0]) {
		cout << "no" << endl;
		return;
	}

	for (int i = 1; i < n; i++) {
		if (p[i] < p[i - 1]) {
			cout << "no" << endl;
			return;
		} else if (p[i] == p[i - 1]) {
			if (c[i] != c[i - 1]) {
				cout << "no" << endl;
				return;
			}
		} else {
			if (c[i] < c[i - 1] || p[i] - p[i - 1] < c[i] - c[i - 1]) {
				cout << "no" << endl;
				return;
			}
		}
	}

	cout << "yes" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}