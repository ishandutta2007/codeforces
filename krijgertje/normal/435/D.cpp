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
char g[400][400];

int rr[400][400];
int dd[400][400];
int dr[400][400];
int dl[400][400];

void run() {
	scanf("%d%d",&h,&w);
	REP(i,h) REP(j,w) scanf(" %c",&g[i][j]);

	for(int x=h-1;x>=0;--x) for(int y=w-1;y>=0;--y) {
		rr[x][y]=g[x][y]=='1'?0:1+(y+1<w?rr[x][y+1]:0);
		dd[x][y]=g[x][y]=='1'?0:1+(x+1<h?dd[x+1][y]:0);
		dr[x][y]=g[x][y]=='1'?0:1+(x+1<h&&y+1<w?dr[x+1][y+1]:0);
		dl[x][y]=g[x][y]=='1'?0:1+(x+1<h&&y-1>=0?dl[x+1][y-1]:0);
	}
	
	int ret=0;
	REP(x,h) REP(y,w) {
		for(int sz=1;;++sz) {
			if(x-sz<0||y+sz>=w) break;
			if(dd[x-sz][y]>=sz+1&&rr[x][y]>=sz+1&&dr[x-sz][y]>=sz+1) ++ret;
		}
		for(int sz=1;;++sz) {
			if(x-sz<0||y-sz<0) break;
			if(dd[x-sz][y]>=sz+1&&rr[x][y-sz]>=sz+1&&dl[x-sz][y]>=sz+1) ++ret;
		}
		for(int sz=1;;++sz) {
			if(x+sz>=h||y+sz>=w) break;
			if(dd[x][y]>=sz+1&&rr[x][y]>=sz+1&&dl[x][y+sz]>=sz+1) ++ret;
		}
		for(int sz=1;;++sz) {
			if(x+sz>=h||y-sz<0) break;
			if(dd[x][y]>=sz+1&&rr[x][y-sz]>=sz+1&&dr[x][y-sz]>=sz+1) ++ret;
		}
		for(int sz=1;;++sz) {
			if(x-sz<0||y-sz<0||y+sz>=w) break;
			if(dr[x-sz][y-sz]>=sz+1&&dl[x-sz][y+sz]>=sz+1&&rr[x-sz][y-sz]>=2*sz+1) ++ret;
		}
		for(int sz=1;;++sz) {
			if(x+sz>=h||y-sz<0||y+sz>=w) break;
			if(dl[x][y]>=sz+1&&dr[x][y]>=sz+1&&rr[x+sz][y-sz]>=2*sz+1) ++ret;
		}
		for(int sz=1;;++sz) {
			if(y-sz<0||x-sz<0||x+sz>=h) break;
			if(dr[x-sz][y-sz]>=sz+1&&dl[x][y]>=sz+1&&dd[x-sz][y-sz]>=2*sz+1) ++ret;
		}
		for(int sz=1;;++sz) {
			if(y+sz>=w||x-sz<0||x+sz>=h) break;
			if(dl[x-sz][y+sz]>=sz+1&&dr[x][y]>=sz+1&&dd[x-sz][y+sz]>=2*sz+1) ++ret;
		}
	}
	printf("%d\n",ret);
	
}

int main() {
	run();
	return 0;
}