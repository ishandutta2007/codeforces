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

pair<vi,vi> Solve(const vector<pi>& ci,int x1,int x2){
	int n=ci.size();
	for(int i=n-1;i>=0;i--){
		int a=(x1-1)/ci[i].first+1;
		int j=i+a;
		if(j<n){
			int b=(x2-1)/ci[j].first+1;
			if(j+b<=n){
				vi g1,g2;
				REP(k,a)
					g1.PB(ci[i+k].second);
				REP(k,b)
					g2.PB(ci[j+k].second);
				return MP(g1,g2);
			}
		}
	}
	return MP(vi(),vi());
}

void Answer(const pair<vi,vi>& ans){
	Yes(false);
	vi g1=ans.first,g2=ans.second;
	int k1=g1.size(),k2=g2.size();
	print(k1,2),print(k2);
	REP(i,k1)
		print(g1[i],i==k1-1?1:2);
	REP(i,k2)
		print(g2[i],i==k2-1?1:2);
	exit(0);
}

signed main(){
	int n=read(),x1=read(),x2=read();
	vector<pi> ci(n);
	REP(i,n)
		ci[i]=pi(read(),i+1);
	sort(ALL(ci));
	{
		auto res=Solve(ci,x1,x2);
		if(!res.first.empty())
			Answer(res);
	}
	swap(x1,x2);
	{
		auto res=Solve(ci,x1,x2);
		if(!res.first.empty()){
			swap(res.first,res.second);
			Answer(res);
		}
	}
	No();
}