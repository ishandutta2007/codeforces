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

using ld=long double;

//CF658E
ld eval(const vc<ld>&f,ld x){
	ld a=0;
	per(i,si(f)){
		a*=x;
		a+=f[i];
	}
	return a;
}

ld err(ld a,ld b){
	return abs(a-b)/max({ld(1),abs(a),abs(b)});
}

//CF658E
//x 
vc<ld> interpolate_f(vc<ld>x,vc<ld>y){
	int n=si(x),raw=n;
	assert(si(y)==n);
	{
		assert(is_sorted(all(x)));
		int m=0;
		rep(i,n){
			if(m&&err(x[m-1],x[i])<=1e-6)continue;
			x[m]=x[i];
			y[m]=y[i];
			m++;
		}
		n=m;
		x.resize(m);
		y.resize(m);
	}
	vc<ld> res(n);
	vc<ld> cur(n+1);
	cur[0]=1;
	rep(i,n){
		per(j,i+1){
			cur[j+1]+=cur[j];
			cur[j]*=-x[i];
		}
	}
	vc<ld> tmp(n);
	rep(i,n){
		ld pre=0;
		per(j,n)pre=tmp[j]=cur[j+1]+pre*x[i];
		ld w=y[i]/eval(tmp,x[i]);
		rep(j,n)res[j]+=tmp[j]*w;
	}
	//dmp2(x,y,res);
	res.resize(raw);
	return res;
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

//AOJ1183
bool ips(const vc<cm>&a,ln b){
	int n=a.size();
	rep(i,n){
		cm c=a[(i+n-1)%n],d=a[i],e=a[(i+1)%n];
		if(iss(ln(c,d),b)==2)return 1;
		if(ccw(b,d)==0&&bet(b.a,b.b,d)==0){
			if(ccw(c,d,e)==1)return 1;
			if(ccw(b,c)*ccw(b,e)<0)return 1;
		}
	}
	return 0;
}

//GCJ2019R3D
//0-out,1-edge,2-in
int cont(const vc<cm>&a,cm b){
	int n=a.size();
	int res=0;
	rep(i,n){
		cm c=a[i],d=a[(i+1)%n];
		if(ccw(c,d,b)==0&&abs(bet(c,d,b))<=1)
			return 1;
		if(c.y>d.y)swap(c,d);
		if(sgn(b.y-c.y)>0&&sgn(d.y-b.y)>=0&&ccw(c,d,b)==1)
			res^=1;
	}
	return res*2;
}

ld area2(const vc<cm>&a){
	int n=a.size();
	ld b=0;
	rep(i,n)
		b+=crs(a[i],a[(i+1)%n]);
	return b;
}

//AOJ0068
//TCO 2017 final Hard
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

//AOJ1283
//convex cut
vc<cm> ccut(vc<cm> a,ln b){
	int n=a.size();
	vc<cm> c;
	rep(i,n){
		int j=(i+1)%n;
		int d=ccw(b,a[i]),e=ccw(b,a[j]);
		if(d>=0)c.pb(a[i]);
		if(d*e<0)c.pb(cll(b,ln(a[i],a[j])));
	}
	return c;
}

//CF658E
//(a,b)-(c,d) p 
ld intp2(ld a,ld b,ld c,ld d,ld p){
	return (b*(c-p)+d*(p-a))/(c-a);
}


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	cerr<<fixed<<setprecision(20);
	
	int n,q;cin>>n>>q;
	vc<cm> ps;
	rep(i,n){
		int a,b;cin>>a>>b;
		ps.eb(a,b);
	}
	ld sum=area2(ps)/2;
	if(sum<0){
		sum*=-1;
		reverse(all(ps));
	}
	vc<ld> ys;
	for(auto p:ps)ys.pb(p.y);
	mkuni(ys);
	int s=si(ys);
	vc<array<cm,4>> trap(s);
	
	rep(idx,n){
		cm a=ps[idx],b=ps[(idx+1)%n];
		int i=lwb(ys,a.y);
		int j=lwb(ys,b.y);
		if(i>j){
			rng(k,j,i){
				trap[k][0]=cm(intp2(a.y,a.x,b.y,b.x,ys[k+1]),ys[k+1]);
				trap[k][1]=cm(intp2(a.y,a.x,b.y,b.x,ys[k]),ys[k]);
			}
		}else{
			rng(k,i,j){
				trap[k][2]=cm(intp2(a.y,a.x,b.y,b.x,ys[k]),ys[k]);
				trap[k][3]=cm(intp2(a.y,a.x,b.y,b.x,ys[k+1]),ys[k+1]);
			}
		}
	}
	
	vc<pair<ld,array<ld,3>>> ads;
	rep(idx,s){
		vc<cm> a(all(trap[idx])),b=a;
		reverse(all(b));
		for(auto&p:b)p=cm(-p.x,p.y);
		
		auto shiftarea=[&](ld w){
			auto c=a;
			rep(i,4){
				c=ccut(c,ln(cm(b[i].x+w,b[i].y),cm(b[(i+1)%4].x+w,b[(i+1)%4].y)));
			}
			return area2(c)/2;
		};
		
		vc<ld> ws;
		rep(i,4)rep(j,4)ws.pb(a[i].x-b[j].x);
		mkuni(ws);
		
		ld c=0;
		array<ld,3> pre{};
		rep(i,si(ws)-1){
			ld f=ws[i],h=ws[i+1];
			ld g=(f+h)/2;
			ld d=shiftarea(g);
			ld e=shiftarea(h);
			
			auto poly=interpolate_f({f,g,h},{c,d,e});
			array<ld,3> sub;
			rep(j,3){
				sub[j]=poly[j]-pre[j];
				pre[j]=poly[j];
			}
			ads.eb(ws[i],sub);
			c=e;
		}
		assert(sgn(c)==0);
		rep(j,3)pre[j]=-pre[j];
		ads.eb(ws.back(),pre);
	}
	vc<ld> xs;
	for(auto kv:ads)xs.pb(kv.a);
	mkuni(xs);
	int len=si(xs);
	vc<vc<ld>> f(len,vc<ld>(3));
	for(auto kv:ads){
		int i=lwb(xs,kv.a);
		rep(j,3)f[i][j]+=kv.b[j];
	}
	rep(i,len-1){
		rep(j,3)f[i+1][j]+=f[i][j];
	}
	rep(_,q){
		ld v;cin>>v;
		v*=2;
		int i=lwb(xs,v);
		i--;
		if(i<0)i=0;
		assert(i<len);
		ld common=eval(f[i],v);
		cout<<sum-common/2<<"\n";
	}
}