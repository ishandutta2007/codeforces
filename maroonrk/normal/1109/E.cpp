#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(a>b)a=b;}

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

int extgcd(int a,int b,int&x,int&y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}else{
		int g=extgcd(b,a%b,y,x);
		y-=a/b*x;
		return g;
	}
}

using uint=unsigned;
using ull=unsigned long long;

//const uint mod=998244353;
//const uint mod=1000000007;
uint mod;
struct mint{
	uint v;
	mint(ll vv=0){s(vv%mod+mod);}
	mint& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	mint operator-()const{return mint()-*this;}
	mint& operator+=(const mint&rhs){return s(v+rhs.v);}
	mint&operator-=(const mint&rhs){return s(v+mod-rhs.v);}
	mint&operator*=(const mint&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	mint&operator/=(const mint&rhs){return *this*=rhs.inv();}
	mint operator+(const mint&rhs)const{return mint(*this)+=rhs;}
	mint operator-(const mint&rhs)const{return mint(*this)-=rhs;}
	mint operator*(const mint&rhs)const{return mint(*this)*=rhs;}
	mint operator/(const mint&rhs)const{return mint(*this)/=rhs;}
	mint pow(int n)const{
		mint res(1),x(*this);
		while(n){
			dmp(n);
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	//mint inv()const{return pow(mod-2);}
	mint inv()const{
		dmp(v);
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		dmp(x);
		return mint(x);
	}
	friend ostream& operator<<(ostream&os,const mint&m){
		return os<<m.v;
	}
};

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}

struct BIT{
	vi buf;
	int s;
	BIT(int n=0){init(n);}
	void init(int n){buf.assign(s=n,0);}
	void add(int i,int v){
		for(;i<s;i+=(i+1)&(-i-1))
			buf[i]+=v;
	}
	void addrng(int b,int e,int v){
		add(b,v);
		add(e,-v);
	}
	int get(int i){
		int res=0;
		for(;i>=0;i-=(i+1)&(-i-1))
			res+=buf[i];
		return res;
	}
};

//KUPC2017I
//HDU 5306 Gorgeous Sequence
template<class N>
struct segbeats{
	vc<N> x;
	int s;
	template<class T>
	segbeats(const vc<T>& a){
		int n=a.size();
		s=1;
		while(s<n)s*=2;
		x.resize(s*2);
		rep(i,n)
			x[s+i]=N(a[i]);
		gnr(i,1,s)
			upd(i);
	}
	void push(int i){
		x[i].push(x[i*2],x[i*2+1]);
	}
	void upd(int i){
		x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	template<class F,class... Args>
	void chr(int l,int r,int i,int b,int e,F f,Args... args){
		if(e<=l||r<=b)
			return;
		if(b<=l&&r<=e&&(x[i].*f)(args...))
			return;
		push(i);
		int m=(l+r)/2;
		chr(l,m,i*2,b,e,f,args...);
		chr(m,r,i*2+1,b,e,f,args...);
		upd(i);
	}
	template<class F,class... Args>
	void ch(int b,int e,F f,Args... args){
		assert(b<e);
		chr(0,s,1,b,e,f,args...);
	}
	//use decltype((declval<N>().*F())()) for old-fashioned judges
	template<class F,class G,class H>
	auto getr(int l,int r,int i,int b,int e,F f,G g,H h){
		if(e<=l||r<=b)
			return h;
		if(b<=l&&r<=e)
			return (x[i].*f)();
		push(i);
		int m=(l+r)/2;
		return g(getr(l,m,i*2,b,e,f,g,h),getr(m,r,i*2+1,b,e,f,g,h));
	}
	template<class F,class G,class H>
	auto get(int b,int e,F f,G g,H h){
		assert(b<e);
		return getr(0,s,1,b,e,f,g,h);
	}
};

//usage

//Range add,max
struct N{
	mint lz,sm;
	N(mint v=0):lz(1),sm(v){}
	bool mult(mint v){
		lz*=v;
		return true;
	}
	bool set(mint v){
		lz=1;
		sm=v;
		return true;
	}
	void push(N&x,N&y){
		x.mult(lz);
		y.mult(lz);
		sm*=lz;
		lz=1;
	}
	static N merge(N x,N y){
		return N(x.gets()+y.gets());
	}
	mint gets(){return sm*lz;}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;
	cin>>n>>mod;
	vi ps;
	{
		int x=mod;
		for(int i=2;i*i<=x;i++){
			if(x%i==0){
				ps.pb(i);
				while(x%i==0)x/=i;
			}
		}
		if(x>1)
			ps.pb(x);
	}
	int m=ps.size();
	const auto waf=[&](int v){
		vi res(m+1);
		rep(i,m){
			while(v%ps[i]==0){
				res[i]++;
				v/=ps[i];
			}
		}
		res[m]=v;
		return res;
	};
	vi a(n);
	rep(i,n)cin>>a[i];
	vc<BIT> bits(m,BIT(n));
	vi b(n);
	rep(i,n){
		auto w=waf(a[i]);
		rep(j,m)
			bits[j].addrng(i,i+1,w[j]);
		b[i]=w[m];
	}
	segbeats<N> seg(a),seg2(b);
	int q;cin>>q;
	rep(_,q){
		dmp(_);
		int t;cin>>t;
		if(t==1){
			int l,r,x;cin>>l>>r>>x;
			l--;
			vi w=waf(x);
			rep(j,m)
				bits[j].addrng(l,r,w[j]);
			seg.ch(l,r,&N::mult,mint(x));
			seg2.ch(l,r,&N::mult,mint(w[m]));
		}else if(t==2){
			int p,val;cin>>p>>val;
			p--;
			vi w=waf(val);
			mint nx=1;
			dmp(0);
			rep(j,m){
				bits[j].addrng(p,p+1,-w[j]);
				dmp(0);
				nx*=mint(ps[j]).pow(bits[j].get(p));
				dmp(0);
			}
			dmp(0);
			{
				mint v=seg2.get(p,p+1,&N::gets,[](mint x,mint y){return x+y;},mint(0));
				v/=w[m];
				seg2.ch(p,p+1,&N::set,v);
				nx*=v;
			}
			dmp(0);
			seg.ch(p,p+1,&N::set,nx);
		}else{
			int l,r;cin>>l>>r;
			l--;
			cout<<seg.get(l,r,&N::gets,[](mint x,mint y){return x+y;},mint(0))<<"\n";
		}
	}
}