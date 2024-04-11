#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(x) x.begin(),x.end()
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

//const int mod=1000000007;
int mod;
template<class T,class U>
void add(T& a,U b){
	//a=((ll)a+b)%mod;
	a+=b;
	if(a>=mod)a-=mod;
}

template<class T,class U>
void sub(T& a,U b){
	//a=((ll)a-b%mod+mod)%mod;
	a-=b;
	if(a<0)a+=mod;
}

template<class T,class U>
void mult(T& a,U b){
	a=((ll)a*b)%mod;
}

ll modPow(ll a,ll p){
	ll s=1;
	while(p){
		if(p&1)mult(s,a);
		mult(a,a);
		p>>=1;
	}
	return s;
}

ll modInv(ll a){
	return modPow(a,mod-2);
}

const int Vmax=1001000;
int fact[Vmax],factInv[Vmax],invs[Vmax];
void InitFact(){
	int vv=mod;
	fact[0]=1;
	FOR(i,1,vv){
		fact[i]=fact[i-1];
		mult(fact[i],i);
	}
	factInv[vv-1]=modInv(fact[vv-1]);
	for(int i=vv-2;i>=0;i--){
		factInv[i]=factInv[i+1];
		mult(factInv[i],i+1);
	}
	for(int i=vv-1;i>=1;i--){
		invs[i]=factInv[i];
		mult(invs[i],fact[i-1]);
	}
}
int Choose(int n,int k){
	return ll(fact[n])*factInv[n-k]%mod*factInv[k]%mod;
}
int Binom(int a,int b){
	return ll(fact[a+b])*factInv[a]%mod*factInv[b]%mod;
}

signed main(){
	int n=read(),m=read(),a=read(),q=read();
	vi ans(n,0);
	a%=q;
	if(a>0){
		int x=1;
		{
			int cur=a;
			while(cur!=1){
				x++;
				cur*=a;
				cur%=q;
			}
		}
		cerr<<x<<endl;
		mod=x;
		InitFact();
		int w=0;
		for(int i=n-1;i>=0;i--){
			int c=n-1-i;
			if(c<=m)
				add(w,Choose(m,c));
			ans[i]=1;
			int cur=a,rem=w;
			while(rem){
				if(rem&1){
					ans[i]*=cur;
					ans[i]%=q;
				}
				cur*=cur;
				cur%=q;
				rem>>=1;
			}
		}
	}
	REP(i,n)
		print(ans[i],i==n-1?1:2);
}