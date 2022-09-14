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
	int R,C; scanf("%d%d",&R,&C);
	int sr,sc; scanf("%d%d",&sr,&sc); --sr,--sc;
	
	if(C==1) { printf("%.4lf\n",2.0*(R-sr-1)); return; }
	
	vector<double> E(C,0);
	for(int r=R-2;r>=sr;--r) {
		vector<double> nE(C,0);
		vector<double> extra(C-1,0);
		//nE[0]=(3+nE[1]+E[0])/2;
		nE[0]=1.0*(3+E[0])/2; extra[0]=1.0/2;
		FOR(c,1,C-1) {
			//nE[c]=(4+nE*[c-1]+nE[c+1]+E[c])/(3-extra[c-1])
			nE[c]=1.0*(4+nE[c-1]+E[c])/(3-extra[c-1]); extra[c]=1.0/(3-extra[c-1]);
		}
		//nE[C-1]=(3+nE*[C-2]+E[C-1])/(2-extra[C-2])
		nE[C-1]=1.0*(3+nE[C-2]+E[C-1])/(2-extra[C-2]);
		for(int c=C-2;c>=0;--c) nE[c]+=extra[c]*nE[c+1];
		E=nE;
//		REP(c,C) printf("%.4lf ",E[c]); puts("");
	}
	printf("%.4lf\n",E[sc]);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}