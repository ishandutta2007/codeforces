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
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<endl;
	#else
	cout<<"Possible"<<endl;
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<endl;
	#else
	cout<<"Impossible"<<endl;
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

void imp(){
	cout<<-1<<endl;
	exit(0);
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

vvc<int> solvetree(vi d){
	assert(is_sorted(all(d)));
	int n=d.size();
	vvc<int> res(n);
	rep(i,n-1){
		assert(d[i]==1);
		rng(j,i+1,n)if(j==n-1||d[j]>1){
			res[j].pb(i);
			d[j]--;
			break;
		}
	}
	return res;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vi d=readvi(n);
	vi rawid(n);iota(all(rawid),0);
	sort(all(rawid),[&](int a,int b){return d[a]<d[b];});
	sort(all(d));
	
	int m=accumulate(all(d),0);
	if(m%2)imp();
	m/=2;
	int c=m-(n-1);
	if(c<0)imp();
	dmp(c);
	
	vc<vi> tris;
	if(c){
		int s=2*c+1;
		int k=0;
		if(s>n)imp();
		int sum=0;
		vi val(n);
		rep(i,n)val[i]=d[i]/2;
		rng(i,n-s,n)sum+=val[i];
		dmp(val);
		dmp(sum);
		if(sum<3*c){
			k=3*c-sum;
			s+=k;
			if(s>n)imp();
			rng(p,n-s,n-s+k)
				if(val[p]!=1){
					assert(val[p]==0);
					imp();
				}
		}
		dmp(k);
		rep(_,k){
			assert(s>=3);
			tris.pb({n-s,n-s+1,n-s+2});
			s-=3;
		}
		assert(s%2==1);
		assert(s>=3);
		vi tmp(s);
		int tar=s/2*3;
		int ds=0;
		while(ds<tar){
			bool upd=false;
			per(i,s)if(ds<tar&&tmp[i]<val[n-s+i]){
				tmp[i]++;
				ds++;
				upd=true;
			}
			assert(upd);
		}
		rep(i,s){
			if(tmp[i]==0)imp();
			tmp[i]*=2;
			if(i<s-1)tmp[i]--;
		}
		assert(is_sorted(all(tmp)));
		dmp(tmp);
		vvc<int> tr=solvetree(tmp);
		dmp(tr);
		dmp(s);
		rep(i,s){
			for(int j=0;j<(int)tr[i].size();j+=2){
				tris.pb({n-s+i,n-s+tr[i][j],n-s+tr[i][j+1]});
			}
		}
	}
	
	vi rem=d;
	for(auto t:tris)
		for(auto i:t)
			rem[i]-=2;
	assert((int)tris.size()==c);
	
	dmp(d);
	dmp(tris);
	dmp(rem);
	{
		
		while(1){
			vvc<int> tr(n+c);
			
			rep(i,c)
				for(auto j:tris[i]){
					tr[n+i].pb(j);
					tr[j].pb(n+i);
				}
			
			vi vis(n+c);
			
			pi waf(-1,-1);
			
			function<int(int,int)> dfs;
			dfs=[&](int v,int p){
				int res=0;
				if(v<n)res=rem[v];
				vis[v]=1;
				for(auto to:tr[v])if(to!=p){
					int w=dfs(to,v);
					if(res&&w){
						waf=pi(v,to);
					}
					res+=w;
				}
				return res;
			};
			
			rep(i,n)if(tr[i].size()&&!vis[i]&&rem[i])
				dfs(i,-1);
			
			bool upd=false;
			
			rep(i,c)if(!vis[n+i]){
				if(waf!=pi(-1,-1)){
					int a,b;tie(a,b)=waf;
					if(a<b)swap(a,b);
					a-=n;
					b=find(all(tris[a]),b)-tris[a].bg;
					swap(tris[a][b],tris[i][0]);
					upd=true;
					break;
				}else{
					rep(j,n)if(rem[j]>=2){
						tris[i].pb(j);
						rem[j]-=2;
						upd=true;
						break;
					}
					break;
				}
			}
			
			if(!upd)break;
		}
	}
	
	dmp(tris);
	dmp(rem);
	
	vc<pi> es;
	for(auto t:tris){
		rep(k,t.size())
			es.eb(t[k],t[(k+1)%t.size()]);
	}
	
	if(rem!=vi(n,0)){
		unionfind uf(n);
		
		for(auto t:tris){
			for(auto i:t)
				uf.unite(t[0],i);
		}
		
		vvc<int> vs(n);
		rep(i,n)rep(_,rem[i])
			vs[uf.find(i)].pb(i);
		
		vi idx;
		rep(i,n)if(uf.find(i)==i){
			assert(vs[i].size());
			idx.pb(i);
		}
		
		dmp(vs);
		dmp(idx);
		
		sort(all(idx),[&](int i,int j){return vs[i].size()<vs[j].size();});
		int s=idx.size();
		
		dmp(idx);
		
		vi tmp(s);
		rep(i,s)tmp[i]=vs[idx[i]].size();
		
		dmp(tmp);
		
		auto tr=solvetree(tmp);
		
		dmp(tr);
		
		rep(i,s){
			for(auto j:tr[i]){
				es.eb(vs[idx[i]].back(),vs[idx[j]].back());
				vs[idx[i]].pop_back();
				vs[idx[j]].pop_back();
			}
		}
	}
	
	assert((int)es.size()==m);
	
	cout<<m<<endl;
	for(auto e:es){
		cout<<2<<" "<<rawid[e.a]+1<<" "<<rawid[e.b]+1<<endl;
	}
}