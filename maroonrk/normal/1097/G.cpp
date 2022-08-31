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

template<int mod>
struct ModInt{
	int v;
	ModInt():v(0){}
	ModInt(int vv):v((vv%mod+mod)%mod){}
	explicit operator bool()const{
		return v;
	}
	explicit operator int()const{
		return v;
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
		v*=rhs.v;
		v%=mod;
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

using mint=ModInt<1000000007>;

const int Vmax=2000010;
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
mint Choose(int n,int k){
	return fact[n]*factInv[n-k]*factInv[k];
}
mint Binom(int a,int b){
	return fact[a+b]*factInv[a]*factInv[b];
}
mint Catalan(int n){
	return Binom(n,n)-(n-1>=0?Binom(n-1,n+1):0);
}

const int Nmax=100010;
const int Kmax=210;
int n,k,ss[Nmax];
mint dp[Nmax][Kmax];
vi tr[Nmax];

int dfs1(int v,int p){
	ss[v]=1;
	for(auto to:tr[v])
		if(to!=p)
			ss[v]+=dfs1(to,v);
	return ss[v];
}

mint p2[Nmax],p2inv[Nmax];
void Init(){
	REP(i,Nmax){
		p2[i]=mint(2).pow(i);
		p2inv[i]=p2[i].inv();
	}
}

mint waf[Kmax];
void dfs2(int v,int p){
	dp[v][0]=1;
	int s=0;
	for(auto to:tr[v])
		if(to!=p){
			dfs2(to,v);
			int z=min(k,ss[to]);
			for(int i=s;i>=0;i--){
				mint w=dp[v][i];
				dp[v][i]=0;
				REP(j,z+1)if(i+j<=k)
					dp[v][i+j]+=w*dp[to][j];
			}
			FOR(j,1,z+1)
				waf[j]-=dp[to][j];
			s+=z;
			chmin(s,k);
		}
	FOR(i,1,s+1){
		waf[i]+=dp[v][i];
	}
	cerr<<v<<" "<<s<<endl;
	REP(i,s+1){
		cerr<<i<<" "<<dp[v][i]<<endl;
	}
	for(int i=s;i>=0;i--){
		mint w;
		if(i==0){
			w=dp[v][i]*(p2[ss[v]]-1)*p2inv[ss[v]];
		}else{
			w=dp[v][i];
		}
		dp[v][i+1]+=w;
		if(p!=-1){
			cerr<<i+1<<" "<<w<<endl;
			waf[i+1]+=w*(p2[n-ss[v]]-1)*p2inv[n-ss[v]];
		}
	}
	s++;
	chmin(s,k);
	cerr<<v<<" "<<s<<endl;
	REP(i,s+1){
		cerr<<i<<" "<<dp[v][i]<<endl;
	}
}

signed main(){
	InitFact();
	Init();
	n=read(),k=read();
	REP(_,n-1){
		int a=read()-1,b=read()-1;
		tr[a].PB(b);
		tr[b].PB(a);
	}
	dfs1(0,-1);
	dfs2(0,-1);
	mint ans=0;
	FOR(i,1,k+1){
		mint w=0;
		REP(j,i){
			if(j%2==0)
				w+=mint(i-j).pow(k)*Choose(i,j);
			else
				w-=mint(i-j).pow(k)*Choose(i,j);
		}
		cerr<<i<<" "<<waf[i]*p2[n]<<endl;
		ans+=waf[i]*w;
	}
	ans*=p2[n];
	print(ans);
}