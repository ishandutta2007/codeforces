#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forab(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll k, d, t, res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(2) << endl;

	cin >> k >> d >> t;
	t *= 2;

	ll x = 2 * k;
	ll y = 0;
	if (k % d) y = d - k % d;

	res += t / (x + y) * (x + 2 * y);
	t -= t / (x + y) * (x + y);

	if (t <= x) {
		res += t;
	} else {
		res += x + 2 * (t - x);
	}

	cout << res / 2.0 << endl;

	return 0;
}