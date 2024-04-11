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

ll num () {
	ll n, b, a[11], x = 0, y = 1;

	cin >> n >> b;
	for (int i = n - 1; i >= 0; i--)
		cin >> a[i];

	for (int i = 0; i < n; i++, y *= b) {
		x += a[i] * y;
	}

	return x;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll x, y;

	x = num();
	y = num();

	if (x == y)
		cout << "=" << endl;
	else if (x < y)
		cout << "<" << endl;
	else
		cout << ">" << endl;

	return 0;
}