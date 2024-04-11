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

const int MX = 200005;
int n, mov[256], acu[MX];
string s;

ii go () {
	int mx = 0, mn = 0;

	for (int i = 0; i < n; i++) {
		acu[i] = mov[s[i]];
		if (i) acu[i] += acu[i-1];

		mx = max(acu[i], mx);
		mn = min(acu[i], mn);
	}

	ii res(mx - mn, mx - mn);

	int a = 0, b = 0, f = 1;
	for (int i = 0; i < n; i++) {
		acu[i] = mov[s[i]];
		if (i) acu[i] += acu[i-1];

		if (mov[s[i]] && acu[i] == mx && f) {
			acu[i] -= 2;
			a = max(acu[i], a);
			b = min(acu[i], b);
			acu[i]++;

			f = 0;
		}

		a = max(acu[i], a);
		b = min(acu[i], b);
	}

	res.se = min(res.se, a - b);

	a = 0, b = 0, f = 1;
	for (int i = 0; i < n; i++) {
		acu[i] = mov[s[i]];
		if (i) acu[i] += acu[i-1];

		if (mov[s[i]] && acu[i] == mn && f) {
			acu[i] += 2;
			a = max(acu[i], a);
			b = min(acu[i], b);
			acu[i]--;

			f = 0;
		}

		a = max(acu[i], a);
		b = min(acu[i], b);
	}

	res.se = min(res.se, a - b);

	return res;
}

void solve () {
	cin >> s;
	n = s.size();

	mov['W'] = 1;
	mov['S'] = -1;
	ii x = go();
	mov['W'] = 0;
	mov['S'] = 0;

	mov['A'] = 1;
	mov['D'] = -1;
	ii y = go();
	mov['A'] = 0;
	mov['D'] = 0;

	cout << min(ll(x.fi + 1) * (y.se + 1), ll(x.se + 1) * (y.fi + 1)) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}