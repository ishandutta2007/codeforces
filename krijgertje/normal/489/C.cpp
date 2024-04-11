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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int len,sum;

bool can(int len,int sum,bool first) {
	int l=0*len+(first&&len>1?1:0),h=9*len; return l<=sum&&sum<=h;
}

void printmin(int len,int sum) {
	int rem=sum;
	REP(i,len) REP(j,10) {
		if(i==0&&j==0&&len>1) continue;
		if(!can(len-i-1,rem-j,false)) continue;
		printf("%d",j); rem-=j; break;
	}
}

void printmax(int len,int sum) {
	int rem=sum;
	REP(i,len) for(int j=9;j>=0;--j) {
		if(i==0&&j==0&&len>1) continue;
		if(!can(len-i-1,rem-j,false)) continue;
		printf("%d",j); rem-=j; break;
	}
}

void run() {
	scanf("%d%d",&len,&sum);
	if(!can(len,sum,true)) { printf("-1 -1\n"); return; }
	printmin(len,sum); printf(" "); printmax(len,sum); puts("");
}

int main() {
	run();
	return 0;
}