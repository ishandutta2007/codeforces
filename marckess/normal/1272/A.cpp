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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		vi a(3);
		cin >> a[0] >> a[1] >> a[2];

		int res = abs(a[0] - a[1]) + abs(a[1] - a[2]) + abs(a[0] - a[2]);

		for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
		for (int k = -1; k <= 1; k++) {
			res = min(res, abs((a[0] + i) - (a[1] + j) ) + abs((a[1] + j) - (a[2] + k) ) + abs((a[0] + i) - (a[2] + k) ));
		} 

		cout << res << endl;
	}

	return 0;
}