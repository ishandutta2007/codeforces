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

int a1, b1, c1;
int a2, b2, c2;
int d[8];
int f[8];

bool solve (int a1, int b1, int c1, int a2, int b2, int c2) {
	if (a1 < 0 || b1 < 0 || c1 < 0) return 0;
	if (a2 < 0 || b2 < 0 || c2 < 0) return 0;

	f[1] = min({a1, b1, c1, d[1]});

	f[4] = min(d[4], a1 - f[1]);
	if (d[4] - f[4] > a2 - d[1] + f[1]) return 0;

	f[6] = min(d[6], b1 - f[1]);
	if (d[6] - f[6] > b2 - d[1] + f[1]) return 0;

	f[7] = min(d[7], c1 - f[1]);
	if (d[7] - f[7] > c2 - d[1] + f[1]) return 0;

	return 1;
}

void solve () {
	cin >> a1 >> b1 >> c1;
	cin >> a2 >> b2 >> c2;
	for (int i = 1; i <= 7; i++)
		cin >> d[i];

	for (f[2] = 0; f[2] <= d[2]; f[2]++)
		for (f[3] = 0; f[3] <= d[3]; f[3]++)
			for (f[5] = 0; f[5] <= d[5]; f[5]++) {
				if (solve(
					a1 - f[2] - f[3], b1 - f[2] - f[5], c1 - f[3] - f[5],
					a2 - (d[2] - f[2]) - (d[3] - f[3]), b2 - (d[2] - f[2]) - (d[5] - f[5]), c2 - (d[3] - f[3]) - (d[5] - f[5])
				)) {
					for (int i = 1; i <= 7; i++)
						cout << f[i] << " ";
					cout << endl;
					return;
				}
			}

	cout << -1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}