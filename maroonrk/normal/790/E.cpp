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

//#define CAPITAL
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

#define GEOF

#ifdef GEOF
using ld=long double;
#else
using ld=ll;
#endif
using cm=complex<ld>;
#define x real()
#define y imag()
const ld eps=1e-8;
#ifdef GEOF
const ld PI=acos(ld(-1));
#endif
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
//AOJ0153
//0-no,1-edge,2-in
int cont(cm a,cm b,cm c,cm d){
	if(ccw(a,b,c)==-1)
		swap(b,c);
	return min({ccw(a,b,d),ccw(b,c,d),ccw(c,a,d)})+1;
}
#ifdef GEOF
//AOJ1183
int qeq(ld a,ld b,ld c,ld&d,ld&e){
	ld f=b*b-4*a*c;
	if(sgn(f)<0)return 0;
	ld g=sqrt(max(f,ld(0)));
	d=(-b+g)/(2*a);
	e=(-b-g)/(2*a);
	return sgn(f)+1;
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
#endif
cm rot90(cm a){
	return cm(-a.y,a.x);
}

#ifndef GEOF
int gcd(int a,int b){return b?gcd(b,a%b):a;}
cm normdir(cm a){
	if(a==cm(0,0))return a;
	int g=gcd(abs(a.x),abs(a.y));
	return cm(a.x/g,a.y/g);
}
#endif

using ln=pair<cm,cm>;
cm dir(ln a){return a.b-a.a;}
cm eval(ln a,ld b){return a.a+dir(a)*b;}
int bet(ln a,cm b){return bet(a.a,a.b,b);}
int ccw(ln a,cm b){return ccw(a.a,a.b,b);}
cm proj(ln a,cm b){
	cm c=dir(a);
	return a.a+c*dot(c,b-a.a)/norm(c);
}
cm refl(ln a,cm b){
	return ld(2)*proj(a,b)-b;
}
//AOJ0153
ld dsp(ln a,cm b){
	cm c=proj(a,b);
	if(abs(bet(a.a,a.b,c))<=1)return abs(b-c);
	return min(abs(b-a.a),abs(b-a.b));
}
//AOJ1157
//0-no,1-yes(endpoint),2-yes(innner),3-overelap
//if the two line touch like this
// x----x----x
//it returns 1
int iss(ln a,ln b){
	int c1=ccw(a.a,a.b,b.a),c2=ccw(a.a,a.b,b.b);
	int d1=ccw(b.a,b.b,a.a),d2=ccw(b.a,b.b,a.b);
	if(c1||c2||d1||d2)return 1-max(c1*c2,d1*d2);
	int f=bet(a.a,a.b,b.a),g=bet(a.a,a.b,b.b);
	if(max(f,g)==-2||min(f,g)==2)return 0;
	if(max(f,g)==-1||min(f,g)==1)return 1;
	return 3;
}
//AOJ1033
cm cll(ln a,ln b){
	return eval(a,crs(b.a,b.b,a.a)/crs(dir(a),dir(b)));
}
//AOJ1157
ld dss(ln a,ln b){
	if(iss(a,b))return 0;
	return min({dsp(a,b.a),dsp(a,b.b),dsp(b,a.a),dsp(b,a.b)});
}
//AOJ2160
//
ln vbis(cm a,cm b){
	cm c=(a+b)*ld(0.5),d=b-a;
	return ln(c,cm(c.x-d.y,c.y+d.x));
}


//JAGSUMMER2019 E
//assume the ansewer is bounded
vc<cm> halfpint(vc<ln> s){
	sort(all(s),[&](ln a,ln b){
		int c=argcmp(dir(a),dir(b));
		if(c)return c<0;
		return ccw(b,a.a)>0;
	});
	s.erase(unique(all(s),[&](ln a,ln b){
		return argcmp(dir(a),dir(b))==0;
	}),s.ed);
	int n=s.size();
	vi cur;
	rep(ii,n*2){
		int i=ii%n,m;
		while((m=cur.size())>=2){
			if(ccw(s[i],cll(s[cur[m-2]],s[cur[m-1]]))>0)
				break;
			cur.pop_back();
		}
		cur.pb(i);
	}
	vi cnt(n);
	for(auto i:cur)cnt[i]++;
	vc<ln> t;
	rep(i,n)if(cnt[i]==2)
		t.pb(s[i]);
	int m=t.size();
	vc<cm> res(m);
	rep(i,m)
		res[i]=(cll(t[i],t[(i+1)%m]));
	return res;
}

ld area2(const vc<cm>&a){
	int n=a.size();
	ld b=0;
	rep(i,n)
		b+=crs(a[i],a[(i+1)%n]);
	return b;
}

cm readcm(){
	int a,b;cin>>a>>b;
	return cm(a,b);
}

void slv(){
	int n;cin>>n;
	n--;
	cm org=readcm();
	vc<cm> ps;
	rep(i,n)ps.pb(readcm()-org);
	sort(all(ps),argless);
	rep(i,n-1)if(ccw(ps[i],ps[i+1])==0){
		print(0);
		return;
	}
	vc<ln> ls;
	
	{
		int j=0;
		rep(i,n){
			chmax(j,i);
			while(1){
				int k=(j+1)%n;
				if(k==i)break;
				if(ccw(ps[i],ps[k])<0)break;
				j++;
			}
			if(i!=j%n)ls.eb(ps[i],ps[j%n]);
		}
	}
	rep(i,n){
		int j=(i+1)%n;
		if(ccw(ps[i],ps[j])>0)ls.eb(ps[i],ps[j]);
	}
	dmp(ls);
	
	for(auto&z:ls){
		z.a+=org;
		z.b+=org;
	}
	const int V=ten(6);
	{
		cm w[4]{
			{-V,-V},
			{V,-V},
			{V,V},
			{-V,V},
		};
		rep(i,4)ls.eb(w[i],w[(i+1)%4]);
	}
	auto res=halfpint(ls);
	cout<<area2(res)/2<<"\n";
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;
	rep(_,t)slv();
}