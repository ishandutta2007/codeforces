/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef complex<double> point;

const int MAXN = 100+10;
const double eps= 1e-8;

int n;
point a[MAXN];

double cross (point A, point B) { return imag(conj(A) * B); }
double dot (point A, point B) { return real(conj(A) * B); }
point rotate_by(const point &p, const point &about, double radians) {	return (p - about) * exp(point(0, radians)) + about; }
point intersect(const point &a, const point &b, const point &p, const point &q){
    double d1 = cross(p - a, b - a);
    double d2 = cross(q - a, b - a);
    return (d1 * q - d2 * p) / (d1 - d2);
}

point centreOfCircle (point A, point B, point C){
	point AB = (A + B) / 2.0;
	point AC = (A + C) / 2.0;
	point AB2 = rotate_by(A, AB, M_PI/2.0);
	point AC2 = rotate_by(A, AC, M_PI/2.0);
	return intersect(AB, AB2, AC, AC2);
}

int inside (point P, point A, point B, point C){
	double AB = cross(A-P, B-P);
	double BC = cross(B-P, C-P);
	double CA = cross(C-P, A-P);
	if (abs(AB)<eps || abs(BC)<eps || abs(CA)<eps)
		return 2;
	if (AB<eps && BC<eps && CA<eps)
		return 1;
	if (AB>-eps && BC>-eps && CA>-eps)
		return 1;
	return 0;
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].real() >> a[i].imag();
	double ans = -1.0;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			for (int k=j+1; k<n; k++) if (abs(cross(a[i]-a[j], a[i]-a[k])) > eps){
				point C = centreOfCircle(a[i], a[j], a[k]);
				int temp = inside(C, a[i], a[j], a[k]);
				if (temp == 0)
					continue;
				double D= abs(C - a[i]);
				int cnt = 0;
				for (int z=0; z<n; z++){
					double dis = abs(C - a[z]);
					if (abs(dis-D) < eps)
						cnt++;
					else if (dis + eps < D){
						cnt = -1;
						break;
					}
				}
				if ((cnt!=-1) && (temp==1 || (temp==2 && cnt>3)))
					ans = max(ans, D);
			}
	if (ans < -0.5)
		cout << -1 << endl;
	else
		cout << fixed << setprecision(10) << ans << endl;
	return 0;
}