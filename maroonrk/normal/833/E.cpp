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

//VERIFY: yosupo
//CF Global3 H
//ARC073 F
//point update
template<class T,class F>
struct SegTree{
	vc<T> buf;
	int s;
	const F f;
	const T g;
	SegTree(F ff,T gg):f(ff),g(gg){}
	void init(const vc<T>& d){
		int n=d.size();
		s=1;
		while(s<n)s*=2;
		buf.resize(s*2,g);
		rep(i,n)
			buf[i+s]=d[i];
		gnr(i,1,s)
			u(i);
	}
	SegTree(const vc<T>& d,F ff,T gg):f(ff),g(gg){
		init(d);
	}
	void u(int i){
		buf[i]=f(buf[i*2],buf[i*2+1]);
	}
	void set(int i,T t){
		i+=s;
		buf[i]=t;
		while(i>>=1)u(i);
	}
	void upd(int i,T t){
		i+=s;
		buf[i]=f(buf[i],t);
		while(i>>=1)u(i);
	}
	T get(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)return g;
		if(b<=l&&r<=e)return buf[i];
		int m=(l+r)/2;
		return f(get(b,e,l,m,i*2),get(b,e,m,r,i*2+1));
	}
	T get(int b,int e){
		return get(b,e,0,s,1);
	}
};
template<class T,class F>
SegTree<T,F> segtree(const vc<T>& d,F f,T g){
	return SegTree<T,F>(d,f,g);
}

struct Rng{
	int l,r,c;
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,cap;cin>>n>>cap;
	vi ps{0,2*ten(9)};
	vc<Rng> rw;
	rep(i,n){
		int l,r,c;cin>>l>>r>>c;
		ps.pb(l);
		ps.pb(r);
		rw.pb({l,r,c});
	}
	mkuni(ps);
	
	vvc<int> qs(si(ps)-1);
	rep(i,n){
		qs[lwb(ps,rw[i].l)].pb(i*2);
		qs[lwb(ps,rw[i].r)].pb(i*2+1);
	}
	vc<pi> del;
	vi vs{0};
	vvc<int> idx;
	{
		int cur=0;
		set<int> s;
		rep(i,si(qs)){
			for(auto j:qs[i]){
				if(j%2){
					s.erase(j/2);
				}else{
					s.insert(j/2);
				}
			}
			bool ok=true;
			if(si(s)>2)ok=false;
			else{
				vi z(all(s));
				int sum=0;
				for(auto j:z)
					sum+=rw[j].c;
				if(sum>cap)ok=false;
				else{
					cur+=ps[i+1]-ps[i];
					if(si(idx)&&idx.back()==z)
						vs.back()=cur;
					else{
						vs.pb(cur);
						idx.pb(z);
					}
				}
			}
			if(!ok){
				del.eb(cur,ps[i+1]-ps[i]);
			}
		}
	}
	
	dmp(vs);
	dmp(idx);
	dmp(del);
	
	int delsum=0,delhead=0;
	auto getdel=[&](int p){
		while(delhead<si(del)&&p>del[delhead].a){
			delsum+=del[delhead++].b;
		}
		return delsum;
	};
	
	int m;cin>>m;
	vc<pi> waf(m);
	rep(i,m)waf[i]=pi(read(),i);
	sort(all(waf));
	int head=0;
	vi ans(m);
	
	auto upd=[&](int l,int r,int w){
		while(head<m&&waf[head].a<=w+r-l){
			int dif=waf[head].a-w;
			if(dif<=0){
				dmp(w);
				dmp(waf[head]);
			}
			assert(dif>0);
			int pos=l+dif;
			ans[waf[head++].b]=pos+getdel(pos);
		}
	};
	
	int global=0,off=0;
	vi len(n),add(n);
	vc<pi> ci(n);
	rep(i,n)ci[i]=pi(rw[i].c,i);
	sort(all(ci));
	auto seg=segtree(vi(n,0),[](int a,int b){return max(a,b);},0LL);
	rep(i,si(idx)){
		int k=vs[i+1]-vs[i];
		if(si(idx[i])==0){
			upd(vs[i],vs[i+1],global+off);
			off+=k;
		}else if(si(idx[i])==1){
			int a=idx[i][0];
			int f=lwb(ci,pi(rw[a].c,a));
			int lim=lwb(ci,pi(cap-rw[a].c,inf));
			int mx=seg.get(0,min(f,lim));
			if(f+1<lim)chmax(mx,seg.get(f+1,lim));
			upd(vs[i],vs[i+1],len[a]+max(mx,add[a])+off);
			len[a]+=k;
			chmax(global,len[a]+add[a]);
			chmax(global,len[a]+mx);
			seg.upd(f,len[a]);
		}else{
			int a=idx[i][0],b=idx[i][1];
			upd(vs[i],vs[i+1],len[a]+len[b]+off);
			chmax(add[a],len[b]+k);
			chmax(add[b],len[a]+k);
			chmax(global,len[a]+len[b]+k);
		}
	}
	
	for(auto v:ans)
		print(v);
}