//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/double>
//#include <self/geometry>
//using namespace std;
//int n,m;
//using PT=Point<Double>;
//PT edges[1005];
//
//struct Segment
//{
//	PT st;
//	PT ed;
//	Segment(){}
//	Segment(PT a,PT b):st(a),ed(b){}
//	inline Double length()
//	{
//		double dx=(ed.x-st.x).x;
//		double dy=(ed.y-st.y).x;
//		return sqrt(dx*dx+dy*dy);
//	}
//}theLine;
//istream & operator >> (istream &cin,Segment &t)
//{
//	cin>>t.st>>t.ed;
//	return cin;
//}
//ostream & operator << (ostream &cout,Segment &t)
//{
//	cout<<mp(t.st,t.ed);
//	return cout;
//}
//PT noInt(2984,123);
//// PT noInt(0,0);
//
//struct Line
//{
//	Double a,b,c;
//};
//ostream & operator << (ostream &cout,Line t)
//{
//	cout<<'('<<t.a<<','<<t.b<<','<<t.c<<')';
//	return cout;
//}
//
//inline Double det(Double a,Double b,Double c,Double d)
//{
//	return a*d-b*c;
//}
//
//bool equivalent(Line a,Line b)
//{
//	// bool eq=(det(a.a,a.b,b.a,b.b)==0 && det(a.b,a.c,b.b,b.c)==0 && det(a.c,a.a,b.c,b.a)==0);
//	// debug(a,b,eq);
//	return (det(a.a,a.b,b.a,b.b)==0 && det(a.b,a.c,b.b,b.c)==0 && det(a.c,a.a,b.c,b.a)==0);
//}
//
//bool intersect(Line a,Line b,PT &c) // a should not be equivalent with b
//{
//	Double d=det(a.a,a.b,b.a,b.b);
//	if(d==0) return false;
//	c.x=-det(a.c,a.b,b.c,b.b)/d;
//	c.y=-det(a.a,a.c,b.a,b.c)/d;
//	return true;
//}
//
//Line toLine(Segment t) //if t is a single point, black hole will be returned
//{
//	// debug(t.length());
//	Line res;
//	res.a=(t.ed.y-t.st.y);
//	res.b=-(t.ed.x-t.st.x);
//	// debug(res.a,res.b);
//	res.c=-res.a*t.st.x-res.b*t.st.y;
//	return res;
//}
//
//bool intersect(Segment a,Line b,PT &c) //a,b?????
//{
//	PT ta=theLine.st,tb=theLine.ed,tc=a.st,td=a.ed;
//	// if(ta.collinear(tb,tc) || ta.collinear(tb,td))
//	// {
//	// 	Double l1=min(ta.x,tb.x),r1=max(ta.x,tb.x),l2=min(tc.x,td.x),r2=max(tc.x,td.x);
//	// 	Double r=min(r1,r2),l=max(l1,l2);
//	// 	Double dx=max(Double(0),r-l);
//	// 	l1=min(ta.y,tb.y),r1=max(ta.y,tb.y),l2=min(tc.y,td.y),r2=max(tc.y,td.y);
//	// 	r=min(r1,r2),l=max(l1,l2);
//	// 	Double dy=max(Double(0),r-l);
//	// 	return sqrt((dx*dx+dy*dy).x);
//	// }
//	// else if(ta.collinear(tb,tc) || ta.collinear(tb,td)) return 0;
//	if((ta.clockwise(tb,tc)^ta.clockwise(tb,td))==0) return 0;
//	bool f=intersect(toLine(a),b,c);
//	assert(f);
//	return true;
//}
//
//inline Double dis(PT a,PT b)
//{
//	return sqrt(((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)).x);
//}
//
//Double solve(PT a,PT b,PT c,Line t,int bi) // ??a,c?????
//{
//	Segment x(a,b),y(b,c),z(c,a);
//	assert(!equivalent(toLine(x),t));
//	// if(equivalent(toLine(x),t)) return x.length();
//	cout<<fixed;
//	cout.precision(10);
//	// debug(y,toLine(y),t);
//	// debug(y,bi,y.length(),equivalent(toLine(y),t));
//	if(equivalent(toLine(y),t)) return (bi?y.length():0);
//	assert(!equivalent(toLine(z),t));
//	// debug(x,y,z);
//	// if(equivalent(toLine(z),t)) return 0;
//	PT ix,iy,iz;
//	bool fx,fy,fz;
//	tie(fx,fy,fz)=mt(intersect(x,t,ix),intersect(y,t,iy),intersect(z,t,iz));
//	PT l(numeric_limits<double>::max(),numeric_limits<double>::max()),r(numeric_limits<double>::lowest(),numeric_limits<double>::lowest());
//	if(fx) chmin(l,ix),chmax(r,ix);
//	if(fy) chmin(l,iy),chmax(r,iy);
//	if(fz) chmin(l,iz),chmax(r,iz);
//	// debug(a,b,c,z,t,fx,fy,fz,ix,iy,iz,l,r);
//	if(!fx && !fy && !fz) return 0;
//	// debug(a,b,c,t,x,y,z,fx,fy,fz,ix,iy,iz);
//	return dis(l,r);
//	// if(fx && fy) return dis(ix,iy);
//	// if(fx && fz) return dis(ix,iz);
//	// if(fy && fz) return dis(iy,iz);
//	// return 0;
//}
//
//ConvexHull <Double> hull;
//Double query(Line t)
//{
//	// debug(t.a,t.b,t.c);
//	Double res=0;
//	for(int i=0;i<n;i++)
//	{
//		// debug(i,res);
//		// cout<<edges[i]<<' '<<edges[(i+1)%n]<<endl;
//		// debug(noInt,edges[i],edges[(i+1)%n],t);
//		// Double len=solve(noInt,edges[i],edges[(i+1)%n],t);
//		// cout<<len<<endl;
//		// PT a=edges[i]-noInt;
//		// PT b=edges[(i+1)%n]-noInt;
//		// cout<<a.crossProduct(b)<<endl;
//		// debug(a,b,hull.areaOfTriangle(noInt,edges[i],edges[(i+1)%n]));
//		int positive=(hull.directedAreaOfTriangle(noInt,edges[i],edges[(i+1)%n])>0);
//		Double len=solve(noInt,edges[i],edges[(i+1)%n],t,positive);
//		// debug(edges[i],edges[(i+1)%n],i,positive,len);
//		// debug(i,len);
//		if(positive) res+=len;else res-=len;
//		// if(hull.directedAreaOfTriangle(noInt,edges[i],edges[(i+1)%n])>0) res+=len;else res-=len;
//	}
//	return mabs(res);
//}
//
//int main()
//{
//	// cout<<fixed;
//	// cout.precision(50);
//	// numeric_limits<double>::min();
//	// cout<<(long double)(1.000000000000000000000123e-23L)<<endl;
//	// cout<<(long double)(1.00000000000000123e-23L)<<endl;
////	ConvexHull <int> t;	
////	cout<<t.areaOfTriangle({0,1},{1,2},{3,2})<<endl;
//	freopen("input.txt","r",stdin);__DBL_MIN__;
//	cin>>n>>m;
//	for(int i=0;i<n;i++)
//	{
//		cin>>edges[i];
//		edges[i].x.x*=100;
//		edges[i].y.x*=100;
//	}
//	Double area=0;
//	for(int i=0;i<n;i++)
//	{
//		area+=hull.directedAreaOfTriangle({0,0},edges[i],edges[(i+1)%n]);
//	}
//	// cout<<area<<endl;
//	if(area<0)
//	{
//		reverse(edges+1,edges+n);
//	}
//	// cout<<solve(noInt,{1,0},{1,1},Line({1,0,0}))<<endl;
//	// return 0;
//	for(int i=0;i<m;i++)
//	{
//		cin>>theLine;
//		theLine.st.x*=100.0;
//		theLine.st.y*=100.0;
//		theLine.ed.x*=100.0;
//		theLine.ed.y*=100.0;
//		// PT tmp;
//		// debug(theLine);
//		// cout<<intersect({{0,0},{0,-100}},toLine(theLine),tmp)<<endl;
//		// debug(t,toLine(t));
//		cout<<fixed;
//		cout.precision(10);
//		cout<<query(toLine(theLine)).x/100<<endl;
//	}
//	return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
#include <numeric>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#include <time.h>
#define Endl endl
#define mp make_pair
#define mt make_tuple
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
#ifdef __TAKE_MOD
int mod;
#else
#ifdef __TAKE_CONST_MOD
const int mod=__TAKE_CONST_MOD;
#else
const int mod=1000000007;
#endif
#endif
const int gmod=3;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
#endif
using namespace std;
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream &operator<<(ostream &cout, vector<T> vec)
{
	cout << "{";
	for (int i = 0; i < (int)vec.size(); i++)
	{
		cout << vec[i];
		if (i != (int)vec.size() - 1)
			cout << ',';
	}
	cout << "}";
	return cout;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p)
{
	cout << "(" << p.first << ',' << p.second << ")";
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T>
ostream &operator<<(ostream &cout, queue<T> q)
{
	vector<T> t;
	while (q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout << t;
	return cout;
}

template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m)
{
	for (auto &x : m)
	{
		cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
	}
	return cout;
}

template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x,const pair<T1, T2> y)
{
	x.first += y.first;
	x.second += y.second;
}
template <typename T1,typename T2>
pair<T1,T2> operator + (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return mp(x.first-y.first,x.second-y.second);
}

