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

#define EPS 1e-10

struct pt {
	long double x,y;
	pt(long double x, long double y):x(x),y(y){}
	pt(){}
	long double norm2(){return *this**this;}
	long double norm(){return sqrt(norm2());}
	bool operator==(const pt& p)const{return abs(x-p.x)<EPS&&abs(y-p.y)<EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(long double t){return pt(x*t,y*t);}
	pt operator/(long double t){return pt(x/t,y/t);}
	long double operator*(pt p){return x*p.x+y*p.y;}
	pt unit(){return *this/norm();}
	long double operator%(pt p){return x*p.y-y*p.x;}
	bool operator<(const pt& p)const{
		return x<p.x-EPS||(abs(x-p.x)<EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(long double a){return rot(pt(sin(a),cos(a)));}
	void in(){
		double _x,_y;
		scanf("%lf%lf",&_x,&_y);x=_x;y=_y;
	}
};
pt ccw90(1,0);
pt cw90(-1,0);


struct circle {
	pt o;long double r;
	circle(pt o, long double r):o(o),r(r){}
	circle(){}
	bool has(pt p){return abs((o-p).norm()-r)<EPS;}
	vector<pt> operator^(circle c){
		vector<pt> s;
		long double d=(o-c.o).norm();
		if(d>r+c.r+EPS||d+min(r,c.r)+EPS<max(r,c.r))return s;
		long double x=(d*d-c.r*c.r+r*r)/(2*d);
		long double y=sqrt(r*r-x*x);
		pt v=(c.o-o)/d;
		s.pb(o+v*x-v.rot(ccw90)*y);
		if(y>EPS)s.pb(o+v*x+v.rot(ccw90)*y);
		return s;
	}
	void in(){
		o.in();
		double _r;
		scanf("%lf",&_r);r=_r;
	}
	bool operator <(const circle& c)const{
		return o<c.o||o==c.o&&r+EPS<c.r;
	}
};

set<circle> sc;
vector<circle> c;
int n,nc;
set<pt> ps;
int uf[1<<10];

int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}

void join(int x, int y){
	x=find(x);y=find(y);
	if(x==y)return;
	nc--;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];
	uf[y]=x;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		circle asd;
		asd.in();
		sc.insert(asd);
	}
	c=vector<circle>(sc.begin(),sc.end());n=nc=SZ(c);
	mset(uf,-1);
	int r=1;
	fore(i,0,n){
		set<pt> z;
		fore(j,0,n)if(j!=i){
			auto v=c[i]^c[j];
			for(auto p:v)z.insert(p),ps.insert(p);
			if(SZ(v))join(i,j);
		}
		r+=SZ(z);
	}
	r+=nc-SZ(ps);
	printf("%d\n",r);
	return 0;
}