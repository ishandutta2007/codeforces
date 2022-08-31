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

const int nmax=200010;
int val[nmax];

ll sub(int h,int w,int k,int r){
	ll res=0;
	res+=ll(h/k)*w;
	h%=k;
	res+=ll(w/k)*h;
	w%=k;
	{
		if(w&&h&&r<=w-1+h-1){
			res+=r+1;
			if(r>=w)res-=r-w+1;
			if(r>=h)res-=r-h+1;
		}
	}
	r+=k;
	{
		if(w&&h&&r<=w-1+h-1){
			res+=r+1;
			if(r>=w)res-=r-w+1;
			if(r>=h)res-=r-h+1;
		}
	}
	return res;
}

const int V=255;
const int K=805;
//const int K=nmax;

int _cnt[V*nmax];
int p[nmax],w[nmax],h[nmax];

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	string s;cin>>s;
	//s=string(200000,'1');
	/*{
		int n=30;
		s=string(n,'1');
		rep(i,n)
			s[i]=rand_int('0','1');
	}*/
	int n=s.size();
	
	ll ans=0;
	rng(v,1,V-3){
		int num=0,j=0;
		int*cnt=_cnt+n*v;
		val[0]=0;
		rep(i,n){
			val[i+1]=val[i]+1;
			if(s[i]=='1'){
				val[i+1]-=v;
				num++;
			}
			while(num>K){
				cnt[val[j]]++;
				if(s[j]=='1')num--;
				j++;
			}
			ans+=cnt[val[i+1]];
		}
		rep(i,n+1)
			cnt[val[i]]=0;
	}
	cerr<<ans<<endl;
	int len=0;
	rep(i,n)if(s[i]=='1')
		p[len++]=i;
	rep(i,len){
		h[i]=p[i]-(i==0?-1:p[i-1]);
		w[i]=(i==len-1?n:p[i+1])-p[i];
	}
	rep(i,len){
		for(int j=i,k=1;j<len&&k<=K;j++,k++){
			int z=p[j]+1-p[i];
			int rem=(k-z%k);
			if(rem>=k)rem-=k;
			ans+=sub(h[i],w[j],k,rem);
		}
	}
	
	/*{
		int waf=0;
		rep(i,n){
			int c=0;
			rng(j,i,n){
				if(s[j]=='1')c++;
				if(c&&(j-i+1)%c==0)
					waf++;
			}
		}
		cerr<<ans<<" "<<waf<<endl;
		assert(ans==waf);
	}*/
	
	cout<<ans<<endl;
}