using namespace std;
#define _USE_MATH_DEFINES
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iomanip>
const double EPS=1e-10;
bool eq(double a,double b){return abs(a-b)<EPS;}
struct Point{
	double x,y;
	Point(double x_=0,double y_=0):x(x_),y(y_){}
	Point operator-()const{return Point(-x,-y);}
	Point operator+(const Point&p)const{return Point(x+p.x,y+p.y);}
	Point operator-(const Point&p)const{return Point(x-p.x,y-p.y);}
	Point operator*(const double k)const{return Point(x*k,y*k);}
	Point operator/(const double k)const{return Point(x/k,y/k);}
	bool operator<(const Point&p)const{return eq(x,p.x)?y<p.y:x<p.x;}
	bool operator==(const Point&p)const{return eq(x,p.x)&&eq(y,p.y);}
};
istream&operator>>(istream&is,Point&p){return is>>p.x>>p.y;}
ostream&operator<<(ostream&os,const Point&p){return os<<fixed<<setprecision(9)<<p.x<<' '<<p.y;}
struct Line{
	Point p1,p2;
	Line(Point p1_=Point(),Point p2_=Point()):p1(p1_),p2(p2_){}
};
struct Segment:Line{
	Segment(Point p1_=Point(),Point p2_=Point()):Line(p1_,p2_){}
};
struct Circle{
	Point o;
	double r;
	Circle(Point o_=Point(),double r_=0):o(o_),r(r_){}
};
using Polygon=vector<Point>;
//function list begin
Point vec(const Line&);
double norm(const Point&);
double norm(const Line&);
double abs(const Point&);
double abs(const Line&);
double arg(const Point&);
double arg(const Line&);
double arg(const Point&,const Point&,const Point&);//a->b->c
int argtype(const Point&);//(-pi,0]->0,(0,pi]->1
bool argless(const Point&,const Point&);//sorting points with arg
double dot(const Point&,const Point&);
double cross(const Point&,const Point&);
Point polar(const double,const double);
Point rotate(const Point&,const double);
enum{ONLINE_FRONT=-2,CLOCKWISE=-1,ON_SEGMENT=0,COUNTER_CLOCKWISE=1,ONLINE_BACK=2};
int ccw(const Point&,const Point&);
int ccw(const Point&,const Point&,const Point&);
int ccw(const Line&,const Point&);
bool orthogonal(const Point&,const Point&);
bool orthogonal(const Line&,const Line&);
bool parallel(const Point&,const Point&);
bool parallel(const Line&,const Line&);
bool intersect(const Line&,const Point&);
bool intersect(const Line&,const Line&);
bool intersect(const Segment&,const Point&);
bool intersect(const Segment&,const Segment&);
bool intersect(const Line&,const Segment&);
bool intersect(const Segment&,const Line&);
bool intersect(const Circle&,const Point&);
int intersect(const Circle&,const Line&);//count contacts
int intersect(const Circle&,const Segment&);
int intersect(const Circle&,const Circle&);//count common tangents
double distance(const Point&,const Point&);
double distance(const Line&,const Point&);
double distance(const Line&,const Line&);
double distance(const Segment&,const Point&);
double distance(const Segment&,const Segment&);
double distance(const Line&,const Segment&);
double distance(const Segment&,const Line&);
double distance(const Circle&,const Point&);
double distance(const Circle&,const Line&);
double distance(const Circle&,const Segment&);
double distance(const Circle&,const Circle&);
Point projection(const Line&,const Point&);
Point reflection(const Line&,const Point&);
Point crosspoint(const Line&,const Line&);
pair<Point,Point>crosspoint(const Circle&,const Line&);
pair<Point,Point>crosspoint(const Circle&,const Segment&);
pair<Point,Point>crosspoint(const Circle&,const Circle&);
pair<Point,Point>tangent(const Circle&,const Point&);
vector<Line>tangent(const Circle&,const Circle&);
bool is_convex(const Polygon&);
Polygon convex_full(Polygon,bool=false);
enum{OUT,ON,IN};
int contain(const Polygon&,const Point&);
int contain(const Circle&,const Point&);
int contain(const Circle&,const Segment&);
Polygon convex_cut(const Polygon&,const Line&);
double diameter(Polygon);
double area(const Polygon&);
double area(const Polygon&,const Line&);
double area(const Polygon&,const Circle&);
//function list end
Point vec(const Line&s){return s.p2-s.p1;}
double norm(const Point&p){return p.x*p.x+p.y*p.y;}
double norm(const Line&s){return norm(vec(s));}
double abs(const Point&p){return hypot(p.x,p.y);}
double abs(const Line&s){return abs(vec(s));}
double arg(const Point&p){return atan2(p.y,p.x);}
double arg(const Line&s){return arg(vec(s));}
double arg(const Point&a,const Point&b,const Point&c){
	double A=arg(b-a),B=arg(c-b);
	double theta=abs(A-B);
	return min(theta,2*M_PI-theta);
}
int argtype(const Point&a)
{
	return a.y<-EPS?0:a.y>EPS?1:a.x<0?1:0;
}
bool argless(const Point&a,const Point&b)
{
	int at=argtype(a),bt=argtype(b);
	return at!=bt?at<bt:ccw(a,b)>0;
}
double dot(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
double cross(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
Point polar(const double r,const double theta){return Point(cos(theta),sin(theta))*r;}
Point rotate(const Point&p,const double theta){
	return Point(p.x*cos(theta)-p.y*sin(theta),p.x*sin(theta)+p.y*cos(theta));
}
int ccw(const Point&a,const Point&b)
{
	return cross(a,b)>EPS?COUNTER_CLOCKWISE
		:cross(a,b)<-EPS?CLOCKWISE
		:dot(a,b)<0?ONLINE_BACK
		:norm(a)<norm(b)?ONLINE_FRONT
		:ON_SEGMENT;
}
int ccw(const Point&a,const Point&b,const Point&c){return ccw(b-a,c-a);}
int ccw(const Line&s,const Point&p){return ccw(s.p1,s.p2,p);}
bool orthogonal(const Point&a,const Point&b){return eq(dot(a,b),0);}
bool orthogonal(const Line&s,const Line&t){return orthogonal(vec(s),vec(t));}
bool parallel(const Point&a,const Point&b){return eq(cross(a,b),0);}
bool parallel(const Line&s,const Line&t){return parallel(vec(s),vec(t));}
bool intersect(const Line&s,const Point&p){return eq(cross(vec(s),p-s.p1),0);}
bool intersect(const Line&s,const Line&t){return !parallel(s,t)||intersect(s,t.p1);}
bool intersect(const Segment&s,const Point&p){return ccw(s,p)==ON_SEGMENT;}
bool intersect(const Segment&s,const Segment&t){
	return ccw(s,t.p1)*ccw(s,t.p2)<=0&&ccw(t,s.p1)*ccw(t,s.p2)<=0;
}
bool intersect(const Line&s,const Segment&t){
	return cross(vec(s),t.p1-s.p1)*cross(vec(s),t.p2-s.p1)<EPS;
}
bool intersect(const Segment&s,const Line&t){return intersect(t,s);}
bool intersect(const Circle&c,const Point&p){return eq(distance(c.o,p),c.r);}
int intersect(const Circle&c,const Line&s){
	double d=distance(s,c.o);
	return eq(d,c.r)?1:d<c.r?2:0;
}
int intersect(const Circle&c,const Segment&s){
	Point h=projection(s,c.o);
	double d1=distance(c.o,s.p1),d2=distance(c.o,s.p2);
	return distance(c.o,h)>c.r+EPS?0
		:d1<c.r-EPS&&d2<c.r-EPS?0
		:d1<c.r-EPS&&d2>c.r-EPS||d1>c.r-EPS&&d2<c.r-EPS?1
		:intersect(s,h)?eq(distance(c.o,h),c.r)?1:2
		:0;
}
int intersect(const Circle&a,const Circle&b){
	double d=distance(a.o,b.o);
	return eq(d,a.r+b.r)?3:d>a.r+b.r?4:eq(d,abs(a.r-b.r))?1:d>abs(a.r-b.r)?2:0;
}
double distance(const Point&a,const Point&b){return abs(a-b);}
double distance(const Line&s,const Point&p){return distance(p,projection(s,p));}
double distance(const Line&s,const Line&t){return intersect(s,t)?0:distance(s,t.p1);}
double distance(const Segment&s,const Point&p){
	return distance(p,
		dot(vec(s),p-s.p1)<0?s.p1
		:dot(-vec(s),p-s.p2)<0?s.p2
		:projection(s,p)
	);
}
double distance(const Segment&s,const Segment&t){
	return intersect(s,t)?0:min({
		distance(s,t.p1),distance(s,t.p2),
		distance(t,s.p1),distance(t,s.p2)
	});
}
double distance(const Line&s,const Segment&t){
	return intersect(s,t)?0:min(distance(s,t.p1),distance(s,t.p2));
}
double distance(const Segment&s,const Line&t){return distance(t,s);}
double distance(const Circle&c,const Point&p){return abs(distance(c.o,p)-c.r);}
double distance(const Circle&c,const Line&s){return max(distance(s,c.o)-c.r,0.);}
double distance(const Circle&c,const Segment&s){
	return intersect(c,s)?0
		:contain(c,s)?c.r-max(distance(c.o,s.p1),distance(c.o,s.p2))
		:distance(s,c.o)-c.r;
}
double distance(const Circle&a,const Circle&b){return max(distance(a.o,b.o)-a.r-b.r,0.);}
Point projection(const Line&s,const Point&p){
	return s.p1+vec(s)*dot(p-s.p1,vec(s))/norm(s);
}
Point reflection(const Line&s,const Point&p){return projection(s,p)*2-p;}
Point crosspoint(const Line&s,const Line&t){
	double d1=abs(cross(vec(s),t.p1-s.p1));
	double d2=abs(cross(vec(s),t.p2-s.p1));
	return t.p1+vec(t)*(d1/(d1+d2));
}
pair<Point,Point>crosspoint(const Circle&c,const Line&s){
	Point h=projection(s,c.o);
	Point e=vec(s)/abs(s)*sqrt(c.r*c.r-norm(h-c.o));
	return minmax(h-e,h+e);
}
pair<Point,Point>crosspoint(const Circle&c,const Segment&s){
	pair<Point,Point>p=crosspoint(c,Line(s));
	return intersect(c,s)==2?p
		:intersect(s,p.first)?make_pair(p.first,p.first)
		:make_pair(p.second,p.second);
}
pair<Point,Point>crosspoint(const Circle&a,const Circle&b){
	double d=distance(a.o,b.o);
	double alpha=acos((a.r*a.r+d*d-b.r*b.r)/(2*a.r*d));
	double theta=arg(b.o-a.o);
	return minmax(a.o+polar(a.r,theta+alpha),a.o+polar(a.r,theta-alpha));
}
pair<Point,Point>tangent(const Circle&c,const Point&p){
	return crosspoint(c,Circle(p,sqrt(norm(c.o-p)-c.r*c.r)));
}
vector<Line>tangent(const Circle&a,const Circle&b){
	vector<Line>ret;
	double g=distance(a.o,b.o);
	if(eq(g,0))return ret;
	Point u=(b.o-a.o)/g;
	Point v=rotate(u,M_PI/2);
	for(int s:{-1,1}){
		double h=(a.r+b.r*s)/g;
		if(eq(h*h,1))ret.emplace_back(a.o+(h>0?u:-u)*a.r,a.o+(h>0?u:-u)*a.r+v);
		else if(1-h*h>0){
			Point U=u*h,V=v*sqrt(1-h*h);
			ret.emplace_back(a.o+(U+V)*a.r,b.o-(U+V)*b.r*s);
			ret.emplace_back(a.o+(U-V)*a.r,b.o-(U-V)*b.r*s);
		}
	}
	return ret;
}
bool is_convex(const Polygon&P){
	for(int i=0;i<P.size();i++)
		if(ccw(P[i],P[(i+1)%P.size()],P[(i+2)%P.size()])==CLOCKWISE)return false;
	return true;
}
Polygon convex_full(Polygon P,bool ONSEG){
	if(P.size()<=2)return P;
	sort(P.begin(),P.end());
	Polygon ret(2*P.size());
	int k=0,t;
	if(ONSEG){
		for(const Point&p:P){
			while(k>=2&&ccw(ret[k-2],ret[k-1],p)==CLOCKWISE)k--;
			ret[k++]=p;
		}
		t=k;
		for(int i=P.size()-2;i>=0;i--){
			while(k>=t+1&&ccw(ret[k-2],ret[k-1],P[i])==CLOCKWISE)k--;
			ret[k++]=P[i];
		}
	}
	else{
		for(const Point&p:P){
			while(k>=2&&ccw(ret[k-2],ret[k-1],p)!=COUNTER_CLOCKWISE)k--;
			ret[k++]=p;
		}
		t=k;
		for(int i=P.size()-2;i>=0;i--){
			while(k>=t+1&&ccw(ret[k-2],ret[k-1],P[i])!=COUNTER_CLOCKWISE)k--;
			ret[k++]=P[i];
		}
	}
	ret.resize(k-1);
	int mi=0;
	for(int i=1;i<k-1;i++)
		if(eq(ret[mi].y,ret[i].y)?ret[mi].x>ret[i].x:ret[mi].y>ret[i].y)mi=i;
	rotate(ret.begin(),ret.begin()+mi,ret.end());
	return ret;
}
int contain(const Polygon&P,const Point&p){
	bool in=false;
	for(int i=0;i<P.size();i++){
		Segment s(P[i],P[(i+1)%P.size()]);
		if(intersect(s,p))return ON;
		else{
			Point a=s.p1-p,b=s.p2-p;
			if(a.y>b.y)swap(a,b);
			if(a.y<EPS&&EPS<b.y&&cross(a,b)>EPS)in=!in;
		}
	}
	return in?IN:OUT;
}
int contain(const Circle&c,const Point&p){
	double d=distance(c.o,p);
	return eq(d,c.r)?ON:d<c.r?IN:OUT;
}
int contain(const Circle&c,const Segment&s){
	double d1=distance(c.o,s.p1),d2=distance(c.o,s.p2);
	return d1<c.r+EPS&&d2<c.r+EPS?eq(d1,c.r)||eq(d2,c.r)?ON:IN:OUT;
}
Polygon convex_cut(const Polygon&P,const Line&s){
	Polygon ret;
	for(int i=0;i<P.size();i++){
		Segment t(P[i],P[(i+1)%P.size()]);
		if(ccw(s,t.p1)!=CLOCKWISE)ret.push_back(t.p1);
		if(!parallel(s,t)&&!intersect(s,t.p1)
			&&!intersect(s,t.p2)&&intersect(s,t))ret.push_back(crosspoint(s,t));
	}
	return ret;
}
double diameter(Polygon P){
	if(!is_convex(P))P=convex_full(P);
	int mi=0,Mi=0;
	for(int i=1;i<P.size();i++){
		if(P[i].x<P[mi].x)mi=i;
		if(P[i].x>P[Mi].x)Mi=i;
	}
	double ret=0;
	int sm=mi,sM=Mi;
	while(mi!=sM||Mi!=sm){
		ret=max(ret,norm(P[mi]-P[Mi]));
		if(cross(P[(mi+1)%P.size()]-P[mi],P[(Mi+1)%P.size()]-P[Mi])<0)mi=(mi+1)%P.size();
		else Mi=(Mi+1)%P.size();
	}
	return sqrt(ret);
}
double area(const Polygon&P){
	double ret=0;
	for(int i=0;i<P.size();i++)ret+=cross(P[i],P[(i+1)%P.size()]);
	return ret/2;
}
double area(const Polygon&P,const Line&s){return area(convex_cut(P,s));}
double area(const Polygon&P,const Circle&c){
	double ret=0;
	for(int i=0;i<P.size();i++)
	{
		Segment s(P[i],P[(i+1)%P.size()]);
		if(contain(c,s))ret+=cross(s.p1-c.o,s.p2-c.o);
		else if(!intersect(c,s)){
			double a=arg(s.p2-c.o)-arg(s.p1-c.o);
			if(a>M_PI)a-=2*M_PI;
			if(a<-M_PI)a+=2*M_PI;
			ret+=c.r*c.r*a;
		}
		else
		{
			pair<Point,Point>p=crosspoint(c,s);
			Point tmp[4]={s.p1,p.first,p.second,s.p2};
			if(intersect(c,Segment(s.p1,p.first))==2)swap(tmp[1],tmp[2]);
			for(int j=0;j<3;j++)
			{
				Segment t(tmp[j],tmp[j+1]);
				if(contain(c,t))ret+=cross(t.p1-c.o,t.p2-c.o);
				else{
					double a=arg(t.p2-c.o)-arg(t.p1-c.o);
					if(a>M_PI)a-=2*M_PI;
					if(a<-M_PI)a+=2*M_PI;
					ret+=c.r*c.r*a;
				}
			}
		}
	}
	return ret/2;
}
#include<cstdio>
main()
{
	int N;cin>>N;
	Polygon P(N);
	for(Point&p:P)
	{
		scanf("%lf%lf",&p.x,&p.y);
	}
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		Polygon Q;
		for(int j=0;j<N;j++)
		{
			if(i!=j)Q.push_back(P[j]-P[i]);
		}
		sort(Q.begin(),Q.end(),argless);
		vector<int>inv(N-1);
		int id=0;
		for(int j=0;j<N-1;j++)
		{
			while(id<N-1&&ccw(Q[j],Q[id])==COUNTER_CLOCKWISE)id++;
			inv[j]=id;
		}
		vector<int>cumsum(N,0);
		for(int j=0;j<N-1;j++)cumsum[j+1]=cumsum[j]+inv[j];
		for(int j=0;j<N-1;j++)
		{
			ans+=cumsum[inv[j]]-cumsum[j]-inv[j]*(inv[j]-j);
		}
	}
	cout<<ans*(N-4)/2<<endl;
}