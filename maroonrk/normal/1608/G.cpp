#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

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

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

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

pi readpi(int off=0){
	int a,b;cin>>a>>b;
	return pi(a+off,b+off);
}

template<class t,class u>
void print(const pair<t,u>&p,int suc=1){
	print(p.a,2);
	print(p.b,suc);
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

template<class T>
void print_offset(const vector<T>&v,ll off,int suc=1){
	rep(i,v.size())
		print(v[i]+off,i==int(v.size())-1?suc:2);
}

template<class T,size_t N>
void print(const array<T,N>&v,int suc=1){
	rep(i,N)
		print(v[i],i==int(N)-1?suc:2);
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
	#ifdef LOCAL
	cout.flush();
	#endif
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
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

vvc<int> readGraph(int n,int m){
	vvc<int> g(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		//sc.read(a,b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> readTree(int n){
	return readGraph(n,n-1);
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

//yosupo
//TKPPC G
struct SA{
	int n;
	vi sa,as,lcp;
	SA(){}
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
	}
};

//CF530F
//returns the suffix tree
//the i-th (0<=i<=n-1) element corresponds to the lexicographically i-th suffix
struct ste{
	int to,l,r;
	operator int()const{return to;}
};
ostream&operator<<(ostream&os,const ste&a){
	return os<<"ste{"<<a.to<<",["<<a.l<<","<<a.r<<"]}";
}
pair<vvc<ste>,int> stree(const SA&sa){
	int n=sa.n,s=n*2-1;
	vi len(s);
	rep(i,n)len[i]=n-sa.sa[i];
	rep(i,n-1)len[i+n]=sa.lcp[i];
	vi idx(n-1);
	iota(all(idx),n);
	stable_sort(all(idx),[&](int a,int b){return len[a]>len[b];});
	unionfind uf(s);
	vi par(s,-1),c(s,-1);
	rep(i,n)c[i]=sa.sa[i];
	for(auto i:idx){
		int a=uf.find(i-n),b=uf.find(i-n+1);
		uf.unite(i,a);
		uf.unite(i,b);
		par[a]=i;
		par[b]=i;
		c[i]=c[a];
	}
	par[n==1?0:idx.back()]=s++;
	len.pb(0);
	uf=unionfind(s);
	rep(i,s-1)if(len[i]==len[par[i]])
		uf.unite(i,par[i]);
	vi vs;
	rep(i,s)if(uf.find(i)==i)vs.pb(i);
	auto z=[&](int i){return lower_bound(all(vs),uf.find(i))-vs.bg;};
	vvc<ste> res(vs.size());
	rep(ii,s-1){
		int i=ii/2+ii%2*n;
		int a=z(i),b=z(par[i]);
		if(a==b)continue;
		res[b].pb(ste{a,c[i]+len[par[i]],c[i]+len[i]});
	}
	return make_pair(res,z(s-1));
}

template<class t>
struct BIT{
	vc<t> buf;
	int s;
	BIT(int n=0){init(n);}
	void init(int n){buf.clear();buf.resize(s=n,0);}
	void init(const vc<t>&a){
		s=si(a);
		buf.resize(s);
		rep(i,s)buf[i]=a[i];
		rep(i,s){
			int j=i+((i+1)&(-i-1));
			if(j<s)buf[j]+=buf[i];
		}
	}
	void add(int i,t v){
		for(;i<s;i+=(i+1)&(-i-1))
			buf[i]+=v;
	}
	t get(int i){
		t res=0;
		for(;i>=0;i-=(i+1)&(-i-1))
			res+=buf[i];
		return res;
	}
	t sum(int b,int e){
		return get(e-1)-get(b-1);
	}
	void add_range(int b,int e,t v){
		add(b,v);
		add(e,-v);
	}
	int kth(int k){
		int res=0;
		for(int i=topbit(s);i>=0;i--){
			int w=res+(1<<i);
			if(w<=s&&buf[w-1]<=k){
				k-=buf[w-1];
				res=w;
			}
		}
		return res;
	}
	//yukicoder No.1024
	int kth_helper(int k,int i){
		return kth(k+get(i-1));
	}
};

template<class t>
struct Point1D{
	BIT<t> bit;
	vi pos;
	void addp(int p){
		pos.pb(p);
	}
	void init(){
		mkuni(pos);
		bit.init(pos.size());
	}
	int idx(int p){
		return lwb(pos,p);
	}
	void addv(int p,t v){
		bit.add(idx(p),v);
	}
	t sum(int b,int e){
		return bit.sum(idx(b),idx(e));
	}
	//[-inf,p)
	t getpref(int p){
		return bit.get(idx(p)-1);
	}
};

template<class t>
struct Point2D{
	vc<Point1D<t>> buf;
	vi pos,xs,ys;
	void addp(int x,int y){
		xs.pb(x);
		ys.pb(y);
	}
	int idx(int p){
		return lwb(pos,p);
	}
	void init(){
		pos=xs;
		mkuni(pos);
		buf.resize(pos.size());
		rep(i,xs.size())
			for(int j=idx(xs[i]);j<int(buf.size());j+=(j+1)&(-j-1))
				buf[j].addp(ys[i]);
		for(auto&b:buf)b.init();
	}
	void addv(int x,int y,t v){
		for(int j=idx(x);j<int(buf.size());j+=(j+1)&(-j-1))
			buf[j].addv(y,v);
	}
	//[x1,x2)*[y1,y2)
	t rect(int x1,int x2,int y1,int y2){
		t res=0;
		for(int j=idx(x1)-1;j>=0;j-=(j+1)&(-j-1))
			res-=buf[j].sum(y1,y2);
		for(int j=idx(x2)-1;j>=0;j-=(j+1)&(-j-1))
			res+=buf[j].sum(y1,y2);
		return res;
	}
	//NOT VERIFIED
	//[-inf,x)*[-inf,y)
	t getpref(int x,int y){
		t res=0;
		for(int j=idx(x)-1;j>=0;j-=(j+1)&(-j-1))
			res+=buf[j].getpref(y);
		return res;
	}
};


//KUPC 2020 C
//
// (a,b) LCA  a LCA  b 
// N 
//N() 
//N.extend(e)  e 
//N  extend 
template<class E,class N>
struct cdecomp{
	const vvc<E>&g;
	int n;
	vi rem;
	
	int ts(int v,int p){
		int res=1;
		for(auto e:g[v])if(e!=p&&!rem[e])
			res+=ts(e,v);
		return res;
	}
	int fc(int v,int p,int s){
		int ret=1,mx=0;
		for(auto e:g[v])if(e!=p&&!rem[e]){
			int f=fc(e,v,s);
			if(f<=0)
				return f;
			else{
				ret+=f;
				mx=max(mx,f);
			}
		}
		mx=max(mx,s-ret);
		if(mx*2<=s)
			return -v;
		else
			return ret;
	}
	
	cdecomp(const vvc<E>&gg):g(gg),n(g.size()),rem(n){
	}
	
	vc<N> buf0;
	vc<N> buf1;
	vi tp;
	vvc<tuple<int,int,int>> bucket;
	
	void dfs1(int v,int p,int i,N cur0,N cur1){
		buf0[v]=cur0;
		buf1[v]=cur1;
		tp[v]=i;
		for(auto e:g[v])if(e!=p&&!rem[e]){
			dfs1(e,v,i==-1?e:i,cur0.extend(e),cur1.extend(e));
		}
	}
	
	template<class F>
	void con(int r,const vc<tuple<int,int,int>>&qs,F f){
		r=-fc(r,-1,ts(r,-1));
		
		N ini0,ini1;
		ini0.init(0);
		ini1.init(1);
		dfs1(r,-1,-1,ini0,ini1);
		for(const auto&w:qs){
			int a,b,i;tie(a,b,i)=w;
			if(tp[a]!=tp[b]){
				f(i,buf0[a],buf1[b],r);
			}else{
				bucket[tp[a]].pb(w);
			}
		}
		
		rem[r]=1;
		for(auto e:g[r])if(!rem[e]){
			vc<tuple<int,int,int>> tmp;
			tmp.swap(bucket[e]);
			con(e,tmp,f);
		}
	}
	
	//f(idx,N lf,N rt,int lca) 
	//[qs[i].a,lca)  lf [qs[i].b,lca)  rt 
	template<class F>
	void slv(const vc<pi>&qs,F f){
		fill(all(rem),0);
		buf0.resize(n);
		buf1.resize(n);
		tp.resize(n);
		bucket.resize(n);
		
		vc<tuple<int,int,int>> tmp(si(qs));
		rep(i,si(qs))
			tmp[i]=mt(qs[i].a,qs[i].b,i);
		con(0,tmp,f);
	}
};

struct E{
	int to;
	char c;
	operator int()const{return to;}
};

SA sa[2];
vvc<ste> st[2];
int stroot[2];
vi in[2],out[2];
int ord[2];

void dfs(int k,int v){
	in[k][v]=ord[k]++;
	for(auto e:st[k][v])
		dfs(k,e.to);
	out[k][v]=ord[k];
}

string z[2];

struct N{
	int k,v,dig,len;
	void init(int kk){
		k=kk;
		v=stroot[k];
		dig=-1;
		len=-1;
	}
	N extend(const E&e)const{
		if(v==-1)return N{-1,-1,-1,-1};
		N res=*this;
		if(res.dig==-1){
			rep(i,si(st[k][v])){
				if(z[k][st[k][v][i].l]==e.c){
					res.dig=i;
					break;
				}
			}
			if(res.dig==-1){
				return N{-1,-1,-1,-1};
			}
			res.len=0;
		}
		const auto&f=st[k][v][res.dig];
		if(z[k][f.l+res.len]!=e.c)return N{-1,-1,-1,-1};
		res.len++;
		if(f.r-f.l==res.len){
			return N{k,f.to,-1,-1};
		}else{
			return res;
		}
	}
	pi getlr(){
		if(v==-1)return pi(-1,-1);
		int w=v;
		if(len>0){
			w=st[k][v][dig].to;
		}
		return pi(in[k][w],out[k][w]);
	}
};

/*
//example
auto slv=[&](int dst,N x,N y,int lca){
	x.off^=y.off;
	rep(i,y.s)x.add(y.vs[i]);
	if(cv[lca]!=-1)x.add(cv[lca]);
	ans[dst]=x.getans(ks[dst]);
};
*/

void slv(){
	int n,m,q;cin>>n>>m>>q;
	
	vvc<E> tr(n);
	rep(i,n-1){
		int u,v;cin>>u>>v;
		u--;v--;
		string s;cin>>s;
		tr[u].pb(E{v,s[0]});
		tr[v].pb(E{u,s[0]});
	}
	
	z[0]="$";
	vi off(m),len(m);
	rep(i,m){
		off[i]=si(z[0]);
		string s;cin>>s;
		len[i]=si(s);
		z[0]+=s;
		z[0]+='$';
	}
	z[1]=z[0];
	reverse(all(z[1]));
	
	rep(k,2){
		tie(st[k],stroot[k])=stree(sa[k]=SA(z[k]));
		in[k].resize(si(st[k]));
		out[k].resize(si(st[k]));
		dfs(k,stroot[k]);
		dmp(k);
		dmp(st[k]);
		dmp(in[k]);
	}
	
	using P=pair<pi,pi>;
	vc<pi> uv(q);
	vvc<int> baka(m+1);
	vc<P> ls(q);
	rep(i,q){
		int u,v,l,r;cin>>u>>v>>l>>r;
		u--,v--,l--;
		uv[i]=pi(v,u);
		baka[l].pb(i*2);
		baka[r].pb(i*2+1);
	}
	
	auto unko=[&](int idx,N lf,N rt,int){
		ls[idx]=P(lf.getlr(),rt.getlr());
	};
	
	cdecomp<E,N> cd(tr);
	cd.slv(uv,unko);
	
	dmp(ls);
	
	Point2D<int> p2d;
	rep(i,m){
		rng(j,off[i],off[i]+len[i]+1){
			int x=in[0][sa[0].as[j]];
			int y=in[1][sa[1].as[si(z[1])-j]];
			dmp2(x,y);
			p2d.addp(x,y);
		}
	}
	p2d.init();
	
	vi ans(q);
	
	rep(i,m+1){
		for(auto w:baka[i]){
			auto [xl,xr]=ls[w/2].a;
			auto [yl,yr]=ls[w/2].b;
			ans[w/2]+=p2d.rect(xl,xr,yl,yr)*(w%2==0?-1:1);
		}
		if(i<m){
			rng(j,off[i],off[i]+len[i]+1){
				int x=in[0][sa[0].as[j]];
				int y=in[1][sa[1].as[si(z[1])-j]];
				p2d.addv(x,y,1);
			}
		}
	}
	
	rep(i,q)print(ans[i]);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}