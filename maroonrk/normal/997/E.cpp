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
#define dmp2(...) dmpr(cerr,"Line:",__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

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

void print(ll x,int suc=1){
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
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
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

//b==e 

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
	//return minimum index
	template<class F,class...Args>
	pair<int,N> findr(int i,int l,int r,int b,int e,F f,Args&&...args){
		if(e<=l||r<=b)return {e,N()};
		if(b<=l&&r<=e){
			if(!(x[i].*f)(forward<Args>(args)...))return {e,N()};
			if(r-l==1)return {l,x[i]};
		}
		push(i);
		int m=(l+r)/2;
		auto a=findr(i*2,l,m,b,e,f,forward<Args>(args)...);
		if(a.a<e)return a;
		return findr(i*2+1,m,r,b,e,f,forward<Args>(args)...);
	}
	template<class F,class...Args>
	pair<int,N> find(int b,int e,F f,Args&&...args){
		assert(b<e);
		return findr(1,0,s,b,e,f,forward<Args>(args)...);
	}
	//NOT VERIFIED
	/*
	//return maximum index
	template<class F,class...Args>
	pair<int,N> findr(int i,int l,int r,int b,int e,F f,Args&&...args){
		if(e<=l||r<=b)return {b-1,N()};
		if(b<=l&&r<=e){
			if(!(x[i].*f)(args...))return {b-1,N()};
			if(r-l==1)return {l,x[i]};
		}
		push(i);
		int m=(l+r)/2;
		auto a=findr(i*2+1,m,r,b,e,f,forward<Args>(args)...);
		if(a.a>=b)return a;
		return findr(i*2,l,m,b,e,f,forward<Args>(args)...);
	}
	template<class F,class...Args>
	pair<int,N> find(int b,int e,F f,Args&&...args){
		assert(b<e);
		return findr(1,0,s,b,e,f,forward<Args>(args)...);
	}
	*/
};

//Range add,max
struct N{
	int lz,mn,mncnt,val,sum;
	N(int v=0):lz(0),mn(v),mncnt(1),val(0),sum(0){}
	bool addmn(int v){
		lz+=v;
		mn+=v;
		return true;
	}
	bool addval(int v,int tar){
		if(mn!=tar)return true;
		val+=v;
		sum+=v*mncnt;
		return true;
	}
	void push(N&x,N&y){
		x.addmn(lz);
		y.addmn(lz);
		lz=0;
		x.addval(val,mn);
		y.addval(val,mn);
		val=0;
	}
	static N merge(N x,N y){
		N res;
		res.mn=min(x.mn,y.mn);
		res.mncnt=0;
		if(res.mn==x.mn)
			res.mncnt+=x.mncnt;
		if(res.mn==y.mn)
			res.mncnt+=y.mncnt;
		res.sum=x.sum+y.sum;
		return res;
	}
	int getm(){return mn;}
	int gets(){return sum;}
	N self(){return *this;}
};

struct ysp{
	vc<pi> z;
	ysp(int n):z{pi(n,n)}{}
	vc<tuple<int,int,int>> add(int x,int y){
		vc<tuple<int,int,int>> res;
		while(1){
			int s=z.size();
			if(z[s-1].b>y)break;
			res.eb(z[s-1].a,z[s-2].a,-z[s-1].b);
			z.pop_back();
		}
		res.eb(x,z.back().a,y);
		z.eb(x,y);
		return res;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vi p=readvi(n,-1);
	
	int q;cin>>q;
	vvc<pi> qs(n);
	vi ans(q);
	rep(i,q){
		int l,r;cin>>l>>r;
		l--;
		qs[l].eb(r,i);
	}
	
	ysp up(n),lw(n);
	segbeats<N> seg(vi(n,0));
	rep(i,n)
		seg.ch(i,i+1,&N::addmn,-(n-1)-i);
	per(i,n){
		auto x=up.add(i,p[i]);
		dmp(x);
		auto y=lw.add(i,n-1-p[i]);
		dmp(y);
		for(auto z:{x,y}){
			for(auto w:z){
				int l,r,v;
				tie(l,r,v)=w;
				seg.ch(l,r,&N::addmn,v);
			}
		}
		//dmp(seg.get(i,n,&N::getm,[](int a,int b){return min(a,b);},inf));
		//assert(seg.get(i,n,&N::getm,[](int a,int b){return min(a,b);},inf)==-i);
		/*{
			N tmp=seg.get(i,n,&N::self,&N::merge,N(inf));
			dmp(tmp.mn);
			dmp(tmp.mncnt);
		}*/
		seg.ch(i,n,&N::addval,1,-i);
		for(auto w:qs[i]){
			ans[w.b]=seg.get(i,w.a,&N::gets,[](int a,int b){return a+b;},int(0));
		}
	}
	
	for(auto v:ans)
		print(v);
}