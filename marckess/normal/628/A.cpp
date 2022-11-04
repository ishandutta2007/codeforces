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

int n, b, p, x = 0, y;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> b >> p;
	b = 2 * b + 1;
	y = n * p;

	while (n > 1) {
		int k = 1;
		while (2 * k <= n) k *= 2;
		x += b * k / 2;
		n -= k / 2;
	}

	cout << x << " " << y << endl;

	return 0;
}