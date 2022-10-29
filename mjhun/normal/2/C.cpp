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

#define EPS 1e-7

struct pt {
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<EPS&&abs(y-p.y)<EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(x*t,y*t);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
	void out(){printf("%.5lf %.5lf\n",x,y);}
};
pt ccw90(1,0);
pt cw90(-1,0);

int sgn2(double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<EPS;}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<EPS;}
	pt operator^(ln l){
		return l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
	}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	double dist(pt r){return (r-proj(r)).norm();}
	ln rot(auto a){return ln(p,p+pq.rot(a));}
};
ln bisector(pt p, pt q){
	return ln((p+q)*.5,p).rot(ccw90);
}

struct circle {
	pt o;double r;
	circle(pt o, double r):o(o),r(r){}
	bool has(pt p){return abs((o-p).norm()-r)<EPS;}
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
};

pair<pt,int> w[3];

circle doit(pt c0, double r0, pt c1, double r1){
	pt p0=c1+(c0-c1)*(r1/(r0+r1));
	pt p1=c1+(c0-c1)*(r1/(r1-r0));
	pt c=(p0+p1)/2;
	double r=(c-p0).norm();
	deb("%.5lf %.5lf %.5lf\n",c.x,c.y,r);
	return circle(c,r);
}

int main(){
	fore(i,0,3){
		int x,y,r;
		scanf("%d%d%d",&x,&y,&r);
		w[i]=mp(pt(x,y),r);
	}
	if(w[0].snd==w[1].snd&&w[0].snd==w[2].snd){
		ln l01=bisector(w[0].fst,w[1].fst);
		ln l02=bisector(w[0].fst,w[2].fst);
		ln l12=bisector(w[1].fst,w[2].fst);
		if(l01/l02)return 0;
		pt p=l01^l02;
		if(l12.has(p))p.out();
	}
	else if(w[0].snd==w[1].snd||w[0].snd==w[2].snd||w[1].snd==w[2].snd){
		if(w[0].snd==w[2].snd)swap(w[1],w[2]);
		else if(w[1].snd==w[2].snd)swap(w[0],w[2]);
		ln l01=bisector(w[0].fst,w[1].fst);
		circle c02=doit(w[0].fst,w[0].snd,w[2].fst,w[2].snd);
		circle c12=doit(w[1].fst,w[1].snd,w[2].fst,w[2].snd);
		vector<pt> r;
		for(pt p:c02^l01)if(c12.has(p))r.pb(p);
		if(r.size()==1)r[0].out();
		else if(r.size()==2){
			if((r[0]-w[0].fst).norm()<(r[1]-w[0].fst).norm())r[0].out();
			else r[1].out();
		}
	}
	else {
		circle c01=doit(w[0].fst,w[0].snd,w[1].fst,w[1].snd);
		circle c02=doit(w[0].fst,w[0].snd,w[2].fst,w[2].snd);
		circle c12=doit(w[1].fst,w[1].snd,w[2].fst,w[2].snd);
		vector<pt> r;
		for(pt p:c02^c01)if(c12.has(p))r.pb(p);
		if(r.size()==1)r[0].out();
		else if(r.size()==2){
			if((r[0]-w[0].fst).norm()<(r[1]-w[0].fst).norm())r[0].out();
			else r[1].out();
		}
	}
	return 0;
}