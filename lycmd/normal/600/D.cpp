
//my geometry template

#include<bits/stdc++.h>
#define double long double
using namespace std;
double const INF=1e20;
int const N=233333;
double const PI=acos(-1.0),EPS=1e-12;
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
	};
	typedef line segment;
	segment makeseg(point a,point b){
		return line(a,b-a);
	}
	line midline(segment a){
		point x=a.p,y=a.p+a.v;
		return line((x+y)/2.0,normal(a.v));
	}
	point lineintersect(line a,line b){
		return a.p+a.v*(cross(b.v,a.p-b.p)/cross(a.v,b.v));
	}
	int islinepara(line a,line b){
		return equ(cross(a.v,b.v),0);
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
	
	typedef vector<line> pslg;
	typedef vector<point> polygon;
	polygon const polyplane=
		{{-INF,-INF},{-INF,INF},{INF,INF},{INF,-INF}};
	pslg const pslgplane=
		{{{-INF,-INF},{0,2*INF}},{{-INF,INF},{2*INF,0}},
		{{INF,INF},{0,2*-INF}},{{INF,-INF},{2*-INF,0}}};
	double polygonarea(polygon a){
		double s=0;
		for(int i=1;i<(int)a.size()-1;i++)
			s+=triarea(a[0],a[i],a[i+1]);
		return s;
	}
#define nxt(b,x) ((x+1)%b.size())
	int ispointinpoly(polygon a,point p){
		int cnt=0;
		for(int i=0;i<(int)a.size();i++){
			int j=nxt(a,i);
			if(onseg(makeseg(a[i],a[j]),p))
				return -1;
			double k=cross(a[j]-a[i],p-a[i]),
				d1=a[i].y-p.y,d2=a[j].y-p.y;
			if(les(0,k)&&leq(d1,0)&&les(0,d2))
				cnt++;
			if(les(k,0)&&leq(d2,0)&&les(0,d1))
				cnt--;
		}
		return !!cnt;
	}
	double convexhull(polygon a,polygon&b){
		sort(a.begin(),a.end());
		a.erase(unique(a.begin(),a.end()),a.end());
		b.clear();
#define p (int)b.size()
		for(int i=0;i<(int)a.size();i++){
			while(p>1&&leq(cross(b[p-1]-b[p-2],a[i]-b[p-2]),0))
				b.pop_back();
			b.push_back(a[i]);
		}
		for(int t=p,i=a.size()-2;~i;i--){
			while(p>t&&leq(cross(b[p-1]-b[p-2],a[i]-b[p-2]),0))
				b.pop_back();
			b.push_back(a[i]);
		}
		if(a.size()>1)
			b.pop_back();
		double res=0;
		for(int i=0;i<p;i++)
			res+=(b[i]-b[nxt(b,i)]).len();
#undef p
		return res;
	}
	double convpolydia(polygon a){
		if(a.size()==2)
			return (a[0]-a[1]).len();
		double ans=0;
		for(int i=1,j=2;i<(int)a.size();i++){
			while(leq(triarea(a[i-1],a[i],a[j]),
				triarea(a[i-1],a[i],a[nxt(a,j)])))
				j=nxt(a,j);
			ans=max(ans,max((a[i-1]-a[j]).len(),
				(a[i]-a[j]).len()));
		}
		return ans;
	}
	int onright(line a,point b){
		return les(cross(a.v,b-a.p),0);
	}
	void polytopslg(polygon a,pslg&b){
		b.push_back(makeseg(a[a.size()-1],a[0]));
		for(int i=1;i<(int)a.size();i++)
			b.push_back(makeseg(a[i-1],a[i]));
	}
	int hfplintersect(pslg a,polygon&b){
		sort(a.begin(),a.end(),[](line x,line y){
			return les(x.ang(),y.ang());
		});
		int l=0,r=0;
		pslg q;q.resize(N);
		polygon p;p.resize(N);
		q[0]=a[0];
		for(int i=1;i<(int)a.size();i++){
			while(l<r&&onright(a[i],p[r]))r--;
			while(l<r&&onright(a[i],p[l+1]))l++;
			q[++r]=a[i];
			if(l<r&&islinepara(q[r],q[r-1])){
				if(onright(q[r],q[r-1].p)&&
					les(dot(q[r].v,q[r-1].v),0))
					return 0;
				r--;
				if(!onright(q[r],a[i].p))
					q[r]=a[i];
			}
			if(l<r)
				p[r]=lineintersect(q[r],q[r-1]);
		}
		while(l<r&&onright(q[l],p[r]))
			r--;
		if(r<=l+1)
			return 0;
		p[l]=lineintersect(q[l],q[r]);
		b.clear();
		for(int i=l;i<=r;i++)
			b.push_back(p[i]);
		return 1;
	}
#undef nxt
	struct circle{
		point o;double r;
		circle(point a={0,0},double b=0.0):o(a),r(b){}
		circle(point a,point b):o(a),r((a-b).len()){}
		circle(point a,point b,point c);
		point gprad(double a){
			return point(o.x+cos(a)*r,o.y+sin(a)*r);
		}
	};
	vector<point>linecircintersect(line l,circle c){
		point t=lineproj(l,c.o);
		double d=(c.o-t).len();
		if(les(c.r,d))return vector<point>();
		if(equ(c.r,d))return vector<point>{t};
		double k=sqrtl(c.r*c.r-d*d);
		return vector<point>{t+unit(l.v)*k,t-unit(l.v)*k};
	}
	vector<point>circintersect(circle a,circle b){
		double d=(a.o-b.o).len();
		if(equ(d,0.0)&&equ(a.r,b.r))
			return vector<point>{{INF,INF}};
		if(les(a.r+b.r,d)||les(d,fabs(a.r-b.r)))
			return vector<point>();
		double ap=(b.o-a.o).ang(),
			at=acos((a.r*a.r+d*d-b.r*b.r)/2.0/d/a.r);
		if(equ(at,0.0))
			return vector<point>{a.gprad(ap)};
		else
			return vector<point>{a.gprad(ap+at),a.gprad(ap-at)};
	}
	vector<line>getcirctang(point p,circle c){
		double d=(p-c.o).len(),a=asin(c.r/d);
		if(les(d,c.r))return vector<line>();
		if(equ(d,c.r))return vector<line>{{p,normal(p-c.o)}};
		return vector<line>{{p,rotate(c.o-p,a)},{p,rotate(c.o-p,-a)}};
	}
	vector<line>getcirctang(circle a,circle b){
		if(les(a.r,b.r))swap(a,b);
		double d=(a.o-b.o).len(),ap=atan2(b.o.y-a.o.y,b.o.x-a.o.x);
		if(equ(d,0.0)&&equ(a.r,b.r))
			return vector<line>{makeseg({INF,INF},{INF,INF})};
		if(les(d,a.r-b.r))
			return vector<line>();
		if(equ(d,a.r-b.r))
			return vector<line>{line(a.gprad(ap),normal(b.o-a.o))};
		double at=acos((a.r-b.r)/d);
		vector<line>res;
		res.push_back(makeseg(a.gprad(ap+at),b.gprad(ap+at)));
		res.push_back(makeseg(a.gprad(ap-at),b.gprad(ap-at)));
		if(equ(d,a.r+b.r))
			res.push_back(makeseg(a.gprad(ap),b.gprad(ap+PI)));
		if(les(a.r+b.r,d)){
			double t=acos((a.r+b.r)/d);
			res.push_back(makeseg(a.gprad(ap+t),b.gprad(ap+t+PI)));
			res.push_back(makeseg(a.gprad(ap-t),b.gprad(ap-t+PI)));
		}
		return res;
	}
	point incenter(point a,point b,point c){
		return lineintersect(line(a,rotate(b-a,ang(c-a,b-a)/2)),
			line(b,rotate(c-b,ang(a-b,c-b)/2)));
	}
	point circumcenter(point a,point b,point c){
		return lineintersect(midline(makeseg(a,b)),
			midline(makeseg(b,c)));
	}
	point centroid(point a,point b,point c){
		return lineintersect(makeseg(a,(b+c)/2),makeseg(b,(a+c)/2));
	}
	point orthocenter(point a,point b,point c){
		return lineintersect(makeseg(a,lineproj(makeseg(b,c),a)),
			makeseg(b,lineproj(makeseg(a,c),b)));
	}
	circle::circle(point a,point b,point c){
		o=circumcenter(a,b,c),r=(o-a).len();
	}
}
using namespace twodgeo;
namespace tridgeo{
	struct point3{
		double x,y,z;
		point3(double a=0.0,double b=0.0,double c=0.0):x(a),y(b),z(){}
		point3 operator+(const point3&rhs)const{
			return point3(x+rhs.x,y+rhs.y,z+rhs.z);
		}
		point3 operator-(const point3&rhs)const{
			return point3(x-rhs.x,y-rhs.y,z-rhs.z);
		}
		point3 operator*(const double&rhs)const{
			return point3(x*rhs,y*rhs,z*rhs);
		}
		point3 operator/(const double&rhs)const{
			return point3(x/rhs,y/rhs,z/rhs);
		}
		int operator<(const point3&rhs)const{
			if(!equ(x,rhs.x))return les(x,rhs.x);
			if(!equ(y,rhs.y))return les(y,rhs.y);
			return les(z,rhs.z);
		}
		int operator==(const point3&rhs)const{
			return equ(x,rhs.x)&&equ(y,rhs.y)&&equ(z,rhs.z);
		}
		double len()const{
			return sqrtl(x*x+y*y+z*z);
		}
	};
	typedef point3 vect3;
	double dot(vect3 a,vect3 b){
		return a.x*b.x+a.y*b.y+a.z*b.z;
	}
	vect3 cross(vect3 a,vect3 b){
		return vect3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
	}
	double ang(vect3 a,vect3 b){
		return acos(dot(a,b)/a.len()/b.len());
	}
	struct plane{
		point3 p;vect3 v;
		plane(point3 a=point3(),vect3 b=vect3()):p(a),v(b){}
	};
	struct line3{
		point3 p;vect3 v;
		line3(point3 a={0,0},vect3 b={0,0}):p(a),v(b){}
	};
	typedef line3 segment3;
	line3 makeseg(point3 a,point3 b){
		return line3(a,b-a);
	}
	double distoplane(point3 a,plane p){
		return fabs(dot(a-p.p,p.v));
	}
	point3 planeproj(point3 a,plane p){
		return a-p.v*dot(a-p.p,p.v);
	}
	int islineplanepara(line3 l,plane p){
		return equ(dot(p.v,l.v),0.0);
	}
	int issegplaneintersect(line3 l,plane p){
		if(islineplanepara(l,p))return 0;
		double k=dot(p.v,p.p-l.p)/dot(p.v,l.v);
		return leq(0.0,k)&&leq(k,1.0);
	}
	point3 lineplaneintersect(line3 l,plane p){
		return l.p+l.v*dot(p.v,p.p-l.p)/dot(p.v,l.v);
	}
	double triarea(point3 a,point3 b,point3 c){
		return cross(b-a,c-a).len()/2.0;
	}
	double tetravolumn(point3 a,point3 b,point3 c,point3 d){
		return dot(d-a,cross(b-a,c-a))/6.0;
	}
	int pointintri(point3 p,point3 a,point3 b,point3 c){
		return equ(triarea(a,b,c),
			triarea(p,a,b)+triarea(p,b,c)+triarea(p,a,c));
	}
	double distoline(line3 a,point3 b){
		return cross(a.v,b-a.p).len()/a.v.len();
	}
	double distoseg(segment3 a,point3 p){
		point3 x=a.p,y=a.p+a.v;
		if(x==y)
			return (p-x).len();
		vect3 v2=p-x,v3=p-y;
		if(les(dot(a.v,v2),0.0))
			return v2.len();
		if(les(0.0,dot(a.v,v3)))
			return v3.len();
		return distoline(a,p);
	}
}
//using namespace tridgeo;
circle a,b;
int main(){
	ios::sync_with_stdio(0);
	cin>>a.o.x>>a.o.y>>a.r>>b.o.x>>b.o.y>>b.r;
	if(les(a.r,b.r))swap(a,b);
	cout<<fixed<<setprecision(12);
	double d=(a.o-b.o).len();
	if(leq(d,fabs(a.r-b.r)))
		cout<<PI*b.r*b.r<<"\n";
	else if(leq(a.r+b.r,d))
		cout<<0.0<<"\n";
	else{
		double res=0,at=acos((a.r*a.r+d*d-b.r*b.r)/(2.0*d*a.r)),
			s1=PI*a.r*a.r*at/PI,
			s2=a.r*a.r*sin(at*2)/2.0;
		res+=s1-s2;
		at=acos((b.r*b.r+d*d-a.r*a.r)/(2.0*d*b.r)),
		s1=PI*b.r*b.r*at/PI,
		s2=b.r*b.r*sin(at*2)/2.0;
		cout<<res+s1-s2<<"\n";
	}
}