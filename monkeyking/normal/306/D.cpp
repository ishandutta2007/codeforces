//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/Geometry>
//#include <self/rand>
//using namespace std;
//using namespace Geometry2;
//int n;
//Vector p[105];
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>n;
//	if(n<=4) over("No solution");
//	for(int i=0;i<n;i++)
//	{
//		static double r=2*pi/n;
//		static double st=1;
//		p[i]=Vector(500,500)+Vector(cos(st),sin(st))*300;
//		st+=r;
//	}
//	while(true)
//	{
//		vector<Double> vSort;
//		for(int i=0;i<n;i++)
//		{
//			Vector &a=p[i],&b=p[(i+1)%n],&c=p[(i+2)%n],&d=p[(i+3)%n];
//			Double t=0.001*rand(1,800);
//			b=a+(b-a)/(b-a).length()*((b-a).length()+t);
//			c=d+(c-d)/(c-d).length()*((c-d).length()+t);
//		}
//		for(int i=0;i<n;i++)
//		{
//			Vector &a=p[i],&b=p[(i+1)%n];
//			vSort.push_back((b-a).length());
//		}
//		sort(all(vSort));
//		int ok=1;
//		for(int i=0;i<n-1;i++)
//		{
//			if((vSort[i+1]-vSort[i]).x<=0.001) ok=0;
//		}
//		if(ok) break;
//	}
//	for(int i=0;i<n;i++)
//	{
//		cout.precision(10);
//		cout<<fixed;
//		cout<<p[i].x<<' '<<p[i].y<<endl;
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
#ifdef __TAKE_CONST_EPS
const double eps=__TAKE_CONST_EPS;
#else
const double eps=1e-9;
#endif
const double pi=3.141592653589793238462643383279;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
using namespace std;
#endif
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator<<(ostream &cout, const vector<T> &vec)
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
		std::cout<<(x&1);
		x>>=1;
		len--;
		// vec.push_back(x&1);
		// x>>=1;
	}
	while(len--) cout<<0;
	// reverse(vec.begin(),vec.end());
	// for(int i=(int)vec.size();i<len;i++)
	// {
	// 	putchar('0');
	// }
	// for(size_t i=0;i<vec.size();i++)
	// {
	// 	std::cout<<vec[i];
	// }
	// std::cout<<' ';
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
#ifndef _SELF_GEOMETRY
#define _SELF_GEOMETRY
#ifndef _SELF_DOUBLE
#define _SELF_DOUBLE
struct Double
{
    double x;
    Double(){}
    Double(const double _):x(_){}
    Double length()const{
        return (x<0?-x:x);
    }
    bool operator == (const Double &oth)const{
        return (mabs(x-oth.x)<eps);
    }
    bool operator != (const Double &oth)const{
        return (mabs(x-oth.x)>=eps);
    }
    bool operator < (const Double &oth)const{
        return (x-oth.x<=-eps);
    }
    bool operator > (const Double &oth)const{
        return (x-oth.x>=eps);
    }
    bool operator <= (const Double &oth)const{
        return (x-oth.x<eps);
    }
    bool operator >= (const Double &oth)const{
        return (x-oth.x>-eps);
    }
    Double operator + (void)const{
        return x;
    }
    Double operator - (void)const{
        return -x;
    }
    Double operator + (const Double &oth)const{
        return x+oth.x;
    }
    Double operator - (const Double &oth)const{
        return x-oth.x;
    }
    Double operator * (const Double &oth)const{
        return x*oth.x;
    }
    Double operator / (const Double &oth)const{
        return x/oth.x;
    }
    void operator += (const Double &oth){
        x+=oth.x;
    }
    void operator -= (const Double &oth){
        x-=oth.x;
    }
    void operator *= (const Double &oth){
        x*=oth.x;
    }
    void operator /= (const Double &oth){
        x/=oth.x;
    }
};

Double sqrt(const Double &x){
    return sqrt(x.x);
}
ostream & operator << (ostream &cout,const Double &x){
    cout<<x.x;
    return cout;
}
istream & operator >> (istream &cin,Double &x){
    cin>>x.x;
    return cin;
}
#endif

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
	bool polarCompare(PT o,PT a,PT b)//oab 
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

