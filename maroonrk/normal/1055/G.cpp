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

template<class D>
struct Line{
	Vec2<D> s,t;
};
template<class D>
ostream& operator<<(ostream&os,Line<D> l){
	return os<<"{"<<l.s<<","<<l.t<<"}";
}
template<class D>
struct Segment{
	Vec2<D> s,t;
	auto length()const{
		return (s-t).length();
	}
};
template<class D>
ostream& operator<<(ostream&os,Segment<D> s){
	return os<<"{"<<s.s<<","<<s.t<<"}";
}

//not verified
template<class D>
bool parallelLL(Line<D> a,Line<D> b){
	return parallelVV(a.s-a.t,b.s-b.t);
}
//not verified
template<class D>
bool parallelLS(Line<D> a,Segment<D> b){
	return parallelVV(a.s-a.t,b.s-b.t);
}
template<class D>
bool parallelSS(Segment<D> a,Segment<D> b){
	return parallelVV(a.s-a.t,b.s-b.t);
}

//assume the unique answer exists
//D should not be integer
template<template<class>class T1,template<class>class T2,class D>
Vec2<D> intersectP(T1<D> a,T2<D> b){
	auto p=a.t-a.s;
	D w=-cross(p,b.s-a.s)/cross(p,b.t-b.s);
	return b.s+(b.t-b.s)*w;
}
//all inclusive
//not verified
template<class D>
bool intersectLL(Line<D> a,Line<D> b){
	return !parallelLL(a,b);
}
template<class D>
bool intersectLS(Line<D> a,Segment<D> b){
	int p=ccw(a.s,a.t,b.s);
	int q=ccw(a.s,a.t,b.t);
	if(p==0||q==0)
		return true;
	return p!=q;
}
template<class D>
bool intersectSS(Segment<D> p,Segment<D> q){
	if(parallelSS(p,q)){
		//not verified
		return
			ccw(p.s,p.t,q.s)==0
			&&
			(
			between(p.s,p.t,q.s)||
			between(p.s,p.t,q.t)||
			between(q.s,q.t,p.s)
			);
	}
	return
		intersectLS(Line<D>{p.s,p.t},q)&&
		intersectLS(Line<D>{q.s,q.t},p);
}

template<class D>
typename LenType<D>::type distVS(Vec2<D> v,Segment<D> s){
	auto res=min((v-s.s).length(),(v-s.t).length());
	Line<D> l{v,v+(s.t-s.s).rot90()};
	if(intersectLS(l,s))
		chmin(res,(intersectP(l,s)-v).length());
	return res;
}

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
}

P readP(){
	P p;
	p.x=read();
	p.y=read();
	return p;
}

using L=Line<D>;
using S=Segment<D>;

namespace MaxFlow{
	using CapType=int;
	struct Edge{
		int to,rev;
		CapType cap;
	};
	vector<vector<Edge>> g;
	vi itr,level;
	void Init(int n){
		g.assign(n,vector<Edge>());
		itr.assign(n,0);
		level.assign(n,0);
	}
	void AddEdge(int from,int to,CapType cap){
		g[from].pb({to,(int)g[to].size(),cap});
		g[to].pb({from,(int)g[from].size()-1,0});
	}
	void bfs(int s){
		fill(level.begin(),level.end(),-1);
		level[s]=0;
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int v=q.front();q.pop();
			for(auto e:g[v])if(e.cap>0&&level[e.to]==-1){
				level[e.to]=level[v]+1;
				q.push(e.to);
			}
		}
	}
	CapType dfs(int v,int t,CapType f){
		if(v==t)
			return f;
		CapType res=0;
		for(int&i=itr[v];i<(int)g[v].size();i++){
			Edge& e=g[v][i];
			if(e.cap>0&&level[e.to]==level[v]+1){
				CapType d=dfs(e.to,t,min(f,e.cap));
				if(d>0){
					e.cap-=d;
					g[e.to][e.rev].cap+=d;
					res+=d;
					f-=d;
					if(f<=0)break;
				}
			}
		}
		return res;
	}
	CapType Calc(int s,int t){
		CapType flow=0;
		while(1){
			bfs(s);
			if(level[t]==-1)
				return flow;
			fill(itr.begin(),itr.end(),0);
			flow+=dfs(s,t,inf);
		}
	}
}

signed main(){
	int n=read(),w=read();
	int lr=0;
	V<P> pol;
	{
		V<P> ps(n);
		rep(i,n)
			ps[i]=readP();
		rotate(ps.bg,min_element(all(ps),[](P a,P b){return mp(-a.y,a.x)<mp(-b.y,b.x);}),ps.ed);
		{
			int l=inf,r=-inf;
			rep(i,n){
				chmin(l,ps[i].x);
				chmax(r,ps[i].x);
			}
			lr=r-l;
		}
		P s=ps[0];
		V<P> vs;
		rep(i,n)
			vs.pb(ps[(i+1)%n]-ps[i]);
		for(auto&p:ps)
			p=-p;
		rotate(ps.bg,min_element(all(ps),[](P a,P b){return mp(-a.y,a.x)<mp(-b.y,b.x);}),ps.ed);
		s+=ps[0];
		rep(i,n)
			vs.pb(ps[(i+1)%n]-ps[i]);
		sort(all(vs),argcmp<D>);
		pol.pb(s);
		for(auto v:vs)
			pol.pb(s+=v);
	}
	n=pol.size()-1;
	struct J{P c;int r;};
	int m=read();
	V<J> js(m);
	rep(i,m){
		js[i].c=readP();
		js[i].r=read();
	}
	int s=1+m*2+1;
	MaxFlow::Init(s);
	rep(i,m){
		if(js[i].c.x-js[i].r-lr<0)
			MaxFlow::AddEdge(0,1+i*2,inf);
		if(js[i].c.x+js[i].r+lr>w)
			MaxFlow::AddEdge(1+i*2+1,s-1,inf);
		MaxFlow::AddEdge(1+i*2,1+i*2+1,1);
	}
	rep(i,m)rep(j,i){
		auto d=js[j].c-js[i].c;
		bool in=true;
		D x=1e9;
		rep(k,n){
			chmin(x,distVS(d,S{pol[k],pol[k+1]}));
			in&=ccw(pol[k],pol[k+1],d)>=1;
		}
		if(in||x+eps<js[i].r+js[j].r){
			dmp(in,x);
			dmp(i,j);
			MaxFlow::AddEdge(1+i*2+1,1+j*2,inf);
			MaxFlow::AddEdge(1+j*2+1,1+i*2,inf);
		}
	}
	print(MaxFlow::Calc(0,s-1));
}