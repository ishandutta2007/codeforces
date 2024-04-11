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

const int MAXSTEPS=200000;

int n,nsteps; ll want;

int ret[MAXSTEPS];

bool solve() {
	if(want<nsteps) return false;
	if(want>(ll)(n-1)*nsteps) return false;
	ll rem=want-nsteps;
	int at=1;
	REP(i,nsteps) {
		int cur=(int)min(rem,(ll)n-2)+1;
		rem-=cur-1; if(at==1) at+=cur; else at-=cur;
		ret[i]=at;
	}
	return true;
}

void run() {
	scanf("%d%d%lld",&n,&nsteps,&want);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,nsteps) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}