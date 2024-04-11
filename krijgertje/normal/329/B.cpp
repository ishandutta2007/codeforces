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

const int DR[]={-1,0,+1,0},DC[]={0,+1,0,-1};

int R,C;
char g[1000][1000];
int d[1000][1000];

int qh,qt;
int qr[1000000];
int qc[1000000];

void run(int casenr) {
	scanf("%d%d",&R,&C);
	REP(r,R) REP(c,C) scanf(" %c",&g[r][c]);

	qh=qt=0;
	memset(d,-1,sizeof(d));
	REP(r,R) REP(c,C) if(g[r][c]=='E') { qr[qh]=r; qc[qh]=c; d[r][c]=0; ++qh; }
	while(qt<qh) {
		int r=qr[qt],c=qc[qt]; ++qt;
		REP(k,4) {
			int nr=r+DR[k],nc=c+DC[k];
			if(nr<0||nr>=R||nc<0||nc>=C||g[nr][nc]=='T'||d[nr][nc]!=-1) continue;
			qr[qh]=nr; qc[qh]=nc; d[nr][nc]=d[r][c]+1; ++qh;
		}
	}
	
	int dme=0; REP(r,R) REP(c,C) if(g[r][c]=='S') { assert(d[r][c]!=-1); dme+=d[r][c]; }
	int ret=0; REP(r,R) REP(c,C) if(d[r][c]!=-1&&isdigit(g[r][c])&&d[r][c]<=dme) ret+=g[r][c]-'0';
	printf("%d\n",ret);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}