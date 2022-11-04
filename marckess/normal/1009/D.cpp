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
vii res;
bitset<100005> bs;

int gcd (int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	if (m < n - 1) {
		cout << "Impossible" << endl;
		return 0;
	}

	for (int i = 2; i <= n; i++) {
		res.emplace_back(1, i);
		m--;
	}

	for (int i = 2; i <= n && m; i++)
		for (int j = i+1; j <= n && m; j++)
			if (gcd(i, j) == 1) {
				res.emplace_back(i, j);
				m--;
			}

	if (m) {
		cout << "Impossible" << endl;
		return 0;
	}

	cout << "Possible" << endl;
	for (ii &x : res)
		cout << x.fi << " " << x.se << endl;

	return 0;
}