#include<bits/stdc++.h>
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
	
	struct line{
		point p;
		vect v;
		line(point a={0,0},vect b={0,0}):p(a),v(b){}
		double ang(){
			return atan2(v.y,v.x);
		}
		double slope(){
			return equ(v.x,0)?INF:v.y/v.x;
		}
	};
	typedef line segment;
	segment makeseg(point a,point b){
		return line(a,b-a);
	}
	line midline(segment a){
		point x=a.p,y=a.p+a.v;
		return line((x+y)/2.0,normal(a.v));
	}
	int islinepara(line a,line b){
		return equ(cross(a.v,b.v),0);
	}
	point lineintersect(line a,line b){
		return islinepara(a,b)?a.p+a.v:a.p+a.v*(cross(b.v,a.p-b.p)/cross(a.v,b.v));
	}
	double distoline(line a,point b){
		return fabs(cross(a.v,b-a.p))/a.v.len();
	}
	double distoseg(segment a,point p){
		point x=a.p,y=a.p+a.v;
		if(x==y)
			return (p-x).len();
		vect v2=p-x,v3=p-y;
		if(les(dot(a.v,v2),0.0))
			return v2.len();
		if(les(0.0,dot(a.v,v3)))
			return v3.len();
		return distoline(a,p);
	}
	point lineproj(line a,point b){
		point x=a.p;
		vect v=a.v;
		return x+v*(dot(v,b-x)/dot(v,v));
	}
	int issegintersect(segment a,segment b){
		point a1=a.p,a2=a.p+a.v,b1=b.p,b2=b.p+b.v;
		double c1=cross(a2-a1,b1-a1),c2=cross(a2-a1,b2-a1),
		       c3=cross(b2-b1,a1-b1),c4=cross(b2-b1,a2-b1);
		return les(c1*c2,0.0)&&les(c3*c4,0.0);
	}
	int onseg(segment a,point p){
		point x=a.p,y=a.p+a.v;
		return equ(cross(x-p,y-p),0.0)&&les(dot(x-p,y-p),0.0);
	}
	
}
using namespace twodgeo;
int n,h;
point p[N],e,cur;
double ans;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>h;
	for(int i=1,x,y;i<=n;i++)
		cin>>x>>y,p[i]=point(x,y);
	e=p[n]+vect(0,h),cur=p[n];
	for(int i=n-1;i;i--)
		if(leq(makeseg(p[i],e).slope(),makeseg(cur,e).slope()))
			ans+=(p[i]-lineintersect(makeseg(p[i],p[i+1]),makeseg(cur,e))).len(),cur=p[i];
	cout<<fixed<<setprecision(8)<<ans<<"\n";
}