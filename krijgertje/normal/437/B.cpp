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

int want,maxval;

int ret[100000],nret;

void run() {
	scanf("%d%d",&want,&maxval);
	nret=0;
	int left=want;
	for(int i=20;i>=0;--i) {
		int can=left/(1<<i);
		int have=((maxval>>i)+1)/2;
		int cur=min(can,have);
		REP(j,cur) ret[nret++]=(2*j+1)<<i,left-=1<<i;
	}
	if(left!=0) { printf("-1\n"); return; }
	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}