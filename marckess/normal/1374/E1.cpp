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
int n, k, a[MX], b[MX], t[MX];
vi x, y, xy;

void solve () {
	cin >> n >> k;
	
	forn (i, n) {
		cin >> t[i] >> a[i] >> b[i];
		
		if (a[i] && b[i]) xy.pb(t[i]);
		else if (a[i]) x.pb(t[i]);
		else if (b[i]) y.pb(t[i]);
	}

	sort(all(xy));
	sort(all(x));
	sort(all(y));

	ll sab = 0, sa = 0, sb = 0, res = 1e18;

	if (xy.size() + x.size() < k || xy.size() + y.size() < k) {
		cout << -1 << endl;
		return;
	}

	forn (i, xy.size()) sab += xy[i];

	for (int i = xy.size(), j = 0, l = 0; i >= 0; i--) {
		while (j < x.size() && i + j < k) {
			sa += x[j];
			j++;
		}

		while (l < y.size() && i + l < k) {
			sb += y[l];
			l++;
		}

		if (i + j >= k && i + l >= k) res = min(res, sab + sa + sb);

		if (i) sab -= xy[i - 1];
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();	

	return 0;
}