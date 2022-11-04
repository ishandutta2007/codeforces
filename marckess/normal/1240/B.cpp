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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 300005;
int n, a[MX], ini[MX], fin[MX];
vi c;

void solve () {
	cin >> n;

	c.clear();
	for (int i = 1; i <= n; i++)
		ini[i] = fin[i] = -1;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (ini[a[i]] == -1) ini[a[i]] = i;
		fin[a[i]] = i;
		c.pb(a[i]);
	}

	sort(all(c));
	c.erase(unique(all(c)), c.end());

	int res = int(c.size()) - 1, acu = 1;
	for (int i = 1; i < c.size(); i++) {
		if (fin[c[i-1]] < ini[c[i]])
			acu++;
		else
			acu = 1;
		res = min(res, int(c.size()) - acu);
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