#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

#define EPS 0

struct pt {
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(x*t,y*t);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;}
	double angle(pt p){
		return acos(*this*p/(norm()*p.norm()));}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
	void in(){scanf("%lf%lf",&x,&y);}
};
pt ccw90(1,0);
pt cw90(-1,0);
int sgn2(double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool seghas(pt r){return (r-p)*(r-(p+pq))-EPS<0;}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
};
struct circle {
	pt o;double r;
	circle(){}
	circle(pt o, double r):o(o),r(r){}
	vector<pt> operator^(circle c){
		vector<pt> s;
		double d=(o-c.o).norm();
		if(d>r+c.r+EPS||d+min(r,c.r)+EPS<max(r,c.r))return s;
		double x=(d*d-c.r*c.r+r*r)/(2*d);
		double y=sqrt(r*r-x*x);
		pt v=(c.o-o)/d;
		s.pb(o+v*x+v.rot(ccw90)*y);
		if(y>EPS)s.pb(o+v*x-v.rot(ccw90)*y);
		return s;
	}
	vector<pt> operator^(ln l){
		vector<pt> s;
		pt p=l.proj(o);
		double d=(p-o).norm();
		if(d-EPS>r)return s;
		if(abs(d-r)<EPS){s.pb(p);return s;}
		d=sqrt(r*r-d*d);
		s.pb(p+l.pq.unit()*d);
		s.pb(p-l.pq.unit()*d);
		return s;
	}
	vector<pt> tang(pt p){
		double d=sqrt((p-o).norm2()-r*r);
		return *this^circle(p,d);
	}
};

pt pp,q;double vp,vq;
circle c;

bool can(double t){
	pt p=pp.rot(t*vp/pp.norm());
	ln l(p,q);
	auto v=c^l;
	double d=0;
	if(!SZ(v)||!l.seghas(v[0]))d=(p-q).norm();
	else {
		d=1e10;
		auto v0=c.tang(p),v1=c.tang(q);
		for(pt p0:v0)for(pt q0:v1){
			d=min(d,(p-p0).norm()+(q-q0).norm()+p0.angle(q0)*c.r);
		}
	}
	return d<=t*vq;
}

int main(){
	pp.in();scanf("%lf",&vp);
	q.in();scanf("%lf",&vq);
	c.o=pt(0,0);scanf("%lf",&c.r);
	double s=0,e=1e9;
	fore(_,0,100){
		double m=(s+e)/2;
		if(can(m))e=m;
		else s=m;
	}
	printf("%.12lf\n",s);
	return 0;
}