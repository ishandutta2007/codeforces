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

const int MX = 100005;
int n, m, a[MX];
set<int> st[2 * MX];
ll res = 0;

void solve () {
	for (int i = 0; i < 2 * MX; i++)
		st[i].clear();

	for (int i = 1; i <= n; i++)
		st[i + m].insert(i);
	
	for (int i = 0; i < m; i++) {
		auto &x = st[a[i] - i - 1 + m];
		auto &y = st[a[i] - i - 2 + m];
		if (y.size() < x.size()) swap(x, y);

		for (int k : x)
			y.insert(k);
		x.clear();
	}

	for (int i = 0; i < 2 * MX; i++) {
		for (int k : st[i]) {
			res += min(n, max(i + 1, k)) - k + 1;
		}
	}
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> a[i];

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}

	solve();
	for (int i = 0; i < m; i++) a[i] = n - a[i] + 1;
	solve();

	cout << res - n << endl;

	return 0;
}