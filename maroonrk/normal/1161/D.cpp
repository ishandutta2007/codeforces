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
#define REACH cerr<<"reached"<<endl
#define DMP(x) cerr<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))
#define ONE(x) memset(x,-1,sizeof(x))
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

signed main(){
	string s=readString();
	int n=s.size();
	mint ans;
	FOR(i,1,n){
		vi must(n+i,-1);
		VV<pi> g(n+i);
		rep(j,n-i)
			if(s[j]!='?')
				must[j]=s[j]-'0';
		must[n]=1;
		FOR(j,n-i,n)
			if(s[j]!='?'){
				g[j].eb(n+j-(n-i),s[j]-'0');
				g[n+j-(n-i)].eb(j,s[j]-'0');
			}
		rep(j,n)
			g[j].eb(n-1-j,0);
		rep(j,i)
			g[n+j].eb(n+i-1-j,0);
		vi res(n+i,-1);
		bool ok=true;
		function<void(int,int)>dfs=[&](int v,int d){
			if(res[v]!=-1){
				if(res[v]!=d)
					ok=false;
				return;
			}
			res[v]=d;
			for(auto e:g[v])
				dfs(e.first,d^e.second);
		};
		int cnt=0;
		rep(j,n+i)if(must[j]!=-1){
			if(res[j]==-1){
				dfs(j,must[j]);
			}else{
				if(res[j]!=must[j])
					ok=false;
			}
		}
		rep(j,n+i)if(res[j]==-1){
			dfs(j,0);
			cnt++;
		}
		if(ok)
			ans+=mint(2).pow(cnt);
	}
	print(ans);
}