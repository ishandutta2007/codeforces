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
	int n,m,ind; scanf("%d%d%d",&n,&m,&ind);
	if(m<n-1||m>((ll)n-1)*(n-2)/2+1) { printf("-1\n"); return; }
	int other=ind==1?2:1;
	int left=m;
	FORE(i,1,n) if(i!=ind) { printf("%d %d\n",ind,i); --left; }
	FORE(i,1,n) if(i!=ind&&i!=other) {
		FORE(j,i+1,n) if(j!=ind&&j!=other) {
			if(left==0) return;
			printf("%d %d\n",i,j); --left;
		}
	}
	assert(left==0);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}