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

double extra(const vector<int> &pos,int n) {
	double ret=0;
	REPSZ(i,pos) if(pos[i]!=-1) {
		ret+=pos[i]*(n-pos[i]-1);
		bool ul2lr=true,ur2ll=true;
		FORSZ(j,i+1,pos) {
			if(pos[j]==-1) break;
			if(pos[j-1]<=pos[j]) ur2ll=false;
			if(pos[j-1]>=pos[j]) ul2lr=false;
			if(ul2lr) ret+=pos[i]*(n-pos[j]-1);
			if(ur2ll) ret+=pos[j]*(n-pos[i]-1);
		}
	}
	return ret*4;
}

void run() {
	int R,C; scanf("%d%d",&R,&C); int total=R*C;
	vector<int> rows(R,-1),cols(C,-1);
	REP(r,R) REP(c,C) { char x; scanf(" %c",&x); if(x=='X') rows[r]=c,cols[c]=r,--total; }
	double ret=0;
	REP(r1,R) REP(r2,R) ret+=(rows[r1]==-1?C:C-1)*(rows[r2]==-1?C:C-1)*abs(r1-r2);
	REP(c1,C) REP(c2,C) ret+=(cols[c1]==-1?R:R-1)*(cols[c2]==-1?R:R-1)*abs(c1-c2);
	ret+=extra(rows,C)+extra(cols,R);
	ret/=1.0*total*total;
	printf("%.9lf\n",ret);
}


int main() {
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}