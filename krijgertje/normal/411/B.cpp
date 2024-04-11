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

int ncore,ncycle,ncell;
int op[100][100];
int coredead[100];
bool celldead[100];
int cellused[100];

void run() {
	scanf("%d%d%d",&ncore,&ncycle,&ncell);
	REP(i,ncore) REP(j,ncycle) { scanf("%d%",&op[i][j]); --op[i][j]; }
	memset(coredead,-1,sizeof(coredead));
	memset(celldead,false,sizeof(celldead));
	REP(j,ncycle) {
		memset(cellused,-1,sizeof(cellused));
		REP(i,ncore) if(coredead[i]==-1) {
			if(op[i][j]==-1) continue;
			int cell=op[i][j];
			if(celldead[cell]) { coredead[i]=j; continue; }
			if(cellused[cell]==-1) { cellused[cell]=i; continue; }
			coredead[cellused[cell]]=coredead[i]=j; celldead[cell]=true;
		}
	}
	REP(i,ncore) printf("%d\n",coredead[i]+1);

}

int main() {
	run();
	return 0;
}