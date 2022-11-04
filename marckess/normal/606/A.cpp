#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int a, b, c, x, y, z, e = 0;
	cin >> a >> b >> c >> x >> y >> z;

	if (a > x)
		e += (a - x) / 2;
	if (b > y)
		e += (b - y) / 2;
	if (c > z)
		e += (c - z) / 2;

	if (a < x)
		e -= x - a;
	if (b < y)
		e -= y - b;
	if (c < z)
		e -= z - c;

	if (e >= 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}