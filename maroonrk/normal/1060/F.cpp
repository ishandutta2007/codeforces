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

using ld=long double;
#define double ld

const int Nmax=55;
double fact[Nmax],bin[Nmax][Nmax];
void InitFact(){
	fact[0]=1;
	FOR(i,1,Nmax)
		fact[i]=fact[i-1]*i;
	bin[0][0]=1;
	REP(i,Nmax)REP(j,Nmax){
		if(i>0)
			bin[i][j]+=bin[i-1][j];
		if(j>0)
			bin[i][j]+=bin[i][j-1];
	}
}
double dp[Nmax][Nmax],ans[Nmax];
vi tr[Nmax];
int dfs(int v,int p){
	REP(i,Nmax)
		dp[v][i]=0;
	dp[v][0]=1;
	int sum=1;
	for(auto to:tr[v])if(to!=p){
		int s=dfs(to,v);
		sum+=s;
		REP(i,s+1){
			dp[to][i]*=bin[i][s-i];
		}
		for(int j=sum;j>=0;j--){
			double x=0;
			REP(i,s+1)
				if(j-i>=0)
					x+=dp[v][j-i]*dp[to][i];
			dp[v][j]=x;
		}
	}
	REP(i,sum)
		dp[v][i]/=bin[i][sum-1-i];
	if(p==-1){
		ans[v]=dp[v][sum-1];
	}else{
		double cur=0;
		REP(i,sum+1){
			double x=double(1)/sum*0.5*cur;
			cur+=dp[v][i];
			double y=double(sum-i)/sum*dp[v][i];
			dp[v][i]=x+y;
			cerr<<v<<" "<<i<<" "<<dp[v][i]<<endl;
		}
	}
	return sum;
}

signed main(){
	InitFact();
	int n=read();
	REP(_,n-1){
		int a=read()-1,b=read()-1;
		tr[a].PB(b);
		tr[b].PB(a);
	}
	REP(i,n)
		dfs(i,-1);
	cout<<fixed<<setprecision(20);
	REP(i,n)
		cout<<ans[i]<<endl;
}