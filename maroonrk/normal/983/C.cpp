#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
//#define int ll

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

const int V=9*9*9*9;
const int S[]={1,9,9*9,9*9*9,9*9*9*9};
int ds[V][4];
void Init(){
	REP(i,V){
		int x=i;
		REP(k,4){
			ds[i][k]=x%9;
			x/=9;
		}
	}
}
int dp[2][5][9][V];
void Clear(int (&dst)[5][9][V]){
	REP(cnt,5)
	REP(h,9)
	REP(d,V)
		dst[cnt][h][d]=inf;
}

signed main(){
	Init();
	int n=read();
	int cur=0;
	Clear(dp[cur]);
	dp[cur][0][0][0]=0;
	REP(_,n){
		int nx=cur^1;
		Clear(dp[nx]);
		int from=read()-1,to=read()-1;
		for(int cnt=4;cnt>=0;cnt--)REP(h,9){
			REP(i,S[cnt])if(dp[cur][cnt][h][i]<inf){
				if(cnt<4){
					int tmp[4];
					REP(k,cnt)
						tmp[k]=ds[i][k];
					tmp[cnt]=to;
					sort(tmp,tmp+(cnt+1));
					int w=0;
					for(int kk=cnt;kk>=0;kk--){
						w*=9;
						w+=tmp[kk];
					}
					cerr<<w<<endl;
					chmin(dp[nx][cnt+1][from][w],dp[cur][cnt][h][i]+abs(h-from));
				}
			}
		}
		cur=nx;
		for(int cnt=4;cnt>=0;cnt--)REP(h,9){
			REP(i,S[cnt])if(dp[cur][cnt][h][i]<inf){
				REP(k,cnt){
					int w=0;
					for(int kk=cnt-1;kk>=0;kk--)if(kk!=k){
						w*=9;
						w+=ds[i][kk];
					}
					cerr<<cnt<<" "<<w<<endl;
					chmin(dp[cur][cnt-1][ds[i][k]][w],dp[cur][cnt][h][i]+abs(h-ds[i][k]));
				}
			}
		}
	}
	int ans=inf;
	REP(h,9)
		chmin(ans,n*2+dp[cur][0][h][0]);
	print(ans);
}