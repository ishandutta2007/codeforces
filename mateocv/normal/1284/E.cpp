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
 
long double EPS=1e-9;
struct pt {  // for 3D add z coordinate
	long double x,y;
	pt(long double x, long double y):x(x),y(y){}
	pt(){}
	long double norm2(){return *this**this;}
	long double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p)const{return pt(x-p.x,y-p.y);}
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
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(long double a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);
 
struct Cmp { // IMPORTANT: add const in pt operator -
	pt r;
	Cmp(pt r):r(r){}
	int cuad(const pt &a)const {
		if(a.x>0&&a.y>=0)return 0;
		if(a.x<=0&&a.y>0)return 1;
		if(a.x<0&&a.y<=0)return 2;
		if(a.x>=0&&a.y<0)return 3;
		assert(a.x==0&&a.y==0);
		return -1;
	}
	bool cmp(const pt& p1, const pt& p2)const {
		int c1=cuad(p1),c2=cuad(p2);
		if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
		return c1<c2;
	}
	bool operator()(const pt& p1, const pt& p2)const {
		return cmp(p1-r,p2-r);
	}
};
 
int main(){FIN;
	ll n; cin>>n;
	ll x[n],y[n];
	fore(i,0,n)cin>>x[i]>>y[i];
	ll res=0;
	fore(i,0,n){
		pt p={x[i],y[i]};
		vector<pt> v;
		fore(j,0,n){
			if(i!=j)v.pb({x[j],y[j]});
		}
		sort(ALL(v),Cmp(p));
		//for(auto i:v)cout<<i.x<<" "<<i.y<<"\n";
		ll l=0,r=0;
		res+=(n-1)*(n-2)*(n-3)*(n-4)/24;
		while(1){
			while(v[(r+1)%SZ(v)].left(p,v[l])&&(r+1)%SZ(v)!=l)r++,r%=SZ(v);
			if(l<=r){
				res-=(r-l)*(r-l-1)*(r-l-2)/6;
			}else{
				res-=(r-l+SZ(v))*(r-l+SZ(v)-1)*(r-l+SZ(v)-2)/6;
			}
			l++;
			l%=SZ(v);
			if(l==0)break;
		}
		//cout<<res<<"\n";
	}
	cout<<res;
	return 0;
}