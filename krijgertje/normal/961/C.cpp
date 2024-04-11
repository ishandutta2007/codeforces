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

const int MAXN=100;

int n;
char g[4][MAXN][MAXN+1];

int c[4][2];

void run() {
	scanf("%d",&n);
	REP(k,4) REP(i,n) scanf("%s",g[k][i]);

	REP(k,4) REP(par,2) {
		int cur=0;
		REP(i,n) REP(j,n) { int have=g[k][i][j]-'0',want=(i+j+par)%2; cur+=abs(want-have); }
		c[k][par]=cur;
	}

	int ret=INT_MAX;
	REP(mask,1<<4) {
		int cnt=0; REP(k,4) if(mask&(1<<k)) ++cnt; if(cnt!=2) continue;
		int cur=0; REP(k,4) if(mask&(1<<k)) cur+=c[k][0]; else cur+=c[k][1]; ret=min(ret,cur);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}