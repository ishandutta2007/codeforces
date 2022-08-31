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

using uint=unsigned;
using ull=unsigned long long;

//const uint mod=998244353;
const uint mod=1000000007;
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
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	mint inv()const{return pow(mod-2);}
	/*mint inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return mint(x);
	}*/
	friend ostream& operator<<(ostream&os,const mint&m){
		return os<<m.v;
	}
};

//KUPC2017I
//HDU 5306 Gorgeous Sequence
template<class N>
struct segbeats{
	vc<N> x;
	int s;
	segbeats(){}
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
	//return maximum index
	template<class F,class...Args>
	pair<int,N> findr(int i,int l,int r,int b,int e,F f,Args...args){
		if(e<=l||r<=b||!(x[i].*f)(args...))return {b-1,N()};
		if(b<=l&&r<=e&&r-l==1)
			return {l,x[i]};
		push(i);
		int m=(l+r)/2;
		auto a=findr(i*2+1,m,r,b,e,f,args...);
		if(b<=a.a)return a;
		return findr(i*2,l,m,b,e,f,args...);
	}
	template<class F,class...Args>
	pair<int,N> find(int b,int e,F f,Args...args){
		assert(b<e);
		return findr(1,0,s,b,e,f,args...);
	}
};

//usage

//Range add,max
struct N{
	int lz[2],mn[2];
	mint sm[4];
	N(pi c=pi(0,0)):lz{0,0},mn{c.a,c.b},sm{1,c.a,c.b,c.a*c.b}{}
	bool add(int k,int v){
		lz[k]+=v;
		sm[(1<<k)]+=sm[0]*v;
		sm[3]+=sm[(1<<k)^3]*v;
		mn[k]+=v;
		return true;
	}
	void push(N&x,N&y){
		rep(k,2){
			x.add(k,lz[k]);
			y.add(k,lz[k]);
			lz[k]=0;
		}
	}
	static N merge(N x,N y){
		N res;
		rep(k,4)
			res.sm[k]=x.sm[k]+y.sm[k];
		rep(k,2)
			res.mn[k]=min(x.mn[k],y.mn[k]);
		return res;
	}
	mint gets(){return sm[3];}
	bool find(int v){
		return min(mn[0],mn[1])<v;
	}
};

using Q=tuple<int,int,int>;

struct sgm{
	static int q;
	int x,y;
	bool operator<(const sgm&r)const{
		return pi(x,y)<pi(r.x,r.y);
	}
	bool operator<(int r)const{
		if(q)return x<r;
		else return y<r;
	};
};
int sgm::q;

struct ysp{
	set<sgm,less<>> s;
	ysp(int w,int h){
		s.insert(sgm{0,h});
		s.insert(sgm{w,h});
	}
	vc<Q> cm(int a,int b){
		{
			sgm::q=1;
			auto itr=s.lower_bound(a);
			if(itr->x>a)
				s.insert(sgm{a,prev(itr)->y});
		}
		sgm::q=0;
		auto itr=s.lower_bound(b);
		int fx=itr->x;
		if(fx>=a)return {};
		vc<Q> qs;
		while(itr->x<a){
			qs.eb(itr->x,next(itr)->x,b-itr->y);
			itr=s.erase(itr);
		}
		s.insert(sgm{fx,b});
		return qs;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vi a(n);
	rep(i,n)cin>>a[i];
	vi nx(n,-1),pr(n,-1);
	{
		map<int,int> pos;
		for(auto v:a)pos[v]=-1;
		rep(i,n){
			pr[i]=pos[a[i]];
			pos[a[i]]=i;
		}
	}
	{
		map<int,int> pos;
		for(auto v:a)pos[v]=n;
		per(i,n){
			nx[i]=pos[a[i]];
			pos[a[i]]=i;
		}
	}
	segbeats<N> seg;
	{
		vc<pi> d(n);
		rep(i,n)
			d[i]=pi(i,n);
		seg=segbeats<N>(d);
	}
	dmp(seg.get(0,n,&N::gets,[&](mint x,mint y){return x+y;},mint(0)));
	const auto upd=[&](int k,vc<Q> qs){
		for(auto w:qs){
			int l,r,v;
			tie(l,r,v)=w;
			if(v){
				dmp(k);
				dmp(l);
				dmp(r);
				dmp(v);
			}
			seg.ch(l,r,&N::add,k,v);
		}
	};
	ysp l(n,n),r(n,n);
	mint ans=0;
	rep(i,n){
		dmp(i);
		upd(0,l.cm(i+1,n-(pr[i]+1)));
		upd(1,r.cm(i+1,nx[i]));
		seg.ch(0,n,&N::add,1,-1);
		int j=seg.find(0,i+1,&N::find,0).a;
		dmp(j);
		if(j+1<i+1)
			ans+=seg.get(j+1,i+1,&N::gets,[&](mint x,mint y){return x+y;},mint(0));
		dmp(ans);
	}
	cout<<ans<<endl;
}