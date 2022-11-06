#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

double EPS=1e-9;

struct pt {  // for 3D add z coordinate
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
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
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);

double DINF=1e18;

int sgn2(double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
//	bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<=EPS;} // 3D
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		if(*this/l)return pt(DINF,DINF);
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
	ln rot(double a){return ln(p,p+pq.rot(a));} // 2D
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		pt ver[4];
		ver[0]={0,0};
		ver[1]={0,1};
		ver[2]={1,1};
		ver[3]={1,0};
		ln sid[4];
		fore(i,0,4)sid[i]=ln(ver[i],ver[(i+1)%4]);
		pt p(0.5,0.5);
		double res=0;
		ll tot=1;
		fore(it,0,tot){
			pt s(0,1.*it/tot);
			vector<ln> l;
			fore(i,0,n){
				l.pb(ln(p,s).rot(acos(-1)*i/n));
			}
			/*if(it==0){
				for(auto i:l)cout<<i.p.x<<" "<<i.p.y<<" "<<i.pq.x<<" "<<i.pq.y<<"\n";
			}*/
			double resp=10;
			fore(i,0,n){
				vector<pt> p;
				fore(j,0,4){
					auto in=sid[j]^l[i];
					if(in.x>-EPS&&in.x<1.+EPS&&in.y>-EPS&&in.y<1.+EPS)p.pb(in);
				}
				//for(auto j:p)cout<<j.x<<" "<<j.y<<" ";
				//cout<<"\n";
				if(SZ(p)==2){
					resp=min(resp,(p[0]-p[1]).norm());
				}
			}
			res=max(res,resp);
		}
		cout<<fixed<<setprecision(9)<<1./(sin(acos(-1)/(2*n))*res)<<"\n";
	}
	
	return 0;
}