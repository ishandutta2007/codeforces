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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n;
ll t, a, b, res, d[MX], k0, k1, s;
ll acu;
set<int> st;
map<int, int> x, y;

void solve () {
	cin >> n >> t >> a >> b;

	st.clear(), x.clear(), y.clear();
	k0 = k1 = 0;
	s = 0;

	for (int i = 0; i < n; i++) {
		cin >> d[i];
		if (d[i]) k1++;
		else k0++;
	}
	
	st.insert(t);
	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;
		if (d[i]) y[in]++;
		else x[in]++;
		st.insert(in);
		st.insert(in-1);
	}
	st.erase(-1);

	res = acu = 0;

	for (int i : st) {
		acu += a * x[i]; s += x[i];
		acu += b * y[i]; s += y[i];
		k0 -= x[i];
		k1 -= y[i];

		if (acu <= i) {
			ll c = i - acu;
			
			if (k0 * a <= c) {
				c -= k0 * a;
				res = max(res, s + k0 + min(k1, c / b));
			} else {
				res = max(res, s + min(k0, c / a));
			}
		}
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