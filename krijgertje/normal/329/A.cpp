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
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

int n;
char g[100][100];
int col[100],row[100];

void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf(" %c",&g[i][j]);
	REP(i,n) { row[i]=-1; REP(j,n) if(g[i][j]!='E') { row[i]=j; break; } }
	REP(j,n) { col[j]=-1; REP(i,n) if(g[i][j]!='E') { col[j]=i; break; } }
	bool allrow=true; REP(i,n) if(row[i]==-1) allrow=false;
	bool allcol=true; REP(j,n) if(col[j]==-1) allcol=false;
	if(allrow) { REP(i,n) printf("%d %d\n",i+1,row[i]+1); return; }
	if(allcol) { REP(j,n) printf("%d %d\n",col[j]+1,j+1); return; }
	printf("-1\n");
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}