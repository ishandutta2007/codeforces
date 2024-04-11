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

const int Vmax=min<int>(2000010,mint::base);
mint fact[Vmax],factInv[Vmax],invs[Vmax];
void InitFact(){
	fact[0]=1;
	FOR(i,1,Vmax){
		fact[i]=fact[i-1]*i;
	}
	factInv[Vmax-1]=fact[Vmax-1].inv();
	for(int i=Vmax-2;i>=0;i--){
		factInv[i]=factInv[i+1]*(i+1);
	}
	for(int i=Vmax-1;i>=1;i--){
		invs[i]=factInv[i]*fact[i-1];
	}
}
struct InitFactDummy{
	InitFactDummy(){
		InitFact();
	}
} initFactDummy;
mint Choose(int n,int k){
	return fact[n]*factInv[n-k]*factInv[k];
}
mint Binom(int a,int b){
	return fact[a+b]*factInv[a]*factInv[b];
}
mint Catalan(int n){
	return Binom(n,n)-(n-1>=0?Binom(n-1,n+1):0);
}

const int B=510;
const int C=210;
const int Nmax=100010;

/*
const int B=2;
const int C=10;
const int Nmax=20;
*/

mint sum[C][Nmax];
mint dp[Nmax];
int raw[Nmax],off[C];

mint Get(int len,int k){
	cerr<<"Get "<<len<<endl;
	int blocks=len/B;
	mint res;
	REP(i,blocks){
		cerr<<i<<" "<<off[i]<<endl;
		int a=k-off[i];
		if(a>=0)
			res+=sum[i][a];
	}
	for(int i=blocks*B;i<len;i++)
		if(raw[i]+off[blocks]<=k)
			res+=dp[i];
	cerr<<res<<endl;
	return res;
}

//[)
void Add(int l,int r,int v){
	cerr<<"Add "<<l<<" "<<r<<" "<<v<<endl;
	int p=l/B,q=r/B;
	if(l%B)p++;
	if(p<=q){
		FOR(i,p,q)
			off[i]+=v;
		FOR(i,l,p*B){
			if(v==1){
				assert(raw[i]>=0);
				sum[p-1][raw[i]]-=dp[i];
			}else{
				assert(raw[i]>=1);
				sum[p-1][raw[i]-1]+=dp[i];
			}
			raw[i]+=v;
		}
		FOR(i,q*B,r){
			if(v==1){
				assert(raw[i]>=0);
				sum[q][raw[i]]-=dp[i];
			}else{
				assert(raw[i]>=1);
				sum[q][raw[i]-1]+=dp[i];
			}
			raw[i]+=v;
		}
	}else{
		FOR(i,l,r){
			if(v==1){
				assert(raw[i]>=0);
				sum[q][raw[i]]-=dp[i];
			}else{
				assert(raw[i]>=1);
				sum[q][raw[i]-1]+=dp[i];
			}
			raw[i]+=v;
		}
	}
}

void SetSum(int i){
	ZERO(sum[i]);
	assert(off[i]==0);
	cerr<<vector<mint>(sum[i],sum[i]+3)<<endl;
	FOR(j,i*B,(i+1)*B){
		cerr<<j<<" "<<raw[j]<<" "<<dp[j]<<endl;
		sum[i][raw[j]]+=dp[j];
	}
	cerr<<vector<mint>(sum[i],sum[i]+3)<<endl;
	REP(j,Nmax-1)
		sum[i][j+1]+=sum[i][j];
	cerr<<"Sum "<<i<<endl;
	cerr<<vector<mint>(sum[i],sum[i]+3)<<endl;
}

signed main(){
	int n=read(),k=read();
	bool dbg=n==-1;
	if(dbg){
		n=100000;
	}
	vi a(n);
	REP(i,n){
		if(!dbg)
			a[i]=read()-1;
		else
			a[i]=rand()%n;
	}
	vector<pi> pre(n,pi(-1,0));
	dp[0]=1;
	REP(i,n){
		if(pre[a[i]]!=pi(-1,0)){
			Add(pre[a[i]].first,pre[a[i]].second,-1);
		}
		pre[a[i]]=pi(pre[a[i]].second,i+1);
		Add(pre[a[i]].first,pre[a[i]].second,1);
		dp[i+1]=Get(i+1,k);
		if((i+1)%B==B-1)
			SetSum((i+1)/B);
	}
	print(dp[n]);
}