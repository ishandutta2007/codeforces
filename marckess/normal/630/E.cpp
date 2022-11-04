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

ll np (ll a, ll b) {
	return b / 2 - (a - 1) / 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll x, y, x2, y2;
	cin >> x >> y >> x2 >> y2;

	x += 2e9;
	y += 2e9;
	x2 += 2e9;
	y2 += 2e9;

	if (x % 2 != y % 2) {
		y++;
		y2++;
	}

	cout << np(x, x2) * np(y, y2) + (x2 - x + 1 - np(x, x2)) * (y2 - y + 1 - np(y, y2)) << endl; 

	return 0;
}