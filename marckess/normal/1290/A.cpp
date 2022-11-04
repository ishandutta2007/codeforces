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

const int MX = 3555;
int n, m, k, a[MX];

int go (int l, int r) {
	int t = r - l + 1, res = 1e9;
	t -= (m - 1) - k;
	
	for (int i = l; i + t - 1 <= r; i++)
		res = min(res, max(a[i], a[i + t - 1]));
	return res;
}

void solve () {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	k = min(k, m - 1);

	int res = 0;
	for (int i = 0; i <= k; i++)
		res = max(res, go(1 + i, n - (k - i)));
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