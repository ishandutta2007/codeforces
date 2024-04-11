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

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	int k;cin>>k;
	vvc<int> state(4);
	rep(i,4)state[i]=readvi(n,-1);
	vc<tuple<int,int,int>> ans;
	int rem=k;
	while(rem){
		vvc<int> vis(4,vi(n));
		auto dfs=[&](auto self,int r,int c,int z,vc<pi>&pos)->bool{
			if(inc(0,r,3)&&inc(0,c,n-1)){
				if((inc(1,r,2)&&state[r][c]==-1)||state[r][c]==z){
					if(!vis[r][c]){
						vis[r][c]=1;
						if(r==0||r==3)return true;
						rep(dir,4){
							const int dyx[]{-1,0,1,0,-1};
							int y=r+dyx[dir];
							int x=c+dyx[dir+1];
							pos.eb(y,x);
							if(self(self,y,x,z,pos))return true;
							pos.pop_back();
						}
					}
				}
			}
			return false;
		};
		bool f=false;
		rng(r,1,3)rep(c,n){
			if(!f&&state[r][c]!=-1){
				rep(i,4)rep(j,n)vis[i][j]=0;
				vc<pi> pos;
				if(dfs(dfs,r,c,state[r][c],pos)){
					dmp(state[r][c]);
					dmp(pos);
					for(auto p:pos)
						ans.eb(state[r][c],p.a,p.b);
					state[r][c]=-1;
					f=true;
				}
			}
		}
		if(!f){
			break;
		}
		rem--;
	}
	if(rem==2*n){
		print(-1);
		return 0;
	}
	auto waf=[&](int r_,int c_,int y,int x){
		if(y==0||y==3){
			ans.eb(state[r_][c_],y,x);
			state[r_][c_]=-1;
			return;
		}
		
		vvc<pi> vis(4,vc<pi>(n,pi(-1,-1)));
		vis[r_][c_]=pi(-2,-2);
		
		queue<pi> z;
		auto reach=[&](int p,int q,int r,int s){
			if(inc(1,p,2)&&inc(0,q,n-1)&&vis[p][q]==pi(-1,-1)){
				vis[p][q]=pi(r,s);
				z.emplace(p,q);
			}
		};
		reach(y,x,r_,c_);
		pi cur(-1,-1);
		while(si(z)){
			int p,q;tie(p,q)=z.front();z.pop();
			if(state[p][q]==-1){
				cur=pi(p,q);
				break;
			}
			rep(dir,4){
				const int dyx[]{-1,0,1,0,-1};
				int r=p+dyx[dir];
				int s=q+dyx[dir+1];
				reach(r,s,p,q);
			}
		}
		assert(cur!=pi(-1,-1));
		while(cur!=pi(r_,c_)){
			pi pre=vis[cur.a][cur.b];
			ans.eb(state[pre.a][pre.b],cur.a,cur.b);
			swap(state[pre.a][pre.b],state[cur.a][cur.b]);
			cur=pre;
		}
	};
	while(rem){
		bool f=false;
		rng(r,1,3)rep(c,n)if(!f&&state[r][c]!=-1){
			int y,x;
			for(auto i:{0,3})rep(j,n)if(state[i][j]==state[r][c])
				tie(y,x)=pi(i,j);
			int p=r,q=c;
			while(q<x){
				waf(p,q,p,q+1);
				q++;
			}
			while(q>x){
				waf(p,q,p,q-1);
				q--;
			}
			while(p<y){
				waf(p,q,p+1,q);
				p++;
			}
			while(p>y){
				waf(p,q,p-1,q);
				p--;
			}
			f=true;
		}
		assert(f);
		rem--;
	}
	assert(si(ans)<=20000);
	print(si(ans));
	for(auto q:ans){
		int a,b,c;tie(a,b,c)=q;
		cout<<a+1<<" "<<b+1<<" "<<c+1<<"\n";
	}
}