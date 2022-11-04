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

const int LG = 21, MX = 1 << LG;
int n, a[1000005];
ii dp[MX+5];
vi pos[2000005];

void add (int i, int x) {
	if (dp[i].fi == x || dp[i].se == x) return;
	if (dp[i].fi < x) {
		dp[i].se = dp[i].fi;
		dp[i].fi = x;
	} else if (dp[i].se < x) {
		dp[i].se = x;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn(i, n) {
		cin >> a[i+1];
		pos[a[i+1]].pb(i+1);
	}

	for (int i = 2000000; i + 1; i--) {
		for (int j : pos[i])
			add(i, j);

		forn (j, LG)
			if (~i & (1 << j)) {
				add(i, dp[i | (1 << j)].fi);
				add(i, dp[i | (1 << j)].se);
			}
	}

	int res = 0;
	forr(i, 1, n - 2) {
		int q = 0;
		for (int j = LG - 1; j + 1; j--)
			if (~a[i] & (1 << j))
				if (dp[q | (1 << j)].se > i)
					q |= 1 << j;
		res = max(res, a[i] | q);
	}
	cout << res << endl;

	return 0;
}