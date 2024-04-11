#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
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
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}

ll read(){
	ll i;
	cin>>i;
	return i;
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

pi readpi(int off=0){
	int a,b;cin>>a>>b;
	return pi(a+off,b+off);
}

template<class t,class u>
void print(const pair<t,u>&p,int suc=1){
	print(p.a,2);
	print(p.b,suc);
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

template<class T>
void print_offset(const vector<T>&v,ll off,int suc=1){
	rep(i,v.size())
		print(v[i]+off,i==int(v.size())-1?suc:2);
}

template<class T,size_t N>
void print(const array<T,N>&v,int suc=1){
	rep(i,N)
		print(v[i],i==int(N)-1?suc:2);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}

//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
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
ll mask(int i){
	return (ll(1)<<i)-1;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
void myshuffle(vc<t>&a){
	rep(i,si(a))swap(a[i],a[rand_int(0,i)]);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

vvc<int> readGraph(int n,int m){
	vvc<int> g(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		//sc.read(a,b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> readTree(int n){
	return readGraph(n,n-1);
}

vc<ll> presum(const vi&a){
	vc<ll> s(si(a)+1);
	rep(i,si(a))s[i+1]=s[i]+a[i];
	return s;
}

//copied from yosupo's library
//PARTLY VERIFIED

//USACO 2022 January Platinum C

#define GEOF

#ifdef GEOF
//using ld=long double;
using ld=double;
const ld PI=acos(ld(-1));
#else
using ld=ll;
#endif
const ld eps=1e-9;
int sgn(ld a){return a<-eps?-1:(a>eps?1:0);}
int sgn(ld a,ld b){return sgn(a-b);}
struct P {
    ld x,y;
    //P(ld _x = ld(0), ld _y = ld(0)) : x(_x), y(_y) {}
    P():x(0),y(0){}
    P(ld xx,ld yy):x(xx),y(yy){}
    P operator+(const P& r) const { return {x + r.x, y + r.y}; }
    P operator-(const P& r) const { return {x - r.x, y - r.y}; }
    P operator*(const P& r) const {
        return {x * r.x - y * r.y, x * r.y + y * r.x};
    }

    P operator*(const ld& r) const { return {x * r, y * r}; }
    P operator/(const ld& r) const { return {x / r, y / r}; }

    P& operator+=(const P& r) { return *this = *this + r; }
    P& operator-=(const P& r) { return *this = *this - r; }
    P& operator*=(const P& r) { return *this = *this * r; }
    P& operator*=(const ld& r) { return *this = *this * r; }
    P& operator/=(const ld& r) { return *this = *this / r; }

    P operator-() const { return {-x, -y}; }

    bool operator<(const P& r) const {
        return 2 * sgn(x, r.x) + sgn(y, r.y) < 0;
    }
    bool operator==(const P& r) const { return sgn((*this - r).rabs()) == 0; }
    bool operator!=(const P& r) const { return !(*this == r); }

    ld norm() const { return x * x + y * y; }
    ld rabs() const { return max(std::abs(x), std::abs(y)); }  // robust abs
    pair<ld, ld> to_pair() const { return {x, y}; }
    #ifdef GEOF
    ld abs() const { return sqrt(norm()); }
    ld arg() const { return atan2(y, x); }
    static P polar(ld le, ld th) { return {le * cos(th), le * sin(th)}; }
	#endif
};
istream& operator>>(istream& is, P& p){
	return is>>p.x>>p.y;
}
ostream& operator<<(ostream& os, const P& p) {
    return os << "P(" << p.x << ", " << p.y << ")";
}
ld norm(const P&a){
	return a.norm();
}
#ifdef GEOF
ld abs(const P&a){
	return sqrt(norm(a));
}
#endif
ld norm(const P&a,const P&b){
	return (a-b).norm();
}
//XXII Opencup GP of Ural K
P normalized(const P&a){
	return a/abs(a);
}
ld arg(const P&a){return a.arg();}
//AOJ1183
//arg between ab
//assume given lengths are valid
ld arg(ld a,ld b,ld c){
	return acos(min(max((a*a+b*b-c*c)/(2*a*b),ld(-1)),ld(1)));
}
ld dot(const P&a,const P&b){return a.x*b.x+a.y*b.y;}
ld crs(const P& a,const P& b){return a.x*b.y-a.y*b.x;}
ld crs(const P& a,const P& b,const P& c){return crs(b-a,c-a);}
int ccw(const P& a,const P& b){return sgn(crs(a,b));}
int ccw(const P& a,const P& b,const P& c){return ccw(b-a,c-a);}
//(-pi,0](0,pi]
int argtype(const P&a){
	if(sgn(a.y)==0)return a.x<0?1:0;
	return a.y<0?0:1;
}
int argcmp(const P&a,const P&b){
	int at=argtype(a),bt=argtype(b);
	if(at!=bt)return at<bt?-1:1;
	return -ccw(a,b);
};
bool argless(const P&a,const P&b){return argcmp(a,b)<0;}
//(-2)[a,-1](0)[b,1](2)
int bet(P a,P b,P c){
	P d=b-a;
	ld e=dot(d,c-a);
	if(sgn(e)<=0)return sgn(e)-1;
	return sgn(e-norm(d))+1;
}
//(a,b) x  y 
//(,)
pair<ld,ld> xcut(const P&a,const P&b,ld x){
	return mp(a.y*(b.x-x)-b.y*(a.x-x),b.x-a.x);
}
//normalize to [-PI,PI)
//Contest 2: PKU Contest 1, PTZ Summer 2022 Day 4
ld normarg(ld a){
	ld res=fmod(a+PI,2*PI);
	if(res<0)res+=PI;
	else res-=PI;
	return res;
}
//XXII Opencup GP of Ural K
P rot90(P a){
	return P(-a.y,a.x);
}
//AOJ1183
//Xmas2010 E
//-+ small/large  
int qeq(ld a,ld b,ld c,ld&d,ld&e){
	if(sgn(a)==0){
		if(sgn(b)==0)return 0;
		d=-c/b;
		return 1;
	}
	ld f=b*b-4*a*c;
	if(sgn(f)<0)return 0;
	ld g=sqrt(max(f,ld(0)));
	d=(-b-g)/(2*a);
	e=(-b+g)/(2*a);
	return sgn(f)+1;
}

P conj(P a){
	return P(a.x,-a.y);
}

ld arg(P a,P b,P c){
	return PI-arg((c-b)*conj(b-a));
}

ld getlen(P a,P b,P c){
	rep(k,3){
		if(a==b)return abs(c-b);
		swap(a,b);
		swap(b,c);
	}
	if(ccw(a,b,c)<0)swap(a,b);
	if(ccw(a,b,c)==0){
		return max({abs(a-b),abs(b-c),abs(c-a)});
	}
	rep(k,3){
		if(arg(a,b,c)>PI/3*2)return abs(a-b)+abs(c-b);
		swap(a,b);
		swap(b,c);
	}
	//dmp(0);
	P dif=b-a;
	dif*=P::polar(1,-PI/3);
	P d=a+dif;
	return abs(c-d);
}

void slv(){
	P ps[3];
	rep(i,3)cin>>ps[i];
	auto calcxy=[&](ld x,ld y){
		ld res=0;
		rep(i,3)chmax(res,getlen(P(x,y),ps[i],ps[(i+1)%3]));
		return res;
	};
	const ld vmax=ten(4);
	auto calcx=[&](ld x){
		ld lw=-vmax,up=vmax;
		rep(_,100){
			ld m1=(lw+lw+up)/3;
			ld m2=(lw+up+up)/3;
			if(calcxy(x,m1)>calcxy(x,m2))lw=m1;
			else up=m2;
		}
		//dmp2(x,lw,calcxy(x,lw));
		return calcxy(x,lw);
	};
	auto calc=[&](){
		ld lw=-vmax,up=vmax;
		rep(_,100){
			ld m1=(lw+lw+up)/3;
			ld m2=(lw+up+up)/3;
			if(calcx(m1)>calcx(m2))lw=m1;
			else up=m2;
		}
		return calcx(lw);
	};
	cout<<calc()<<endl;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//dmp(getlen(P(0,0),P(1,0),P(0,1)));
	
	//int t;cin>>t;rep(_,t)
	slv();
}