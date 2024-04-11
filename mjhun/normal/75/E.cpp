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

#define EPS 1e-8

struct pt {  // for 3D add z coordinate
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
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
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
	bool has(pt r){return dist(r)<EPS;}
	bool hhas(pt r){return has(r)&&(r-p)*pq>-EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))+EPS<0;}
//	bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<EPS;} // 3D
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
//		if(!has(r)){return pt(NAN,NAN,NAN);} // check only for 3D
		return r;
	}
	double angle(ln l){return pq.angle(l.pq);}
	int side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	double dist(pt r){return (r-proj(r)).norm();}
//	double dist(ln l){ // only 3D
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

pt s,e,p[64],q[64];int n,m,i0=-1,i1=-1;double r;

int main(){
	s.in();e.in();
	scanf("%d",&n);
	fore(i,0,n)p[i].in();
	ln l(s,e);
	fore(i,0,n){
		q[m++]=p[i];
		if(l.seghas(p[i])){
			if(i0<0)i0=m-1;
			else {
				assert(i1<0);
				i1=m-1;
			}
		}
		else {
			ln z(p[i],p[(i+1)%n]);
			if(!(z/l)){
				pt w=z^l;
				if(l.seghas(w)&&z.seghas(w)){
					q[m++]=w;
					if(i0<0)i0=m-1;
					else {
						assert(i1<0);
						i1=m-1;
					}
				}
			}
		}
	}
	//assert(i0<0&&i1<0||i0>=0&&i1>=0);
	if(i1<0)r=(s-e).norm();
	else {
		double a=0,b=0;
		fore(i,0,m){
			a+=(q[i]-q[(i+1)%m]).norm();
			if(i>=i0&&i<i1)b+=(q[i]-q[(i+1)%m]).norm();
		}
		r=(e-s).norm()-(q[i0]-q[i1]).norm()+min(2*(q[i0]-q[i1]).norm(),
			min(b,a-b));
	}
	printf("%.12lf\n",r);
	return 0;
}