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

template<class t>
bool inc(t a,t b,t c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
	//#ifdef LOCAL
	static mt19937_64 gen;
	//#else
	//static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	//#endif
	return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

//VERIFY: yosupo
//KUPC2017J
//AOJDSL1A
//without rank
struct unionfind{
	vi p,s;
	int c;
	unionfind(int n):p(n,-1),s(n,1),c(n){}
	int find(int a){
		return p[a]==-1?a:(p[a]=find(p[a]));
	}
	//set b to a child of a
	bool unite(int a,int b){
		a=find(a);
		b=find(b);
		if(a==b)return false;
		p[b]=a;
		s[a]+=s[b];
		c--;
		return true;
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
	int sz(int a){
		return s[find(a)];
	}
};

//AOJGRL2B
//yosupo judge
//others->root
//assume the answer exits
template<class D>
struct dirmst{
	struct E{
		int to,id;
		D cost;
		bool operator<(const E&e)const{
			//
			return cost>e.cost;
		}
	};
	struct Q{
		using pq=priority_queue<E>;
		pq* q;
		D off;
		Q():q(new pq()),off(0){}
		~Q(){delete q;}
		void push(E e){
			q->push(e);
		}
		void merge(Q& x){
			if(q->size()<x.q->size()){
				swap(q,x.q);
				swap(off,x.off);
			}
			while(x.q->size()){
				E e=x.q->top();
				x.q->pop();
				e.cost+=x.off-off;
				q->push(e);
			}
		}
		E pop(){
			E e=q->top();
			q->pop();
			e.cost+=off;
			return e;
		}
	};
	int n,m;
	vc<Q> g;
	vi st,ci,fi,src;
	vc<D> cc;
	dirmst(int nn):n(nn),m(0),g(n),
		st(n),ci(n,-1),fi(n,-1),cc(n){}
	void ae(int s,int t,D d){
		src.pb(s);
		g[s].push({t,m++,d});
	}
	pair<D,vi> calc(int rt){
		st[rt]=2;
		vi p(m),idx;
		unionfind uf(n);
		D ans=0;
		rep(i,n)if(!st[i]){
			vi vs{i};
			st[i]=1;
			vi ch;
			while(1){
				int a=vs.back();
				E e=g[a].pop();
				cc[a]=e.cost;
				ans+=e.cost;
				ci[a]=e.id;
				if(fi[a]==-1)
					fi[a]=e.id;
				for(auto c:ch)
					p[c]=e.id;
				ch.clear();
				idx.pb(e.id);
				int to=uf.find(e.to);
				if(st[to]==0){
					vs.pb(to);
					st[to]=1;
				}else if(st[to]==1){
					int r=vs.size(),l=r-1;
					while(vs[l]!=to)
						l--;
					rng(j,l,r){
						g[vs[j]].off-=cc[vs[j]];
						if(l<j){
							g[vs[l]].merge(g[vs[j]]);
							uf.unite(vs[l],vs[j]);
						}
					}
					rng(j,l,r)
						ch.pb(ci[vs[j]]);
					vs.resize(l+1);
				}else{
					break;
				}
			}
			for(auto v:vs)
				st[v]=2;
		}
		
		vi tmp,waf(m);
		reverse(all(idx));
		for(auto i:idx)if(!waf[i]){
			tmp.pb(i);
			int x=fi[src[i]];
			while(x!=i){
				waf[x]=1;
				x=p[x];
			}
		}
		
		return make_pair(ans,tmp);
	}
};


struct E{
	int a,b,c;
};
pair<int,vi> mst(int n,vc<E> es){
	unionfind uf(n);
	vi idx(es.size());
	iota(all(idx),0);
	sort(all(idx),[&](int i,int j){return es[i].c>es[j].c;});
	int ans=0;
	vi used;
	for(auto i:idx)
		if(uf.unite(es[i].a,es[i].b)){
			ans+=es[i].c;
			used.pb(i);
		}
	return {ans,used};
}

using T=tuple<int,int,int>;

struct ysp{
	T x[2];
	ysp(){
		rep(k,2)x[k]=T(-1,-1,-1);
	}
	void upd(T v){
		rep(k,2)if(get<1>(x[k])==get<1>(v)){
			chmax(x[k],v);
			if(x[0]<x[1])swap(x[0],x[1]);
			return;
		}
		rep(k,2)
			if(x[k]<v)swap(x[k],v);
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	const int L=18;
	const int S=1<<L;
	const int M=S-1;
	
	int n;cin>>n;
	bool dbg=n<0;
	vi a;
	if(dbg){
		n=-n;
		a.resize(n);
		rep(i,n)a[i]=rand_int(0,M);
	}else
		a=readvi(n);
	
	vc<E> es;
	rep(i,n)es.pb(E{i,n,a[i]});
	
	unionfind uf(n);
	while(1){
		vc<ysp> mori(S);
		vi tmp(n);
		rep(i,n)tmp[i]=uf.find(i);
		rep(i,n){
			mori[a[i]].upd(T(a[i],tmp[i],i));
		}
		rep(i,L)rep(j,S)if(!(j&1<<i))rep(k,2)mori[j|1<<i].upd(mori[j].x[k]);
		bool add=false;
		vc<T> mx(n,T(-1,-1,-1));
		rep(i,n){
			T w=mori[M-a[i]].x[0];
			if(get<1>(w)==tmp[i])
				w=mori[M-a[i]].x[1];
			if(get<1>(w)==-1)continue;
			add=true;
			chmax(mx[tmp[i]],T(a[i]+get<0>(w),i,get<2>(w)));
		}
		if(!add)break;
		rep(i,n)if(tmp[i]==i){
			int a,b,c;tie(c,a,b)=mx[i];
			if(c!=-1){
				uf.unite(a,b);
				es.pb(E{a,b,c});
			}
		}
	}
	
	int ans=mst(n+1,es).a;
	if(0){
		vc<E> z;
		rep(i,n)z.pb(E{i,n,a[i]});
		rep(i,n)rep(j,i)if((a[i]&a[j])==0){
			z.pb(E{i,j,a[i]+a[j]});
		}
		int tmp=mst(n+1,z).a;
		assert(ans==tmp);
	}
	ans-=accumulate(all(a),int(0));
	cout<<ans<<endl;
}