#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, m, a, b, res = 0;
string x, y;

int nd (int n) {
	int res = 0;
	while (n) {
		res++;
		n /= 7;
	}
	return max(1, res);
}

int check () {
	int mk = 0;
	for (char c : x) {
		if (mk & (1 << (c-'0'))) return 0;
		mk |= (1 << (c-'0'));
	}
	for (char c : y) {
		if (mk & (1 << (c-'0'))) return 0;
		mk |= (1 << (c-'0'));
	}
	return 1;
}

void sig (string &s) {
	int acu = 0;
	s[0]++;
	for (char &c : s) {
		c += acu;
		if (c >= '7') {
			c -= 7;
			acu = 1;
		} else {
			acu = 0;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	a = nd(n-1), b = nd(m-1);

	if (a + b > 7) {
		cout << 0 << endl;
		return 0;
	}

	x.assign(a, '0');

	for (int i = 0; i < n; i++) {
		y.assign(b, '0');
		for (int j = 0; j < m; j++) {
			res += check();
			sig(y);
		}
		sig(x);
	}

	cout << res << endl;

	return 0;
}