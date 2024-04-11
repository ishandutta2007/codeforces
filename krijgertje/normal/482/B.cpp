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

int n,m;
int l[100000],r[100000],v[100000];

int ret[100000];
int upto[100000];
int cum[100001];

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { scanf("%d%d%d",&l[i],&r[i],&v[i]); --l[i],--r[i]; }

	memset(ret,0,sizeof(ret));
	REP(i,30) {
		memset(upto,-1,sizeof(upto));
		REP(j,m) if((v[j]&(1<<i))!=0&&r[j]>upto[l[j]]) upto[l[j]]=r[j];
		REP(j,n-1) if(upto[j]>=j+1&&upto[j]>upto[j+1]) upto[j+1]=upto[j];
		//REP(j,n) printf("%d ",upto[j]); puts("");
		REP(j,n) if(upto[j]!=-1) ret[j]|=1<<i;
		cum[0]=0; REP(j,n) cum[j+1]=cum[j]+(upto[j]==-1?1:0);
		REP(j,m) if((v[j]&(1<<i))==0&&cum[r[j]+1]==cum[l[j]]) { printf("NO\n"); return; }
	}
	printf("YES\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}