namespace Geometry2
{
	struct Vector
	{
		Double x,y;
		Vector(){}
		Vector(const Double &_x,const Double &_y):x(_x),y(_y){}
		Double length()const{
			return sqrt(x*x+y*y);
		}
		#ifdef SELF_GEOMETRY_MACRO 
		#ifdef ENABLE_VECTOR_POLAR_COMPARE
		#define ENABLED_VECTOR_POLAR_COMPARE 1
		bool operator < (const Vector &oth)const{
			int b1=(y>0 || (y==0 && x>0));
			int b2=(oth.y>0 || (oth.y==0 && oth.x>0));
			if(b1!=b2) return b1>b2;
			if(((*this)^oth)==0) return (*this).length()<(*this).length();
			return ((*this)^oth)>0;
		}
		bool operator > (const Vector &oth)const{
			return oth<(*this);
		}
		#endif
		#endif
		#ifndef ENABLED_VECTOR_POLAR_COMPARE
		bool operator < (const Vector &oth)const{
			if(x!=oth.x) return x<oth.x;
			return y<oth.y;
		}
		bool operator > (const Vector &oth)const{
			return oth<(*this);
		}
		#endif
		bool operator == (const Vector &oth)const{
			return x==oth.x && y==oth.y;
		}
		bool operator != (const Vector &oth)const{
			return x!=oth.x || y!=oth.y;
		}
		Vector operator + (const Vector &oth)const{
			return Vector(x+oth.x,y+oth.y);
		}
		Vector operator - (const Vector &oth)const{
			return Vector(x-oth.x,y-oth.y);
		}
		Double operator * (const Vector &oth)const{
			return x*oth.x+y*oth.y;
		}
		Double operator ^ (const Vector &oth)const{
			return x*oth.y-y*oth.x;
		}
		Vector operator * (const Double &oth)const{
			return Vector(x*oth,y*oth);
		}
		Vector operator / (const Double &oth)const{
			return Vector(x/oth,y/oth);
		}
		void operator += (const Vector &oth){
			x+=oth.x;
			y+=oth.y;
		}
		void operator -= (const Vector &oth){
			x-=oth.x;
			y-=oth.y;
		}
		void operator *= (const Double &oth){
			x*=oth;
			y*=oth;
		}
		void operator /= (const Double &oth){
			x/=oth;
			y/=oth;
		}
		bool clockwise(Vector b,Vector c)const{
			b-=(*this);
			c-=(*this);
			return (b^c)<0;
		}
		bool coClockwise(Vector b,Vector c)const{
			b-=(*this);
			c-=(*this);
			return (b^c)<=0;
		}
		bool counterClockwise(Vector b,Vector c)const{
			b-=(*this);
			c-=(*this);
			return (b^c)>0;
		}
		bool coCounterClockwise(Vector b,Vector c)const{
			b-=(*this);
			c-=(*this);
			return (b^c)>=0;
		}
		bool collinear(Vector b,Vector c)const{
			b-=(*this);
			c-=(*this);
			return (b^c)==0;
		}
		Vector rotate(const Double &deg)const{
			Double c=cos(deg.x),s=sin(deg.x);
			return Vector(c*x-s*y,s*x+c*y);
		}
		Vector rotate90()const{
			return Vector(-y,x);
		}
		Vector orth()const{
			return (*this)/length();
		}
	};
	ostream & operator << (ostream &cout,const Vector &v){
		cout<<'('<<v.x<<','<<v.y<<')';
		return cout;
	}

	struct Line;
	struct Line2;
	struct Line
	{
		Double a,b,c;
		Line(){}
		Line(const Double &_a,const Double &_b,const Double &_c):a(_a),b(_b),c(_c){}
		Line(const Line2&);
	};

	struct Line2
	{
		Vector a,b;
		Line2(){}
		Line2(const Vector _a,const Vector _b):a(_a),b(_b){}
		Line2(const Line &l){
			if(l.a==0)
			{
				a.y=b.y=l.c/l.b;
				a.x=1;b.x=2;
			}
			else if(l.b==0)
			{
				a.x=b.x=l.c/l.a;
				a.y=1;b.y=2;
			}
			else
			{
				a=Vector(0,l.c/l.b);
				b=Vector(l.c/l.a,0);
			}
		}
	};
	Line::Line(const Line2& l):a(l.a.y-l.b.y),b(l.b.x-l.a.x),c(l.b.x*l.a.y-l.b.y*l.a.x){}
}
#endif
#ifndef _SELF_RAND
#define _SELF_RAND 1
#if __cplusplus < 201103L
long long _Rand_Gen_Num() {return 1LL*rand()*RAND_MAX+rand();}
int rand(int l,int r) {long long x=_Rand_Gen_Num();return x%(r-l+1)+l;}
#else
#include <time.h>
#include <chrono>
#include <random>
using namespace std; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
#endif
template <typename Iterator>
void _m_random_shuffle(Iterator begin,Iterator end)
{
    for(Iterator it=begin+1;it!=end;it++)
    {
        iter_swap(begin+rand(0,it-begin),it);
    }
}
#define random_shuffle(a,b) _m_random_shuffle(a,b)
#endif
using namespace std;
using namespace Geometry2;
int n;
Vector p[105];

int main()
{
//	// freopen("input.txt","r",stdin);
	cin>>n;
	if(n<=4) over("No solution");
	for(int i=0;i<n;i++)
	{
		static double r=2*pi/n;
		static double st=1;
		p[i]=Vector(500,500)+Vector(cos(st),sin(st))*300;
		st+=r;
	}
	while(true)
	{
		vector<Double> vSort;
		for(int i=0;i<n;i++)
		{
			Vector &a=p[i],&b=p[(i+1)%n],&c=p[(i+2)%n],&d=p[(i+3)%n];
			Double t=0.001*rand(1,800);
			b=a+(b-a)/(b-a).length()*((b-a).length()+t);
			c=d+(c-d)/(c-d).length()*((c-d).length()+t);
		}
		for(int i=0;i<n;i++)
		{
			Vector &a=p[i],&b=p[(i+1)%n];
			vSort.push_back((b-a).length());
		}
		sort(all(vSort));
		int ok=1;
		for(int i=0;i<n-1;i++)
		{
			if((vSort[i+1]-vSort[i]).x<=0.001) ok=0;
		}
		if(ok) break;
	}
	for(int i=0;i<n;i++)
	{
		cout.precision(10);
		cout<<fixed;
		cout<<p[i].x<<' '<<p[i].y<<endl;
	}
	return 0;
}