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

template<class t,class u>
void print_offset(const pair<t,u>&p,ll off,int suc=1){
	print(p.a+off,2);
	print(p.b+off,suc);
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

// in,out 
//hei[v] -> heavy edge 
//pe[v]: v->par[v] 
//-
//-
//VERIFY: yosupo
//CF530F
//CodeChef Persistent Oak
//AOJ GRL5C
template<class E>
struct HLD{
	vvc<E> g;
	int n,rt,cnt;
	vi sub,in,out,par,head,dep,hei,ni;
	vc<E> pe;
	int dfs1(int v,int p,int d){
		par[v]=p;
		dep[v]=d;
		for(auto itr=g[v].bg;itr!=g[v].ed;itr++)
			if(*itr==p){
				pe[v]=*itr;
				g[v].erase(itr);
				break;
			}
		for(auto&e:g[v]){
			pe[e]=e;
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
		if(si(g[v]))hei[v]=hei[g[v][0]]+1;
	}
	HLD(){}
	HLD(const vvc<E>&gg,int rr):g(gg),n(g.size()),rt(rr),cnt(0),
		sub(n,1),in(n),out(n),par(n,-1),head(n),dep(n),hei(n,1),ni(n),
		pe(n){
		dfs1(rt,-1,0);
		dfs2(rt,rt);
		rep(i,n)ni[in[i]]=i;
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
	//CF692F
	int getpar(int v,int len){
		assert(dep[v]>=len);
		int tar=dep[v]-len;
		while(1){
			int h=head[v];
			if(dep[h]<=tar){
				return ni[in[h]+(tar-dep[h])];
			}
			v=par[h];
		}
		assert(false);
	}
	//XX Opencup GP of Korea
	//CF625 F
	//2020 Multi-Uni Contest Day5 G
	//CF415E
	vi index;
	//vs  virtual tree 
	// virtual tree 
	//virtual tree 
	// virtual tree index 
	// ch->par 
	//virtual tree 
	// 0 
	pair<vi,vc<pi>> tree_compress(vi vs){
		if(si(index)==0)index.resize(n);
		assert(index.size());
		auto comp = [&](int x,int y){
			return in[x] < in[y];
		};
		sort(all(vs),comp);
		vs.erase(unique(all(vs)),vs.ed);
		int k = vs.size();
		rep(i,k-1){
			vs.pb(lca(vs[i],vs[i+1]));
		}
		sort(all(vs),comp);
		vs.erase(unique(all(vs)),vs.ed);
		k = vs.size();
		rep(i,k) index[vs[i]] = i;
		vc<pi> es;
		rng(i,1,k){
			int p = lca(vs[i-1],vs[i]);
			es.eb(i,index[p]);
		}
		return mp(vs,es);
	}
	//assume a is desdendant of b
	//ex=true <=> exclude b
	template<class F>
	void subpath_work(int a,int b,bool ex,F f){
		while(1){
			if(head[a]==head[b]){
				f(in[b]+ex,in[a]+1);
				break;
			}else{
				int h=head[a];
				f(in[h],in[a]+1);
				a=par[h];
			}
		}
	}
	//KUPC2021E
	//
	//euler-tour 
	//ex=true exclude lca(a,b) (=apply path edges)
	template<class F>
	void path_work(int a,int b,bool ex,F f){
		int c=lca(a,b);
		subpath_work(a,c,ex,f);
		subpath_work(b,c,true,f);
	}
};

//atcoder-library 

//N() 

//merge  inactive 
//lazy 

//get 
// min  0  1 

//VERIFY:
//https://atcoder.jp/contests/practice2/tasks/practice2_k
template<class N>
struct seglazy{
	vc<N> x;
	int L,s;
	seglazy(){}
	template<class T>
	seglazy(const vc<T>& a){
		int n=a.size();
		L=0;
		while((1<<L)<n)L++;
		s=1<<L;
		x.resize(s*2);
		rep(i,n)x[s+i]=N(a[i]);
		gnr(i,1,s)upd(i);
	}
	void upd(int i){
		x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	void push(int i){
		x[i].push(x[i*2],x[i*2+1]);
	}
	N composite(int l,int r){
		assert(0<=l&&l<=r&&r<=s);
		if(l==r)return N();
		
		l+=s;
		r+=s;
		
		for (int i = L; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}
		
		N sml,smr;
		while (l < r) {
			if (l & 1) sml = N::merge(sml, x[l++]);
			if (r & 1) smr = N::merge(x[--r], smr);
			l >>= 1;
			r >>= 1;
		}

		return N::merge(sml, smr);
	}
	template<class F,class... Args>
	void ch(int l, int r, F f,Args&&... args) {
		assert(0<=l&&l<=r&&r<=s);
		if (l == r) return;

		l+=s;
		r+=s;

		for (int i = L; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}
		
		static int buf[2][30];
		int cnt[2]{};
		{
			int l2 = l, r2 = r;
			while (l < r) {
				if (l & 1){
					//(x[l++].*f)(forward<Args>(args)...);
					buf[0][cnt[0]++]=l++;
				}
				if (r & 1){
					//(x[--r].*f)(forward<Args>(args)...);
					buf[1][cnt[1]++]=--r;
				}
				l >>= 1;
				r >>= 1;
			}
			l = l2;
			r = r2;
		}
		rep(i,cnt[0])(x[buf[0][i]].*f)(forward<Args>(args)...);
		per(i,cnt[1])(x[buf[1][i]].*f)(forward<Args>(args)...);

		for (int i = 1; i <= L; i++) {
			if (((l >> i) << i) != l) upd(l >> i);
			if (((r >> i) << i) != r) upd((r - 1) >> i);
		}
	}
	N getall(){return x[1];}
	template <class F,class... Args> 
	pair<int,N> max_right(int l,F f,Args&&... args){
		assert(0<=l&&l<=s);
		if(l==s)return mp(s,N());
		l+=s;
		
		for (int i = L; i >= 1; i--) push(l >> i);
		N sm;
		assert((sm.*f)(forward<Args>(args)...));
		do {
			while (l % 2 == 0) l >>= 1;
			if (!(N::merge(sm,x[l]).*f)(forward<Args>(args)...)){
				while (l < s) {
					push(l);
					l = (2 * l);
					N tmp=N::merge(sm,x[l]);
					if ((tmp.*f)(forward<Args>(args)...)) {
						sm = tmp;
						l++;
					}
				}
				return mp(l - s,sm);
			}
			sm = N::merge(sm, x[l]);
			l++;
		} while ((l & -l) != l);
		return mp(s,sm);
	}
	//XXI Opencup Krakow M
	template <class F,class... Args> 
	pair<int,N> min_left(int r,F f,Args&&... args){
		assert(0<=r&&r<=s);
        if(r==0)return mp(0,N());
        r+=s;
        for (int i = L; i >= 1; i--) push((r - 1) >> i);
        N sm;
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!(N::merge(x[r],sm).*f)(forward<Args>(args)...)) {
                while (r < s) {
                    push(r);
                    r = (2 * r + 1);
                    N tmp=N::merge(x[r],sm);
                    if ((tmp.*f)(forward<Args>(args)...)) {
                        sm = tmp;
                        r--;
                    }
                }
                return mp(r + 1 - s,sm);
            }
            sm = N::merge(x[r], sm);
        } while ((r & -r) != r);
        return mp(0,sm);
    }
	template<class F,class...Args>
	void point_change(int p,F f,Args&&...args){
		assert(0 <= p && p < s);
		p += s;
		for (int i = L; i >= 1; i--) push(p >> i);
		(x[p].*f)(forward<Args>(args)...);
		for (int i = 1; i <= L; i++) upd(p >> i);
	}
	N point_get(int p){
		assert(0 <= p && p < s);
		p += s;
		for (int i = L; i >= 1; i--) push(p >> i);
		return x[p];
	}
	void point_set(int p,N val){
		assert(0 <= p && p < s);
		p += s;
		for (int i = L; i >= 1; i--) push(p >> i);
		x[p]=val;
		for (int i = 1; i <= L; i++) upd(p >> i);
	}
	void enumerater(int l,int r,int i,int b,int e,vc<N>&dst){
		if(e<=l||r<=b)
			return;
		if(l+1==r){
			dst.pb(x[i]);
			return;
		}
		push(i);
		int m=(l+r)/2;
		enumerater(l,m,i*2,b,e,dst);
		enumerater(m,r,i*2+1,b,e,dst);
	}
	void enumerate(int b,int e,vc<N>&dst){
		assert(b<=e);
		return enumerater(0,s,1,b,e,dst);
	}
};

//Range add,min
struct N{
	ll lz,mn;
	N(ll v=infLL):lz(0),mn(v){}
	void add(ll v){
		mn+=v;
		lz+=v;
	}
	void push(N&x,N&y){
		x.add(lz);
		y.add(lz);
		lz=0;
	}
	static N merge(N x,N y){
		return N(min(x.getm(),y.getm()));
	}
	ll getm(){return mn;}
	bool ok(ll v){
		return mn>v;
	}
};

void slv(){
	int n,m;cin>>n>>m;
	vvc<int> g=readGraph(n,m);
	vvc<int> t(n),z(n);
	{
		vi vis(n);
		auto dfs=[&](auto self,int v,int p)->void{
			assert(vis[v]==0);
			vis[v]=1;
			for(auto to:g[v])if(to!=p){
				if(vis[to]==0){
					t[v].pb(to);
					self(self,to,v);
				}else if(vis[to]==1){
					z[v].pb(to);
				}
			}
			vis[v]=2;
		};
		dfs(dfs,0,-1);
	}
	HLD<int> hld(t,0);
	
	auto work=[&](vc<pi> ls){
		vi res(n);
		for(auto [a,b]:ls){
			res[a]++;
			res[b]++;
			res[hld.lca(a,b)]-=2;
		}
		auto dfs=[&](auto self,int v)->void{
			for(auto ch:t[v]){
				self(self,ch);
				res[v]+=res[ch];
			}
		};
		dfs(dfs,0);
		return res;
	};
	
	int qnum;cin>>qnum;
	vc<pi> qs(qnum);
	vvc<int> qup(n);
	rep(i,qnum){
		int a,b;cin>>a>>b;a--;b--;
		qs[i]=pi(a,b);
		int c=hld.lca(a,b);
		qup[a].pb(c);
		qup[b].pb(c);
	}
	
	vi pass=work(qs);
	vi block;
	vi cov(n,0);
	vc<pi> binfo(n);
	{
		vc<pi> tmp;
		rep(i,n)for(auto j:z[i])tmp.eb(i,j);
		block=work(tmp);
		sort(all(tmp),[&](pi a,pi b){return hld.dep[a.b]>hld.dep[b.b];});
		unionfind uf(n);
		for(auto [from,to]:tmp){
			pi e(from,to);
			from=uf.find(from);
			while(hld.dep[from]>hld.dep[to]){
				cov[from]=hld.dep[to];
				binfo[from]=e;
				int p=uf.find(hld.par[from]);
				uf.unite(p,from);
				from=p;
			}
		}
	}
	using A=array<int,2>;
	vc<A> zup(n,A{inf,inf});
	auto updzup=[&](int v,int d){
		rep(k,2){
			if(d<zup[v][k])swap(d,zup[v][k]);
		}
	};
	{
		auto dfs=[&](auto self,int v)->void{
			for(auto j:z[v])updzup(v,hld.dep[j]);
			for(auto ch:t[v]){
				self(self,ch);
				updzup(v,zup[ch][0]);
			}
		};
		dfs(dfs,0);
	}
	
	int ans=-1;
	pi e1,e2;
	auto updans=[&](int val,pi x,pi y){
		if(chmax(ans,val)){
			e1=x;
			e2=y;
		}
	};
	{
		int x[2]{-inf,-inf};
		pi e[2]{};
		rng(i,1,n){
			int v=block[i]==0?pass[i]:0;
			pi cur=pi(i,hld.par[i]);
			rep(k,2)if(v>x[k]){
				swap(v,x[k]);
				swap(cur,e[k]);
			}
		}
		updans(x[0]+x[1],e[0],e[1]);
	}
	rng(i,1,n)if(block[i]==1){
		updans(pass[i],pi(i,hld.par[i]),binfo[i]);
	}
	
	seglazy<N> seg(vc<ll>(n,0));
	
	const int V=1<<30;
	
	auto upd=[&](int v,int w){
		for(auto up:qup[v]){
			seg.ch(hld.dep[up],hld.dep[v],&N::add,w*2);
		}
	};
	
	auto sub=[&](auto self,int v,int w)->void{
		upd(v,w);
		for(auto ch:t[v])self(self,ch,w);
	};
	
	vc<pi> ebuf;
	
	auto dfs=[&](auto self,int v)->void{
		int p=hld.par[v];
		int ban;
		if(p!=-1){
			ebuf.eb(v,p);
			ban=zup[p][0];
			if(ban==zup[v][0])ban=zup[p][1];
			if(ban<hld.dep[p]){
				seg.ch(ban,hld.dep[p],&N::add,V);
			}
			seg.point_change(hld.dep[p],&N::add,-pass[v]);
		}
		int hc=si(t[v])?hld.g[v][0]:-1;
		for(auto ch:hld.g[v]){
			if(ch!=hc){
				self(self,ch);
			}
		}
		if(hc!=-1)self(self,hc);
		if(p!=-1){
			upd(v,1);
			for(auto ch:hld.g[v]){
				if(ch!=hc){
					sub(sub,ch,1);
				}
			}
			if(cov[v]<hld.dep[p]){
				ll val=seg.composite(cov[v],hld.dep[p]).mn;
				ll unko=pass[v]-val;
				if(ans<unko){
					int pos=seg.max_right(cov[v],&N::ok,val).a;
					updans(unko,ebuf.back(),ebuf[pos]);
				}
			}
			if(ban<hld.dep[p]){
				seg.ch(ban,hld.dep[p],&N::add,-V);
			}
			seg.point_change(hld.dep[p],&N::add,pass[v]);
			ebuf.pop_back();
		}
		if(hld.head[v]==v){
			sub(sub,v,-1);
		}
	};
	dfs(dfs,0);
	
	print(ans);
	print_offset(e1,1);
	print_offset(e2,1);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;rep(_,t)
	slv();
}