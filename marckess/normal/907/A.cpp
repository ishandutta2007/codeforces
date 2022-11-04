#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int a, b, c, d;

	bitset<300> x, y, z;

	cin >> a >> b >> c >> d;

	for (int i = a; i <= 2*a; i++) {
		x[i] = (d <= i && !(i <= 2*d));
	}

	for (int i = b; i <= 2*b; i++)
		y[i] = (d <= i && !(i <= 2*d));

	for (int i = c; i <= 2*c; i++)
		z[i] = (d <= i && i <= 2*d);

	if (!x.count() || !y.count() || !z.count())
		cout << -1 << endl;
	else  {
		for (int i = 0; i < 300; i++) {
			if (z[i]) {
				c = i;
				break;
			}
		}

		b = -1;
		for (int i = 0; i < 300; i++) {
			if (y[i] && i > c) {
				b = i;
				break;
			}
		}

		a = -1;
		for (int i = 0; i < 300; i++) {
			if (x[i] && i > b) {
				a = i;
				break;
			}
		}

		if (!(a > b && b > c))
			cout << -1 << endl;
		else
			cout << a << endl << b << endl << c << endl;
	}

	return 0;
}