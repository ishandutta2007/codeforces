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

vi pos(string s){
	cout<<"? "<<s<<endl;
	int k;cin>>k;
	if(k==-1)exit(0);
	return readvi(k,-1);
}

void answer(string s){
	cout<<"! "<<s<<endl;
	int res;cin>>res;
	if(res==0)exit(0);
}

string base="CHO";

vc<string> queries;
vc<string> fours;
vc<string> shote
{
	"CC",
	"HH",
	"OO",
};

map<vc<string>,pair<double,string>> memo;

map<vi,vc<string>> nextstep(const vc<string>&ss,const string&q){
	map<vi,vc<string>> res;
	for(auto&s:ss){
		vi x;
		rep(i,si(s)-si(q)+1)
			if(s.substr(i,si(q))==q)
				x.pb(i);
		res[x].pb(s);
	}
	return res;
}

pair<double,string> calc(const vc<string>&ss,int cur=0){
	if(memo.count(ss))return memo[ss];
	if(si(ss)==1)return mp(0.0,"");
	double mnv=inf;
	string mnq;
	for(auto q:queries){
		if(cur<si(shote)&&shote[cur]!=q)continue;
		if(si(ss)>2&&si(q)==4)continue;
		auto nx=nextstep(ss,q);
		if(si(nx)>1||cur<si(shote)){
			double val=0;
			for(auto kv:nx)
				chmax(val,calc(kv.b,cur+1).a);
			val+=1.0/sq(si(q));
			if(val<mnv){
				mnv=val;
				mnq=q;
				//if(si(ss)==81&&mnv<=1.4)
				//	break;
			}
		}
	}
	if(memo.count(ss))return memo[ss];
	return memo[ss]=mp(mnv,mnq);
}

void slv4(){
	vc<string> cur=fours;
	while(si(cur)>1){
		string q=calc(cur).b;
		vi z=pos(q);
		cur=nextstep(cur,q)[z];
	}
	answer(cur[0]);
}

void slv(){
	int n;cin>>n;
	
	if(n==4)return slv4();
	
	
	string ans(n,'?');
	
	vi same(n-1);
	auto fillans=[&](){
		rep(i,n-1)if(ans[i]!=base[0]&&ans[i+1]!=base[0]){
			if(same[i])ans[i+1]=ans[i];
			else ans[i+1]=base[1]+base[2]-ans[i];
		}
	};
	rep(i,3){
		vi p=pos(""s+base[0]+base[i]);
		for(auto j:p){
			ans[j]=base[0];
			ans[j+1]=base[i];
			if(i==0)same[j]=1;
		}
	}
	rng(i,1,3){
		vi p=pos(""s+base[i]+base[i]);
		for(auto j:p){
			ans[j]=base[i];
			ans[j+1]=base[i];
			same[j]=1;
		}
	}
	if(ans[0]!=base[0]){
		ans[0]=base[1];
		fillans();
		vi z=pos(string(ans.bg,ans.bg+n-1));
		if(si(z)==0||z[0]!=0)
			ans[0]=base[2];
	}
	fillans();
	if(ans[n-2]!=base[0]&&!same[n-2]){
		fillans();
		vi z=pos(ans);
		if(si(z)==0)
			ans[n-1]=base[0];
	}
	fillans();
	answer(ans);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	{
		rep(i,3)rep(j,3){
			queries.pb(""s+base[i]+base[j]);
		}
		rep(i,3)rep(j,3)rep(k,3){
			queries.pb(""s+base[i]+base[j]+base[k]);
			//fours.pb(""s+base[i]+base[j]+base[k]);
		}
		rep(i,3)rep(j,3)rep(k,3)rep(l,3){
			queries.pb(""s+base[i]+base[j]+base[k]+base[l]);
			fours.pb(""s+base[i]+base[j]+base[k]+base[l]);
		}
		//dmp(fours.size());
		//dmp(calc(fours));
		cerr<<calc(fours)<<endl;
	}
	
	int t;cin>>t;rep(_,t)slv();
}