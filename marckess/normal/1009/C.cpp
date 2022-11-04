#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, m;
ll x, y;
ll mx = 0, mn = 0;
ld res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		mx += i;
		mn += abs(n/2-i);
	}

	while (m--) {
		cin >> x >> y;
		res += x * n;
		if (y >= 0)
			res += y * mx;
		else
			res += y * mn;
	}

	cout << fixed << setprecision(10) << res / n << endl;

	return 0;
}