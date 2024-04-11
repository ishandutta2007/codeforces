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

//#define CAPITAL
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

void Solve(int n,int s,int b){
	int origS=s;
	vi cnt{1};
	s--;
	int a=1;
	FOR(i,1,n){
		if(a==1||cnt[a-2]*b==cnt[a-1]){
			cnt.PB(0);
			a++;
		}
		s-=a;
		cnt.back()++;
	}
	for(int i=a-1;i>=0;i--){
		while(cnt[i]>1){
			if(s==0)
				break;
			if(a-i<=s){
				cnt[i]--;
				cnt.PB(1);
				s-=(a-i);
				a++;
			}else{
				cnt[i]--;
				cnt[i+s]++;
				s=0;
			}
		}
	}
	vector<vi> idx(a);
	vi p(n,-1);
	int cur=0;
	REP(i,a){
		REP(j,cnt[i]){
			if(i>0){
				p[cur]=idx[i-1][j/b];
			}
			origS-=(i+1);
			idx[i].PB(cur++);
		}
	}
	assert(origS==0);
	FOR(i,1,a)
		assert(cnt[i-1]*b>=cnt[i]);
	Yes(false);
	FOR(i,1,n)
		print(p[i]+1,i==n-1?1:2);
	exit(0);
}

signed main(){
	int n=read(),s=read();
	{
		int mx=n*(n+1)/2;
		if(mx<s)No();
	}
	{
		int mn=2*n-1;
		if(s<mn)No();
	}
	for(int i=1;i<n;i++){
		int cur=1,avail=n,sum=0,dep=1;
		while(avail){
			int w=min(cur,avail);
			sum+=dep*w;
			avail-=w;
			cur*=i;
			dep++;
		}
		if(sum<=s){
			Solve(n,s,i);
		}
	}
}