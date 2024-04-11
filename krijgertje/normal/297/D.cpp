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

char down[1000][1000];
char rght[1000][1000];
int col[1000][1000];

int calc(int col,char eq) { return eq=='E'?col:3-col; }
int calc(int col1,char eq1,int col2,char eq2,int col3,char eq3) {
	int a=calc(col1,eq1),b=calc(col2,eq2),c=calc(col3,eq3);
	return a==b||a==c?a:3-a;
}

void run(int casenr) {
	int h,w,k; scanf("%d%d%d",&h,&w,&k);
	REP(i,h) {
		REP(j,w-1) scanf(" %c",&rght[i][j]);
		if(i!=h-1) REP(j,w) scanf(" %c",&down[i][j]);
	}
	if(k==1) {
		REP(i,h) REP(j,w) col[i][j]=1;
		int num=0,den=0;
		FOR(i,1,h) REP(j,w) { ++den; if(calc(col[i-1][j],down[i-1][j])==col[i][j]) ++num; }
		REP(i,h) FOR(j,1,w) { ++den; if(calc(col[i][j-1],rght[i][j-1])==col[i][j]) ++num; }
		if(4*num<3*den) { printf("NO\n"); return; }
	} else {
		int hh=h%2==1?h:h-1,ww=w%2==1?w:w-1;
		col[0][0]=1;
		FOR(i,1,hh) col[i][0]=calc(col[i-1][0],down[i-1][0]);
		FOR(j,1,w) {
			for(int i=0;i<hh;i+=2) col[i][j]=calc(col[i][j-1],rght[i][j-1]);
			for(int i=1;i<hh;i+=2) col[i][j]=calc(col[i-1][j],down[i-1][j],col[i][j-1],rght[i][j-1],col[i+1][j],down[i][j]);
		}
		FOR(i,hh,h) {
			for(int j=0;j<ww;j+=2) col[i][j]=calc(col[i-1][j],down[i-1][j]);
			for(int j=1;j<ww;j+=2) col[i][j]=calc(col[i][j-1],rght[i][j-1],col[i-1][j],down[i-1][j],col[i][j+1],rght[i][j]);
		}
		FOR(i,hh,h) FOR(j,ww,w) col[i][j]=calc(col[i][j-1],rght[i][j-1]);
	}
	printf("YES\n");
	REP(i,h) { REP(j,w) { if(j!=0) printf(" "); printf("%d",col[i][j]); } puts(""); }
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}