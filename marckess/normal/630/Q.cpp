#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ld l[6], x[6], y[6], z[6], h[6], a[6], b[6], res[6], pi = acos(ld(-1));

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 3; i <= 5; i++) {
		cin >> l[i];

		a[i] = pi / i;

		x[i] = l[i] / 2;
		y[i] = x[i] / tan(a[i]);
		z[i] = x[i] / sin(a[i]);

		b[i] = x[i] * y[i] * i;
		h[i] = sqrt(l[i] * l[i] - z[i] * z[i]);

		res[i] = b[i] * h[i] / 3;
	}

	cout << fixed << setprecision(20) << (res[3] + res[4] + res[5]) << endl;

	return 0;
}