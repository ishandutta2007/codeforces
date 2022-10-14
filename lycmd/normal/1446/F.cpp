#include<bits/stdc++.h>
#define int long long
//#define double long double
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
	struct circle{
		point o;double r;
		circle(point a={0,0},double b=0.0):o(a),r(b){}
		circle(point a,point b):o(a),r((a-b).len()){}
		point gprad(double a){
			return point(o.x+cos(a)*r,o.y+sin(a)*r);
		}
	};
}
using namespace twodgeo;
int n,k,m,tr[N];
point p[N];
double l[N],r[N];
pair<int,int>a[N];
vector<double>b;
void add(int x,int y=1){
	for(;x<N;x+=x&-x)tr[x]+=y;
}
int ask(int x){
	return x?ask(x&(x-1))+tr[x]:0; 
}
int check(double mid){
	circle c({0,0},mid);
	b.clear(),m=0;
	for(int i=1;i<=n;i++){
		if(leq(p[i].len(),mid))
			continue;
		double dm=p[i].ang(),da=acos(c.r/p[i].len()),dl=dm-da,dr=dm+da;
		if(leq(dl,-PI))dl+=PI*2;
		if(les(PI,dr))dr-=PI*2;
		if(les(dr,dl))swap(dl,dr);
		l[++m]=dl,r[m]=dr,b.push_back(dl),b.push_back(dr);
	}
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=1;i<=m;i++)
		a[i]={lower_bound(b.begin(),b.end(),l[i])-b.begin()+1,
			lower_bound(b.begin(),b.end(),r[i])-b.begin()+1};
	sort(a+1,a+1+m);
	memset(tr,0,sizeof tr);
	int res=n*(n-1)/2;
	for(int i=1;i<=m;i++)
		res-=ask(a[i].second)-ask(a[i].first-1),add(a[i].second);
	return res>=k;
} 
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	double l=0.0,r=2e4;
	while(l<r-EPS){
		double mid=(l+r)/2.0;
		if(check(mid))r=mid;else l=mid;
	}
	cout<<fixed<<setprecision(8)<<r<<"\n";
}