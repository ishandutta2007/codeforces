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
#include <cstring>
#include <list>  
#include <cassert>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXDIM=115;

int h,w;
char g[MAXDIM][MAXDIM+1];

void run() {
	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]);
	int lx=INT_MAX,ly=INT_MAX,hx=INT_MIN,hy=INT_MIN; REP(x,h) REP(y,w) if(g[x][y]=='B') { lx=min(lx,x); ly=min(ly,y); hx=max(hx,x); hy=max(hy,y); }
	int cx=lx+(hx-lx)/2,cy=ly+(hy-ly)/2;
	printf("%d %d\n",cx+1,cy+1);
}

int main() {
	run();
	return 0;
}