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

void solve () {
	int n, mn = -1, mx = -1;
	string s;

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') continue;
		if (mn == -1) mn = i;
		mx = i;
	}

	int res = n;
	if (mn != -1) {
		res = max(res, 2 * (mx + 1));
		res = max(res, 2 * n - (2 * mn));
	}
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}