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

void Solve(){
	int n=read();
	double c,t;
	cin>>c>>t;
	vector<pi> ap(n);
	REP(i,n){
		int a=read(),p=read();
		ap[i]=pi(a,p);
	}
	sort(ALL(ap));
	const int S=n*10+1;
	const double mlt=10.0/9;
	const double maxT=Sq((t+1.0/c)/2)*c+1;
	cerr<<maxT<<endl;
	vector<vector<pair<int,double>>> dp(S);
	dp[0].PB(MP(0,0.0));
	vector<pair<int,double>> work;
	for(auto kv:ap){
		int a=kv.first;
		int p=kv.second;
		for(int i=S-1;i>=p;i--){
			int x=0,y=0;
			double mn=maxT;
			while(x<int(dp[i].size())||y<int(dp[i-p].size())){
				int dec=0;
				if(x==int(dp[i].size()))
					dec=1;
				if(y==int(dp[i-p].size()))
					dec=-1;
				if(dec==0){
					if(dp[i][x].first!=dp[i-p][y].first+1){
						if(dp[i][x].first<dp[i-p][y].first+1)
							dec=-1;
						else
							dec=1;
					}else{
						if(dp[i][x].second<(a+dp[i-p][y].second)*mlt){
							dec=-1;
						}else
							dec=1;
					}
				}
				if(dec==-1){
					work.PB(dp[i][x++]);
				}else{
					work.PB(MP(dp[i-p][y].first+1,(a+dp[i-p][y].second)*mlt));
					y++;
				}
				cerr<<work.back()<<" "<<mn<<endl;
				if(work.back().second<mn){
					mn=work.back().second;
				}else
					work.pop_back();
			}
			swap(dp[i],work);
			work.clear();
		}
	}
	int ans=0;
	REP(i,S)for(auto cv:dp[i]){
		cerr<<i<<" "<<cv<<endl;
		double w=cv.second/c;
		double r=sqrt(w);
		double z;
		if(1.0/c<r){
			z=r*2;
		}else{
			z=c*w+1.0/c;
		}
		z-=1.0/c;
		if(z+cv.first*10<t)
			ans=i;
	}
	print(ans);
}

signed main(){
	int tc=read();
	REP(_,tc)
		Solve();
}