#include <bits/stdc++.h>
using namespace std;

using uint=unsigned;
using ll=long long;
using ull=unsigned long long;
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

void AllNo(int q){
	rep(_,q)
		printf("Fou\n");
	exit(0);
}

//without rank
struct UnionFind{
	vi par,sz;
	UnionFind(int n){
		par.resize(n,-1);
		sz.resize(n,1);
	}
	int Find(int a){
		return par[a]==-1?a:(par[a]=Find(par[a]));
	}
	void Unite(int a,int b){
		a=Find(a);
		b=Find(b);
		if(a==b)return;
		assert(par[a]==-1);
		assert(par[b]==-1);
		par[b]=a;
		sz[a]+=sz[b];
	}
	int Size(int a){
		return sz[Find(a)];
	}
};

const int Nmax=150010;
int cnt[Nmax][26],ups[Nmax][26],sum[Nmax];
bool brk[Nmax];
int ch[Nmax][2];

signed main(){
	int n=read(),q=read();
	vi p(n,-1);
	V<char> cs(n);
	FOR(i,1,n){
		p[i]=read()-1;
		cs[i]=readString()[0];
		if(cs[i]!='?')
			ups[i][cs[i]-'a']++;
	}
	vi len(n,0);
	ROF(i,1,n){
		if(len[p[i]]&&len[p[i]]!=len[i]+1)
			AllNo(q);
		len[p[i]]=len[i]+1;
	}
	UnionFind uf(n);
	V<bool> al(n);
	{
		vi inc(n);
		FOR(i,1,n)
			inc[p[i]]++;
		inc[0]=2;
		FOR(i,1,n)if(inc[i]!=1){
			int x=p[i];
			while(inc[x]==1){
				uf.Unite(i,x);
				rep(k,26)
					ups[i][k]+=ups[x][k];
				x=p[x];
			}
			p[i]=x;
		}
		rep(i,n)
			al[i]=inc[i]!=1;
	}
	one(ch);
	FOR(i,1,n)if(al[i]){
		if(ch[p[i]][0]==-1)
			ch[p[i]][0]=i;
		else
			ch[p[i]][1]=i;
	}
	per(i,n)if(al[i]&&ch[i][0]!=-1){
		rep(c,2)if(ch[i][c]!=-1){
			rep(k,26)
				chmax(cnt[i][k],cnt[ch[i][c]][k]+ups[ch[i][c]][k]);
			brk[i]|=brk[ch[i][c]];
		}
		sum[i]=accumulate(cnt[i],cnt[i]+26,0);
		brk[i]|=sum[i]>len[i];
	}
	rep(_,q){
		int v=read()-1,x=uf.Find(v);
		char d=readString()[0];
		int pos[2]{-1,-1};
		if(d!=cs[v]){
			if(d!='?'){
				pos[0]=d-'a';
				ups[x][d-'a']++;
			}
			if(cs[v]!='?'){
				pos[1]=cs[v]-'a';
				ups[x][cs[v]-'a']--;
			}
			cs[v]=d;
			while(1){
				x=p[x];
				if(x==-1)break;
				brk[x]=false;
				rep(c,2)if(ch[x][c]!=-1)
					brk[x]|=brk[ch[x][c]];
				rep(k,2)if(pos[k]!=-1){
					sum[x]-=cnt[x][pos[k]];
					cnt[x][pos[k]]=0;
					rep(c,2)if(ch[x][c]!=-1)
						chmax(cnt[x][pos[k]],cnt[ch[x][c]][pos[k]]+ups[ch[x][c]][pos[k]]);
					sum[x]+=cnt[x][pos[k]];
				}
				brk[x]|=sum[x]>len[x];
			}
		}
		if(brk[0])
			printf("Fou\n");
		else{
			printf("Shi ");
			int f=len[0]-sum[0];
			int ans=0;
			rep(i,26)
				ans+=(i+1)*(cnt[0][i]+f);
			print(ans);
		}
	}
}