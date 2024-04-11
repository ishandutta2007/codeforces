#pragma GCC optimize("O3,fast-math")
#include<bits/stdc++.h>
using namespace std;
double const INF=1e20;
int const N=1000010;
namespace twodgeo{
	static double const PI=acos(-1.0);
	static double const EPS=1e-10;
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
			return sqrt(x*x+y*y);
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
		return vect(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
	}
	vect normal(vect a){
		return vect(-a.y/a.len(),a.x/a.len());
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
	line makeseg(point a,point b){
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
		vect x=a.p,y=a.p+a.v,v1=y-x,v2=b-x;
		return fabs(cross(v1,v2))/v1.len();
	}
	double distoseg(line a,point p){
		point x=a.p,y=a.p+a.v;
		if(x==y)
			return (p-x).len();
		vect v1=y-x,v2=p-x,v3=p-y;
		if(les(dot(v1,v2),0.0))
			return v2.len();
		if(les(0.0,dot(v1,v3)))
			return v3.len();
		return fabs(cross(v1,v2))/v1.len();
	}
	point lineproj(line a,point b){
		point x=a.p;
		vect v=a.v;
		return x+v*(dot(v,b-x)/dot(v,v));
	}
	int issegintersect(line a,line b){
		point a1=a.p,a2=a.p+a.v,b1=b.p,b2=b.p+b.v;
		double c1=cross(a2-a1,b1-a1),c2=cross(a2-a1,b2-a1),
		       c3=cross(b2-b1,a1-b1),c4=cross(b2-b1,a2-b1);
		return les(c1*c2,0.0)&&les(c3*c4,0.0);
	}
	int onseg(line a,point p){
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
	int ispointinpoly(polygon a,point p){
		int cnt=0;
		for(int i=0;i<(int)a.size();i++){
			int j=(i+1)%a.size();
			if(onseg(makeseg(a[i],a[j]),p))
				return -1;
			double k=cross(a[j]-a[i],p-a[i]),d1=a[i].y-p.y,d2=a[j].y-p.y;
			if(les(0,k)&&leq(d1,0)&&les(0,d2))
				cnt++;
			if(les(k,0)&&leq(d2,0)&&les(0,d1))
				cnt--;
		}
		return !!cnt;
	}
#define nxt(b,x) ((x+1)%b.size()) 
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
			while(leq(triarea(a[i-1],a[i],a[j]),triarea(a[i-1],a[i],a[nxt(a,j)])))
				j=nxt(a,j);
			ans=max(ans,max((a[i-1]-a[j]).len(),(a[i]-a[j]).len()));
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
#undef nxt
}
using namespace twodgeo;
int n,q;
double w,h,s[N];
polygon p[N];
pslg g[N];
int main(){
	scanf("%lf%lf%d",&w,&h,&n);
	for(int i=0,t;i<n;i++){
		for(scanf("%d",&t);t--;){
			double x,y;scanf("%lf%lf",&x,&y);
			p[i].push_back({x,y}); 
		}
		polytopslg(p[i],g[i]);
		s[i]=polygonarea(p[i]);
	}
	for(cin>>q;q--;){
		double x,y,r,ans=0.0;
		scanf("%lf%lf%lf",&x,&y,&r);
		point tp=point(x,y);
		vector<int>t;
		for(int i=0;i<n;i++){
			int flg=0;
			if(!flg)
				for(auto j:p[i])
					if(leq((j-tp).len(),r)){
						flg=1;break;
					}
			if(!flg)
				for(auto j:g[i]){
					if(leq(distoseg(j,tp),r)){
						flg=1;break;
					}
				}
			if(!flg)flg=ispointinpoly(p[i],tp);
			if(flg)t.push_back(i),ans+=s[i];
		}
		printf("%.8lf %d",ans,t.size());
		for(int x:t)printf(" %d",x);
		printf("\n"); 
	}
}