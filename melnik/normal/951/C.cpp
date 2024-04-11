#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int inf = 1e9;
const int base = 1e9 + 7;
const double eps = 1e-7;
const int maxn = 100500;
const ll llinf = 1e18;

	int n;
bool q(int x1, int y1, int x2, int y2) {
	assert(abs(x2 - x1) + abs(y2 - y1) >= n - 1);

	cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	cout.flush();

	string res;
	cin >> res;

	return res == "YES";
}

int main() {
	srand(time(NULL));
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// ios_base::sync_with_stdio(false);

	cin >> n;


	string p1;
	int x = 1, y = 1;

	while (1) {
		int xr = x, yr = y + 1;
		int xd = x + 1, yd = y;

		if (xr <= n && yr <= n && abs(n - xr) + abs(n - yr) >= n - 1) {
			bool kek = q(xr, yr, n, n);
			if (kek) {
				p1 += "R";
				x = xr, y = yr;
				continue;
			}
		}
		if (xd <= n && yd <= n && abs(n - xd) + abs(n - yd) >= n - 1) {
			bool kek = q(xd, yd, n, n);
			if (kek) {
				p1 += "D";
				x = xd, y = yd;
				continue;
			}
		}
		break;
	}
	
	string p2;

	int xo = x, yo = y;
	x = n, y = n;

	while (1) {
		if (x == xo && y == yo) break;
		int xu = x - 1, yu = y;
		int xl = x, yl = y - 1;
		if (xu >= 1 && yu >= 1 && abs(xu - 1) + abs(yu - 1) >= n - 1) {
			bool kek = q(1, 1, xu, yu);
			if (kek) {
				p2 += "D";
				x = xu, y = yu;
				continue;
			}
		}
		if (xl >= 1 && yl >= 1 && abs(xl - 1) + abs(yl - 1) >= n - 1) {
			bool kek = q(1, 1, xl, yl);
			if (kek) {
				p2 += "R";
				x = xl, y = yl;
				continue;
			}
		}
		break;
	}

	assert(x == xo && y == yo);

	reverse(p2.begin(), p2.end());
	p1 += p2;
	cout << "! " << p1 << endl;
	return 0;
}