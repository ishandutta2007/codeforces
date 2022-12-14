#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long int ll;
const double eps = 1e-8;

inline int dcmp(double a, double b){return fabs(a - b) <= eps ? 0 : (a > b ? -1 : 1);}
int main(){
	double r1, r2, delta, a, b, c, x1, y1, x2, y2, vmax, t, vx, vy, wx, wy;
	cin >> x1 >> y1 >> x2 >> y2 >> vmax >> t >> vx >> vy >> wx >> wy;
	a = vx * vx + vy * vy - vmax * vmax;
	b = - 2 * vx * (x2 - x1) - 2 * vy * (y2 - y1);
	c = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	if(dcmp(0.0, delta = b * b - 4 * a * c) >= 0){
		r2 = (-b - sqrt(delta)) / (a * 2.0);
		r1 = (-b + sqrt(delta)) / (a * 2.0);
		if(dcmp(0.0, r1) >= 0 && dcmp(r1, t) >= 0){
			printf("%.15f\n", r1);
			return 0;
		}else if(dcmp(r2, t) >= 0){
			printf("%.15f\n", r2);
			return 0;
		}
	}
	a = wx * wx + wy * wy - vmax * vmax;
	b = - 2 * wx * ll(x2 - x1 - vx * t + wx * t) - 2 * wy * ll(y2 - y1 - vy * t + wy * t);
	c = ll(x2 - x1 - vx * t + wx * t) * ll(x2 - x1 - vx * t + wx * t) + ll(y2 - y1 - vy * t + wy * t) * ll(y2 - y1 - vy * t + wy * t);
	delta = b * b - 4.0 * a * c;
	r2 = (-b - sqrt(delta)) / (a * 2.0);
	r1 = (-b + sqrt(delta)) / (a * 2.0);
	if(dcmp(0.0, r1) >= 0 && dcmp(t, r1) >= 0) printf("%.15f\n", r1);
	else printf("%.15f\n", r2);
	return 0;
}