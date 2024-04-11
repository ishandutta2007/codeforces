
//my geometry template

#include<bits/stdc++.h>
//#define double long double
using namespace std;
double const INF=1e20;
int const N=233333;
double const PI=acos(-1.0),EPS=1e-10;
int les(double x,double y){
	return x<y-EPS;
}
int leq(double x,double y){
	return x<=y+EPS;
}
int equ(double x,double y){
	return leq(x,y)&&leq(y,x);
}
double dtor(double deg){
	return deg/180.0*PI;
}
double rtod(double rad){
	return rad/PI*180.0;
}
namespace twodgeo{
	struct point{
		double x,y;
		point(double a=0.0,double b=0.0):x(a),y(b){}
		point operator+(const point&rhs)const{
			return point(x+rhs.x,y+rhs.y);
		}
		point operator-(const point&rhs)const{
			return point(x-rhs.x,y-rhs.y);
		}
		point operator*(const double&rhs)const{
			return point(x*rhs,y*rhs);
		}
		point operator/(const double&rhs)const{
			return point(x/rhs,y/rhs);
		}
		int operator<(const point&rhs)const{
			return les(x,rhs.x)||(equ(x,rhs.x)&&les(y,rhs.y));
		}
		int operator==(const point&rhs)const{
			return equ(x,rhs.x)&&equ(y,rhs.y);
		}
		double len(){
			return sqrtl(x*x+y*y);
		}
		double ang(){
			return atan2(y,x);
		}
	};
	typedef point vect;
	double dot(vect a,vect b){
		return a.x*b.x+a.y*b.y;
	}
	double ang(vect a,vect b){
		return acos(dot(a,b)/a.len()/b.len());
	}
	double cross(vect a,vect b){
		return a.x*b.y-a.y*b.x;
	}
	double triarea(point a,point b,point c){
		return cross(b-a,c-a)/2.0;
	}
	vect rotate(vect a,double rad){
		return vect(a.x*cos(rad)-a.y*sin(rad),
			a.x*sin(rad)+a.y*cos(rad));
	}
	vect normal(vect a){
		return vect(-a.y/a.len(),a.x/a.len());
	}
	vect unit(vect a){
		return vect(a.x/a.len(),a.y/a.len());
	} 
	int atinf(point a){
		return equ(abs(a.x),INF)||equ(abs(a.y),INF);
	}
}
using namespace twodgeo;
point p,v;
double a,b,c,d;
void print(point p){
	cout<<fixed<<setprecision(10)<<p.x<<" "<<p.y<<"\n"; 
}
int main(){
	cin>>p.x>>p.y>>v.x>>v.y>>a>>b>>c>>d;
	print(p+unit(v)*b);
	print(p+normal(v)*a/2);
	print(p+normal(v)*c/2);
	print(p+normal(v)*c/2-unit(v)*d);
	print(p-normal(v)*c/2-unit(v)*d);
	print(p-normal(v)*c/2);
	print(p-normal(v)*a/2);
}