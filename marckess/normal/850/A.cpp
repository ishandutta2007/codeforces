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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const ld eps = 1e-12;
const ld pi = acos(ld(-1));
const int MX = 10005;
int n, a[MX][5], b[MX][5];
vi res;

bool le (ld a, ld b) {
	return a < b && abs(a - b) > eps;
}

ld mod (int p[]) {
	ld res = 0;
	forn (i, 5)
		res += p[i] * p[i];
	return sqrt(res);
}

ld dot (int a[], int b[]) {
	ld res = 0;
	forn (i, 5)
		res += a[i] * b[i];
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	
	cin >> n;
	forn (i, n)
		forn (j, 5)
			cin >> a[i][j];

	if (n > 100) {
		cout << 0 << endl;
		return 0;
	}

	forn (i, n) {
		int f = 1;

		forn (j, n)
			forn (k, 5)
				b[j][k] = a[j][k] - a[i][k];

		forn (j, n) forn (k, n) if (i != j && i != k && j != k)
			if ( le(acos(dot(b[j], b[k]) / mod(b[j]) / mod(b[k])), pi / 2) )
				f = 0;

		if (f) res.pb(i + 1);
	}

	cout << res.size() << endl;
	for (int r : res)
		cout << r << endl;

	return 0;
}