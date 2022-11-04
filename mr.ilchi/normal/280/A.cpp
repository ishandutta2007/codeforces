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

#define double long double

typedef long long LL;
typedef complex<double> point;
typedef pair<int,int> pii;

const double eps = 1e-9;

int w,h,t;
vector <point> store;

double dot(const point &a, const point &b) { return real(conj(a) * b); }
double cross(const point &a, const point &b) { return imag(conj(a) * b); }

void intersect(const point &a, const point &b, const point &p, const point &q){
    double d1 = cross(p - a, b - a);
    double d2 = cross(q - a, b - a);
	if (abs(d1-d2) < eps)
		return;
	point ret = (d1 * q - d2 * p) / (d1 - d2);
	if (abs(abs(a-ret) + abs(b-ret) - abs(a-b)) > eps) return;
	if (abs(abs(p-ret) + abs(q-ret) - abs(p-q)) > eps) return;
    store.push_back (ret);
}

point rotate_by(const point &p, const point &about, double radians){ 
    return (p - about) * exp(point(0, radians)) + about; 
}

bool cmp (const point &A, const point &B){
	return cross(A-store[0], B-store[0]) > eps;
}

int main(){
	cin >> w >> h >> t;
	cout << fixed << setprecision(10);
	if (t==0 || t==180){
		cout << (w+0.0) * h << endl;
		return 0;
	}
	point f[4], ff[4];
	f[0] = point(w/2.0, h/2.0); 
	f[1] = point(-w/2.0, h/2.0); 
	f[2] = point(-w/2.0, -h/2.0); 
	f[3] = point(w/2.0, -h/2.0); 
	for (int i=0; i<4; i++)
		ff[i] = rotate_by(f[i], point(0.0, 0.0), t/180.0*M_PI);
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			intersect(f[i], f[(i+1)%4], ff[j], ff[(j+1)%4]);
	int pos = 0;
	for (int i=1; i<(int)store.size(); i++) if ((store[i].imag()+eps < store[pos].imag()) || (abs(store[pos].imag()-store[i].imag())<eps && store[pos].real()<store[i].real()))
		pos = i;
	swap(store[0], store[pos]);
	sort(store.begin()+1, store.end(), cmp);
	double ans = 0;
	for (int i=2; i<(int)store.size(); i++)
		ans+= cross(store[i-1]-store[0], store[i]-store[0]);
	cout << ans/2.0 << endl;
	return 0;
}