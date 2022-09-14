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

int n,need;
char g[100][100];
int x,y;

char ans5[26]=">...vv.<....^..>......^.<";
char ans3[10]=">vv^<.^.<";
char ans100[201]="RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.R.DU.L.L.L.L.L.L.L.L.L..L.L.L.L.L.L.L.L.L.L.L.L.L.L.L.L.L.L.L.L.L.L.L.LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL";

void getdir(char c,int &dx,int &dy) { if(c=='<'||c=='>') { dx=0; dy=c=='<'?-1:+1; } else { dx=c=='^'?-1:+1; dy=0; } }
char norm(char c) { if(c=='L') return '<'; if(c=='U') return '^'; if(c=='D') return 'v'; if(c=='R') return '>'; if(c=='V') return 'v'; return c; }

void run(int casenr) {
	scanf("%d%d",&n,&need);
	if(n==5) { REP(i,n) REP(j,n) g[i][j]=ans5[n*i+j]; x=1; y=1; }
	if(n==3) { REP(i,n) REP(j,n) g[i][j]=ans3[n*i+j]; x=1; y=3; }
	if(n==100) { REP(i,n) REP(j,n) g[i][j]=norm(ans100[n*(i%2)+j]); x=100; y=1; }
	REP(i,n) { REP(j,n) printf("%c",g[i][j]); puts(""); } printf("%d %d\n",x,y);
}

void simulate() {
	scanf("%d",&n);
	REP(i,n) REP(j,n) { scanf(" %c",&g[i][j]); g[i][j]=norm(g[i][j]); }
	scanf("%d %d",&x,&y); --x,--y;
	bool hitwall=false; int eventcnt=0,soundcnt=0;
	while(!hitwall&&eventcnt<10000000) {
		int dx,dy; getdir(g[x][y],dx,dy); int len=0; ++eventcnt;
//		printf("\tstart from (%d,%d) dir (%d,%d) [%c]\n",x,y,dx,dy,g[x][y]);
		while(true) {
			int nx=x+dx,ny=y+dy;
//			printf("\t\t(%d,%d)->(%d,%d)\n",x,y,nx,ny);
			if(nx<0||nx>=n||ny<0||ny>=n) { if(len>0) ++soundcnt; hitwall=true; break; }
			if(g[nx][ny]!='.') { if(len>0) ++soundcnt;  x=nx; y=ny; break; }
			swap(g[x][y],g[nx][ny]); ++len; x=nx,y=ny;
		}
	}
	REP(i,n) { REP(j,n) printf("%c",g[i][j]); puts(""); }
	printf("%d events, %d sounds\n",eventcnt,soundcnt);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
//	simulate();
	return 0;
}