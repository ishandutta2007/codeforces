#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=long long;
#define int ll

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
#endif
#define reach cerr<<"reached"<<endl
void dmpr(decltype(cerr)&os){os<<endl;}
template<class T,class... Args>
void dmpr(decltype(cerr)&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp(...) dmpr(cerr,##__VA_ARGS__)
#define zero(x) memset(x,0,sizeof(x))
#define one(x) memset(x,-1,sizeof(x))
#define fs first
#define sc second

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

vi readVi(int n,int off=0){
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

#define CAPITAL
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

int topbit(signed t){
	return 31-__builtin_clz(t);
}
int topbit(ll t){
	return 63-__builtin_clzll(t);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(int(1)<<topbit(i))==i;
}

const int Nmax=1000010;
V<pi> tr[Nmax];
int z[Nmax];
void dfs(int v,int d){
	z[v]=d;
	for(auto e:tr[v])
		dfs(e.first,d^e.second);
}

signed main(){
	int n=read(),k=read();
	FOR(i,1,n){
		int p=read()-1,v=read();
		tr[p].eb(i,v);
	}
	dfs(0,0);
	cerr<<endl;
	sort(z,z+n);
	V<pair<pi,pi>> cur={mp(pi(0,n),pi(0,n))},nx;
	int ans=0;
	for(int i=61;i>=0;i--){
		//cerr<<i<<endl;
		int cnt=0;
		for(auto&p:cur){
			//cerr<<vi(z+p.fs.fs,z+p.fs.sc)<<endl;
			//cerr<<vi(z+p.sc.fs,z+p.sc.sc)<<endl;
			int x=p.fs.fs;
			while(x<p.fs.sc&&((z[x]>>i)&1)==0)x++;
			int y=p.sc.fs;
			while(y<p.sc.sc&&((z[y]>>i)&1)==0)y++;
			cnt+=(x-p.fs.fs)*(y-p.sc.fs)+(p.fs.sc-x)*(p.sc.sc-y);
		}
		//cerr<<cnt<<endl;
		nx.clear();
		for(auto&p:cur){
			int x=p.fs.fs;
			while(x<p.fs.sc&&((z[x]>>i)&1)==0)x++;
			int y=p.sc.fs;
			while(y<p.sc.sc&&((z[y]>>i)&1)==0)y++;
			if(k<=cnt){
				nx.eb(pi(p.fs.fs,x),pi(p.sc.fs,y));
				nx.eb(pi(x,p.fs.sc),pi(y,p.sc.sc));
			}else{
				nx.eb(pi(p.fs.fs,x),pi(y,p.sc.sc));
				nx.eb(pi(x,p.fs.sc),pi(p.sc.fs,y));
			}
		}
		if(cnt<k){
			k-=cnt;
			ans+=int(1)<<i;
		}
		cur.clear();
		for(auto&p:nx)
			if(p.fs.fs<p.fs.sc&&p.sc.fs<p.sc.sc)
				cur.pb(p);
	}
	print(ans);
}