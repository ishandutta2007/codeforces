#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <ctime>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=300000;
const int MAXVAL=300000;
const int NMOD=3;

int n;
int a[MAXN];

int cnt[MAXVAL+1];
int one[MAXVAL+1];
int mod[NMOD];
int ways[MAXVAL+1][NMOD];

bool isprime(int x) { for(int y=2;y*y<=x;++y) if(x%y==0) return false; return true; }

int solve() {
	sort(a,a+n); n=unique(a,a+n)-a;
	REPE(i,MAXVAL) cnt[i]=0; REP(i,n) ++cnt[a[i]];
	REPE(i,MAXVAL) one[i]=0; for(int i=MAXVAL;i>=1;--i) for(int j=i;j<=MAXVAL;j+=i) one[i]+=cnt[j];
	//printf("one:"); REP(i,100) if(one[i]!=0) printf(" %d=%d",i,one[i]); puts("");

	srand(time(NULL));
	REP(i,NMOD) { mod[i]=1000000000+rand()%1000*10000; while(!isprime(mod[i])) ++mod[i]; }
	//printf("mod:"); REP(i,NMOD) printf(" %d",mod[i]); puts("");

	FORE(ret,1,7) {
		FORE(i,1,MAXVAL) REP(j,NMOD) { ways[i][j]=1; REP(k,ret) ways[i][j]=(ll)ways[i][j]*one[i]%mod[j]; }
		//printf("%d:",ret); REP(i,100) if(ways[i][0]!=0) printf(" %d=%d",i,ways[i][0]); puts("");
		for(int i=MAXVAL;i>=1;--i) REP(j,NMOD) for(int k=i+i;k<=MAXVAL;k+=i) { ways[i][j]-=ways[k][j]; if(ways[i][j]<0) ways[i][j]+=mod[j]; }
		//printf("%d:",ret); REP(i,100) if(ways[i][0]!=0) printf(" %d=%d",i,ways[i][0]); puts("");
		REP(j,NMOD) if(ways[1][j]!=0) return ret;
	}
	return -1;
}


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}