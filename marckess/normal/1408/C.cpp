#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 100005;
int n, l, a[MX];

void solve () {
	cin >> n >> l;
	forn (i, n) cin >> a[i];

	ld x = 0, y = l;
	int i = -1, j = n;
	ld s1 = 1, s2 = 1;
	ld res = 0;

	while (i + 1 < j) {
		ld tx = (a[i + 1] - x) / s1;
		ld ty = (y - a[j - 1]) / s2;

		if (tx < ty) {
			res += tx;

			x += s1 * tx;
			y -= s2 * tx;

			i++;
			s1 += 1;
		} else {
			res += ty;

			x += s1 * ty;
			y -= s2 * ty;

			j--;
			s2 += 1;
		}
	}

	res += (y - x) / (s1 + s2);

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cout << fixed << setprecision(9);
	
	int t = 1;
	cin >> t;
	while (t--)	
		solve();

	return 0;
}