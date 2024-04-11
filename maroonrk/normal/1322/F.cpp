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
//KUPC2017J
//AOJDSL1A
//without rank
struct unionfind{
	vi p,s;
	int c;
	unionfind(int n=0):p(n,-1),s(n,1),c(n){}
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

//AOJGRL4B
template<class t>
vi toposort(vvc<t> g){
	int n=g.size();
	vi a(n);
	rep(i,n)for(auto e:g[i])
		a[e]++;
	queue<int> q;
	rep(i,n)if(a[i]==0)
		q.push(i);
	vi res;
	rep(i,n){
		if(q.empty())return {};
		int v=q.front();q.pop();
		res.pb(v);
		for(auto e:g[v])
			if(--a[e]==0)
				q.push(e);
	}
	return res;
}


// in,out 
//VERIFY: yosupo
//CF530F
//CodeChef Persistent Oak
//AOJ GRL5C
template<class E>
struct HLD{
	vvc<E> g;
	int n,rt,cnt;
	vi sub,in,out,par,head,dep;
	int dfs1(int v,int p,int d){
		par[v]=p;
		dep[v]=d;
		g[v].erase(remove(all(g[v]),p),g[v].ed);
		for(auto&e:g[v]){
			sub[v]+=dfs1(e,v,d+1);
			if(sub[g[v][0]]<sub[e])
				swap(g[v][0],e);
		}
		return sub[v];
	}
	void dfs2(int v,int h){
		in[v]=cnt++;
		head[v]=h;
		for(int to:g[v])
			dfs2(to,to==g[v][0]?h:to);
		out[v]=cnt;
	}
	HLD(){}
	HLD(const vvc<E>&gg,int rr):g(gg),n(g.size()),rt(rr),cnt(0),
		sub(n,1),in(n),out(n),par(n,-1),head(n),dep(n){
		dfs1(rt,-1,0);
		dfs2(rt,rt);
	}
	int lca(int a,int b){
		while(head[a]!=head[b]){
			if(dep[head[a]]>dep[head[b]])
				swap(a,b);
			b=par[head[b]];
		}
		if(dep[a]>dep[b])
			swap(a,b);
		return a;
	}
	int len(int a,int b){
		return dep[a]+dep[b]-dep[lca(a,b)]*2;
	}
	bool asde(int a,int b){
		return in[a]<=in[b]&&out[b]<=out[a];
	}
	unionfind uf;
	vi has,dif;
	int k;
	vc<pi> buf;
	int ac(int v){
		return uf.find(v*2)/2;
	}
	vi memo;
	int dfs(int v){
		for(auto to:g[v]){
			memo[to]=dfs(to);
		}
		buf[ac(v)]=pi(0,k);
		for(auto to:g[v]){
			buf[ac(to)]=pi(0,k);
		}
		//if(v==0)dmp(0);
		for(auto to:g[v]){
			int w=memo[to];
			if(w==inf)return inf;
			int i=uf.find(to*2);
			int t=i%2;
			i/=2;
			if(!has[i])continue;
			if(t==0){
				chmax(buf[i].a,w+1);
			}else{
				chmin(buf[i].b,k-w-1);
			}
			/*if(v==0){
				dmp(to);
				dmp(w);
				dmp(buf[ac(1)]);
			}*/
			if(buf[i].b<buf[i].a)return inf;
		}
		rep(waf,2){
			int vac=uf.find(v*2);
			int vt=vac%2;
			vac/=2;
			int lw,up;tie(lw,up)=buf[vac];
			if(vt){
				tie(lw,up)=pi(k-up,k-lw);
			}
			for(auto to:g[v]){
				int i=uf.find(to*2);
				int t=i%2;
				i/=2;
				if(!has[i])continue;
				dif[to]=t;
				if(i==vac){
					dif[to]^=vt;
					continue;
				}
				int l,r;tie(l,r)=buf[i];
				if((k-r<l)^waf){
					tie(l,r)=pi(k-r,k-l);
					dif[to]^=1;
				}
				chmax(lw,l);
				chmin(up,r);
			}
			if(lw<=up){
				dmp2(v,lw,up);
				return lw;
			}
		}
		return inf;
	}
	void geth(int v,int p,int t,vvc<int>&h){
		if(has[ac(v)]){
			if(t==0){
				h[v].pb(p);
			}else{
				h[p].pb(v);
			}
		}
		for(auto to:g[v]){
			geth(to,v,t^dif[to],h);
		}
	}
	void slv(int m){
		uf=unionfind(n*2);
		auto unitesub=[&](int v,int p){
			while(1){
				v=ac(v);
				dmp2(v,p);
				if(dep[v]-dep[p]>=2){
					dmp2(v,par[v]);
					rep(t,2){
						uf.unite(par[v]*2+t,v*2+t);
					}
					v=par[v];
				}else
					break;
			}
		};
		vi ls;
		vc<pi> es;
		rep(_,m){
			int a,b;cin>>a>>b;
			a--;b--;
			int c=lca(a,b);
			unitesub(a,c);
			unitesub(b,c);
			if(a!=c&&b!=c){
				//uf.unite(a*2,b*2+1);
				//uf.unite(a*2+1,b*2);
				es.eb(a,b);
			}
			if(a!=c)ls.pb(a);
			else ls.pb(b);
		}
		for(auto e:es){
			rep(t,2){
				uf.unite(e.a*2+t,e.b*2+1-t);
			}
		}
		has.resize(n);
		for(auto i:ls)
			has[ac(i)]=1;
		rep(i,n)if(uf.same(i*2,i*2+1)){
			print(-1);
			return;
		}
		dif.resize(n);
		buf.resize(n);
		memo.resize(n);
		
		/*{
			k=1;
			dfs(0);
			exit(0);
		}*/
		
		int lw=-1,up=n-1;
		while(up-lw>1){
			const int mid=(lw+up)/2;
			k=mid;
			if(dfs(0)<inf)
				up=mid;
			else
				lw=mid;
		}
		k=up;
		dmp(k);
		int tmp=dfs(0);
		dmp2(k,tmp);
		assert(tmp<inf);
		
		dmp(dif);
		
		vvc<int> h(n);
		geth(0,-1,0,h);
		dmp(h);
		dmp(has[ac(1)]);
		dmp(has[ac(2)]);
		
		vi ans(n);
		
		vi ord=toposort(h);
		for(auto i:ord){
			for(auto j:h[i])
				chmax(ans[j],ans[i]+1);
		}
		
		for(auto&v:ans)v++;
		print(k+1);
		print(ans);
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	vvc<int> t(n);
	rep(_,n-1){
		int a,b;cin>>a>>b;
		a--;b--;
		t[a].pb(b);
		t[b].pb(a);
	}
	
	HLD<int> hld(t,0);
	hld.slv(m);
}