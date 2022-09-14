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

const int MAXHAVE=18;

int have,need,nrule;
int val[MAXHAVE];
int extra[MAXHAVE][MAXHAVE];

ll mem[MAXHAVE][1<<MAXHAVE];
ll go(int at,int can,int left) {
	if(left==0) return 0;
	ll &ret=mem[at][can];
	if(ret==-1) {
		ret=0;
		REP(to,have) if(can&(1<<to)) { ll cur=(ll)val[to]+extra[at][to]+go(to,can^(1<<to),left-1); if(cur>ret) ret=cur; }
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&have,&need,&nrule);
	REP(i,have) scanf("%d",&val[i]);
	REP(i,have) REP(j,have) extra[i][j]=0;
	REP(i,nrule) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; extra[a][b]+=c; }

	memset(mem,-1,sizeof(mem));
	ll ret=0;
	REP(i,have) { ll cur=(ll)val[i]+go(i,(1<<have)-(1<<i)-1,need-1); if(cur>ret) ret=cur; }
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}