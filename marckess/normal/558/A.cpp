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

int n, x = 0, y = 0, g, h, res = 0;
ii a[105], b[105];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> g >> h;
		if (g < 0) a[x++] = {-g, h};
		else b[y++] = {g, h};
	}

	sort(a, a+x);
	sort(b, b+y);

	for (int i = 0; i < min(x, y); i++)
		res += a[i].se + b[i].se;

	if (x > min(x, y))
		res += a[min(x, y)].se;

	if (y > min(x, y))
		res += b[min(x, y)].se;

	cout << res << endl;

	return 0;
}