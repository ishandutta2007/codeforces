#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 2005;

int a, b, c, d, e, f;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> b >> c >> d >> e >> f;

	if (a == c && c == e) {
		cout << 1 << endl;
		return 0;
	}

	if (b == d && d == f) {
		cout << 1 << endl;
		return 0;
	}

	if (a == c && (f == min({b, d, f}) || f == max({b, d, f}))) {
		cout << 2 << endl;
		return 0;
	}

	if (a == e && (d == min({b, d, f}) || d == max({b, d, f}))) {
		cout << 2 << endl;
		return 0;
	}

	if (c == e && (b == min({b, d, f}) || b == max({b, d, f}))) {
		cout << 2 << endl;
		return 0;
	}

	if (b == d && (e == min({a, c, e}) || e == max({a, c, e}))) {
		cout << 2 << endl;
		return 0;
	}

	if (b == f && (c == min({a, c, e}) || c == max({a, c, e}))) {
		cout << 2 << endl;
		return 0;
	}

	if (d == f && (a == min({a, c, e}) || a == max({a, c, e}))) {
		cout << 2 << endl;
		return 0;
	}

	cout << 3 << endl;

	return 0;
}