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

vvc<int> dub(vi a){
	int n=a.size();
	int h=topbit(n)+1;
	vvc<int> res(h);
	res[0]=a;
	rng(i,1,h){
		res[i].resize(n,-1);
		rep(j,n)
			if(res[i-1][j]!=-1)
				res[i][j]=res[i-1][res[i-1][j]];
	}
	return res;
}

pair<int,vi> sub(int len,vi x,int m){
	//cerr<<x<<endl;
	dmp(x);
	int n=x.size();
	rep(i,n)x.pb(x[i]+len);
	n*=2;
	vi a(n,-1);
	map<int,int> pos;
	per(i,n){
		if(pos.count((x[i]+1)%m))a[i]=pos[(x[i]+1)%m];
		pos[x[i]%m]=i;
	}
	dmp(a);
	auto b=dub(a);
	dmp(b);
	pi mx(0,-1);
	rep(i,n/2){
		int cur=i,c=0;
		per(j,b.size()){
			if(b[j][cur]!=-1&&b[j][cur]<=i+n/2){
				c+=1<<j;
				cur=b[j][cur];
			}
		}
		chmax(mx,pi(c,i));
	}
	dmp(mx);
	int z=mx.a;
	while(z&&z%m!=len%m)z--;
	if(z==0)
		return make_pair(-1,vi{});
	vi res;
	int cur=mx.b;
	rep(i,z){
		res.pb(x[cur]%len);
		cur=a[cur];
	}
	dmp(res);
	sort(all(res));
	return make_pair(res.size(),res);
}

void waf(vi cur,int s,int k,int n,int off,vi&head,vvc<int>&val){
	dmp(cur);
	vi ex(cur.size(),s);
	int mn=inf;
	for(int ii=0;ii<(int)cur.size()-1;ii+=k-1){
		int i=min(ii,(int)cur.size()-k);
		int has=0;
		rng(j,ii,i+k)
			has+=cur[j];
		int tar=0;
		rng(j,ii,i+k)
			tar+=ex[j];
		//cerr<<i<<" "<<ex<<" "<<cur<<endl;
		if(has>=tar){
			head.pb((i+off)%n);
			val.eb(k);
			rng(j,i,ii)
				val.back()[j-i]=cur[j];
			rng(j,ii,i+k-1)
				has-=(val.back()[j-i]=ex[j]);
			val.back()[k-1]=has;
			cur[i+k-1]=has;
			for(int z=ii-(k-1);z>=mn;z-=(k-1)){
				head.pb((z+off)%n);
				val.eb(k,s);
				val.back()[0]=ex[z];
			}
			rng(j,min(mn,i),i+k){
				ex[j]=s;
			}
			rng(j,min(mn,i),i+k-1){
				cur[j]=s;
			}
			mn=inf;
		}else{
			ex[i+k-1]=tar-(has-cur[i+k-1]);
			chmin(mn,i);
		}
	}
	dmp(ex);
	assert(mn==inf);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,k;cin>>n>>k;
	vi a=readvi(n);
	
	int s=accumulate(all(a),int(0));
	s/=n;
	
	pair<int,vi> ans(0,vi{0});
	
	map<int,vi> pos;
	{
		int cur=0;
		rep(i,n){
			//cerr<<cur-s*i<<endl;
			pos[cur-s*i].pb(i);
			cur+=a[i];
		}
	}
	for(auto kv:pos){
		chmax(ans,sub(n,kv.b,k-1));
	}
	
	vi head;
	vvc<int> val;
	vi idx=ans.b;
	idx.pb(idx[0]+n);
	dmp(idx);
	rep(i,(int)idx.size()-1){
		int x=idx[i],y=idx[i+1];
		vi cur;
		rng(j,x,y)cur.pb(a[j%n]);
		waf(cur,s,k,n,x,head,val);
	}
	
	print(head.size());
	rep(i,head.size()){
		print(head[i],2);
		print(val[i]);
		int cnt=0;
		rng(j,head[i],head[i]+k)
			cnt+=a[j%n];
		assert(cnt==accumulate(all(val[i]),int(0)));
		rep(j,k)
			a[(head[i]+j)%n]=val[i][j];
	}
	assert(a==vi(n,s));
}