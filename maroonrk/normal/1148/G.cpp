#include <bits/stdc++.h>
using namespace std;

using uint=unsigned;
using ll=long long;
using ull=unsigned long long;
//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) FOR(i,0,b)
#define ROF(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) ROF(i,0,b)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
auto& errStream=cerr;
#ifdef LOCAL
#define cerr (cerr<<"-- line "<<__LINE__<<" -- ")
void dmpr(decltype(cerr)&os){os<<endl;}
template<class T,class... Args>
void dmpr(decltype(cerr)&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp(...) dmpr(cerr,##__VA_ARGS__)
#else
class CerrDummy{}cerrDummy;
template<class T>
CerrDummy& operator<<(CerrDummy&cd,const T&){
	return cd;
}
using charTDummy=char;
using traitsDummy=char_traits<charTDummy>;
CerrDummy& operator<<(CerrDummy&cd,basic_ostream<charTDummy,traitsDummy>&(basic_ostream<charTDummy,traitsDummy>&)){
	return cd;
}
#define cerr cerrDummy
#define dmp(...) void(0)
#endif
#define reach cerr<<"reached"<<endl
#define zero(x) memset(x,0,sizeof(x))
#define one(x) memset(x,-1,sizeof(x))
#define fs first
#define sc second
#define bg begin()
#define ed end()

template<class T> using V=vector<T>;
template<class T> using VV=V<V<T>>;

using pi=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	rep(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
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
	os<<"(";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<")";
}

ll read(){
	ll i;
	scanf("%lld",&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(ll x,int suc=1){
	printf("%lld",x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
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
	static char buf[3341000];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341000];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(b<a)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

//#define CAPITAL
void Yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void No(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

constexpr ll TEN(int n){
	return n==0?1:TEN(n-1)*10;
}

template<class T>
vector<T> uni(const vector<T>&vv){
	auto v(vv);
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	return v;
}
template<class T>
void mkuni(vector<T>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.end());
}

//ayasii
int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
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

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

struct BIT{
	vi buf;
	int s;
	BIT(int n=0){
		init(n);
	}
	void init(int n){
		buf.resize(s=n,0);
	}
	void add(int i,int v){
		for(;i<s;i+=(i+1)&(-i-1))
			buf[i]+=v;
	}
	int get(int i){
		int res=0;
		for(;i>=0;i-=(i+1)&(-i-1))
			res+=buf[i];
		return res;
	}
	int rng(int b,int e){
		return get(e-1)-get(b-1);
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
};

struct Point1D{
	BIT bit;
	vi pos;
	void addp(int p){
		pos.pb(p);
	}
	void init(){
		mkuni(pos);
		bit.init(pos.size());
	}
	int idx(int p){
		return lower_bound(all(pos),p)-pos.begin();
	}
	void addv(int p,int v){
		bit.add(idx(p),v);
	}
	int rng(int b,int e){
		return bit.rng(idx(b),idx(e));
	}
	int get(int i){
		return bit.get(upper_bound(all(pos),i)-pos.bg-1);
	}
};

const int S=TEN(7)+10;
//const int S=100000;

Point1D buf[S];

vi factors(int x){
	vi res;
	for(int i=2;i*i<=x;i+=(i==2?1:2)){
		if(x%i==0){
			res.pb(i);
			while(x%i==0)
				x/=i;
		}
	}
	if(x>1)res.pb(x);
	sort(all(res));
	return res;
}

VV<int> build(vi a){
	//sort(all(a));
	map<int,int> cnt;
	for(auto v:a)
		cnt[v]++;
	mkuni(a);
	dmp(a);
	int n=a.size();
	VV<pi> fs(n);
	rep(i,n){
		vi f=factors(a[i]);
		dmp(a[i],f);
		rep(bit,1<<f.size()){
			int j=1,w=1;
			rep(k,f.size())if(bit&1<<k){
				j*=f[k];
				w=-w;
			}
			buf[j].addp(i);
			fs[i].eb(j,w);
		}
	}
	dmp();
	rep(i,S)
		buf[i].init();
	dmp();
	rep(i,n)
		for(auto f:fs[i])
			buf[f.fs].addv(i,f.sc);
	
	const auto has=[&](int i,int up){
		int s=0;
		for(auto f:fs[i])
			s+=buf[f.fs].get(up);
		return bool(s);
	};
	
	VV<int> res;
	V<bool> u(n);
	rep(i,n)if(!u[i]){
		dmp(i);
		vi r;
		const auto add=[&](int x){
			dmp(x);
			r.pb(x);
			u[x]=1;
			for(auto f:fs[x])
				buf[f.fs].addv(x,-f.sc);
		};
		add(i);
		int j=0;
		while(j<(int)r.size()){
			if(!has(r[j],n-1))
				j++;
			else{
				int lw=-1,up=n-1;
				while(up-lw>1){
					int m=(lw+up)/2;
					if(has(r[j],m))
						up=m;
					else
						lw=m;
				}
				add(up);
			}
		}
		if(r.size()==1){
			rep(_,cnt[a[r[0]]])
				res.pb({a[r[0]]});
		}else{
			vi z;
			rep(k,r.size()){
				int s=j==0?1:cnt[a[r[k]]];
				rep(_,s)
					z.pb(a[r[k]]);
			}
			rep(_,cnt[a[r[0]]]-1)
				z.pb(a[r[0]]);
			res.pb(z);
		}
	}
	
	return res;
}

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

signed main(){
	int n=read(),k=read();
	vi a=readvi(n);
	map<int,vi> cnt;
	rep(i,n)
		cnt[a[i]].pb(i);
	const auto Ans=[&](vi x){
		dmp(x);
		#ifdef LOCAL
		int s=x.size();
		int d=0;
		rep(i,s){
			int c=0;
			rep(j,s)if(i!=j)
				c+=gcd(x[i],x[j])>1;
			d+=c==s-1;
			dmp(i,c);
		}
		dmp(d);
		assert(d==0||d==s);
		#endif
		vi vs;
		for(auto v:x){
			assert(cnt[v].size());
			vs.pb(cnt[v].back()+1);
			cnt[v].pop_back();
		}
		print(vs);
		exit(0);
	};
	auto r=build(a);
	dmp(r);
	if((int)r.size()>=k){
		vi x(k);
		rep(i,k)
			x[i]=r[i][0];
		Ans(x);
	}else{
		vi u(r.size());
		rep(i,r.size())if(r[i].size()>=2){
			if(k>=2){
				u[i]=2;
				k-=2;
			}
		}
		vi x;
		rep(i,r.size())if(r[i].size()>=2){
			while(int(r[i].size())>u[i]&&k){
				u[i]++;
				k--;
			}
			rep(j,u[i])
				x.pb(r[i][j]);
		}
		assert(k==0);
		Ans(x);
	}
}