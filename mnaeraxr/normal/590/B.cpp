#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

double x1, y1, x2, y2;
double v, t;
double vx, vy, wx, wy;

double sqr(double v){
	return v * v;
}

bool calc(double ct){
	double x = vx * min(ct, t) + wx * max(0.0, ct - t);
	double y = vy * min(ct, t) + wy * max(0.0, ct - t);
	// cout << x2 << " " << y2 << endl;
	// cout << x << " " << y << endl;
	// cout << sqr(x2 - x) + sqr(y2 - y) << endl; 
	// cout << v * v * ct * ct << endl;
	return sqr(x2 - x) + sqr(y2 - y) <= v * v * ct * ct;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> x1 >> y1 >> x2 >> y2;
	x2 -= x1; y2 -= y1;
	cin >> v >> t;
	cin >> vx >> vy >> wx >> wy;

	// calc(3.729935587093555327);
	// exit(0);

	double lo = 0, hi = 1;
	int iter = 0;	
	while (!calc(hi)){
		hi *= 2;
		++iter;
	}
	for (int i = 0; i < 200 + iter; ++i){
		double mid = (lo + hi) / 2;
		if (calc(mid)) hi = mid;
		else lo = mid;
	}

	cout.precision(20);
	cout << fixed << lo << endl;

	return 0;
}