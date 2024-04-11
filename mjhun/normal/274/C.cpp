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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define EPS 1e-9

struct pt {  // for 3D add z coordinate
	long double x,y;
	pt(long double x, long double y):x(x),y(y){}
	pt(){}
	long double norm2(){return *this**this;}
	long double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<EPS&&abs(y-p.y)<EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(long double t){return pt(x*t,y*t);}
	pt operator/(long double t){return pt(x/t,y/t);}
	long double operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	long double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	long double operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(long double a){return rot(pt(sin(a),cos(a)));}
	void in(){double _x,_y;scanf("%lf%lf",&_x,&_y);x=_x;y=_y;}
};
pt ccw90(1,0);
pt cw90(-1,0);

int sgn2(long double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))-EPS<0;}
//	bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<EPS;} // 3D
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		return l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
	}
	long double angle(ln l){return pq.angle(l.pq);}
	int side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	long double dist(pt r){return (r-proj(r)).norm();}
//	long double dist(ln l){ // only 3D
//		if(*this/l)return dist(l.p);
//		return abs((l.p-p)*(pq^l.pq))/(pq^l.pq).norm();
//	}
	ln rot(auto a){return ln(p,p+pq.rot(a));} // 2D
};
ln bisector(ln l, ln m){ // angle bisector
	pt p=l^m;
	return ln(p,p+l.pq.unit()+m.pq.unit());
}
ln bisector(pt p, pt q){ // segment bisector (2D)
	return ln((p+q)*.5,p).rot(ccw90);
}

set<pt> w;
pt p[128];int n;pt *pp;

bool asd(pt p, pt q, pt r, long double a, long double b, long double c){
	pt s;
	if(abs(a)<EPS)s=q+r-p;
	else if(abs(b)<EPS)s=p+r-q;
	else if(abs(c)<EPS)s=p+q-r;
	else return false;
	fore(i,0,n)if(s==pp[i])return true;
	return false;
}

int main(){pp=p;
	scanf("%d",&n);
	long double r=-1;
	fore(i,0,n)p[i].in(),w.insert(p[i]);
	fore(i,0,n)fore(j,i+1,n)fore(k,j+1,n){
		long double a=(p[j]-p[i])*(p[k]-p[i]);
		long double b=(p[i]-p[j])*(p[k]-p[j]);
		long double c=(p[i]-p[k])*(p[j]-p[k]);
		if(a>EPS&&b>EPS&&c>EPS||asd(p[i],p[j],p[k],a,b,c)){
			pt q=bisector(p[i],p[j])^bisector(p[i],p[k]);
			long double rr=(q-p[i]).norm();
			bool c=true;
			fore(l,0,n)c=c&&(q-p[l]).norm()>rr-EPS;
			if(c)r=max(r,rr);
		}
	}
	if(r<0)puts("-1");
	else printf("%.12lf\n",(double)r);
	return 0;
}