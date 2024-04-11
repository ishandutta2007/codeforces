#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define ran 222222
const double pi = acos(-1.0);
const double eps = 1e-12;
int n;
double x[ran],y[ran],X,Y;
double sqr(double x){return x*x;}
double solve(double x,double dx,double y,double dy,double a){
	a = tan(a);
	return (x * a - y) / (dy - dx * a);
}
double calc(double x1,double y1,double x2,double y2,double a1, double a2){
	double t1 = solve(x1, x2-x1, y1, y2-y1, a1);
	double t2 = solve(x1, x2-x1, y1, y2-y1, a2);
	return sqrt(sqr(x2-x1)+sqr(y2-y1)) * fabs(t2-t1);
}
int main(){
	scanf("%d%lf",&n,&Y);
	for(int i=1; i<=n; i++)
		scanf("%lf%lf",&x[i],&y[i]);
	Y += y[n];
	X = x[n];
	double ang = pi / 2, res = 0;
	for(int i=n-1; i>=1; i--){
		double from = atan2(Y - y[i+1], X - x[i+1]);
		double to = atan2(Y - y[i], X - x[i]);
		if(from > to)swap(from, to);
		if(to < ang + eps){
			res += sqrt(sqr(x[i+1]-x[i])+sqr(y[i+1]-y[i]));
			ang = from;
			continue;
		}
		if(from > ang + eps)
			continue;
		if(from < ang){
			res += calc(x[i]-X, y[i]-Y, x[i+1]-X, y[i+1]-Y, from, ang);
			ang = from;
		}
	}
	printf("%.12lf\n",res);
	return 0;
}