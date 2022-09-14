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

const int MAXN=200000;
const int MOD=1000000007;

int n;
int x[MAXN];
int type[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&x[i]),--x[i];
	REP(i,n) type[i]=0;
	int ret=1;
	REP(i,n) if(type[i]==0) {
		int at=i,cnt=0,cyc=0;
		while(type[at]==0) { type[at]=1; at=x[at]; }
		while(type[at]==1) { type[at]=2; at=x[at]; ++cyc; }
		at=i; while(type[at]==1) { type[at]=3; at=x[at]; ++cnt; }
		REP(j,cnt) ret=2*ret%MOD; int cur=1; REP(j,cyc) cur=2*cur%MOD; cur=(cur+MOD-2)%MOD; if(cyc!=0) ret=(ll)ret*cur%MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}