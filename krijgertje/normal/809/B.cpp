#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;

int n,nhave,nq;
bool local=false;

bool have[MAXN];
int loclft[MAXN];
int locrgt[MAXN];

bool query(int a,int b) {
	++nq;
	if(local) {
		return min(loclft[a],locrgt[a])<=min(loclft[b],locrgt[b]);
	} else {
		printf("1 %d %d\n",a+1,b+1); fflush(stdout);
		char s[10]; scanf("%s",s); return strcmp(s,"TAK")==0;
	}
}

int find(int a,int c) {
	if(a==c) return a;
	if(c-a==1) return query(a,c)?a:c;
	int b=(a+c)/2;
	return query(b,b+1)?find(a,b):find(b+1,c);
}

pair<int,int> solve() {
	int a=find(0,n-1);
	int b=a==0?-1:find(0,a-1); if(b!=-1&&query(b,a)) return MP(a,b);
	int c=a==n-1?-1:find(a+1,n-1); if(c!=-1&&query(c,a)) return MP(a,c);
	return MP(a,-1);
}

void run() {
	scanf("%d%d",&n,&nhave);
	pair<int,int> res=solve();
	printf("2 %d %d\n",res.first+1,res.second+1); fflush(stdout);
}

void test() {
	n=MAXN,nhave=2; local=true; int nqmx=0;
	REP(rep,1000) {
		//nhave=rand()%(n-1)+2;
		REP(i,n) have[i]=false; nq=0;
		//have[25810]=have[52087]=true; 
		REP(i,nhave) while(true) { int x=(rand()*1000+rand())%n; if(!have[x]) { have[x]=true; break; } }

		for(int i=n-1;i>=0;--i) locrgt[i]=have[i]?0:i+1>=n||locrgt[i+1]==INT_MAX?INT_MAX:locrgt[i+1]+1;
		REP(i,n) loclft[i]=have[i]?0:i-1<0||loclft[i-1]==INT_MAX?INT_MAX:loclft[i-1]+1;
		pair<int,int> res=solve();
		if(nq>nqmx) nqmx=nq;
		//REP(i,n) if(have[i]) printf("have %d\n",i);
		printf("-> %d %d (%d)\n",res.first,res.second,nq);
		if(res.first!=-1&&!have[res.first]) { printf("err\n"); exit(0); }
		if(res.second!=-1&&!have[res.second]) { printf("err\n"); exit(0); }
	}
	printf("mx=%d\n",nqmx);
}

int main() {
	run();
	//test();
	return 0;
}