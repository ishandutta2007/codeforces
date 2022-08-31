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
void yes(bool =true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
}
void no(bool =true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
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

void answer(int n,vi rem){
	if(n==(int)rem.size()){
		return no(0);
	}
	assert(rem.size());
	vi has(n,1);
	for(auto i:rem)has[i]=0;
	vi ans;
	rep(i,n)if(has[i])ans.pb(i+1);
	yes(0);
	assert(ans.size());
	print(ans.size());
	print(ans);
}

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

//AGC034E
//int(E)->to
template<class N,class E>
struct treedp{
	const vvc<E>& g;
	vvc<N> dp1,dp2;
	vc<N> res;
	N dfs1(int v,int p){
		N tmp;tmp.init(v);
		dp1[v].pb(tmp);
		E up;
		for(auto e:g[v])
			if(e!=p)
				dp1[v].pb(dfs1(e,v));
			else
				up=e;
		dp2[v]=dp1[v];
		rng(i,1,dp2[v].size())
			dp2[v][i]=dp2[v][i-1]+dp2[v][i];
		if(p==-1)return N();
		else return dp2[v].back().up(up);
	}
	void dfs2(int v,int p,N cur){
		res[v]=cur+dp2[v].back();
		per(i,g[v].size()){
			auto e=g[v][i];
			if(e==p)continue;
			dp2[v].pop_back();
			dfs2(e,v,(cur+dp2[v].back()).up(e));
			cur=cur+dp1[v].back();
			dp1[v].pop_back();
		}
	}
	treedp(const vvc<E>&gg):g(gg),dp1(g.size()),dp2(g.size()),res(g.size()){
		dfs1(0,-1);
		N tmp;tmp.init(0);
		dfs2(0,-1,tmp);
	}
};

//usage
vi val;
struct N{
	int v;
	pi a,b;
	void init(int vv){
		v=val[vv];
		a=pi(-1,-1);
		b=pi(-1,-1);
	}
	N up(int to)const{
		int x=v,y=-1;
		auto ch=[&](int i){
			if(i!=-1)swap(x,i);
			if(i!=-1)swap(y,i);
		};
		ch(a.a);ch(a.b);
		ch(b.a);ch(b.b);
		return N{val[to],pi(y,x),pi(-1,-1)};
	}
	N operator+(const N&r)const{
		N res=*this;
		auto ch=[&](pi i){
			if(res.a<i)swap(res.a,i);
			if(res.b<i)swap(res.b,i);
		};
		ch(r.a);ch(r.b);
		return res;
	}
};

void slv(){
	int n,m;cin>>n>>m;
	vvc<int> g(n);
	vc<pi> es;
	rep(_,m){
		int u,v;cin>>u>>v;
		u--;v--;
		g[u].pb(v);
		g[v].pb(u);
		es.eb(u,v);
	}
	vi d(n);
	rep(i,n)d[i]=g[i].size()%3;
	rep(i,n)if(d[i]==0)
		return answer(n,{i});
	auto waf=[&](int a,int b){
		queue<int> q;
		vi pre(n,-1);
		auto rc=[&](int v,int p){
			if(d[v]!=2)return;
			if(pre[v]!=-1)return;
			pre[v]=p;
			q.push(v);
		};
		rc(a,-2);
		while(1){
			int v=q.front();q.pop();
			if(v==b)break;
			for(auto to:g[v])
				rc(to,v);
		}
		if(pre[b]<0)return vi{};
		vi res;
		while(b>=0){
			res.pb(b);
			b=pre[b];
		}
		return res;
	};
	unionfind uf(n);
	{
		for(auto e:es){
			int a,b;tie(a,b)=e;
			if(d[a]!=2||d[b]!=2)continue;
			if(uf.same(a,b)){
				g[a].erase(find(all(g[a]),b));
				g[b].erase(find(all(g[b]),a));
				vi res=waf(a,b);
				return answer(n,res);
			}else
				uf.unite(a,b);
		}
	}
	int a=-1;
	{
		int b=-1;
		rep(i,n)if(d[i]==1){
			if(a==-1)
				a=i;
			else
				b=i;
		}
		if(b!=-1){
			vi tmp=d;
			d=vi(n,2);
			vi res=waf(a,b);
			d=tmp;
			rng(i,1,res.size()){
				if(d[res[i]]==1){
					res.resize(i+1);
					break;
				}
			}
			return answer(n,res);
		}
	}
	if(a==-1)
		return no(0);
	vi cnt(n);
	for(auto to:g[a])
		cnt[uf.find(to)]++;
	vi roots;
	rep(i,n)if(cnt[i]>=2){
		roots.pb(i);
	}
	if(roots.size()==0)
		return no(0);
	auto nei=[&](int i){
		for(auto to:g[i])
			if(to==a)return true;
		return false;
	};
	auto rectify=[&](vi p){
		rng(i,1,p.size()){
			if(nei(p[i])){
				p.resize(i+1);
				break;
			}
		}
		return p;
	};
	if(roots.size()==1){
		vi vs;
		rep(i,n)if(uf.same(i,roots[0]))
			vs.pb(i);
		int s=vs.size();
		val.assign(s,-1);
		rep(i,s)if(nei(vs[i]))
			val[i]=vs[i];
		vvc<int> t(s);
		rep(i,s)for(auto to:g[vs[i]])
			t[i].pb(lower_bound(all(vs),to)-vs.bg);
		auto res=treedp<N,int>(t).res;
		rep(i,s)if(res[i].a.a>=0&&res[i].b.a>=0){
			vi ans{a};
			vi p=rectify(waf(res[i].a.a,res[i].a.b));
			vi q=rectify(waf(res[i].b.a,res[i].b.b));
			ans.insert(ans.ed,all(p));
			ans.insert(ans.ed,all(q));
			return answer(n,ans);
		}
		return no(0);
	}else{
		pi z[2]{pi(-1,-1),pi(-1,-1)};
		for(auto to:g[a])rep(k,2)if(uf.find(to)==roots[k]){
			if(z[k].a==-1)
				z[k].a=to;
			else
				z[k].b=to;
		}
		vi res{a};
		rep(k,2){
			vi p=rectify(waf(z[k].a,z[k].b));
			res.insert(res.ed,all(p));
		}
		answer(n,res);	
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;
	rep(_,t)slv();
}