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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, a[MX], x, y;

void solve () {
	cin >> n;
	x = y = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (x == -1) {
			x = i;
		} else if (y == -1 && a[x] != a[i]) {
			y = i;
		}
	}
	if (y == -1) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		cout << x << " " << y << endl;
		for (int i = 1; i <= n; i++)
			if (i != x && i != y) {
				if (a[i] != a[x]) {
					cout << i << " " << x << endl;
				} else {
					cout << i << " " << y << endl;
				}
			}
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