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
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,39};
vector<int> dv;

ll ret;
void go(int at,int left,ll sofar,int pos,int mult,int depth) {
//	REP(i,depth) printf("  "); printf("go(%d,%d,%lld,%d,%d)\n",at,left,sofar,pos,mult);
	if(mult>1) {
		ll nsofar=sofar; bool ok=true;
		REP(j,mult-1) {
			if(nsofar>ret/primes[at]) { ok=false; break; }
			nsofar*=primes[at];
		}
		if(ok) go(at+1,left,nsofar,0,1,depth+1);		
	}
	if(left==0&&mult==1) { if(sofar<ret) ret=sofar; return; }
	for(;pos<SZ(dv);++pos) {
		if((left&(1<<pos))==0) continue;
		if(pos==0||(left&(1<<(pos-1)))==0||dv[pos-1]!=dv[pos]) go(at,left-(1<<pos),sofar,pos+1,mult*dv[pos],depth+1);
	}
}

void run() {
	int n; scanf("%d",&n);
	
	{ dv.clear(); int tmp=n; FORE(i,2,tmp) while(tmp%i==0) dv.PB(i),tmp/=i; }
	
	ret=LLONG_MAX;
	go(0,(1<<(SZ(dv)))-1,1,0,1,0);
	cout<<ret<<endl;
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}