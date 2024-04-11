#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DBG(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl

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
	scanf("%lld",&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	printf("%lld",x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

string readString(){
	static char buf[3341919];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341919];
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
	if(a>b)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

signed main(){
	int n=read();
	vi a,b;
	vector<pi> memo(2*n,pi(-1,-1));
	memo[n]=pi(0,0);
	REP(i,n)
		a.PB(read());
	REP(i,n)
		b.PB(read());
	int x=1,y=1,dif=a[0]-b[0];
	while(memo[dif+n]==pi(-1,-1)){
		memo[dif+n]=pi(x,y);
		if(dif<0){
			assert(x<n);
			dif+=a[x++];
		}else{
			assert(y<n);
			dif-=b[y++];
		}
	}
	print(x-memo[dif+n].first);
	FOR(i,memo[dif+n].first,x)
		print(i+1,i==x-1?1:2);
	print(y-memo[dif+n].second);
	FOR(i,memo[dif+n].second,y)
		print(i+1,i==y-1?1:2);
}