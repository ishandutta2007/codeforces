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
typedef vector<ii> vii;

int a, b, c;

void solve () {
	int res = 0;
	cin >> a >> b >> c;

	for (int i = 1; i < (1 << 7); i++) {
		int x = 0, y = 0, z = 0;

		for (int j = 0; j < 7; j++)
			if (i & (1 << j)) {
				if (j + 1 & 1) x++;
				if (j + 1 & 2) y++;
				if (j + 1 & 4) z++;
			}

		if (x <= a && y <= b && z <= c)
			res = max(res, __builtin_popcount(i));
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