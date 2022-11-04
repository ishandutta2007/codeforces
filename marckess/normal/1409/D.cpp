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

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int sd (ll x) {
	string s = to_string(x);
	int res = 0;

	for (char c : s)
		res += c - '0';

	return res;
}

ll n, s;
void solve () {
	cin >> n >> s;

	ll res = 1e18;

	if (sd(n) <= s)
		res = 0;

	string x = to_string(n);
	int ini = x.size();

	for (ll i = ini - 1, b = 10; i != -1; i--, b *= 10) {
		x[i] = '0';

		ll y = stoll(x);
		y += b;

		if (sd(y) <= s)
			res = min(res, y - n);
	}

	cout << res << endl;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}