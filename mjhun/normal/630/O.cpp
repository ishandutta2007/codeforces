#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

const double PI=acos(-1);
const double EPS=1e-9;

struct pt {  // for 3D add z coordinate
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<EPS&&abs(y-p.y)<EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(t*x,t*y);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;} // 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};

vector<pt> r;
int px,py,vx,vy,a,b,c,d;

int main(){
	scanf("%d%d%d%d%d%d%d%d",&px,&py,&vx,&vy,&a,&b,&c,&d);
	pt p(px,py),v(vx,vy);
	v=v.unit();
	r.pb(p+v*b);
	r.pb(p+v.rot(PI/2)*a/2);
	r.pb(p+v.rot(PI/2)*c/2);
	r.pb(p+v.rot(PI/2)*c/2-v*d);
	r.pb(p-v.rot(PI/2)*c/2-v*d);
	r.pb(p-v.rot(PI/2)*c/2);
	r.pb(p-v.rot(PI/2)*a/2);
	for(pt w:r)printf("%.12lf %.12lf\n",w.x,w.y);
	return 0;
}