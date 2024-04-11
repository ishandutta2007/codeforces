#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=int64_t;
#define int ll

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

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int lcm(int a,int b){
	return a/gcd(a,b)*b;
}

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

//x_i=floor((a*i+b)/c), i=0,1,..n-1
//a,c>0, b>=0
//verified: CF530E
int gauss_sum(int n,int a,int b,int c){
	if(n==0)return 0;
	int res=0;
	{
		int p=a/c;
		res+=n*(n-1)/2*p;
		a%=c;
	}
	{
		int p=b/c;
		res+=n*p;
		b%=c;
	}
	if(a==0)return res;
	int top=(a*(n-1)+b)/c;
	res+=top*n;
	int h=(b+1+c-1)/c;
	if(h<=top)
		res-=gauss_sum(top-h+1,c,c*h-(b+1),a)+top-h+1;
	return res;
}

const int Vmax=300005;
//const int Vmax=20;
vi divs[Vmax];
void InitDivs(){
	FOR(i,1,Vmax)
		for(int j=i;j<Vmax;j+=i)
			divs[j].PB(i);
}
bool pri[Vmax];
void InitPrime(){
	FOR(i,2,Vmax)
		pri[i]=1;
	FOR(i,2,Vmax)if(pri[i])
		for(int j=i*2;j<Vmax;j+=i)
			pri[j]=0;
}
vi factors[Vmax];
void InitFactor(){
	FOR(i,2,Vmax)if(pri[i])
		for(int j=i;j<Vmax;j+=i)
			factors[j].PB(i);
}
int mebius[Vmax];
void InitMebius(){
	FOR(i,1,Vmax){
		mebius[i]=1;
		for(auto p:factors[i]){
			mebius[i]=-mebius[i];
			if(i%(p*p)==0){
				mebius[i]=0;
				break;
			}
		}
	}
}

bool has[Vmax];
int buf[Vmax];
vi ok[Vmax];
void InitOK(){
	FOR(i,1,Vmax){
		int s=(Vmax-1)/i;
		FOR(j,1,s+1)if(has[i*j])
			for(auto d:divs[j])
				buf[d]+=mebius[d];
		FOR(j,1,s+1){
			int w=0;
			for(auto d:divs[j])
				w+=buf[d];
			if(w)
				ok[i].PB(i*j);
		}
		FOR(j,1,s+1)
			buf[j]=0;
	//	cerr<<i<<" "<<ok[i]<<endl;
	}
}

signed main(){
	InitDivs();
	InitPrime();
	InitFactor();
	InitMebius();
	
	int n=read();
	vi a(n);
	REP(i,n)
		a[i]=read();
	MakeUniqued(a);
	
	for(auto v:a)
		has[v]=true;
	InitOK();
	
	vi dp(Vmax,inf);
	for(auto v:a)
		dp[v]=1;
	
	
	REP(_,20){
		for(int i=Vmax-1;i>=1;i--){
			for(auto j:ok[i])
				chmin(dp[i],dp[j]+1);
		}
	}
	if(dp[1]<inf)
		print(dp[1]);
	else
		print(-1);
}