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

const int MX = 600005;
int n, a[MX], mn, cn, res, ra, rb;
string s;
vi v[2 * MX];

int find (vi &v, int x) {
	return lower_bound(all(v), x) - v.begin();
}

int count (vi &v, int l, int r) {
	return find(v, r + 1) - find(v, l);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;
	s = " " + s + s;

	for (int i = 1; i <= 2 * n; i++) {
		a[i] = a[i-1];
		a[i] += s[i] == '(' ? 1 : -1;
		mn = min(mn, a[i]);
		v[a[i] + MX].pb(i);
	}

	if (a[2 * n] != 0) {
		cout << 0 << endl << 1 << " " << 1 << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++)
		if (a[i] == mn)
			cn++;

	res = cn;

	for (int i = 1; i <= n; i++)
		if (a[i] == mn) {
			int p = find(v[mn + MX], i);
			int k = count(v[mn + 1 + MX], v[mn + MX][p], v[mn + MX][p + 1]);

			if (k > res) {
				res = k;
				ra = v[mn + MX][p] + 1;
				rb = v[mn + MX][p + 1];
			}
		} else if (a[i] == mn + 1) {
			int p = find(v[mn + 1 + MX], i);
			int k = count(v[mn + 2 + MX], v[mn + 1 + MX][p], v[mn + 1 + MX][p + 1]);

			if (!count(v[mn + MX], v[mn + 1 + MX][p], v[mn + 1 + MX][p + 1])) {
				if (k + cn > res) {
					res = k + cn;
					ra = v[mn + 1 + MX][p] + 1;
					rb = v[mn + 1 + MX][p+1];
				}
			}
		}

	cout << res << endl;
	
	ra = ra % n, rb = rb % n;
	if (ra == 0) ra = n;
	if (rb == 0) rb = n;

	cout << ra << " " << rb << endl;

	return 0;
}