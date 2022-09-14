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

int npers,ndish;
int have[100000];
int got[99999],mumble[99999];
bool canfirstempty[100000];

void run() {
	scanf("%d%d",&npers,&ndish);
	REP(i,ndish) scanf("%d",&have[i]);
	REP(i,npers-1) { scanf("%d%d",&got[i],&mumble[i]); --got[i]; }

	REP(i,ndish) canfirstempty[i]=true;
	bool mumbled=false; int nfreebeforemumble=0,nfreeaftermumble=0;
	REP(i,npers-1) {
		if(mumble[i]==1) mumbled=true;
		if(got[i]==-1) { if(!mumbled) nfreebeforemumble++; else nfreeaftermumble++; continue; }
		assert(have[got[i]]>=1); have[got[i]]--;
		if(mumbled) canfirstempty[got[i]]=false;
	}
	int minneededbeforemumble=nfreebeforemumble;
	REP(i,ndish) if(canfirstempty[i]&&have[i]<minneededbeforemumble) minneededbeforemumble=have[i];
	REP(i,ndish) {
		int maxfree=0;
		if(canfirstempty[i]&&have[i]<=nfreebeforemumble) maxfree=nfreebeforemumble+nfreeaftermumble;
		else maxfree=nfreebeforemumble-minneededbeforemumble+nfreeaftermumble;
		printf("%c",maxfree>=have[i]?'Y':'N');
	}
	puts("");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}