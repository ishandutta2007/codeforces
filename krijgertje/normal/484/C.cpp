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

char s[1000001]; int n,m;
char ns[1000000];

int shuf[1000000];
int shft[1000000];
int have[1000000];
int cur[2][1000000];

void run() {
	scanf("%s",s); n=strlen(s); scanf("%d",&m);
	REP(i,m) {
		int k,d; scanf("%d%d",&k,&d);
		int pos=0; REP(off,d) for(int j=off;j<k;j+=d) shuf[j]=pos++; FOR(j,k,n) shuf[j]=pos++;
		REP(j,n) shft[j]=j==0?n-1:j-1;
		REP(j,n) have[j]=j;
		REP(j,n) cur[0][j]=shft[shuf[j]];
		int times=n-k+1;
		for(int bit=0,at=0;times>=(1<<bit);++bit,at=1-at) {
			if(times&(1<<bit)) REP(j,n) have[j]=cur[at][have[j]];
			REP(j,n) cur[1-at][j]=cur[at][cur[at][j]];
		}
		REP(j,n) { have[j]-=(n-times); if(have[j]<0) have[j]+=n; }
		REP(j,n) ns[have[j]]=s[j]; REP(j,n) s[j]=ns[j];
		printf("%s\n",s);
	}
}

int main() {
	run();
	return 0;
}