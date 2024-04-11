#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;
typedef complex<ld> point;

const int oo = 0x3f3f3f3f;
const ld eps = 1e-12;
const int maxn = 100010;
const ld pi = acos(-1);

ld sqr(ld v){
	return v * v;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ld x1, y1, r1;
	cin >> x1 >> y1 >> r1;
	ld x2, y2, r2;
	cin >> x2 >> y2 >> r2;
	ld d = abs(point(x1, y1) - point(x2, y2));

	if (d + eps >= r1 + r2){
		cout.precision(10);
		cout << fixed << 0.0 << endl;
		exit(0);
	}

	if (r1 < r2) swap(r1, r2);

	if (d + r2 <= r1 + eps){
		cout.precision(20);
		cout << fixed << pi * r2 * r2 << endl;
		exit(0);
	}

	ld g1 = 2 * acos(((r1 - r2) * (r1 + r2) + sqr(d)) / (2.0 * r1 * d));
	ld g2 = 2 * acos(((r2 - r1) * (r1 + r2) + sqr(d)) / (2.0 * r2 * d));
	ld d1 = (sqr(r1) * (g1 - sin(g1))) / 2.0;
	ld d2 = (sqr(r2) * (g2 - sin(g2))) / 2.0;
	ld dd = d1 + d2;

	cout.precision(20);
	cout << fixed << dd << endl;

	return 0;
}