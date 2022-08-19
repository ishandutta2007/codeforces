#include<bits/stdc++.h>
#define EPS 0.000000001
using namespace std;
typedef long long LL;

int main(){
	double x[3];
	double y[3];
	double r[3];
	double mx[3];
	double my[3];
	double cx[3];
	double cy[3];
	double nr[3];
	for(int i = 0; i < 3; i++){
		cin >> x[i] >> y[i] >> r[i];
	}
	if(abs(r[0]-r[1]) < 0.1 && abs(r[0]-r[2]) < 0.1){
		double b1 = y[1]-y[0];
		double a1 = x[1]-x[0];
		double c1 = (y[1]*y[1]+x[1]*x[1]-y[0]*y[0]-x[0]*x[0])/2.0;
		double b2 = y[2]-y[0];
		double a2 = x[2]-x[0];
		double c2 = (y[2]*y[2]+x[2]*x[2]-y[0]*y[0]-x[0]*x[0])/2.0;
		double x1 = (c1*b2-b1*c2)/(a1*b2-b1*a2);
		double y1 = (a1*c2-c1*a2)/(a1*b2-b1*a2);
		printf("%.5lf %.5lf\n", x1, y1);
		return 0;
	}
	if(abs(r[0]-r[1]) < 0.1){
		swap(x[0],x[2]);
		swap(y[0],y[2]);
		swap(r[0],r[2]);
	}
	if(abs(r[0]-r[2]) < 0.1){
		swap(x[0],x[1]);
		swap(y[0],y[1]);
		swap(r[0],r[1]);
	}
	for(int i = 1; i < 3; i++){
		mx[i] = x[i]*(r[0]/(r[0]+r[i])+r[0]/(r[0]-r[i]))/2.0 + x[0]*(r[i]/(r[0]+r[i])-r[i]/(r[0]-r[i]))/2.0;
		my[i] = y[i]*(r[0]/(r[0]+r[i])+r[0]/(r[0]-r[i]))/2.0 + y[0]*(r[i]/(r[0]+r[i])-r[i]/(r[0]-r[i]))/2.0;
		cx[i] = x[i]*(r[0]/(r[0]+r[i])-r[0]/(r[0]-r[i]))/2.0 + x[0]*(r[i]/(r[0]+r[i])+r[i]/(r[0]-r[i]))/2.0;
		cy[i] = y[i]*(r[0]/(r[0]+r[i])-r[0]/(r[0]-r[i]))/2.0 + y[0]*(r[i]/(r[0]+r[i])+r[i]/(r[0]-r[i]))/2.0;
		nr[i] = sqrt(cx[i]*cx[i]+cy[i]*cy[i]);
		//cout << mx[i] << " " << my[i] << " " << nr[i] << endl;
	}
	if(abs(mx[1]-mx[2]) < EPS){
		swap(mx[1],mx[2]);
		swap(my[1],my[2]);
		swap(cx[1],cx[2]);
		swap(cy[1],cy[2]);
		swap(nr[1],nr[2]);
	}
	double a = 2.0*mx[2]-2.0*mx[1];
	double b = 2.0*my[2]-2.0*my[1];
	double c = mx[2]*mx[2]+my[2]*my[2]+nr[1]*nr[1]-mx[1]*mx[1]-my[1]*my[1]-nr[2]*nr[2];
	//cout << a << " " << b << " " << c << endl;
	double xt1 = a*a+b*b;
	double xt2 = -2.0*a*a*my[1]+2.0*a*b*mx[1]-2*b*c;
	double xt3 = a*a*mx[1]*mx[1]+a*a*my[1]*my[1]-2*a*c*mx[1]+c*c-a*a*nr[1]*nr[1];
	if(xt2*xt2 - 4.0*xt1*xt3 < -EPS){
		return 0;
	}
	double ys1 = (-xt2+sqrt(xt2*xt2-4.0*xt1*xt3))/(2.0*xt1);
	double xs1 = (c-ys1*b)/a;
	double ys2 = (-xt2-sqrt(xt2*xt2-4.0*xt1*xt3))/(2.0*xt1);
	double xs2 = (c-ys2*b)/a;
	if(ys1*ys1+xs1*xs1 < ys2*ys2+xs2*xs2){
		printf("%.5lf %.5lf\n", xs1, ys1);
	} else {
		printf("%.5lf %.5lf\n", xs2, ys2);
	}
}