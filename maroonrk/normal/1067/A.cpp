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

constexpr ll Ten(int n){
	return n==0?1:Ten(n-1)*10;
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
template<int mod>
struct ModInt{
	static constexpr int base=mod;
	int v;
	ModInt():v(0){}
	ModInt(ll vv){
		v=vv%mod;
		if(v<0)v+=mod;
	}
	explicit operator bool()const{
		return v;
	}
	explicit operator int()const{
		return v;
	}
	bool operator==(const ModInt&rhs)const{
		return v==rhs.v;
	}
	bool operator!=(const ModInt&rhs)const{
		return v!=rhs.v;
	}
	ModInt operator-()const{
		return ModInt(0)-*this;
	}
	ModInt& operator+=(const ModInt&rhs){
		v+=rhs.v;
		if(v>=mod)v-=mod;
		return *this;
	}
	ModInt&operator-=(const ModInt&rhs){
		v-=rhs.v;
		if(v<0)v+=mod;
		return *this;
	}
	ModInt&operator*=(const ModInt&rhs){
		v=ll(v)*rhs.v%mod;
		return *this;
	}
	ModInt&operator/=(const ModInt&rhs){
		operator*=(rhs.inv());
		return *this;
	}
	ModInt operator+(const ModInt&rhs)const{
		return ModInt(*this)+=rhs;
	}
	ModInt operator-(const ModInt&rhs)const{
		return ModInt(*this)-=rhs;
	}
	ModInt operator*(const ModInt&rhs)const{
		return ModInt(*this)*=rhs;
	}
	ModInt operator/(const ModInt&rhs)const{
		return ModInt(*this)/=rhs;
	}
	friend ModInt operator+(int x,const ModInt&y){
		return ModInt(x)+y;
	}
	friend ModInt operator-(int x,const ModInt&y){
		return ModInt(x)-y;
	}
	friend ModInt operator*(int x,const ModInt&y){
		return ModInt(x)*y;
	}
	friend ModInt operator/(int x,const ModInt&y){
		return ModInt(x)/y;
	}
	ModInt pow(int n)const{
		ModInt res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	ModInt inv()const{
		return pow(mod-2);
	}
};

template<int mod>
ostream& operator<<(ostream&os,const ModInt<mod>&m){
	return os<<m.v;
}
template<int mod>
void print(const ModInt<mod>&m,int suc=1){
	print(m.v,suc);
}

//using mint=ModInt<1000000007>;
using mint=ModInt<998244353>;

const int Vmax=210;
mint dp[2][Vmax][2];

signed main(){
	int n=read();
	int cur=0;
	dp[cur][0][1]=1;
	REP(_,n){
		int nx=cur^1;
		ZERO(dp[nx]);
		int a=read();
		REP(i,201){
			dp[nx][i][1]+=dp[cur][i][0];
			dp[nx][i+1][1]-=dp[cur][i][0];
			dp[nx][i+1][0]+=dp[cur][i][0];
			
			dp[nx][0][1]+=dp[cur][i][1];
			dp[nx][i+1][1]-=dp[cur][i][1];
			dp[nx][i+1][0]+=dp[cur][i][1];
		}
		REP(i,201)REP(j,2){
			dp[nx][i+1][j]+=dp[nx][i][j];
		}
		REP(i,201){
			if(i==0||(a!=-1&&a!=i))
				REP(j,2)
					dp[nx][i][j]=0;
		}
		cur=nx;
	}
	mint ans=0;
	REP(i,201)
		ans+=dp[cur][i][1];
	print(ans);
}