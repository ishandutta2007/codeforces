#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int a1, a2, k1, k2, n, mn, mx;
	cin >> a1 >> a2 >> k1 >> k2 >> n;

	mn = max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1));
	int d;
	if (k1 < k2) {
		d = min(a1, n / k1);
		mx += d;
		n -= d * k1;

		d = min(a2, n / k2);
		mx += d;
		n -= d * k2;
	} else {
		d = min(a2, n / k2);
		mx += d;
		n -= d * k2;

		d = min(a1, n / k1);
		mx += d;
		n -= d * k1;
	}

	cout << mn << " " << mx << endl;

	return 0;
}