template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x)
{
	return make_pair(-x.first, -x.second);
}

template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec)
{
	vector<vector<T>> v;
	int n = vec.size(), m = vec[0].size();
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		v[i].resize(n);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[i][j] = vec[j][i];
		}
	}
	return v;
}
#endif
#include <sstream>
void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void print0x(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=(int)vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(size_t i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#endif
#ifndef _SELF_DOUBLE
#define _SELF_DOUBLE
struct Double
{
	public:
	long double x;
	Double(){}
	template <typename T> Double(const T &_x):x(_x){}
	void operator = (const Double &d)
	{
		x=d.x;
	}
	template <typename T>
	void operator = (const T &d)
	{
		x=d;
	}
	Double operator - ()const&
	{
		return -x;
	}
	bool operator == (const Double &d)const&
	{
		return (abs(x-d.x)<=eps);
	}
	bool operator != (const Double &d)const&
	{
		return !(*this==d);
	}
	bool operator < (const Double &d)const&
	{
		return x+eps<d.x;
	}
	bool operator > (const Double &d)const&
	{
		return x-eps>d.x;
	}
	template <typename T>
	bool operator > (const T &d)const&
	{
		return x>d;
	}
	bool operator <= (const Double d)const
	{
		return !(*this>d);
	}
	bool operator >= (const Double d)const
	{
		return !(*this<d);
	}
	Double operator - (const Double d)const
	{
		return x-d.x;
	}
	Double operator + (const Double d)const
	{
		return x+d.x;
	}
	Double operator * (const Double d)const
	{
		return x*d.x;
	}
	Double operator / (const Double d)const
	{
		return (Double)(x/d.x);
	}
	void operator ++ (int)
	{
		x++;
	}
	Double operator / (Double d)
	{
		return (Double)(x/d.x);
	}
	template <typename T>
	Double operator / (T d)
	{
		return (Double)(x/(double)d);
	}
//	template <typename T>
//	operator T (void) const
//	{
//		return floor(x+0.5);
//	}
	// operator int (void)const
	// {
	// 	return floor(x+0.5);
	// }
	void operator += (const Double &d)
	{
		x+=d.x;
	}
	void operator -= (const Double &d)
	{
		x-=d.x;
	}
	void operator *= (const Double &d)
	{
		x*=d.x;
	}
	void operator /= (Double d)
	{
		x/=d.x;
	}
	template <typename T>
	void operator += (T d)
	{
		x+=d;
	}
	template <typename T>
	void operator -= (T d)
	{
		x-=d;
	}
	template <typename T>
	void operator *= (T d)
	{
		x*=d;
	}
};

ostream & operator << (ostream &cout,Double x)
{
	cout<<x.x;
	return cout;
}

istream & operator >> (istream &cin,Double &x)
{
	cin>>x.x;
	return cin;
}

#endif
#ifndef _SELF_GEOMETRY
#define _SELF_GEOMETRY

template <typename T>
struct Point
{
	T x;
	T y;
	Point(){}
	Point(T _x,T _y){x=_x;y=_y;}
	inline T sqrLen()const&
	{
		return x*x+y*y;
	}
	
	inline bool operator == (const Point <T> &p)const&
	{
		return (x==p.x && y==p.y);
	}
	inline bool operator != (const Point <T> &p)const
	{
		return !((*this)==p);
	}
	Point <T>& operator += (const Point <T> &p)
	{
		x+=p.x;
		y+=p.y;
		return (*this);
	}
	Point <T>& operator -= (const Point <T> &p)
	{
		x-=p.x;
		y-=p.y;
		return (*this);
	}
	Point <T>& operator *= (T k)
	{
		x*=k;
		y*=k;
		return (*this);
	}
	Point <T> operator + (const Point <T> &p)const&
	{
		return Point<T>(*this)+=p;
	}
	Point<T> operator - (const Point <T> &p)const&
	{
		return Point<T>(*this)-=p;
	}
	Point<T> operator * (int k)const&
	{
		return Point<T>(*this)*=k;
	}

	T dotProduct(const Point <T> &p)const&
	{
		return x*p.x+y*p.y;
	}
	T crossProduct(const Point <T> &p)const&
	{
		return x*p.y-y*p.x;
	}

	inline bool counterClockwise(const Point <T> &a,const Point<T> &b)const&
	{
		return (a-(*this)).crossProduct(b-(*this))>0;
	}
	inline bool clockwise(const Point <T> &a,const Point <T> &b)const&
	{
		return (a-(*this)).crossProduct(b-(*this))<0;
	}
	inline bool collinear(const Point <T> &a,const Point <T> &b)const&
	{
		return ((a-(*this)).crossProduct(b-(*this))==0);
	}
	bool operator < (const Point <T> &a)const&
	{
		if(x!=a.x) return x<a.x;
		return y<a.y;
	}
	bool operator > (const Point <T> &a)const&
	{
		return a<(*this);
	}
};
template <typename T>
istream & operator >> (istream &cin,Point <T> &p)
{
	cin>>p.x>>p.y;
	return cin;
}
template <typename T>
ostream & operator << (ostream &cout,const Point <T> &p)
{
	cout<<mp(p.x,p.y);
	return cout;
}

template <typename T>
struct ConvexHull
{
	using PT=Point <T>;
	vector <PT> points;
	vector <PT> cuts;
	static inline T mabs(const T &x)
	{
		return (x<0?-x:x);
	}
	static inline T areaOfTriangle(const PT &a,const PT &b,const PT &c)
	{
		return mabs((b-a).crossProduct(c-a));
	}
	static inline T directedAreaOfTriangle(const PT &a,const PT &b,const PT &c)
	{
		return (b-a).crossProduct(c-a);
	}
	inline void init(vector <PT> v)
	{
		sort(all(v),[](const PT &a,const PT &b)
		{
			if(a.x!=b.x) return a.x<b.x;
			return a.y<b.y;
		});
		const PT &a=v.front();
		const PT &b=v.back();
		vector <PT> u,d;
		u.push_back(a);
		d.push_back(a);
		for(size_t i=1;i<v.size();i++)
		{
			auto &p=v[i];
			if(p==v.back() || a.counterClockwise(b,p))
			{
				while(u.size()>=2 && !u[u.size()-2].clockwise(u.back(),p)) u.pop_back();
				u.push_back(p);
			}
			if(p==v.back() || a.clockwise(b,p))
			{
				while(d.size()>=2 && !d[d.size()-2].counterClockwise(d.back(),p)) d.pop_back();
				d.push_back(p);
			}
		}
		for(size_t i=0;i<d.size();i++)
		{
			points.push_back(d[i]);
		}
		for(size_t i=u.size()-2;i>=1;i--)
		{
			points.push_back(u[i]);
		}
		for(size_t i=1;i<points.size();i++)
		{
			cuts.push_back(points[i]-points[0]);
		}
	}
	inline size_t size()const&
	{
		return points.size();
	}
	inline bool occupy(const PT &_x) //[]
	{
		PT x=_x-points[0];
		int pos=lower_bound(all(cuts),x,[](const PT &a,const PT &b)
		{
			return a.crossProduct(b)>0;
		})-cuts.begin();
		if(pos==0 && x.crossProduct(cuts[0])==0) pos++;
		if(pos==int(cuts.size()) || pos==0) return false;
		PT A=Point <T> (0,0),B=cuts[pos-1],C=cuts[pos],D=x;
		return (areaOfTriangle(A,B,C)==areaOfTriangle(A,B,D)+areaOfTriangle(B,C,D)+areaOfTriangle(C,A,D));
	}
	PT operator [] (size_t pos)const&
	{
		return points[pos];
	}
	PT& operator [] (size_t pos)&
	{
		return points[pos];
	}
};

template <typename T>
inline ConvexHull <T> minkowskiSum(const ConvexHull <T> &a,const ConvexHull <T> &b)
{
	vector <Point <T> > va,vb;
	ConvexHull <T> hc;
	auto &vc=hc.points;
	for(size_t i=0;i<a.size()-1;i++)
	{
		va.push_back(a[i+1]-a[i]);
	}
	va.push_back(a[0]-a.points.back());
	for(size_t i=0;i<b.size()-1;i++)
	{
		vb.push_back(b[i+1]-b[i]);
	}
	vb.push_back(b[0]-b.points.back());
	vc.push_back(a[0]+b[0]);
	vc.resize(va.size()+vb.size()+1);
	merge(all(va),all(vb),vc.begin()+1,[](const Point <T> &a,const Point <T> &b)
	{
		return a.crossProduct(b)>0;
	});
	for(size_t i=1;i<vc.size();i++)
	{
		vc[i]+=vc[i-1];
	}
	vc.pop_back();
	for(size_t i=1;i<vc.size();i++)
	{
		hc.cuts.push_back(vc[i]-vc[0]);
	}
	return hc;
}

template <typename T>
struct LowerHull
{
	using PT=Point <T>;
	bool polarCompare(PT o,PT a,PT b)//oab? 
	{
		return (a-o).clockwise(b-o);
	}
	vector <PT> points;
	inline int size()
	{
		return (int)points.size();
	}
	inline int insert(PT p)
	{
		while(size()>1 && !polarCompare(points[size()-2],points[size()-1],p))
		{
			points.pop_back();
		}
		points.push_back(p);
		return size();
	}
};
template <typename T>
ostream & operator << (ostream&cout,LowerHull <T> x)
{
	cout<<x.points;
	return cout;
}

template <typename T>
struct PersistentLowerHull:public LowerHull <T>
{
	using PT = Point <T>;
	struct Event
	{
		vector <PT> points;
	};
	vector <Event> events;
	inline size_t size()
	{
		return LowerHull <T> ::size();
	}
	inline int persistentInsert(PT p)
	{
		Event event;
		while(size()>1 && !polarCompare(p,LowerHull <T>::points[size()-2],LowerHull <T>::points[size()-1]))
		{
			event.points.push_back(LowerHull <T>::points.back());
			LowerHull <T>::points.pop_back();
		}
		LowerHull <T>::points.push_back(p);
		events.push_back(event);
		return size();
	}
	inline void rollback()
	{
		LowerHull <T>::points.pop_back();
		while(events.back().points.size())
		{
			LowerHull <T>::points.push_back(events.back().points.back());
			events.back().points.pop_back();
		}
		events.pop_back();
	}
};

namespace LICHAOTREE
{
	template <typename T>
	struct DefaultFunction
	{
		T k;
		T b;
		inline T operator () (T x)const&
		{
			return k*x+b;
		}
		inline void inf()
		{
			k=0;
			b=numeric_limits <T> :: max()/2;
			if(b==0) throw logic_error("no limits for non-fundamental type");
		}
		DefaultFunction(){}
		DefaultFunction(T _k,T _b):k(_k),b(_b){}
	};
	template <typename T,typename _Compare=std::less <T>,typename Function=DefaultFunction <T> >
	struct LiChaoTree
	{
		vector <Function> data;
		vector <T> lsh;
		int nn;
		_Compare _comp;
		inline void _init(int n)
		{
			nn=1;
			while(nn<n) nn<<=1;
			data.resize(nn*2+5);
		}

		inline void init(int n)
		{
			_init(n);
			for(int i=0;i<nn;i++)
			{
				lsh.push_back(i);
			}
		}

		inline void init(const vector <T> &_lsh)
		{
			int n=_lsh.size();
			_init(n);
			lsh=_lsh;
			sort(all(lsh));
			for(int i=n;i<nn;i++)
			{
				lsh.push_back(lsh.back());
			}
		}

		inline void clear()
		{
			for(int i=0;i<nn*2;i++)
			{
				data[i].inf();
			}
		}

		void insert(int x,int l,int r,Function f)
		{
			bool mid=_comp(f(lsh[(l+r)>>1]),data[x](lsh[(l+r)>>1]));
			bool lef=_comp(f(lsh[l]),data[x](lsh[l]));
			bool rgt=_comp(f(lsh[r]),data[x](lsh[r]));
			if(mid)
			{
				swap(data[x],f);
			}
			if(lef==rgt) return;
			if(r-l==1) return;
			if(lef!=mid)
			{
				insert(x*2,l,(l+r)>>1,f);
			}
			else
			{
				insert(x*2+1,(l+r)>>1,r,f);
			}
		}
		inline void insert(Function f)
		{
			insert(1,0,nn,f);
		}
		inline void insert(T k,T b)
		{
			insert(Function(k,b));
		}

		inline T query(T value)
		{
			int pos=lower_bound(all(lsh),value)-lsh.begin()+nn;
			int now=1;
			T res=data[now](value);
			while(pos>=1)
			{
				T v=data[pos](value);
				if(_comp(v,res)) res=v;
				pos>>=1;
			}
			return res;
		}
	};
}
using LICHAOTREE::LiChaoTree;

#endif
using namespace std;
int n,m;
using PT=Point<Double>;
PT edges[1005];

struct Segment
{
	PT st;
	PT ed;
	Segment(){}
	Segment(PT a,PT b):st(a),ed(b){}
	inline Double length()
	{
		double dx=(ed.x-st.x).x;
		double dy=(ed.y-st.y).x;
		return sqrt(dx*dx+dy*dy);
	}
}theLine;
istream & operator >> (istream &cin,Segment &t)
{
	cin>>t.st>>t.ed;
	return cin;
}
ostream & operator << (ostream &cout,Segment &t)
{
	cout<<mp(t.st,t.ed);
	return cout;
}
PT noInt(2984,123);
// PT noInt(0,0);

struct Line
{
	Double a,b,c;
};
ostream & operator << (ostream &cout,Line t)
{
	cout<<'('<<t.a<<','<<t.b<<','<<t.c<<')';
	return cout;
}

inline Double det(Double a,Double b,Double c,Double d)
{
	return a*d-b*c;
}

bool equivalent(Line a,Line b)
{
	// bool eq=(det(a.a,a.b,b.a,b.b)==0 && det(a.b,a.c,b.b,b.c)==0 && det(a.c,a.a,b.c,b.a)==0);
	// debug(a,b,eq);
	return (det(a.a,a.b,b.a,b.b)==0 && det(a.b,a.c,b.b,b.c)==0 && det(a.c,a.a,b.c,b.a)==0);
}

bool intersect(Line a,Line b,PT &c) // a should not be equivalent with b
{
	Double d=det(a.a,a.b,b.a,b.b);
	if(d==0) return false;
	c.x=-det(a.c,a.b,b.c,b.b)/d;
	c.y=-det(a.a,a.c,b.a,b.c)/d;
	return true;
}

Line toLine(Segment t) //if t is a single point, black hole will be returned
{
	// debug(t.length());
	Line res;
	res.a=(t.ed.y-t.st.y);
	res.b=-(t.ed.x-t.st.x);
	// debug(res.a,res.b);
	res.c=-res.a*t.st.x-res.b*t.st.y;
	return res;
}

bool intersect(Segment a,Line b,PT &c) //a,b?????
{
	PT ta=theLine.st,tb=theLine.ed,tc=a.st,td=a.ed;
	// if(ta.collinear(tb,tc) || ta.collinear(tb,td))
	// {
	// 	Double l1=min(ta.x,tb.x),r1=max(ta.x,tb.x),l2=min(tc.x,td.x),r2=max(tc.x,td.x);
	// 	Double r=min(r1,r2),l=max(l1,l2);
	// 	Double dx=max(Double(0),r-l);
	// 	l1=min(ta.y,tb.y),r1=max(ta.y,tb.y),l2=min(tc.y,td.y),r2=max(tc.y,td.y);
	// 	r=min(r1,r2),l=max(l1,l2);
	// 	Double dy=max(Double(0),r-l);
	// 	return sqrt((dx*dx+dy*dy).x);
	// }
	// else if(ta.collinear(tb,tc) || ta.collinear(tb,td)) return 0;
	if((ta.clockwise(tb,tc)^ta.clockwise(tb,td))==0) return 0;
	bool f=intersect(toLine(a),b,c);
	assert(f);
	return true;
}

inline Double dis(PT a,PT b)
{
	return sqrt(((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)).x);
}

Double solve(PT a,PT b,PT c,Line t,int bi) // ??a,c?????
{
	Segment x(a,b),y(b,c),z(c,a);
	assert(!equivalent(toLine(x),t));
	// if(equivalent(toLine(x),t)) return x.length();
	cout<<fixed;
	cout.precision(10);
	// debug(y,toLine(y),t);
	// debug(y,bi,y.length(),equivalent(toLine(y),t));
	if(equivalent(toLine(y),t)) return (bi?y.length():0);
	assert(!equivalent(toLine(z),t));
	// debug(x,y,z);
	// if(equivalent(toLine(z),t)) return 0;
	PT ix,iy,iz;
	bool fx,fy,fz;
	tie(fx,fy,fz)=mt(intersect(x,t,ix),intersect(y,t,iy),intersect(z,t,iz));
	PT l(numeric_limits<double>::max(),numeric_limits<double>::max()),r(numeric_limits<double>::lowest(),numeric_limits<double>::lowest());
	if(fx) chmin(l,ix),chmax(r,ix);
	if(fy) chmin(l,iy),chmax(r,iy);
	if(fz) chmin(l,iz),chmax(r,iz);
	// debug(a,b,c,z,t,fx,fy,fz,ix,iy,iz,l,r);
	if(!fx && !fy && !fz) return 0;
	// debug(a,b,c,t,x,y,z,fx,fy,fz,ix,iy,iz);
	return dis(l,r);
	// if(fx && fy) return dis(ix,iy);
	// if(fx && fz) return dis(ix,iz);
	// if(fy && fz) return dis(iy,iz);
	// return 0;
}

ConvexHull <Double> hull;
Double query(Line t)
{
	// debug(t.a,t.b,t.c);
	Double res=0;
	for(int i=0;i<n;i++)
	{
		// debug(i,res);
		// cout<<edges[i]<<' '<<edges[(i+1)%n]<<endl;
		// debug(noInt,edges[i],edges[(i+1)%n],t);
		// Double len=solve(noInt,edges[i],edges[(i+1)%n],t);
		// cout<<len<<endl;
		// PT a=edges[i]-noInt;
		// PT b=edges[(i+1)%n]-noInt;
		// cout<<a.crossProduct(b)<<endl;
		// debug(a,b,hull.areaOfTriangle(noInt,edges[i],edges[(i+1)%n]));
		int positive=(hull.directedAreaOfTriangle(noInt,edges[i],edges[(i+1)%n])>0);
		Double len=solve(noInt,edges[i],edges[(i+1)%n],t,positive);
		// debug(edges[i],edges[(i+1)%n],i,positive,len);
		// debug(i,len);
		if(positive) res+=len;else res-=len;
		// if(hull.directedAreaOfTriangle(noInt,edges[i],edges[(i+1)%n])>0) res+=len;else res-=len;
	}
	return mabs(res);
}

int main()
{
	// cout<<fixed;
	// cout.precision(50);
	// numeric_limits<double>::min();
	// cout<<(long double)(1.000000000000000000000123e-23L)<<endl;
	// cout<<(long double)(1.00000000000000123e-23L)<<endl;
//	ConvexHull <int> t;	
//	cout<<t.areaOfTriangle({0,1},{1,2},{3,2})<<endl;
//	freopen("input.txt","r",stdin);__DBL_MIN__;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>edges[i];
		edges[i].x.x*=100;
		edges[i].y.x*=100;
	}
	Double area=0;
	for(int i=0;i<n;i++)
	{
		area+=hull.directedAreaOfTriangle({0,0},edges[i],edges[(i+1)%n]);
	}
	// cout<<area<<endl;
	if(area<0)
	{
		reverse(edges+1,edges+n);
	}
	// cout<<solve(noInt,{1,0},{1,1},Line({1,0,0}))<<endl;
	// return 0;
	for(int i=0;i<m;i++)
	{
		cin>>theLine;
		theLine.st.x*=100.0;
		theLine.st.y*=100.0;
		theLine.ed.x*=100.0;
		theLine.ed.y*=100.0;
		// PT tmp;
		// debug(theLine);
		// cout<<intersect({{0,0},{0,-100}},toLine(theLine),tmp)<<endl;
		// debug(t,toLine(t));
		cout<<fixed;
		cout.precision(10);
		cout<<query(toLine(theLine)).x/100<<endl;
	}
	return 0;
}