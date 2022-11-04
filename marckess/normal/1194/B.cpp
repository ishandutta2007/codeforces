#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;
 
const int MX = 100000;
int n, m, cn[MX], cm[MX];

void solve () {
	cin >> n >> m;
	fill(cn, cn+n, 0);
	fill(cm, cm+m, 0);
	vvi a(n, vi(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '*') cn[i]++, cm[j]++, a[i][j] = 1;
		}
	int res = 1e9;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res = min(res, n + m - cn[i] - cm[j] - 1 + a[i][j]);
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int q;
	cin >> q;
	while (q--) {
		solve();
	}

	return 0;
}