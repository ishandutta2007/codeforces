#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

ll x, y, ax, ay, bx, by, xs, ys, t;
vii a;

int main() {
	ios_base::sync_with_stdio(); cin.tie(0);
		
	cin >> x >> y >> ax >> ay >> bx >> by;
	while (x <= 3e16 && y <= 3e16) {
		a.emplace_back(x, y);
		x = ax * x + bx;
		y = ay * y + by;
	}
	cin >> xs >> ys >> t;

	int res = 0;
	for (int i = 0; i < a.size(); i++) {
		ll x = abs(a[i].fi - xs) + abs(a[i].se - ys);
		int j = i + 1;

		while (x <= t) {
			res = max(res, j - i);
			if (j == a.size()) break;
			x += abs(a[j].fi - a[j-1].fi) + abs(a[j].se - a[j-1].se);
			j++;
		}

		x = abs(a[i].fi - xs) + abs(a[i].se - ys);
		j = i - 1;
		while (x <= t) {
			res = max(res, i - j);
			if (j < 0) break;
			x += abs(a[j].fi - a[j+1].fi) + abs(a[j].se - a[j+1].se);
			j--;
		}
	}

	cout << res << endl;

	return 0;
}