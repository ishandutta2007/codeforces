#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, a, b;
	ll res = 0;

	map<int, int> x, y;
	map<ii, int> p;

	cin >> n;
	while (n--) {
		cin >> a >> b;

		res += x[a];
		res += y[b];
		res -= p[ii(a, b)];

		x[a]++;
		y[b]++;
		p[ii(a, b)]++;
	}

	cout << res << endl;

	return 0;
}