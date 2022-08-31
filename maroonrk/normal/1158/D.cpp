#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) FOR(i,0,b)
#define ROF(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) ROF(i,0,b)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
auto& errStream=cerr;
#ifdef LOCAL
#define cerr (cerr<<"-- line "<<__LINE__<<" -- ")
#else
class CerrDummy{}cerrDummy;
template<class T>
CerrDummy& operator<<(CerrDummy&cd,const T&){
	return cd;
}
using charTDummy=char;
using traitsDummy=char_traits<charTDummy>;
CerrDummy& operator<<(CerrDummy&cd,basic_ostream<charTDummy,traitsDummy>&(basic_ostream<charTDummy,traitsDummy>&)){
	return cd;
}
#define cerr cerrDummy
#endif
#define reach cerr<<"reached"<<endl
void dmpr(decltype(cerr)&os){os<<endl;}
template<class T,class... Args>
void dmpr(decltype(cerr)&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp(...) dmpr(cerr,##__VA_ARGS__)
#define zero(x) memset(x,0,sizeof(x))
#define one(x) memset(x,-1,sizeof(x))
#define fs first
#define sc second
#define bg begin()
#define ed end()

template<class T> using V=vector<T>;
template<class T> using VV=V<V<T>>;

using pi=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	rep(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"(";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<")";
}

ll read(){
	ll i;
	scanf("%lld",&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(ll x,int suc=1){
	printf("%lld",x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

string readString(){
	static char buf[3341000];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341000];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(b<a)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

#define CAPITAL
void Yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void No(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

constexpr ll TEN(int n){
	return n==0?1:TEN(n-1)*10;
}

template<class T>
vector<T> uni(const vector<T>&vv){
	auto v(vv);
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	return v;
}
template<class T>
void mkuni(vector<T>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.end());
}

//ayasii
int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}


template<class E>
struct LenType{
	using type=E;
};
template<>
struct LenType<int>{
	using type=ld;
};

template<class D>
struct Vec2{
	D x,y;
	Vec2(D xx=0,D yy=0):x(xx),y(yy){
	}
	Vec2 operator-()const{
		return Vec2(-x,-y);
	}
	bool operator<(const Vec2&rhs)const{
		return (x!=rhs.x)?(x<rhs.x):(y<rhs.y);
	}
	Vec2& operator +=(const Vec2&rhs){
		x+=rhs.x;
		y+=rhs.y;
		return *this;
	}
	Vec2 operator +(const Vec2&rhs)const{
		return Vec2(*this)+=rhs;
	}
	Vec2& operator -=(const Vec2&rhs){
		x-=rhs.x;
		y-=rhs.y;
		return *this;
	}
	Vec2 operator -(const Vec2&rhs)const{
		return Vec2(*this)-=rhs;
	}
	Vec2& operator *=(D d){
		x*=d;
		y*=d;
		return *this;
	}
	Vec2 operator *(D d)const{
		return Vec2(*this)*=d;
	}
	Vec2& operator /=(D d){
		x/=d;
		y/=d;
		return *this;
	}
	Vec2 operator /(D d)const{
		return Vec2(*this)/=d;
	}
	D norm()const{
		return Sq(x)+Sq(y);
	}
	typename LenType<D>::type length()const{
		return sqrt(norm());
	}
	double arg()const{
		return atan2(y,x);
	}
	//ccw
	Vec2 rot90()const{
		return Vec2(-y,x);
	}
};
template<class D>
Vec2<D> operator*(D d,const Vec2<D>& v){
	return v*d;
}
template<class D>
ostream& operator<<(ostream&os,const Vec2<D>& p){
	return os<<"{"<<p.x<<","<<p.y<<"}";
}
template<class D>
D dot(Vec2<D> a,Vec2<D> b){
	return a.x*b.x+a.y*b.y;
}
template<class D>
D cross(Vec2<D> a,Vec2<D> b){
	return a.x*b.y-a.y*b.x;
}
template<class D>
int sgn(D x){
	if(x>0)return 1;
	else if(x<0)return -1;
	else return 0;
}
//ccw 1, line 0, cw -1
template<class D>
int ccw(Vec2<D> a,Vec2<D> b,Vec2<D> c){
	return sgn(cross(b-a,c-a));
}
template<class D>
complex<double> toC(Vec2<D> v){
	return complex<double>(v.x,v.y);
}
//a->b->c 
// 0
template<class D>
double turnArg(Vec2<D> a,Vec2<D> b,Vec2<D> c){
	auto p=toC(b-a);
	auto q=toC(c-b);
	return arg(q/p);
}
template<class D>
int argtype(Vec2<D> a){
	if(a.y<0)return 0;
	else if(a.y>0)return 2;
	else if(a.x>0)return 1;
	else return 3;
}
//arg(a)<arg(b)
//arg({-1,0})=+pi
template<class D>
int argcmp(Vec2<D> a,Vec2<D> b){
	int ta=argtype(a),tb=argtype(b);
	if(ta!=tb)return ta<tb;
	else return sgn(cross(a,b))==1;
}

//assume a,b,c lie on the same line
//returns if the order is a-b-c
//not verified
template<class D>
bool between(Vec2<D> a,Vec2<D> b,Vec2<D> c,bool inc=true){
	return sgn(dot(a-b,c-b))<=(inc?0:-1);
}

template<class D>
bool parallelVV(Vec2<D> a,Vec2<D> b){
	return !sgn(cross(a,b));
}

/*
//cut here
using D=ld;
using P=Vec2<D>;
const D PI=acos(-1);
const D eps=1e-15;

template <>
int sgn(D d){
	if(d>eps) return 1;
	else if(d<-eps) return -1;
	else return 0;
}
int sgn(D a,D b){
	return sgn(a-b);
}
P polar(D len,D a){
	return P(len*cos(a),len*sin(a));
}*/

using P=Vec2<int>;

P readP(){
	P p;
	p.x=read();
	p.y=read();
	return p;
}

signed main(){
	using Z=pair<P,int>;
	int n=read();
	V<Z> z(n);
	rep(i,n){
		z[i].fs=readP();
		z[i].sc=i;
	}
	string s=readString()+'R';
	swap(*min_element(all(z)),z[0]);
	P rt;
	auto cmp=[&](Z a,Z b){
		return cross(a.fs-rt,b.fs-rt)>0;
	};
	rep(i,n-1){
		rt=z[i].fs;
		if(s[i]=='L'){
			swap(z[i+1],*min_element(z.bg+i+1,z.ed,cmp));
		}else{
			swap(z[i+1],*max_element(z.bg+i+1,z.ed,cmp));
		}
	}
	vi ans;
	rep(i,n)
		ans.pb(z[i].sc+1);
	print(ans);
}