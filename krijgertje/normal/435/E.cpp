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

int h,w;
char g[1000][1000];

void transpose() {
	swap(h,w);
	REP(i,1000) FOR(j,i+1,1000) swap(g[i][j],g[j][i]);
}

int usedmask[2];
int usedlst[2][4],usedcnt[2];
char p[1000][2];

bool samecols() {
	REP(i,h) REP(j,2) p[i][j]='0';
	REP(i,h) REP(j,w) if(g[i][j]!='0') { int jj=j%2; if(p[i][jj]!='0'&&p[i][jj]!=g[i][j]) return false; p[i][jj]=g[i][j]; }
	REP(i,h) if(p[i][0]!='0'&&p[i][1]!='0'&&p[i][0]==p[i][1]) return false;

	REP(i,2) usedmask[i]=0,usedcnt[i]=0;
	REP(i,h) REP(j,2) if(p[i][j]!='0') {
		int ii=i%2; int x=p[i][j]-'0'; if(usedmask[ii]&(1<<x)) continue;
		usedmask[ii]|=1<<x; usedlst[ii][usedcnt[ii]++]=x;
	}
	if(usedmask[0]&usedmask[1]) return false;
	if(usedcnt[0]>2||usedcnt[1]>2) return false;
	FORE(x,1,4) if((usedmask[0]&(1<<x))==0&&(usedmask[1]&(1<<x))==0) REP(i,2) if(usedcnt[i]<2) { usedmask[i]|=1<<x; usedlst[i][usedcnt[i]++]=x; break; }
	return true;
}

void finish() {
	REP(i,h) {
		if(p[i][0]=='0') p[i][0]='0'+usedlst[i%2][usedlst[i%2][0]==p[i][1]-'0'?1:0];
		if(p[i][1]=='0') p[i][1]='0'+usedlst[i%2][usedlst[i%2][0]==p[i][0]-'0'?1:0];
	}
	REP(i,h) REP(j,w) g[i][j]=p[i][j%2];
}

void print() {
	REP(i,h) { REP(j,w) printf("%c",g[i][j]); puts(""); }
}

void run() {
	scanf("%d%d",&h,&w);
	REP(i,h) REP(j,w) scanf(" %c",&g[i][j]);
	if(samecols()) { finish(); print(); return; }
	transpose();
	if(samecols()) { finish(); transpose(); print(); return; }
	printf("0\n");
}

int main() {
	run();
	return 0;
}