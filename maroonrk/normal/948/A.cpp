#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
#define int ll

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

#ifdef int
const int inf=LLONG_MAX/3;
#else
const int inf=INT_MAX/2-100;
#endif

char buf[510][510];

signed main(){
	int r=read(),c=read();
	REP(i,r)scanf("%s",buf[i]);
	int dxy[]={-1,0,1,0,-1};
	REP(i,r)REP(j,c)if(buf[i][j]=='S'){
		REP(k,4){
			int y=i+dxy[k],x=j+dxy[k+1];
			if(0<=y&&y<r&&0<=x&&x<c){
				if(buf[y][x]=='W'){
					No();
				}else if(buf[y][x]=='.'){
					buf[y][x]='D';
				}
			}
		}
	}
	Yes(false);
	REP(i,r)printf("%s\n",buf[i]);
}