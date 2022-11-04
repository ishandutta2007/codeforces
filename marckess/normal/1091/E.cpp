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

const int MX = 5e5+5;
int n, _a[MX], a[MX];
ll acu[MX], s = 0, mn[MX];

int esPos (int x) {
	s = 0;

	for (int i = 1; i < n; i++)
		a[i] = _a[i-1];
	a[0] = x;
	sort(a, a+n, greater<int>());

	for (int i = n - 1; i >= 0; i--)
		acu[i] = a[i] + acu[i+1];

	for (int k = 1; k <= n; k++) {
		ll act = k * ll(k - 1);
		s += a[k-1];

		int i = lower_bound(a+k, a+n, k, greater<int>()) - a;

		act += acu[i];
		act += k * ll(i - k);
		
		if (s > act)
			return a[k-1] <= x ? 1 : -1;
	}

	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> _a[i];
		s += _a[i];
	}
	n++;

	int f = s & 1;

	int i = 0, j = 5e5+5, rep = 19, l, r;

	while (rep--) {
		int m = (i+j)/2;

		if (esPos(2 * m + f) != -1) j = m;
		else i = m; 
	}

	l = 2 * j + f;

	i = 0, j = 5e5+5, rep = 19;
	while (rep--) {
		int m = (i+j)/2;

		if (esPos(2 * m + f) != 1) i = m;
		else j = m;
	}

	if (esPos(2 * j + f) != 1) r = 2 * j + f;
	else r = 2 * i + f;

	if (l > r) {
		cout << -1 << endl;
		return 0;
	}

	while (l <= r) {
		cout << l << " ";
		l += 2;
	}
	cout << endl;

	return 0;
}