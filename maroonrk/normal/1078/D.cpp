#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=int64_t;
//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(x) x.begin(),x.end()
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
#define REACH cerr<<"reached"<<endl
#define DMP(x) cerr<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))
#define ONE(x) memset(x,-1,sizeof(x))

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
	REP(i,(int)v.size()){
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
	scanf("%"  SCNd64,&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(ll x,int suc=1){
	printf("%" PRId64,x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

template<class T>
void print(const vector<T>&v){
	REP(i,v.size())
		print(v[i],i==int(v.size())-1?1:2);
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
vector<T> Uniqued(const vector<T>&vv){
	auto v(vv);
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	return v;
}
template<class T>
void MakeUniqued(vector<T>&v){
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
}

int TopBit(signed t){
	return 31-__builtin_clz(t);
}
int TopBit(ll t){
	return 63-__builtin_clzll(t);
}
int PopCount(signed t){
	return __builtin_popcount(t);
}
int PopCount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(int(1)<<TopBit(i))==i;
}

template<class T>
struct SparseTableMax{
	vector<vector<T>> st;
	void Init(const vector<T>& data){
		if(data.empty())
			return;
		int n=data.size(),h=TopBit(n);
		st.resize(h+1);
		st[0]=data;
		FOR(j, 1, h + 1){
			st[j].resize(n-(1<<j)+1);
			REP(i,n-(1<<j)+1)
				st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		}
	}
	T GetMax(int b, int e){
		int diff = TopBit(e-b);
		return max(st[diff][b], st[diff][e - (1 << diff)]);
	}
};
template<class T>
struct SparseTableMin{
	vector<vector<T>> st;
	void Init(const vector<T>& data){
		if(data.empty())
			return;
		int n=data.size(),h=TopBit(n);
		st.resize(h+1);
		st[0]=data;
		FOR(j, 1, h + 1){
			st[j].resize(n-(1<<j)+1);
			REP(i,n-(1<<j)+1)
				st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		}
	}
	T GetMin(int b, int e){
		int diff = TopBit(e-b);
		return min(st[diff][b], st[diff][e - (1 << diff)]);
	}
};

const int Nmax=300010;
const int Lmax=19;

int limR[Nmax][Lmax],limL[Nmax][Lmax];
SparseTableMax<pi> str;
SparseTableMin<pi> stl;
void Init(vi len){
	int n=len.size();
	vector<pi> rawR(n),rawL(n);
	REP(i,n){
		rawR[i]=pi(min(n-1,i+len[i]),i);
		rawL[i]=pi(max(int(0),i-len[i]),i);
	}
	str.Init(rawR);
	stl.Init(rawL);
	REP(i,n){
		limR[i][0]=rawR[i].first;
		limL[i][0]=rawL[i].first;
	}
	FOR(j,1,Lmax){
		REP(i,n){
			int p=str.GetMax(limL[i][j-1],limR[i][j-1]+1).second;
			int q=stl.GetMin(limL[i][j-1],limR[i][j-1]+1).second;
			limL[i][j]=min(limL[p][j-1],limL[q][j-1]);
			limR[i][j]=max(limR[p][j-1],limR[q][j-1]);
		}
	}
}

signed main(){
	int n=read();
	if(n==1){
		print(0);
		return 0;
	}
	vi len(n);
	REP(i,n)
		len[i]=read();
	REP(i,n*2)
		len.PB(len[i]);
		
	Init(len);
	
	REP(i,n){
		int ans=0;
		int p=n+i,q=n+i;
		for(int j=Lmax-1;j>=0;j--){
			int x=stl.GetMin(p,q+1).second;
			int y=str.GetMax(p,q+1).second;
			int nxp=min(limL[x][j],limL[y][j]);
			int nxq=max(limR[x][j],limR[y][j]);
			if(nxq-nxp<n-1){
				ans+=1<<j;
				p=nxp;
				q=nxq;
			}
		}
		print(ans+1,i==n-1?1:2);
	}
}