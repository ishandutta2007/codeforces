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

typedef unsigned int ui;

const ui MX = 135, phi = 1ll << 31;
ui n, p, q, comb[MX], res;

ui pot (ui b, ui p) {
	ui res = 1;
	while (p) {
		if (p & 1) res *= b;
		b *= b;
		p /= 2;
	}
	return res;
}

ui p2 (ui &a) {
	ui res = 0;
	while (a % 2 == 0) {
		a /= 2;
		res++;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> p >> q;

	comb[0] = 1;
	for (ui i = 1, _2 = 0, x = 1; i <= min(p, n - 1); i++) {
		ui a = n - i + 1;
		ui b = i;

		_2 += p2(a) - p2(b);
		x *= a * pot(b, phi - 1);

		comb[i] = x * pot(2, _2);
	}

	for (ui i = 1; i <= q; i++) {
		ui x = 0, c = 1;

		for (ui j = 0; j <= min(p, n - 1); j++, c *= i)
			x += comb[j] * c;

		res ^= x * i;
	}

	cout << res << endl;

	return 0;
}