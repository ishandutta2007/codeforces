#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 400005;

struct BIT {
	ll ft[MX];

	BIT () { memset(ft, 0, sizeof(ft)); }

	void update (int i, int k) {
		i++;
		while (i < MX) {
			ft[i] += k;
			i += i & -i;
		}
	}

	ll sum (int i) {
		i++;
		ll sum = 0;
		while (i) {
			sum += ft[i];
			i -= i & -i;
		}
		return sum;
	}

	ll sum (int a, int b) {
		if (a > b) return 0;
		return sum(b) - sum(a-1);
	}
}ft, acu;

int n;
ll t, a[MX], s = 0, cn, res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];

		ft.update(i, a[i]);
		ft.update(i+n, a[i]);
		acu.update(i, 1);
		acu.update(i+n, 1);
	}
	cn = n;

	int act = 0;
	while (cn) {
		res += (t / s) * cn;
		t %= s;

		int i = act, j = act + n, rep = 20;
		while (rep--) {
			int m = (i+j)/2;
			if (ft.sum(act, m) > t) j = m;
			else i = m;
		}

		res += acu.sum(act, j-1);
		t -= ft.sum(act, j-1);

		act = j % n;
		s -= a[act];
		ft.update(act, -a[act]);
		ft.update(act+n, -a[act]);
		acu.update(act, -1);
		acu.update(act+n, -1);
		cn--;
	}

	cout << res << endl;

	return 0;
}