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

int n,k,d;

int ret[1000][1000];

void run() {
	scanf("%d%d%d",&n,&k,&d);
	REP(i,d) ret[i][0]=1;
	FOR(j,1,n) {
		REP(i,d) ret[i][j]=ret[i][j-1];
		int at=d-1; while(at>=0&&ret[at][j]>=k) ret[at--][j]=1;
		if(at<0) { printf("-1\n"); return; } else ++ret[at][j];
	}
	REP(i,d) { REP(j,n) { if(j!=0) printf(" "); printf("%d",ret[i][j]); } puts(""); }
}

int main() {
	run();
	return 0;
}