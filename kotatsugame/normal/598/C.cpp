#line 1 "a.cpp"
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#line 1 "/home/kotatsugame/library/math/integer_point.cpp"
#include<iostream>
#line 4 "/home/kotatsugame/library/math/integer_point.cpp"
using Int=long long;
int sign(Int a){return a>0?1:a<0?-1:0;}
Int sqr(Int a){return a*a;}
struct Rational{
	Int a,b;
	Rational(Int a_=0):a(a_),b(1){}
	Rational(Int a_,Int b_){
		Int g=a_,h=b_;
		while(h){
			Int t=g%h;
			g=h;
			h=t;
		}
		a=a_/g;
		b=b_/g;
		if(b<0)a=-a,b=-b;
	}
	bool operator<(const Rational&r)const{return a*r.b<r.a*b;}
	bool operator==(const Rational&r)const{return a==r.a&&b==r.b;}
};
struct Point{
	Int x,y;
	Point(Int x_=0,Int y_=0):x(x_),y(y_){}
	Point operator-()const{return Point(-x,-y);}
	Point operator+(const Point&p)const{return Point(x+p.x,y+p.y);}
	Point operator-(const Point&p)const{return Point(x-p.x,y-p.y);}
	Point operator*(const Int k)const{return Point(x*k,y*k);}
	bool operator<(const Point&p)const{return x==p.x?y<p.y:x<p.x;}
	bool operator==(const Point&p)const{return x==p.x&&y==p.y;}
};
istream&operator>>(istream&is,Point&p){return is>>p.x>>p.y;}
ostream&operator<<(ostream&os,const Point&p){return os<<p.x<<' '<<p.y;}
struct Line{
	Point p1,p2;
	Line(Point p1_=Point(),Point p2_=Point()):p1(p1_),p2(p2_){}
};
struct Segment:Line{
	Segment(Point p1_=Point(),Point p2_=Point()):Line(p1_,p2_){}
};
struct Circle{
	Point o;
	Int r;
	Circle(Point o_=Point(),Int r_=0):o(o_),r(r_){}
};
using Polygon=vector<Point>;
//function list begin
Point vec(const Line&);
Int norm(const Point&);
Int norm(const Line&);
int argtype(const Point&);//(-pi,0]->-1,(0,pi]->1,(0,0)->0
bool argless(const Point&,const Point&);//sorting points with arg
Int dot(const Point&,const Point&);
Int cross(const Point&,const Point&);
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
int intersect(const Circle&,const Line&);//overflow, count contacts
int intersect(const Circle&,const Segment&);//overflow, count contacts
bool intersect(const Circle&,const Circle&);
int count_tangent(const Circle&,const Circle&);//count common tangents
Int distance2(const Point&,const Point&);
Rational distance2(const Line&,const Point&);
Rational distance2(const Line&,const Line&);
Rational distance2(const Segment&,const Point&);
Rational distance2(const Segment&,const Segment&);
Rational distance2(const Line&,const Segment&);
Rational distance2(const Segment&,const Line&);
bool is_convex(const Polygon&);
Polygon convex_hull(Polygon,bool=false);
enum{OUT,ON,IN};
int contain(const Polygon&,const Point&);
int contain(const Circle&,const Point&);
int contain(const Circle&,const Segment&);
int convex_contain(const Polygon&,const Point&);//O(log |P|)
Int diameter2(Polygon P);
//function list end
Point vec(const Line&s){return s.p2-s.p1;}
Int norm(const Point&p){return p.x*p.x+p.y*p.y;}
Int norm(const Line&s){return norm(vec(s));}
int argtype(const Point&a){return a.y<0?-1:a.y>0?1:a.x<0?1:a.x>0?-1:0;}
bool argless(const Point&a,const Point&b)
{
	int at=argtype(a),bt=argtype(b);
	return at!=bt?at<bt:ccw(a,b)>0;
}
Int dot(const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
Int cross(const Point&a,const Point&b){return a.x*b.y-a.y*b.x;}
int ccw(const Point&a,const Point&b)
{
	return cross(a,b)>0?COUNTER_CLOCKWISE
		:cross(a,b)<0?CLOCKWISE
		:dot(a,b)<0?ONLINE_BACK
		:norm(a)<norm(b)?ONLINE_FRONT
		:ON_SEGMENT;
}
int ccw(const Point&a,const Point&b,const Point&c){return ccw(b-a,c-a);}
int ccw(const Line&s,const Point&p){return ccw(s.p1,s.p2,p);}
bool orthogonal(const Point&a,const Point&b){return dot(a,b)==0;}
bool orthogonal(const Line&s,const Line&t){return orthogonal(vec(s),vec(t));}
bool parallel(const Point&a,const Point&b){return cross(a,b)==0;}
bool parallel(const Line&s,const Line&t){return parallel(vec(s),vec(t));}
bool intersect(const Line&s,const Point&p){return cross(vec(s),p-s.p1)==0;}
bool intersect(const Line&s,const Line&t){return !parallel(s,t)||intersect(s,t.p1);}
bool intersect(const Segment&s,const Point&p){return ccw(s,p)==ON_SEGMENT;}
bool intersect(const Segment&s,const Segment&t){
	return ccw(s,t.p1)*ccw(s,t.p2)<=0&&ccw(t,s.p1)*ccw(t,s.p2)<=0;
}
bool intersect(const Line&s,const Segment&t){
	return sign(cross(vec(s),t.p1-s.p1))*sign(cross(vec(s),t.p2-s.p1))<=0;
}
bool intersect(const Segment&s,const Line&t){return intersect(t,s);}
bool intersect(const Circle&c,const Point&p){return distance2(c.o,p)==sqr(c.r);}
int intersect(const Circle&c,const Line&s){
	Rational r=distance2(s,c.o);
	return r.a==r.b*sqr(c.r)?1:r.a<r.b*sqr(c.r)?2:0;
}
int intersect(const Circle&c,const Segment&s){
	Int d1=distance2(c.o,s.p1),d2=distance2(c.o,s.p2);
	int t=intersect(c,Line(s));
	return t==0?0
		:d1<sqr(c.r)&&d2<sqr(c.r)?0
		:(d1<sqr(c.r)&&d2>=sqr(c.r))||(d1>=sqr(c.r)&&d2<sqr(c.r))?1
		:dot(s.p2-s.p1,c.o-s.p1)>=0&&dot(s.p1-s.p2,c.o-s.p2)>=0?t==1?1:2
		:0;
}
bool intersect(const Circle&a,const Circle&b){
	int c=count_tangent(a,b);
	return 1<=c&&c<=3;
}
int count_tangent(const Circle&a,const Circle&b){
	Int d=distance2(a.o,b.o);
	return d==sqr(a.r+b.r)?3:d>sqr(a.r+b.r)?4:d==sqr(a.r-b.r)?1:d>sqr(a.r-b.r)?2:0;
}
Int distance2(const Point&a,const Point&b){return norm(a-b);}
Rational distance2(const Line&s,const Point&p){
	Int A=(s.p2.y-s.p1.y)*p.x+(s.p1.x-s.p2.x)*p.y-s.p1.x*s.p2.y+s.p1.y*s.p2.x;
	Int B=norm(s);
	return Rational(A,B);
}
Rational distance2(const Line&s,const Line&t){
	return intersect(s,t)?Rational(0):distance2(s,t.p1);
}
Rational distance2(const Segment&s,const Point&p){
	return dot(vec(s),p-s.p1)<0?Rational(distance2(p,s.p1))
		:dot(-vec(s),p-s.p2)<0?Rational(distance2(p,s.p2))
		:distance2(Line(s),p);
}
Rational distance2(const Segment&s,const Segment&t){
	return intersect(s,t)?Rational(0):min({
		distance2(s,t.p1),distance2(s,t.p2),
		distance2(t,s.p1),distance2(t,s.p2)
	});
}
Rational distance2(const Line&s,const Segment&t){
	return intersect(s,t)?Rational(0):min(distance2(s,t.p1),distance2(s,t.p2));
}
Rational distance2(const Segment&s,const Line&t){return distance2(t,s);}
bool is_convex(const Polygon&P){
	for(int i=0;i<P.size();i++)
		if(ccw(P[i],P[(i+1)%P.size()],P[(i+2)%P.size()])==CLOCKWISE)return false;
	return true;
}
Polygon convex_hull(Polygon P,bool ONSEG){
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
		if(ret[mi].y==ret[i].y?ret[mi].x>ret[i].x:ret[mi].y>ret[i].y)mi=i;
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
			if(a.y<=0&&0<b.y&&cross(a,b)>0)in=!in;
		}
	}
	return in?IN:OUT;
}
int contain(const Circle&c,const Point&p){
	Int d=distance2(c.o,p);
	return d==sqr(c.r)?ON:d<sqr(c.r)?IN:OUT;
}
int contain(const Circle&c,const Segment&s){
	Int d1=distance2(c.o,s.p1),d2=distance2(c.o,s.p2);
	return d1<=sqr(c.r)&&d2<=sqr(c.r)?d1==sqr(c.r)||d2==sqr(c.r)?ON:IN:OUT;
}
int convex_contain(const Polygon&P,const Point&p)
{
	if(P[0]==p)return ON;
	int l=0,r=P.size();
	while(r-l>1)
	{
		int mid=(l+r)/2;
		int t=ccw(P[0],P[mid],p);
		if(t==CLOCKWISE)r=mid;
		else l=mid;
	}
	if(r==1)return OUT;
	if(l+1==P.size())
	{
		if(intersect(Segment(P[0],P[P.size()-1]),p))return ON;
		else return OUT;
	}
	if(l==1&&intersect(Segment(P[0],P[1]),p))return ON;
	Polygon tmp={P[0],P[l],P[l+1]};
	int ret=contain(tmp,p);
	if(ret==ON)
	{
		if(intersect(Segment(P[l],P[l+1]),p))return ON;
		else return IN;
	}
	return ret;
}
Int diameter2(Polygon P){
	if(!is_convex(P))P=convex_hull(P);
	int mi=0,Mi=0;
	for(int i=1;i<P.size();i++){
		if(P[i].x<P[mi].x)mi=i;
		if(P[i].x>P[Mi].x)Mi=i;
	}
	Int ret=0;
	int sm=mi,sM=Mi;
	while(mi!=sM||Mi!=sm){
		ret=max(ret,norm(P[mi]-P[Mi]));
		if(cross(P[(mi+1)%P.size()]-P[mi],P[(Mi+1)%P.size()]-P[Mi])<0)mi=(mi+1)%P.size();
		else Mi=(Mi+1)%P.size();
	}
	return ret;
}
#line 7 "a.cpp"
Point f(Point base,Point X)
{
	Int a=base.x,b=base.y;
	Int x=X.x,y=X.y;
	return Point(a*x+b*y,abs(-b*x+a*y));
}
main()
{
	int N;
	scanf("%d",&N);
	vector<pair<Point,int> >X(N);
	for(int i=0;i<N;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		X[i]=make_pair(Point(x,y),i+1);
	}
	sort(X.begin(),X.end(),[](pair<Point,int>a,pair<Point,int>b)
	{
		return argless(a.first,b.first);
	});
	int a,b;
	Point A;
	a=X[0].second,b=X[1].second;
	A=f(X[0].first,X[1].first);
	for(int i=1;i<N;i++)
	{
		Point x=X[i].first,y=X[(i+1)%N].first;
		Point B=f(x,y);
		if(cross(A,B)<0)
		{
			A=B;
			a=X[i].second;b=X[(i+1)%N].second;
		}
	}
	printf("%d %d\n",a,b);
}