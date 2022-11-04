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

const int MX = 200005;
int n, a[MX], ini[MX], fin[MX], dp[MX], cn[MX];
vi pos[MX];

void solve () {
	vi c;

	cin >> n;
	forn (i, n) {
		cin >> a[i];
		c.pb(a[i]);

		ini[i] = -1;
		cn[i] = 0;
		pos[i].clear();
	}

	sort(all(c));
	c.erase(unique(all(c)), c.end());

	forn (i, n) {
		a[i] = lower_bound(all(c), a[i]) - c.begin();
		
		if (ini[a[i]] == -1) ini[a[i]] = i;
		fin[a[i]] = i;
		cn[a[i]]++;
		pos[a[i]].pb(i);
	}

	int res = n;
	int m = c.size();

	ini[m] = fin[m] = -1;
	cn[m] = 0;
	dp[m] = 0;
	pos[m].clear();

	for (int i = m - 1; i >= 0; i--) {
		dp[i] = cn[i];

		if (fin[i] < ini[i + 1]){
			dp[i] += dp[i + 1];
		} else {
			dp[i] += int(pos[i + 1].size()) - (lower_bound(all(pos[i + 1]), fin[i]) - pos[i + 1].begin());
		}

		int p = dp[i];

		p = max(
			p, 
			int(lower_bound(all(pos[i]), ini[i + 1]) - pos[i].begin()) + dp[i + 1]
		);

		res = min(res, n - p);
	}

	forn (i, n) {
		int p = upper_bound(all(pos[a[i]]), i) - pos[a[i]].begin();
		p += int(pos[a[i] + 1].size()) - (lower_bound(all(pos[a[i] + 1]), i) - pos[a[i] + 1].begin());
		res = min(res, n - p);
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