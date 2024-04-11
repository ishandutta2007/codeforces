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

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	
	vvc<pi> ans;
	vvc<int> raw(n);
	rep(i,n)raw[i]=readvi(m);
	vvc<int> x=raw;
	
	auto add=[&](vc<pi> w,bool rev){
		if(rev)reverse(all(w));
		ans.pb(w);
		rng(i,1,w.size())
			swap(x[w[0].a][w[0].b],x[w[i].a][w[i].b]);
	};
	
	auto rotR=[&](int r,int c,bool rev=false){
		assert(r<=n-2&&c<=m-2);
		vc<pi> w;
		w.eb(r,c);
		w.eb(r,c+1);
		w.eb(r+1,c+1);
		w.eb(r+1,c);
		add(w,rev);
	};
	auto rotR2H=[&](int r,int c,bool rev=false){
		assert(r<=n-2&&c<=m-3);
		vc<pi> w;
		w.eb(r,c);
		w.eb(r,c+1);
		w.eb(r,c+2);
		w.eb(r+1,c+2);
		w.eb(r+1,c+1);
		w.eb(r+1,c);
		add(w,rev);
	};
	auto rotR2V=[&](int r,int c,bool rev=false){
		assert(r<=n-3&&c<=m-2);
		vc<pi> w;
		w.eb(r,c);
		w.eb(r,c+1);
		w.eb(r+1,c+1);
		w.eb(r+2,c+1);
		w.eb(r+2,c);
		w.eb(r+1,c);
		add(w,rev);
	};
	auto rotR3=[&](int r,int c,bool rev=false){
		assert(r<=n-3&&c<=m-3);
		vc<pi> w;
		w.eb(r,c);
		w.eb(r,c+1);
		w.eb(r,c+2);
		w.eb(r+1,c+2);
		w.eb(r+2,c+2);
		w.eb(r+2,c+1);
		w.eb(r+2,c);
		w.eb(r+1,c);
		add(w,rev);
	};
	auto rotL=[&](int r,int c){
		rotR(r,c,true);
	};
	auto rotL2H=[&](int r,int c){
		rotR2H(r,c,true);
	};
	auto rotL2V=[&](int r,int c){
		rotR2V(r,c,true);
	};
	auto rotL3=[&](int r,int c){
		rotR3(r,c,true);
	};
	function<void(int,int)> waf,relka;
	//horizontal
	waf=[&](int r,int c){
		if(r>=n-2){
			rotR(r-1,c);
			rotR(r-1,c);
			waf(r-1,c);
			rotR(r-1,c);
			rotR(r-1,c);
			return;
		}
		if(c>=m-2){
			assert(c==m-2);
			rotL2H(r,c-1);
			waf(r,c-1);
			rotR2H(r,c-1);
			return;
		}
		assert(r<=n-3);
		assert(c<=m-3);
		rotR(r,c);
		rotR(r+1,c);
		rotR(r+1,c+1);
		rotR(r,c+1);
		rotL3(r,c);
	};
	//vertical
	relka=[&](int r,int c){
		if(c>=m-2){
			rotR(r,c-1);
			rotR(r,c-1);
			relka(r,c-1);
			rotR(r,c-1);
			rotR(r,c-1);
			return;
		}
		if(r>=n-2){
			assert(r==n-2);
			rotR2V(r-1,c);
			relka(r-1,c);
			rotL2V(r-1,c);
			return;
		}
		assert(r<=n-3);
		assert(c<=m-3);
		rotL(r,c);
		rotL(r,c+1);
		rotL(r+1,c+1);
		rotL(r+1,c);
		rotR3(r,c);
	};
	/*auto right=[&](int r,int c){
		if(r==n-1)
			waf(r,c);
		else
			rotR(r,c);
	};
	auto left=[&](int r,int c){
		if(r==n-1)
			waf(r,c-1);
		else
			rotL(r,c-1);
	};
	auto up=[&](int r,int c,int tar){
		if(c==m-1){
			if(r-1==tar)
				relka(r-1,c);
			else
				rotL(r-1,c-1);
		}else
			rotR(r-1,c);
	};*/
	
	auto right=[&](int r,int c){
		if(r==0)
			waf(r,c);
		else
			rotL(r-1,c);
	};
	auto left=[&](int r,int c){
		if(r==0)
			waf(r,c-1);
		else
			rotR(r-1,c-1);
	};
	auto down=[&](int r,int c,int tar){
		if(c==0){
			if(r+1==tar)
				relka(r,c);
			else
				rotL(r,c);
		}else
			rotR(r,c-1);
	};
	
	per(val,n*m){
		int r,c;
		rep(i,n)rep(j,m)if(x[i][j]==val+1)
			tie(r,c)=pi(i,j);
		while(c<val%m){
			right(r,c);
			c++;
		}
		while(c>val%m){
			left(r,c);
			c--;
		}
		/*while(r>val/m){
			up(r,c,val/m);
			r--;
		}*/
		while(r<val/m){
			down(r,c,val/m);
			r++;
		}
		dmp(ans.size());
	}
	
	print(ans.size());
	for(auto z:ans){
		vi w;
		for(auto p:z)
			w.pb(raw[p.a][p.b]);
		rng(i,1,z.size()){
			swap(raw[z[0].a][z[0].b],raw[z[i].a][z[i].b]);
		}
		cout<<z.size()<<" ";
		print(w);
	}
	dmp(raw);
	rep(i,n)rep(j,m)assert(raw[i][j]==i*m+j+1);
}