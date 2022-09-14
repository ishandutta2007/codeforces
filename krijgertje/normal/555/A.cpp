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

int ndoll,nchain;

void run() {
	scanf("%d%d",&ndoll,&nchain);
	int maxsave=0;
	int ret=ndoll-1;
	REP(i,nchain) {
		int cnt; scanf("%d",&cnt); 
		ret+=cnt-1; 
		int cursave=0;
		REP(j,cnt) { int x; scanf("%d",&x); if(cursave==j&&x==j+1) ++cursave; }
		--cursave;
		//printf("%d: %d\n",i,cursave);
		if(cursave>maxsave) maxsave=cursave;
	}
	ret-=2*maxsave;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}