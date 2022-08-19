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

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

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

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
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

#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
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
int mask(int i){
	return (int(1)<<i)-1;
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
    static random_device rd;
    static mt19937_64 gen(rd());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

//using ld=long double;
using ld=ll;
using cm=complex<ld>;
#define x real()
#define y imag()
//const ld eps=1e-8;
const ld eps=0;
//const ld PI=acos(ld(-1));
int sgn(ld a){return a<-eps?-1:(a>eps?1:0);}
ld rabs(cm a){return max(abs(a.x),abs(a.y));}
ld signed_rabs(cm a){
	if(abs(a.x)>abs(a.y))return a.x;
	else return a.y;
}
ld dot(cm a,cm b){return a.x*b.x+a.y*b.y;}
ld crs(cm a,cm b){return a.x*b.y-a.y*b.x;}
ld crs(cm a,cm b,cm c){return crs(b-a,c-a);}
int ccw(cm a,cm b){return sgn(crs(a,b));}
int ccw(cm a,cm b,cm c){return ccw(b-a,c-a);}
auto cmless=[](cm a,cm b){
	int s=sgn(a.x-b.x);
	if(s)return s<0;
	else return sgn(a.y-b.y)<0;
};
bool cmeq(cm a,cm b){
	return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;
};
//(-pi,0](0,pi]
int argtype(cm a){
	if(sgn(a.y)==0)return a.x<0?1:0;
	return a.y<0?0:1;
}
int argcmp(cm a,cm b){
	int at=argtype(a),bt=argtype(b);
	if(at!=bt)return at<bt?-1:1;
	return -ccw(a,b);
};
bool argless(cm a,cm b){return argcmp(a,b)<0;}
//(-2)[a,-1](0)[b,1](2)
int bet(cm a,cm b,cm c){
	cm d=b-a;
	ld e=dot(d,c-a);
	if(sgn(e)<=0)return sgn(e)-1;
	return sgn(e-norm(d))+1;
}
//AOJ1183
int qeq(ld a,ld b,ld c,ld&d,ld&e){
	ld f=b*b-4*a*c;
	if(sgn(f)<0)return 0;
	ld g=sqrt(max(f,ld(0)));
	d=(-b+g)/(2*a);
	e=(-b-g)/(2*a);
	return sgn(f)+1;
}
//AOJ0153
//0-no,1-edge,2-in
int cont(cm a,cm b,cm c,cm d){
	if(ccw(a,b,c)==-1)
		swap(b,c);
	return min({ccw(a,b,d),ccw(b,c,d),ccw(c,a,d)})+1;
}
//AOJ1183
//arg between ab
//assume given lengths are valid
ld arg(ld a,ld b,ld c){
	return acos(min(max((a*a+b*b-c*c)/(2*a*b),ld(-1)),ld(1)));
}
//AOJ2233
//a->b->c 
//a-b-c0
ld turn(cm a,cm b,cm c){
	return arg((c-b)/(b-a));
}

//AOJ0068
//TCO 2017 final Hard
//
vc<cm> convex(vc<cm> s,bool onedge){
	swap(s[0],*min_element(all(s),cmless));
	sort(s.bg+1,s.ed,[&](cm a,cm b){
		int c=ccw(s[0],a,b);
		if(c)return c==1;
		else{
			if(onedge&&sgn(s[0].x-a.x)==0)
				return a.y>b.y;
			return bet(s[0],a,b)==2;
		}
	});
	vc<cm> t;
	rep(i,s.size()){
		int ss;
		while((ss=t.size())>=2){
			cm a=t[ss-2];
			cm b=t[ss-1];
			cm c=s[i];
			if(ccw(a,b,c)>=(onedge?0:1))
				break;
			t.pop_back();
		}
		t.pb(s[i]);
	}
	return t;
}

//ARC055D
int gcd(int a,int b){return b?gcd(b,a%b):a;}
/*int gcd(int a,int b){
	if(a==0)return b;
	if(b==0)return a;
	if(a<0)a=-a;
	if(b<0)b=-b;
	int s=botbit(a|b);
	a>>=botbit(a);
	do{
		b>>=botbit(b);
		if(a>b)swap(a,b);
		b-=a;
	}while(b);
	return a<<s;
	
}*/
int lcm(int a,int b){return a/gcd(a,b)*b;}

struct res{
	bool isline;
	vc<tuple<int,int,int>> z;
	bool operator==(const res&r)const{
		if(isline){
			return r.isline;
		}else{
			if(r.isline)return false;
			return z==r.z;
		}
	}
};

//yosupo
//TKPPC G
struct SA{
	int n;
	vi sa,as,lcp;
	template<class t> SA(t s):n(s.size()),sa(n),as(n),lcp(n-1){
		rep(i,n)sa[i]=n-1-i;
		stable_sort(all(sa),[&](int a,int b){return s[a]<s[b];});
		vi c(n);
		rep(i,n)c[i]=s[i];
		for(int w=1;w<n;w*=2){
			vi d(c);
			rep(i,n){
				if(i&&sa[i-1]+w<n&&d[sa[i-1]]==d[sa[i]]&&d[sa[i-1]+w/2]==d[sa[i]+w/2])
					c[sa[i]]=c[sa[i-1]];
				else
					c[sa[i]]=i;
			}
			vi e(sa),f(n);
			iota(all(f),0);
			rep(i,n){
				int j=e[i]-w;
				if(j>=0)sa[f[c[j]]++]=j;
			}
		}
		/*
		//as
		rep(i,n)as[sa[i]]=i;
		//lcp
		int w=0;
		for(auto i:as){
			if(w)w--;
			if(i<n-1){
				while(max(sa[i],sa[i+1])+w<n&&s[sa[i]+w]==s[sa[i+1]+w])w++;
				lcp[i]=w;
			}
		}
		*/
	}
};

res getconvex(int n){
	vc<cm> ps;
	rep(i,n){
		int a,b;cin>>a>>b;
		ps.eb(a,b);
	}
	ps=convex(ps,false);
	n=ps.size();
	
	dmp(ps);
	
	//if(n==2)return res{true,{}};
	
	/*int g=0,h=0;
	rep(i,n){
		int j=(i+1)%n,k=(j+1)%n;
		g=gcd(g,norm(ps[j]-ps[i]));
		h=gcd(h,ccw(ps[i],ps[j],ps[k]));
	}*/
	vc<tuple<int,int,int>> c;
	rep(i,n){
		int j=(i+1)%n,k=(j+1)%n;
		c.eb(
		//norm(ps[j]-ps[i])/g,
		//ccw(ps[i],ps[j],ps[k])/h
		norm(ps[j]-ps[i]),
		ccw(ps[i],ps[j],ps[k]),
		dot(ps[j]-ps[i],ps[k]-ps[i])
		);
	}
	auto d=c;
	mkuni(d);
	vi e(n*2);
	rep(i,n)e[i]=e[n+i]=lwb(d,c[i]);
	
	SA sa(e);
	int top=-1;
	rep(i,n*2)if(sa.sa[i]<n){
		top=sa.sa[i];
		break;
	}
	rotate(c.bg,c.bg+top,c.ed);
	return res{false,c};
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	auto a=getconvex(n);
	auto b=getconvex(m);
	if(a==b)yes();
	else no();
}