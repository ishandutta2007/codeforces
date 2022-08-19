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

vi lens(string s){
	vi res;
	char pre='c';
	for(auto c:s){
		if(c!=pre){
			res.eb(0);
			pre=c;
		}
		res.back()++;
	}
	return res;
}

void sums(vi&x){
	rng(i,1,si(x))x[i]+=x[i-1];
}

vi shift(vi x,int off){
	vi res(si(x)+off);
	rep(i,si(x))res[i+off]=x[i];
	return res;
}

pair<int,vc<pi>> sub(vi x,vi y,int off,int k){
	dmp(off);
	bool rev=false;
	if(x.size()<y.size()){
		swap(x,y);
		rev=true;
	}
	if(si(y)==1&&k)return {inf,{}};
	dmp(x);
	dmp(y);
	int dif=x.size()-y.size();
	int mid=dif/2;
	int cut=mid+off;
	if(cut<0||dif<cut)return {inf,{}};
	vc<pi> res;
	dmp(y);
	dmp(k);
	if(cut||k){
		vi z(x.bg,x.bg+cut);
		x.erase(x.bg,x.bg+cut);
		vi w(y.bg,y.bg+k);
		y.erase(y.bg,y.bg+k);
		res.eb(accumulate(all(z),0),accumulate(all(w),0));
		if(si(x)%2==si(y)%2){
			if(si(z)){
				z.back()+=y[0];
				y.erase(y.bg);
			}
			if(si(w)){
				w.back()+=x[0];
				x.erase(x.bg);
			}
		}
		y.insert(y.bg,all(z));
		x.insert(x.bg,all(w));
	}
	dmp(x);
	dmp(y);
	sums(x);
	sums(y);
	int len=max(si(x),si(y));
	x=shift(x,len-si(x));
	y=shift(y,len-si(y));
	per(i,len-1){
		res.eb(x[i],y[i]);
		if((len-2-i)%2)swap(res.back().a,res.back().b);
	}
	if(rev)for(auto&p:res)swap(p.a,p.b);
	dmp(res);
	return {res.size(),res};
}

pair<int,vc<pi>> slv(string s,string t,bool rev){
	s+='a';
	t+='b';
	
	dmp(rev);
	
	vi x=lens(s),y=lens(t);
	dmp(x);
	dmp(y);
	
	pair<int,vc<pi>> ans(inf,{});
	rng(off,-4,5)rep(k,2)chmin(ans,sub(x,y,off,k));
	
	dmp(ans);
	
	if(rev){
		for(auto&p:ans.b)swap(p.a,p.b);
	}
	
	return ans;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	string s,t;
	
	bool dbg=true;
	dbg=false;
	if(!dbg){
		cin>>s>>t;
	}else{
		int n=1000;
		rep(i,n)s+=rand_int('a','b');
		rep(i,n)t+=rand_int('a','b');
	}
	
	pair<int,vc<pi>> ans=min(slv(s,t,false),slv(t,s,true));
	
	print(ans.a);
	for(auto p:ans.b){
		print(p.a,2);
		print(p.b);
		
		if(dbg)
		{
			cout<<endl;
			string x=t.substr(0,p.b)+s.substr(p.a);
			string y=s.substr(0,p.a)+t.substr(p.b);
			cerr<<x<<" "<<y<<endl;
			s=x;
			t=y;
		}
	}
}