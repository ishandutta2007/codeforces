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

using ull=unsigned long long;

const int S=5;

struct Num{
	ull p[S];
	Num(){
		ZERO(p);
	}
	Num operator+(const Num&rhs)const{
		Num res;
		REP(i,S)
			res.p[i]=p[i]+rhs.p[i];
		return res;
	}
	Num operator*(const Num&rhs)const{
		Num res;
		REP(i,S)REP(j,S){
			if(i+j<S)
				res.p[i+j]+=p[i]*rhs.p[j];
			else
				res.p[i+j-S]-=p[i]*rhs.p[j];
		}
		return res;
	}
};

Num pow(Num x,int n){
	Num res;
	res.p[0]=1;
	while(n){
		if(n&1)
			res=res*x;
		x=x*x;
		n>>=1;
	}
	return res;
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

const int B=10;
const int N=100000;
Num w[B];
Num x[N];
void trans(int b,int e){
	int len=e-b;
	if(len==1)return;
	int s=len/B;
	for(int i=b;i<e;i+=s)
		trans(i,i+s);
	FOR(i,b,b+s){
		Num tmp[B];
		REP(j,B)
			tmp[j]=x[i+j*s];
		REP(j,B){
			Num z;
			REP(k,B)
				z=z+w[j*k%B]*tmp[k];
			x[i+j*s]=z;
		}
	}
}

signed main(){
	int n=read();
	REP(i,n){
		int a=read();
		x[a].p[0]++;
	}
	{
		Num root;
		root.p[1]=1;
		REP(i,B)
			w[i]=pow(root,i);
		trans(0,N);
	}
	REP(i,N)
		x[i]=pow(x[i],n);
	{
		Num root;
		root.p[4]=-1;
		REP(i,B)
			w[i]=pow(root,i);
		trans(0,N);
	}
	const int mod=int(1)<<58;
	int inv5,tmp;
	extgcd(5,mod,inv5,tmp);
	if(inv5<0)inv5+=mod;
	REP(i,n){
		ull ans=x[i].p[0]-x[i].p[4];
		cerr<<vector<ull>(x[i].p,x[i].p+5)<<endl;
		REP(_,5)ans*=inv5;
		ans>>=5;
		ans%=mod;
		print(ans);
	}
}