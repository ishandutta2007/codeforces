#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#ifdef MAROON_LOCAL
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
	scanf("%" SCNd64,&i);
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

const int Vmax=100010;
int f[Vmax];

void Init(){
	FOR(i,1,Vmax)
		for(int j=i;j<Vmax;j+=i)
			f[j]++;
}

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int C1(int a){
	return a;
}

int C2(int a){
	return a*(a-1)/2+a;
}

int C3(int a){
	return a*(a-1)*(a-2)/6+a*(a-1)/2*2+a;
}

void Solve(){
	int v[3];
	REP(i,3)v[i]=read();
	int cnt[8]{};
	FOR(bit,1,8){
		int w=0;
		REP(i,3)if((bit>>i)&1)
			w=gcd(v[i],w);
		cnt[bit]=f[w];
	}
	REP(k,3)FOR(bit,1,8)
		if((bit&(1<<k))==0)
			cnt[bit]-=cnt[bit^(1<<k)];
	int ans=cnt[1]*cnt[2]*cnt[4];
	int d=0;
	REP(bit,8)if(__builtin_popcountll(bit)>1)
		d+=cnt[bit];
	REP(i,3){
		int w=1;
		REP(j,3)if(i!=j)w*=cnt[1<<j];
		int rem=7^(1<<i);
		w*=(d-cnt[rem]);
		ans+=w;
	}
	REP(i,3){
		int w=cnt[1<<i];
		int s=C2(d);
		REP(j,3)if(i!=j)
			s-=C2(cnt[(1<<i)+(1<<j)]);
		w*=s;
		ans+=w;
	}
	ans+=C3(d);
	REP(bit,8)if(__builtin_popcountll(bit)==2)
		ans-=C3(cnt[bit]);
	print(ans);
}

signed main(){
	Init();
	int t=read();
	REP(_,t)
		Solve();
}