#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> point;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

double sqr(double v){
	return v * v;
}

struct circle{
	point c;
	double r;
};

point inv(point a){
	return point(1) / conj(a);
}


circle getCircle(point a, point b, point c)
{
	point x = 1.0 / conj(b - a), y = 1.0 / conj(c - a);
	point t = (y - x) / (conj(x) * y - x * conj(y)) + a;
	return {t, abs(a - t)};
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--){
		double R, r;
		int k;
		cin >> R >> r >> k;

		double d = (R - r) / (4 * R * r);
		point c((R + r) / (4 * R * r), 1.0 * k * (R - r) / (2 * R * r));

		point c1 = inv(c + point(d, 0));
		point c2 = inv(c - point(d, 0));
		point c3 = inv(c + point(0, d));

		cout.precision(17);
		cout << fixed << getCircle(c1, c2, c3).r << endl;

	}

	return 0;
}