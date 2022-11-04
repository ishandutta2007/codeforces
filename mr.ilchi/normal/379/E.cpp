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

const double eps = 1e-9;

bool isintersect;
int n,k;
int a[500][500];
double ans[1000];

double dot(const point &a, const point &b) { return real(conj(a) * b); }
double cross(const point &a, const point &b) { return imag(conj(a) * b); }

bool middle (double A, double B, double C){
	return A>=min(B,C)-eps && A-eps<=max(B,C);
}

bool middle (point A, point B, point C){
	return middle(A.real(), B.real(), C.real()) && middle(A.imag(), B.imag(), C.imag());
}

point intersect(const point &a, const point &b, const point &p, const point &q)
{
    double d1 = cross(p - a, b - a);
    double d2 = cross(q - a, b - a);
	if (abs(d1-d2) < eps){
		isintersect = false;
		return point(0.0, 0.0);
	}
	isintersect = true;
	point ret = (d1 * q - d2 * p) / (d1 - d2);
    if (middle(ret, a, b) && middle(ret, p, q))
		return ret;
	isintersect = false;
	return point(0.0, 0.0);
}

int main(){
	cin >> n >> k;
	for (int i=0; i<n; i++)
		for (int j=0; j<=k; j++)
			cin >> a[i][j];
	for (int z=0; z<k; z++){
		vector <point> convex;
		convex.push_back(point(0.0, 0.0));
		convex.push_back(point(1.0, 0.0));
		for (int i=0; i<n; i++){
			int L=-1, R=-1;
			point fL, fR;
			point A = point(0.0, a[i][z]+0.0);
			point B = point(1.0, a[i][z+1]+0.0);
			for (int j=0; j<(int)convex.size()-1; j++){
				point tmp = intersect(A, B, convex[j], convex[j+1]);
				if (isintersect){
					if (L==-1){
						L = j;
						fL= tmp;
					}
					R = j;
					fR= tmp;
				}
			}
			if (a[i][z]+eps>convex[0].imag()){
				convex.insert(convex.begin(), A);
				L = 0;
				if (R!=-1) R++;
				fL= A;
			}
			if (a[i][z+1]+eps>convex.back().imag()){
				convex.insert(convex.end(), B);
				R = (int)convex.size()-2;
				fR = B;
			}
			if (L==-1 && R==-1)
				continue;
			for (int k=0; k<(int)convex.size()-1; k++)
				if (k>L && k<R)
					ans[i]-= (convex[k].imag() + convex[k+1].imag()) * (convex[k+1].real() - convex[k].real()) / 2.0;
			ans[i]-= (fL.imag() + convex[L+1].imag()) * (convex[L+1].real() - fL.real()) / 2.0;
			ans[i]-= (fR.imag() + convex[R].imag()) * (fR.real() - convex[R].real()) / 2.0;
			ans[i]+= (fL.imag() + fR.imag()) * (fR.real() - fL.real()) / 2.0;

			vector <point> tConvex;
			for (int i=0; i<(int)convex.size(); i++){
				if (i<=L || i>R){
					if (tConvex.empty() || abs(convex[i]-tConvex.back()) > eps)
						tConvex.push_back(convex[i]);
				}
				if (i == L){
					if (abs(fL-tConvex.back()) > eps)
						tConvex.push_back(fL);
				}
				if (i == R)
					tConvex.push_back(fR);
			}
			convex = tConvex;

		}
	}
	cout << fixed << setprecision(10);
	for (int i=0; i<n; i++)
		cout << ans[i] << endl;
	return 0;
}