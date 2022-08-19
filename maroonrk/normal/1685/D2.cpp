#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

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

vc<ll> presum(const vi&a){
	vc<ll> s(si(a)+1);
	rep(i,si(a))s[i+1]=s[i]+a[i];
	return s;
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

int calc(const vi&p,const vi&q){
	int n=si(p);
	int curscore=0;
	rep(i,n){
		curscore+=abs(q[i]-p[q[(i+1)%n]]);
	}
	return curscore;
}

vi fast(vi p){
	int n=si(p);
	unionfind uf(n);
	rep(i,n)uf.unite(i,p[i]);
	vvc<pi> ls(n);
	rep(i,n)ls[uf.find(i)].eb(p[i],i);
	ls.erase(remove_if(all(ls),[&](const vc<pi>&x){return x.empty();}),ls.ed);
	for(auto&xs:ls)sort(all(xs));
	
	int tarscore=si(ls)-1;
	vi w(n,-1),winv(n,-1);
	
	{
		vc<pi> z(n);
		rep(i,si(ls))for(auto [x,val]:ls[i])z[x]=pi(i,val);
		
		dmp(z);
		
		unionfind q(si(ls));
		
		vi fw(n-1),bk(n-1);
		
		int i=0;
		do{
			dmp2(i,q.c);
			int mn=inf,k=-1;
			rep(j,n)if(winv[j]==-1){
				bool ok=true;
				unionfind cur=q;
				if(j<i){
					rng(c,j,i)if(bk[c]){
						ok=false;
						break;
					}
				}
				if(j>i){
					rng(c,i,j)if(fw[c]){
						ok=false;
						break;
					}
				}
				{
					auto [l,r]=minmax(i,j);
					rng(c,l,r){
						if(fw[c]==0&&bk[c]==0&&!cur.unite(z[c].a,z[c+1].a))
							ok=false;
					}
				}
				if(!ok)continue;
				if(j<i){
					rng(c,j,i){
						bk[c]++;
						cur.unite(z[c].a,z[c+1].a);
					}
				}
				if(j>i){
					rng(c,i,j){
						fw[c]++;
						cur.unite(z[c].a,z[c+1].a);
					}
				}
				rng(c,1,n-1){
					if(w[c]==-1&&winv[c]==-1){
						if(bk[c-1]&&fw[c-1]&&bk[c]&&fw[c])ok=false;
					}
				}
				
				w[i]=j;
				winv[j]=i;
				
				rep(c,n-1)if(fw[c]==0&&bk[c]==0){
					if(w[c]!=-1&&winv[c]!=-1)continue;
					if(w[c+1]!=-1&&winv[c+1]!=-1)continue;
					cur.unite(z[c].a,z[c+1].a);
				}
				
				if(ok&&cur.c==1){
					if(chmin(mn,z[j].b))k=j;
				}
				if(j<i){
					rng(c,j,i){
						bk[c]--;
					}
				}
				if(j>i){
					rng(c,i,j){
						fw[c]--;
					}
				}
				w[i]=-1;
				winv[j]=-1;
			}
			dmp2(i,k);
			assert(k!=-1);
			assert(winv[k]==-1);
			w[i]=k;
			winv[k]=i;
			
			if(k<i){
				rng(c,k,i){
					bk[c]++;
					q.unite(z[c].a,z[c+1].a);
				}
			}
			if(k>i){
				rng(c,i,k){
					fw[c]++;
					q.unite(z[c].a,z[c+1].a);
				}
			}
			
			i=z[k].b;
		}while(i!=0);
		assert(q.c==1);
	}
	assert(find(all(w),-1)==w.ed);
	tarscore*=2;
	dmp(w);
	
	vi cyc(n);
	rep(i,n)cyc[i]=winv[p[i]];
	
	vi ans;
	{
		int cur=0;
		do{
			ans.pb(cur);
			cur=cyc[cur];
		}while(cur!=0);
		assert(si(ans)==n);
	}
	reverse(ans.bg+1,ans.ed);
	
	{
		int curscore=calc(p,ans);
		dmp2(tarscore,curscore);
		assert(curscore==tarscore);
	}
	
	return ans;
}

vi brute(vi p){
	int n=si(p);
	int mn=inf;
	vi res;
	vi q(n);iota(all(q),0);
	do{
		if(chmin(mn,calc(p,q)))res=q;
	}while(next_permutation(all(q)));
	return res;
}

void slv(){
	int n;cin>>n;
	vi p=readvi(n,-1);
	print_offset(fast(p),1);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	if(0){
		rng(n,2,8){
			vi p(n);iota(all(p),0);
			do{
				vi god=brute(p);
				vi ans=fast(p);
				if(god!=ans){
					cerr<<p<<endl;
					cerr<<god<<endl;
					cerr<<ans<<endl;
				}
				assert(god==ans);
			}while(next_permutation(all(p)));
		}
	}else{
	int t;cin>>t;rep(_,t)
	slv();
}
}