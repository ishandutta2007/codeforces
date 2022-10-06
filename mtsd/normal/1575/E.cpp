#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#include<random>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (int)(Y);++(X))
#define reps(X,S,Y) for (int (X) = (int)(S);(X) < (int)(Y);++(X))
#define rrep(X,Y) for (int (X) = (int)(Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (int)(Y)-1;(X) >= (int)(S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl
#define NL <<"\n"
#define cauto const auto

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#include "benri.h"
#else
#define out(args...)
#endif
void ouT(ll x,int d=3){auto re=to_string(x);if((int)re.size()>d) re=x>0?"oo":"-oo";cout<<string(d-re.size(),' ')<<re<<",";}
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
template<class A,class B> pair<A,B> operator+(const pair<A,B> &p,const pair<A,B> &q){ return {p.X+q.X,p.Y+q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator+=(pair<A,B> &p,const pair<C,D> &q){ p.X+=q.X; p.Y+=q.Y; return p;}
template<class A,class B> pair<A,B> operator-(const pair<A,B> &p,const pair<A,B> &q){ return {p.X-q.X,p.Y-q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator-=(pair<A,B> &p,const pair<C,D> &q){ p.X-=q.X; p.Y-=q.Y; return p;}
template<class A,class B> istream& operator>>(istream &is, pair<A,B> &p){ is>>p.X>>p.Y; return is;}
template<class T=ll> T read(){ T re; cin>>re; return re;}
template<class T=ll> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T=ll> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return re;}
template<class T=ll> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return re;}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return g;}
vv<int> readG(const int &n){ return readG(n,n-1);}
vv<int> readD(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); } return g;}
vv<int> readD(const int &n){ return readD(n,n-1);}
template<class T> vv<pair<int,T>> readG(const int &n,const int &m){ vv<pair<int,T>> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); cauto c=read<T>(); g[a].eb(b,c); g[b].eb(a,c);} return g;}
template<class T> vv<pair<int,T>> readG(const int &n){ return readG<T>(n,n-1);}
template<class T> vv<pair<int,T>> readD(const int &n,const int &m){ vv<pair<int,T>> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); cauto c=read<T>(); g[a].eb(b,c); } return g;}
template<class T> vv<pair<int,T>> readD(const int &n){ return readD<T>(n,n-1);}
template<class T> bool erase(multiset<T> &st, const T &v){if(cauto it=st.find(v); it==st.end()) return false; else{ st.erase(it); return true;}}
#ifdef __cpp_init_captures
template<typename T> vector<T> readT(int n, T v){ return readV(n,v);}
template <class... Args> auto readT(int n, Args... args){ vector re(1,readT(args...));rep(_,n-1) re.eb(readT(args...));	return re;}
template<typename T, size_t... Is> void addadd(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) += get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator += (tuple<T...>& lhs, const tuple<T...>& rhs){	addadd(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator +(tuple<T...> lhs, const tuple<T...>& rhs){ return lhs += rhs;}
template<typename T, size_t... Is> void subsub(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) -= get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator -= (tuple<T...>& lhs, const tuple<T...>& rhs){	subsub(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator - (tuple<T...> lhs, const tuple<T...>& rhs){ return lhs -= rhs;}
template<class Tuple, size_t... Is> void read_tuple_impl(istream &is, Tuple& t, index_sequence<Is...>){((is >> get<Is>(t)), ...);}
template<class... Args> auto& operator>>(istream &is, tuple<Args...>& t){ read_tuple_impl(is, t, index_sequence_for<Args...>{}); return is;}
#endif
#define TT cauto TTT=read();rep(_,TTT)
struct sorted_impl{template<class T>friend vector<T>operator-(vector<T>a,sorted_impl){sort(all(a));return a;}}sorted;struct reversed_impl{template<class T>friend vector<T>operator-(vector<T> a,reversed_impl){reverse(all(a));return a;}}reversed;struct distinct_impl{template<class T>friend vector<T>operator-(vector<T> a,distinct_impl){sort(all(a));UNIQUE(a);return a;}}distinct;template<class S>struct sortedWith{const S f;sortedWith(const S &f):f(f){}template<class T>friend vector<T>operator-(vector<T> a,const sortedWith&b){sort(all(a),[&](cauto&i,cauto&j){return b.f(i)<b.f(j);});return a;}};
template<class T>int operator/(const T&v,const vector<T>&vs){return lower_bound(all(vs),v)-vs.begin();}
vector<int> Inds(const int n){vector<int> inds(n);iota(all(inds),0);return inds;}
const ll MOD=1e9+7; //998244353;

ll modpow_(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=m-1)+=m-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
template <int mod=MOD> struct ModInt{
  int v;
  ModInt(int v=0):v(v){}
  ModInt operator+(const ModInt &n)const{return v+n.v<mod ? v+n.v : v+n.v-mod;}
  ModInt operator-(const ModInt &n)const{return v-n.v<0 ? v-n.v+mod : v-n.v;}
  ModInt operator*(const ModInt &n)const{return int(ll(v)*n.v%mod);}
  ModInt operator/(const ModInt &n)const{return int(ll(v)*modpow_(n.v%mod,-1,mod)%mod);}
  ModInt operator+(const int &n)const{return v+n<mod ? v+n : v+n-mod;}
  ModInt operator-(const int &n)const{return v-n<0 ? v-n+mod : v-n;}
  ModInt operator*(const ll &n)const{return int(ll(v)*(n%mod)%mod);}
  ModInt operator/(const ll &n)const{return int(ll(v)*modpow_(n%mod,-1,mod)%mod);}
  ModInt& operator+=(const ModInt &n){v+=n.v; if(v>=mod) v-=mod; return *this;}
  ModInt& operator-=(const ModInt &n){v-=n.v; if(v<0) v+=mod; return *this;}
  ModInt& operator*=(const ModInt &n){v=ll(v)*n.v%mod; return *this;}
  ModInt& operator/=(const ModInt &n){v=ll(v)*modpow_(n.v,-1,mod)%mod; return *this;}
  ModInt& operator+=(const int &n){v+=n; if(v>=mod) v-=mod; return *this;}
  ModInt& operator-=(const int &n){v-=n; if(v<0) v+=mod; return *this;}
  ModInt& operator*=(const ll &n){v=ll(v)*n%mod; return *this;}
  ModInt& operator/=(const ll &n){v=ll(v)*modpow_(n,-1,mod)%mod; return *this;}
	bool operator==(const ModInt &n)const{return v==n.v;};
	bool operator!=(const ModInt &n)const{return v!=n.v;};
	ModInt& operator++(){ return operator+=(1); }
	ModInt& operator--(){ return operator-=(1); }
	ModInt operator++(int i){ ModInt tmp(*this); operator++(); return tmp; }
	ModInt operator--(int i){ ModInt tmp(*this); operator--(); return tmp; }
};
#ifdef NUIP
class MINT_FRAC____{
public:
	unordered_map<int,pii> dict;
	MINT_FRAC____(int n){
		rep(p,n+1)reps(q,1,n+1)if(__gcd(p,q)==1){
			dict[int(1ll*p*modpow_(q,-1)%MOD)]=pii(p,q);
			dict[int(MOD-1ll*p*modpow_(q,-1)%MOD)]=pii(-p,q);
		}
	}
} Il1Il1Il1(1000);
template<int mod> ostream& operator<<(ostream &os,const ModInt<mod> &n){if(Il1Il1Il1.dict.count(n.v)) os<<n.v, cerr<<"("<<Il1Il1Il1.dict[n.v].X<<"/"<<Il1Il1Il1.dict[n.v].Y<<")";else os<<n.v;return os;};
#else
template<int mod> ostream& operator<<(ostream &os,const ModInt<mod> &n){return os<<n.v;};
#endif
template<int mod> ModInt<mod> operator+(const ll &n,const ModInt<mod> &m){return m.v+n<mod ? m.v+n : m.v+n-mod;}
template<int mod> ModInt<mod> operator-(const ll &n,const ModInt<mod> &m){return n-m.v<0 ? n-m.v+mod : n-m.v;}
template<int mod> ModInt<mod> operator*(const ll &n,const ModInt<mod> &m){return ll(m.v)*(n%mod)%mod;}
template<int mod> ModInt<mod> operator/(const ll &n,const ModInt<mod> &m){return ModInt<mod>(n%mod)/m;}
typedef ModInt<MOD> mint;
template <int mod> ModInt<mod> modpow(ModInt<mod> r,ll n){ ModInt<mod> re(1); if(n<0)(n%=mod-1)+=mod-1; for(;n;n/=2){if(n&1) re*=r; r*=r;} return re;}
vector<mint> fact,finv,inv;
mint comb(ll n,ll r){ if(n<r||r<0)return 0; return fact[n]*finv[n-r]*finv[r];}
class Doralion{
  void Modinvs(vector<mint> &re,int n){ re.resize(n+1); re[1]=1; for(int i=2;i<=n;++i)re[i]=re[MOD%i]*(MOD-MOD/i);}
  void Facts(vector<mint> &re,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*(i+1);}
  void Factinvs(vector<mint> &re,const vector<mint> &inv,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*inv[i+1];}
public:
  Doralion(int n){ Modinvs(inv,n); Facts(fact,n); Factinvs(finv,inv,n);}
} doralion(1123456);
using pmm=pair<mint,mint>;
mint modpow(ll r,ll n){ return (int)modpow_(r,n);}


struct SepDec:public vector<int>{
  struct Rec {
    int root, count, par;
    explicit Rec(int r = 0, int c = 0, int p = 0):root(r), count(c), par(p){}
  };
  struct DFS {
    int u, i, p;
    explicit DFS(int ver = 0, int ind = 0, int pa = 0): u(ver), i(ind), p(pa) {}
  };
  vector<int> dep,par;
  const int n;
  
  void sep_dec(const vv<int> &conn){
    vector<bool> picked(n);
    vector<int> cnt(n); //num_children
    stack<Rec> recs;
    recs.emplace(0, n, -1);
    while(!recs.empty()){
      const Rec rf = recs.top();
      const int lb = rf.count / 2;
      recs.pop();
      int sep = rf.root;
      stack<DFS> dfss;
      dfss.emplace(rf.root, 0, rf.root);
      while(!dfss.empty()){
				DFS df = dfss.top();
				dfss.pop();
				if(df.i >= (int)conn[df.u].size()){
					cnt[df.u] = 1;
					for(const int &v:conn[df.u]){
						if(picked[v] || v == df.p) continue;
						cnt[df.u] += cnt[v];
					}
					if(cnt[df.u] > lb){
						sep = df.u;
						cnt[df.p] = rf.count - cnt[df.u];
						break;
					}
				}else{
					dfss.emplace(df.u, df.i + 1, df.p);
					const int v = conn[df.u][df.i];
					if(!picked[v] && v != df.p){
						dfss.emplace(v, 0, df.u);
					}
				}
      }
      par[sep] = (rf.par < 0 ? sep : rf.par);
      picked[sep] = true;
      for(const int &v:conn[sep])if(!picked[v])	recs.emplace(v, cnt[v], sep);
    }
  }
  
  int dfs(int v){ return dep[v]>=0?dep[v]:dep[v]=(par[v]==v?v:dfs(par[v])+1);}

  SepDec(const vv<int> &g):n(g.size()){
    dep.resize(n,-1); par.resize(n);
    sep_dec(g);
    resize(n);
    rep(i,n)if(dep[i]<0) dfs(i);
    iota(all(*this),0);
    sort(all(*this),[&](int i,int j){return dep[i]>dep[j];});
  }
};

struct UF{
  vector<int> data;
  UF(const int &size):data(size,-1){}
  int unite(int x, int y){
    x=root(x); y=root(y);
    if(x==y) return 0;
		if(-data[y]>-data[x]) swap(x,y);
		data[x]+=data[y]; data[y]=x;
    return y+1;
  }
  bool findSet(const int &x, const int &y){ return root(x)==root(y);}
  int root(const int &x){ return data[x]<0?x:data[x]=root(data[x]);}
  int size(const int &x){ return -data[root(x)];}
	int size(){ return count_if(all(data),[](const int &x){ return x<0;});}; //unverified
	int operator()(const int &x, const int &y){ return unite(x,y);}
	int operator()(const pii &xy){ return unite(xy.X,xy.Y);}
	int operator[](const int &x){ return root(x);}
	bool operator[](const pii &xy){ return findSet(xy.X,xy.Y);}
};


template <class T>
struct fenwick_tree {
  vector<T> x;
  fenwick_tree(int n) : x(n+1) { } 
  void add(int k, T a) { 
    for (++k; k < x.size(); k += k&-k) x[k] += a;
  }
  T sum(int k) {
    T s = 0;
    for (; k > 0; k &= k-1) s += x[k];
    return s;
  }
  int lower_bound(T a) {
    if (a <= 0) return 0;
    int k = x.size()-1; 
    for (int s: {1,2,4,8,16}) k |= (k >> s); 
    for (int p = ++k; p > 0; p >>= 1, k |= p)
      if (k < x.size() && x[k] < a) a -= x[k]; else k ^= p;
    return k+1;
  }
};

vector<mint> bf(const vector<int> vs, const vv<pii> g){
	const int n=g.size();
	vector<mint> re(n);
	cauto dfs=
		[&](auto &&dfs,int v,int p,int c,int cnt,mint sum)->void{
			sum+=vs[v];
			re[cnt]+=sum;
			for(cauto &[u,d]:g[v])if(u!=p) dfs(dfs,u,v,d,cnt+(c!=d),sum);
		};
	rep(v,n)for(cauto &[u,c]:g[v]) dfs(dfs,u,v,c,0,vs[v]);
	for(auto &x:re) x/=2;
	re[0]+=accumulate(all(vs),mint(0));
	reps(i,1,n) re[i]+=re[i-1];
	return re;
}
namespace random_graph{
	mt19937 rand(123);
	vv<int> tree(int n){
		vv<int> g(n);
		vector<int> ind(n); iota(all(ind),0);
		shuffle(all(ind),rand);
		reps(i,1,n){
			int a=ind[i];
			int b=ind[rand()%i];
			g[a].pb(b);
			g[b].pb(a);
		}
		return g;
	}
}

mint solve(const int t, const vector<int> vs, const vv<pii> g){
	const int n=vs.size();
	vv<int> g_(n);
	rep(v,n)for(cauto &p:g[v]) g_[v].eb(p.X);
	const SepDec sd(g_);
	vector<int> usd(n);
	vector<pair<int,mint>> cur;
	cauto dfs=
		[&](auto &&dfs,int v,int p,int c,int cnt,mint sum)->void{
			if(!usd[v]) return;
			sum+=vs[v];
			cur.eb(cnt,sum);
			for(cauto &[u,d]:g[v]){
				if(u==p) continue;
				dfs(dfs,u,v,d,cnt+(c!=d),sum);
			}
		};
	UF uf(n);
	mint re=accumulate(all(vs),mint(0));
	for(cauto &v:sd){
		usd[v]=1;
		for(cauto &u:g_[v])if(usd[u]) uf(u,v);
		const int sz=min<int>(uf.size(v),t)+3;
		fenwick_tree<mint> sum0(sz);
		fenwick_tree<mint> sum1(sz);
		fenwick_tree<mint> cnt0(sz);
		fenwick_tree<mint> cnt1(sz);
		for(cauto &[u,c]:g[v]){
			if(!usd[u]) continue;
			cur.clear();
			dfs(dfs,u,v,c,0,0);
			// out(v,u,c,cur,1);
			for(cauto &[cnt,sum]:cur){
				if(cnt>t) continue;
				// out(cnt,sum,sum+vs[v],sum0.sum(t+(c==0)-cnt),sum1.sum(t+(c==1)-cnt),1);
				re+=sum+vs[v];
				re+=sum0.sum(min(sz-1,t+(c==0)-cnt));
				re+=cnt0.sum(min(sz-1,t+(c==0)-cnt))*(sum+vs[v]);
				re+=sum1.sum(min(sz-1,t+(c==1)-cnt));
				re+=cnt1.sum(min(sz-1,t+(c==1)-cnt))*(sum+vs[v]);
			}
			for(cauto &[cnt,sum]:cur){
				if(cnt>t) continue;
				(c?sum1:sum0).add(cnt,sum);
				(c?cnt1:cnt0).add(cnt,1);
			}
		}
	}
	return re;
}

int main(){
// 	{
// 		vector<int> vs(6,1); //{4,4,3,0,7,8};
// // 	out(bf(vs,{{{3,1}}
// // ,{{4,0}}
// // ,{{3,1},{5,0}}
// // ,{{0,1},{2,1},{4,1}}
// // ,{{1,0},{3,1}}
// // 														 ,{{2,0}}}),1);
// 	out(solve(5,vs,{{{3,1}}
// ,{{4,0}}
// ,{{3,1},{5,0}}
// ,{{0,1},{2,1},{4,1}}
// ,{{1,0},{3,1}}
// 														 ,{{2,0}}}),1);
// 	return 0;
// 	}
	if(0){
		rep(_,100){
			cauto n=rand()%10+2;
			cauto g_=random_graph::tree(n);
			vv<pii> g(n);
			rep(v,n)for(cauto &u:g_[v])if(v<u){
					cauto c=rand()%2;
					g[v].eb(u,c);
					g[u].eb(v,c);
				}
			vector<int> vs(n);
			for(auto &v:vs) v=rand()%10;
			cauto exp=bf(vs,g);
			rep(t,n){
				cauto act=solve(t,vs,g);
				if(act!=exp[t]){
					out(act,exp[t],t,vs,g,1);
					exit(0);
				}
			}
		}
		out("done",1);
	}
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout<<fixed<<setprecision(0);
	cauto n=read();
	cauto t=read();
	cauto vs=readV(n,0);
	cauto g=readG<int>(n);
	cout<<solve(t,vs,g) NL;
	return 0;
}
/*
371: act = 988(988/1), exp[t] = 196(196/1), t = 5, vs = {4,4,3,0,7,8,}
, g = {{{3,1},}
,{{4,0},}
,{{3,1},{5,0},}
,{{0,1},{2,1},{4,1},}
,{{1,0},{3,1},}
,{{2,0},}
,}
*/