#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

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

//change LG
//up to size 1<<LG
static const int LG=19;
using R=double;
using C=complex<R>;

C roots[1<<(LG+1)],iroots[1<<(LG+1)];
struct PrepareRoots{
	PrepareRoots(){
		const R P=2*acos(-1);
		rep(w,LG+1){
			const int s=(1<<w)-1;
			rep(i,1<<w){
				const R a=P/(1<<w)*i;
				roots[s+i]=C(cos(a),sin(a));
				iroots[s+i]=conj(roots[s+i]);
			}
		}
	}
} PrepareRootsDummy;

C& operator*=(C &a,const C&b){
	return a=C(a.real()*b.real()-a.imag()*b.imag(),a.real()*b.imag()+a.imag()*b.real());
}

/*void inplace_fft(vc<C>&f,bool inv){
	static const R P=acos(-1);
	static C r[S],ir[S];
	static bool did=false;
	if(!did){
		rep(i,S){
			R a=2*P/S*i;
			r[i]=C(cos(a),sin(a));
			ir[i]=conj(r[i]);
		}
		did=true;
	}
	const int n=f.size();
	vc<C> g(n);
	for(int b=n/2;b>=1;b/=2){
		int w=S/(n/b),p=0;
		for(int i=0;i<n;i+=b*2){
			rep(j,b){
				f[i+j+b]*=inv?ir[p]:r[p];
				g[i/2+j]=f[i+j]+f[i+b+j];
				g[n/2+i/2+j]=f[i+j]-f[i+b+j];
			}
			p+=w;
		}
		swap(f,g);
	}
	if(inv)rep(i,n)
		f[i]/=n;
}*/

/*
//for doubles
vc<C> convolution(vc<C> x,vc<C> y){
	int n=x.size()+y.size()-1;
	int s=1;
	while(s<n)s*=2;
	x.resize(s);inplace_fft(x,false);
	y.resize(s);inplace_fft(y,false);
	rep(i,s)
		x[i]*=y[i];
	inplace_fft(x,true);x.resize(n);
	return x;
}

template<class D>
vc<D> multiply(const vc<D>&x,const vc<D>&y){
	const auto ch=[&](const vc<D>& v){
		vc<C> r(v.size());
		rep(i,v.size())
			r[i]=v[i];
		return r;
	};
	auto z=convolution(ch(x),ch(y));
	vc<D> r(z.size());
	rep(i,z.size())
		r[i]=z[i].real();
	return r;
}

R invs[S];
struct InitRInvs{
	InitRInvs(){
		rng(i,1,S)
			invs[i]=1/i;
	}
} InitRInvsDummy;*/

#define USE_BROKEN_FFT
void broken_fft(C*f,const int n){
	for(int b=n/2;b>=1;b/=2){
		for(int i=0;i<n;i+=b*2){
			rep(j,b){
				C tmp=f[i+j]-f[i+j+b];
				f[i+j]+=f[i+j+b];
				f[i+j+b]=tmp*roots[b*2-1+j];
			}
		}
	}
}

void broken_ifft(C*f,const int n){
	for(int b=1;b<=n/2;b*=2){
		for(int i=0;i<n;i+=b*2){
			rep(j,b){
				f[i+j+b]*=iroots[b*2-1+j];
				C tmp=f[i+j]-f[i+j+b];
				f[i+j]+=f[i+j+b];
				f[i+j+b]=tmp;
			}
		}
	}
	rep(i,n)
		f[i]/=n;
}

void inplace_fft(C*f,const int n,bool inv){
	if(!inv)broken_fft(f,n);
	else broken_ifft(f,n);
}

using mint=ull;
vc<mint> multiply(const vc<mint>&x,const vc<mint>&y,bool same=false){
	const int B=15;
	int n=x.size()+y.size()-1;
	vc<mint> r(n);
	/*if(x.size()<=32||y.size()<=32){
		rep(i,x.size())rep(j,y.size())
			r[i+j]+=x[i]*y[j];
		return r;
	}*/
	int s=1;
	while(s<n)s*=2;
	const auto ch=[&](const vc<mint>&v,C*w){
		rep(i,v.size())
			w[i]=C(v[i]&((1<<B)-1),v[i]>>B);
		rng(i,v.size(),s)
			w[i]=0;
		inplace_fft(w,s,false);
	};
	static C a[1<<LG],b[1<<LG],c[1<<LG],d[1<<LG];
	ch(x,a);
	if(!same)
		ch(y,b);
	else
		copy(a,a+s,b);
	rep(i,s){
		#ifdef USE_BROKEN_FFT
		int j=i==0?0:i^((1<<topbit(i))-1);
		#else
		int j=(s-i)%s;
		#endif
		C xl=(a[i]+conj(a[j]))*C(0.5,0);
		C xh=(a[i]-conj(a[j]))*C(0,-0.5);
		c[i]=xl*b[i];
		d[i]=xh*b[i];
	}
	inplace_fft(c,s,true);
	inplace_fft(d,s,true);
	rep(i,n){
		r[i]=mint(c[i].real()+.5)
			+mint(c[i].imag()+.5)*(1<<B)
			+mint(d[i].real()+.5)*(1<<B)
			+mint(d[i].imag()+.5)*(1<<B*2);
	}
	return r;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	int x;cin>>x;
	
	ull z=0;
	vc<ull> cnt(n+1);
	{
		int sum=0;
		cnt[0]++;
		uint num=0;
		rep(i,n){
			if(read()<x){
				sum++;
				num=0;
			}else{
				num++;
				z+=num;
			}
			cnt[sum]++;
		}
	}
	vc<ull> tnc(n+1);
	rep(i,n+1)tnc[i]=cnt[n-i];
	
	auto c=multiply(cnt,tnc);
	vc<ull> ans(n+1);
	ans[0]=z;
	rng(i,1,n+1)ans[i]=c[n+i];
	print(ans);
}