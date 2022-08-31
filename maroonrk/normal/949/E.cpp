#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DMP(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))

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
	os<<"[";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"]";
	return os;
}

int read(){
	int i;
	#ifdef int
	scanf("%" SCNd64,&i);
	#else
	scanf("%d",&i);
	#endif
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	#ifdef int
	printf("%" PRId64,x);
	#else
	printf("%d",x);
	#endif
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

#ifdef int
const int inf=LLONG_MAX/3;
#else
const int inf=INT_MAX/2-100;
#endif

int buf[1<<20];
int* getArr(int len){
	static int head=0;
	int*ptr=buf+head;
	head+=len;
	return ptr;
}
int* waf[19];
int cnt[19];
void Assign(int x,int i,int base){
	cnt[i]+=((x+base-1)>>i)&1;
	int w=(x>>i)&1;
	int p=(1<<i)-(x&((1<<i)-1));
	//cerr<<x<<" "<<i<<" "<<p<<" "<<w<<endl;
	waf[i][p]+=1-w*2;
	waf[i][(p+(1<<i))%(1<<(i+1))]+=w*2-1;
}

signed main(){
	int n=read();
	vi a(n);REP(i,n)a[i]=read();
	int base=-min(*min_element(ALL(a)),int(0));
	REP(i,19)waf[i]=getArr(1<<(i+1));
	for(auto x:a)REP(i,19)Assign(x,i,base);
	int ansNum=inf;
	vi ansSet;
	FOR(i,base,1<<18){
		int x=i;
		REP(j,19){
			cnt[j]+=waf[j][i%(1<<(j+1))];
			//cerr<<i<<" "<<j<<" "<<waf[j][i%(1<<(j+1))]<<" "<<cnt[j]<<endl;
			if(cnt[j])
				x|=(1<<j);
		}
		int w=__builtin_popcount(x);
		//cerr<<i<<" "<<x<<" "<<w<<endl;
		if(w<ansNum){
			ansNum=w;
			ansSet.clear();
			REP(j,18)if((i>>j)&1)ansSet.PB(-(1<<j));
			REP(j,19)if(((x>>j)&1)&&!((i>>j)&1))ansSet.PB(1<<j);
		}
	}
	print(ansNum);
	REP(i,ansNum)print(ansSet[i],i==ansNum-1?1:2);
}