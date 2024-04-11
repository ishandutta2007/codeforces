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
int n, a[MX];

void solve () {
	cin >> n;
	forn (i, n) cin >> a[i];

	for (int j = 30; j >= 0; j--) {
		int cn = 0;
		forn (i, n) if (a[i] & (1 << j)) cn++;
		if (cn & 1) {
			if (cn % 4 == 1 || (n - cn) % 2 == 1) {
				cout << "WIN" << endl;
				return;
			} else {
				cout << "LOSE" << endl;
				return;
			}
		}
	}

	cout << "DRAW" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}