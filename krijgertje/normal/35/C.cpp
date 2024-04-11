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

void run() {
	int R,C,n; scanf("%d%d%d",&R,&C,&n);
	vector<int> sr(n),sc(n); REP(i,n) scanf("%d%d",&sr[i],&sc[i]);
	int best=INT_MIN; int rr=-1,rc=-1;
	FORE(r,1,R) FORE(c,1,C) {
		int now=abs(sr[0]-r)+abs(sc[0]-c);
		FOR(i,1,n) now=min(now,abs(sr[i]-r)+abs(sc[i]-c));
		if(now>best) best=now,rr=r,rc=c;
	}	
	printf("%d %d\n",rr,rc);
}

int main() {
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}