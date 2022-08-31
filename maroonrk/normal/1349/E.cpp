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

//[l,r)
bool canmake(int l,int r,int tar){
	if(tar<0)return false;
	if(tar==0)return true;
	int lw=0,up=r-l+1;
	while(up-lw>1){
		const int mid=(lw+up)/2;
		int v=(r-mid+r-1)*mid/2;
		if(v>=tar)up=mid;
		else lw=mid;
	}
	if(up==r-l+1)return false;
	int v=(l+l+up-1)*up/2;
	return v<=tar;
}

vi restore(int l,int r,int tar){
	if(tar<0)assert(0);
	if(tar==0)return {};
	int lw=0,up=r-l+1;
	while(up-lw>1){
		const int mid=(lw+up)/2;
		int v=(r-mid+r-1)*mid/2;
		if(v>=tar)up=mid;
		else lw=mid;
	}
	if(up==r-l+1)assert(0);
	int v=(l+l+up-1)*up/2;
	assert(v<=tar);
	vi res(up);
	rep(i,up)res[i]=l+i;
	int dif=tar-v;
	per(i,up){
		int u=min(r-up+i-res[i],dif);
		res[i]+=u;
		dif-=u;
	}
	assert(dif==0);
	return res;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vi t=readvi(n);
	t.pb(0);
	reverse(all(t));
	n++;
	for(auto&v:t)if(v)v+=n;
	t.pb(n++);
	dmp(t);
	
	vi pre(n,-1);
	pre[n-1]=-2;
	vi mx(n,-1);
	vi left(n);
	vc<tuple<int,int,int>> buf(n);
	int fix=n-1;
	deque<int> fr,bc;
	const int B=5;
	per(i,n-1){
		auto waf=[&](int z,int tar){
			if(i==1&&z==5){
				dmp(tar);
				dmp(mx[z]);
			}
			if(pre[z]!=-1){
				int ad=tar-t[z];
				if(canmake(left[z],z,ad)){
					buf[i]=mt(left[z],z,ad);
					pre[i]=z;
					return;
				}
			}
			if(mx[z]!=-1){
				int ad=tar-(t[z]-1);
				if(canmake(left[z],mx[z],ad)){
					buf[i]=mt(left[z],mx[z],ad);
					pre[i]=mx[z];
					return;
				}
			}
		};
		if(t[i]){
			fr.push_front(fix);
			while(t[fr.front()]!=t[fr.back()]){
				bc.push_front(fr.back());
				fr.pop_back();
			}
			left[fix]=i+1;
			fix=i;
			int tar=t[i]-i;
			dmp2(i,tar);
			if(i<B){
				bool ok=true;
				for(auto z:fr){
					if(ok)waf(z,tar);
					if(t[z]!=t[i]+1)ok=false;
				}
				for(auto z:bc){
					if(ok)waf(z,tar);
					if(t[z]!=t[i]+1)ok=false;
				}
			}else{
				if(t[fr[0]]==t[i]+1){
					if(si(bc)){
						waf(bc[0],tar);
					}
				}else{
					waf(fr[0],tar);
				}
			}
		}else if(si(fr)){
			int tar=t[fix]-1-i;
			if(i<B){
				bool ok=true;
				for(auto z:fr){
					if(ok)waf(z,tar);
					if(t[z]!=t[fix])ok=false;
				}
				for(auto z:bc){
					if(ok)waf(z,tar);
					if(t[z]!=t[fix])ok=false;
				}
			}else{
				if(t[fr[0]]==t[fix]){
					if(si(bc)){
						waf(bc[0],tar);
					}
				}else{
					waf(fr[0],tar);
				}
			}
			if(pre[i]!=-1&&mx[fix]==-1)mx[fix]=i;
		}
	}
	dmp(pre);
	dmp(buf);
	vi res(n);
	int cur;
	rep(i,n)if(pre[i]!=-1){
		cur=i;
		break;
	}
	while(1){
		res[cur]=1;
		if(pre[cur]==-2)break;
		int l,r,ad;
		tie(l,r,ad)=buf[cur];
		
		vi idx=restore(l,r,ad);
		for(auto i:idx)res[i]=1;
		
		cur=pre[cur];
	}
	dmp(res);
	gnr(i,1,n-1)print(res[i],0);
	cout<<endl;
}