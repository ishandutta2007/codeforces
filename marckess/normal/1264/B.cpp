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

int a, b, c, d, f, g;
vi s, t, mit;

void no () {
	cout << "NO" << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> b >> c >> d;
	f = b, g = c;

	if (a) {
		if (g || b > a) {
			if (!b) no();
			s.pb(1);
			b--;
		}

		while (a) {
			s.pb(0);
			a--;
			if (a) {
				if (!b) no();
				s.pb(1);
				b--;
			}
		}
	}

	if (d) {
		if (f || c > d) {
			if (!c) no();
			t.pb(2);
			c--;
		}

		while (d) {
			t.pb(3);
			d--;
			if (d) {
				if (!c) no();
				t.pb(2);
				c--;
			}
		}
	}

	while (b && c) {
		mit.pb(2);
		mit.pb(1);
		b--, c--;
	}

	if (b) {
		s.pb(1);
		b--;
	}

	if (c) {
		t.pb(2);
		c--;
	}

	if (a || b || c || d)
		no();

	vi res;
	reverse(all(s));
	for (int x : s)
		res.pb(x);
	for (int x : mit)
		res.pb(x);
	for (int x : t)
		res.pb(x);


	for (int i = 0; i + 1 < res.size(); i++)
		if (abs(res[i] - res[i+1]) != 1)
			no();

	cout << "YES" << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}