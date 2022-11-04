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

const int MX = 105;
int n, res;
vi a, b;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, n) {
		int t, w;
		cin >> t >> w;
		if (t == 1) a.pb(w), res += 1;
		else b.pb(w), res += 2;
	}
	sort(all(a)), sort(all(b));

	int x = 0;
	for (int i = 0; i <= a.size(); i++) {
		if (i) x += a[i - 1];

		int y = 0;
		for (int j = 0; j <= b.size(); j++) {
			if (j) y += b[j - 1];

			if (x + y <= ((int)a.size() - i) + 2 * ((int)b.size() - j))
				res = min(res, ((int)a.size() - i) + 2 * ((int)b.size() - j));
		}
	}
	cout << res << endl;

	return 0;
}