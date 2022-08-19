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

//suffix automaton
//extend(a,c):  a  c 
//
// trie 
//yosupo number of substrings
//USACO 2017 Dec Platinum 1
template<class C>
struct suffixautomaton{
	struct N{
		int len,suf,org;
		map<C,int> to;
	};
	vc<N> x;
	suffixautomaton():x{N{0,-1,-1,{}}}{}
	int add(int a,C c){
		assert(x[a].to.count(c));
		int b=x[a].to[c];
		if(x[a].len+1==x[b].len)
			return b;
		else{
			int w=x.size();
			x.pb(x[b]);
			x[w].len=x[a].len+1;
			x[w].org=b;
			while(a!=-1&&x[a].to[c]==b){
				x[a].to[c]=w;
				a=x[a].suf;
			}
			return x[b].suf=w;
		}
	}
	int extend(int a,C c){
		if(x[a].to.count(c))return add(a,c);
		int cur=x.size();
		x.pb(N{x[a].len+1,0,-1,{}});
		while(a!=-1&&!x[a].to.count(c)){
			x[a].to[c]=cur;
			a=x[a].suf;
		}
		if(a!=-1){
			int z=add(a,c);
			x[cur].suf=z;
		}
		return cur;
	}
	vi toposort(){
		int n=x.size();
		vi c(n);
		rep(i,n)for(auto kv:x[i].to)c[kv.b]++;
		vi res(n);
		int b=0,e=0;
		rep(i,n)if(c[i]==0)res[e++]=i;
		while(e<n){
			int i=res[b++];
			for(auto kv:x[i].to)if(--c[kv.b]==0)res[e++]=kv.b;
		}
		return res;
	}
	N& operator[](int i){
		return x[i];
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	suffixautomaton<char> sa;
	{
		string s;cin>>s;
		int cur=0;
		for(auto c:s)
			cur=sa.extend(cur,c);
	}
	int s=sa.x.size();
	vvc<int> tree(s);
	rng(i,1,s)tree[sa[i].suf].pb(i);
	dmp(tree);
	vi in(s),out(s);
	vi val(s,-1);
	int head=0;
	auto dfs=[&](auto self,int v)->void{
		in[v]=head++;
		if(sa[v].org==-1)
			val[in[v]]=sa[v].len;
		for(auto to:tree[v])
			self(self,to);
		out[v]=head;
	};
	dfs(dfs,0);
	vi nx(s,-1);
	{
		int pre=s;
		per(i,s){
			nx[i]=pre;
			if(val[i]!=-1)pre=i;
		}
	}
	
	int q;cin>>q;
	vi pos;
	rep(_,q){
		int k;cin>>k;
		int v=0,tlen=0;
		{
			string t;cin>>t;
			for(auto c:t){
				if(sa[v].to.count(c))
					v=sa[v].to[c];
				else{
					v=-1;
					break;
				}
			}
			tlen=si(t);
		}
		int ans=-1;
		if(v!=-1){
			int lim=out[v];
			v=in[v];
			if(val[v]!=-1)pos.pb(val[v]);
			while((v=nx[v])<lim){
				assert(val[v]!=-1);
				pos.pb(val[v]);
			}
			dmp(pos);
			if(si(pos)>=k){
				sort(all(pos));
				ans=inf;
				rep(i,si(pos)-k+1){
					chmin(ans,pos[i+k-1]-pos[i]+tlen);
				}
			}
		}
		print(ans);
		pos.clear();
	}
}