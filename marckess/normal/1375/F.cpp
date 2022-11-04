#include <bits/stdc++.h>

//#define endl '\n'
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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int ant = 0;
ll a, b, c;

int read () {
	int r;
	cin >> r;
	if (r < 1) exit(0);
	return r;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b >> c;

	cout << "First" << endl;

	forn (i, 1000) {
		vi v = {a, b, c};
		sort(all(v));
		ll y = 2 * v[2] - v[1] - v[0], r;

		cout << y << endl;
		r = read();

		if (r < 0) return 0;

		if (r == 1) {
			a += y;

			if (a == v[2] + y) continue;
			
			y = abs(b - c);
			cout << y << endl;
			r = read();
		} else if (r == 2) {
			b += y;

			if (b == v[2] + y) continue;

			y = abs(a - c);
			cout << y << endl;
			r = read();
		} else {
			c += y;

			if (c == v[2] + y) continue;

			y = abs(a - b);
			cout << y << endl;
			r = read();
		}
	}

	return 0;
}