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
	//#ifdef LOCAL
	static mt19937_64 gen;
/*	#else
    static random_device rd;
    static mt19937_64 gen(rd());
    #endif*/
    return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

//ARC055D
int gcd(int a,int b){return b?gcd(b,a%b):a;}
/*int gcd(int a,int b){
	if(a==0)return b;
	if(b==0)return a;
	if(a<0)a=-a;
	if(b<0)b=-b;
	int s=botbit(a|b);
	a>>=botbit(a);
	do{
		b>>=botbit(b);
		if(a>b)swap(a,b);
		b-=a;
	}while(b);
	return a<<s;
	
}*/
int lcm(int a,int b){return a/gcd(a,b)*b;}

int extgcd(int a,int b,int&x,int&y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}else{
		int g=extgcd(b,a%b,y,x);
		y-=a/b*x;
		return g;
	}
}

//x*y=g mod m
//returns (g,y)
pi modinv(int x,int m){
	int a,b;
	int g=extgcd(x,m,a,b);
	if(a<0)a+=m/g;
	return pi(g,a);
}

//x = a mod b
//x = c mod d
// => x = p mod q
//returns (-1,-1) when infeasible
pi crt(int a,int b,int c,int d){
	if(b<d){
		swap(a,c);
		swap(b,d);
	}
	c%=d;
	int g,e;
	tie(g,e)=modinv(b,d);
	int k=(c-a);
	if(k%g)return pi(-1,-1);
	k/=g;
	int m=b/g*d;
	int x=(a+k*e%(d/g)*b)%m;
	if(x<0)x+=m;
	return pi(x,m);
}

bool dbg=false;
vi ysp;

int qcnt;

vi kmzk;

bool ask(vi a){
	assert(si(a));
	if(si(a)==1)return true;
	qcnt++;
	for(auto&v:a)v=kmzk[v];
	if(dbg){
		int s=0;
		for(auto i:a)s+=ysp[i];
		return s%si(a)==0;
	}else{
		cout<<"? "<<si(a);
		for(auto v:a)cout<<" "<<v+1;
		cout<<endl;
		return read();
	}
}

void shf(vi&a){
	rep(i,si(a))swap(a[i],a[rand_int(0,i)]);
}

pi getmnmx(vi x){
	assert(si(x)%2==0);
	if(si(x)==2)return {x[0],x[1]};
	int n=si(x);
	shf(x);
	int a=-1,b=-1;
	rep(i,n){
		vi y=x;
		y.erase(y.bg+i);
		if(ask(y)){
			if(a==-1)a=x[i];
			else{
				b=x[i];
				break;
			}
		}
	}
	return pi(a,b);
}

void answer(vi a){
	dmp(a);
	int n=si(a);
	rep(i,n)assert(inc(1,a[i],n));
	{
		vi b(n);
		rep(i,n)b[kmzk[i]]=a[i];
		a=b;
	}
	if(a[0]>n/2){
		for(auto&v:a)v=n+1-v;
	}
	cout<<"!";
	for(auto v:a)cout<<" "<<v;
	cout<<endl;
	dmp(ysp);
	if(dbg)assert(a==ysp);
	cerr<<qcnt<<"/"<<n*18<<endl;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	if(n<0){
		dbg=true;
		n=-n;
		ysp.resize(n);
		iota(all(ysp),1);
		shf(ysp);
		if(ysp[0]>n/2){
			for(auto&v:ysp)v=n+1-v;
		}
	}
	kmzk.resize(n);
	iota(all(kmzk),0);
	shf(kmzk);
	
	int h=min(n/2,int(8));
	
	vi dec(n);
	
	rep(lv,h){
		vi idx;
		rep(i,n)if(!dec[i])idx.pb(i);
		int a,b;tie(a,b)=getmnmx(idx);
		if(lv!=0){
			rep(i,n)if(dec[i]==1){
				if(ask({i,b}))swap(a,b);
			}
		}
		int c=lv+1,d=n-lv;
		if(c%2==0)swap(c,d);
		dec[a]=c;
		dec[b]=d;
	}
	
	dmp(dec);
	
	vi pos(n+1,-1);
	
	if(8<n){
		dmp(ysp);
		rep(i,n)if(dec[i]){
			pos[dec[i]]=i;
		}
		dmp(pos);
		rep(i,n)if(!dec[i]){
			int a=0,b=1;
			for(int v:{3,5,7,8}){
				{
					int num=0;
					rng(t,1,n+1)if(t%b==a&&pos[t]==-1)num++;
					assert(num);
					if(num==1)break;
				}	
				vi u(pos.bg+1,pos.bg+v+1);
				shf(u);
				u.pb(i);
				rep(j,v){
					vi w=u;
					w.erase(w.bg+j);
					int sum=0;
					rep(k,v-1)sum+=dec[w[k]];
					int m=(v-sum%v)%v;
					dmp2(i,m,v);
					int e,f;
					tie(e,f)=crt(a,b,m,v);
					{
						int num=0;
						rng(t,1,n+1)if(t%f==e&&pos[t]==-1)num++;
						if(num==0)continue;
					}
					if(j==v-1||ask(w)){
						tie(a,b)=pi(e,f);
						break;
					}
				}
			}
			while(a==0||pos[a]!=-1)a+=b;
			dec[i]=a;
			pos[a]=i;
		}
	}
	
	answer(dec);
}