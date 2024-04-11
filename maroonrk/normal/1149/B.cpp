#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=long long;
//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) FOR(i,0,b)
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
#define REACH cerr<<"reached"<<endl
#define DMP(x) cerr<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))
#define ONE(x) memset(x,-1,sizeof(x))

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
vector<T> Uniqued(const vector<T>&vv){
	auto v(vv);
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	return v;
}
template<class T>
void MakeUniqued(vector<T>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.end());
}

const int Nmax=100010;
int nx[Nmax][26];
const int Lmax=260;
int dp[Lmax*Lmax*Lmax];

signed main(){
	int n=read(),q=read();
	{
		string s=readString();
		int cur[26];
		rep(i,26)
			cur[i]=n+1;
		rep(i,26){
			nx[n][i]=n+1;
			nx[n+1][i]=n+1;
		}
		for(int i=n-1;i>=0;i--){
			cur[s[i]-'a']=i+1;
			rep(j,26)
				nx[i][j]=cur[j];
		}
	}
	int len[3]{};
	string t[3];
	dp[0]=0;
	int ws[3]{Lmax*Lmax,Lmax,1};
	rep(_,q){
		string qt=readString();
		if(qt=="+"){
			int k=read()-1,c=readString()[0];
			t[k].pb(c);
			len[k]++;
			vi rem;
			rep(j,3)if(j!=k)
				rem.pb(j);
			auto g=[&](int x,int y,int z)->int&{
				return dp[x*ws[k]+y*ws[rem[0]]+z*ws[rem[1]]];
			};
			rep(a,len[rem[0]]+1){
				rep(b,len[rem[1]]+1){
					g(len[k],a,b)=nx[g(len[k]-1,a,b)][c-'a'];
					if(a>0)
						chmin(g(len[k],a,b),nx[g(len[k],a-1,b)][t[rem[0]][a-1]-'a']);
					if(b>0)
						chmin(g(len[k],a,b),nx[g(len[k],a,b-1)][t[rem[1]][b-1]-'a']);
				}
			}
		}else{
			int k=read()-1;
			t[k].pop_back();
			len[k]--;
		}
		if(dp[len[0]*ws[0]+len[1]*ws[1]+len[2]*ws[2]]<=n)
			Yes(0);
		else
			No(0);
	}
}