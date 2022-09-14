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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int h,w;
char g[2000][2000];
bool up[2000][2000];
bool dn[2000][2000];
bool rt[2000][2000];
bool lt[2000][2000];

void run() {
	scanf("%d%d",&h,&w); REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);

	REP(x,h) REP(y,w) up[x][y]=g[x][y]=='.'&&(x==0||up[x-1][y]);
	for(int x=h-1;x>=0;--x) REP(y,w) dn[x][y]=g[x][y]=='.'&&(x==h-1||dn[x+1][y]);
	REP(x,h) REP(y,w) lt[x][y]=g[x][y]=='.'&&(y==0||lt[x][y-1]);
	REP(x,h) for(int y=w-1;y>=0;--y) rt[x][y]=g[x][y]=='.'&&(y==w-1||rt[x][y+1]);

	//REP(x,h) { REP(y,w) printf("%c",up[x][y]?'V':'.'); puts(""); } puts("");
	//REP(x,h) { REP(y,w) printf("%c",dn[x][y]?'V':'.'); puts(""); } puts("");
	//REP(x,h) { REP(y,w) printf("%c",lt[x][y]?'V':'.'); puts(""); } puts("");
	//REP(x,h) { REP(y,w) printf("%c",rt[x][y]?'V':'.'); puts(""); } puts("");

	ll ret=0;
	FOR(x,1,h-1) FOR(y,1,w-1) {
		if(lt[x][y]&&up[x][y]) ++ret;
		if(lt[x][y]&&dn[x][y]) ++ret;
		if(rt[x][y]&&up[x][y]) ++ret;
		if(rt[x][y]&&dn[x][y]) ++ret;
	}
	FOR(y,1,w-1) if(dn[0][y]) ++ret;
	FOR(x,1,h-1) {
		int sumup=0,sumdn=0;
		FOR(y,1,w-1) {
			if(g[x][y]=='#') { sumup=sumdn=0; continue; }
			if(up[x][y]) ret+=sumup+sumdn-(y-1>=1&&up[x][y-1]?1:0);
			if(dn[x][y]) ret+=sumup+sumdn-(y-1>=1&&dn[x][y-1]?1:0);
			if(up[x][y]) ++sumup;
			if(dn[x][y]) ++sumdn;
//			printf("A after (%d,%d): %d\n",x,y,ret);
		}
	}
	FOR(x,1,h-1) if(rt[x][0]) ++ret;
	FOR(y,1,w-1) {
		int sumlt=0,sumrt=0;
		FOR(x,1,h-1) {
			if(g[x][y]=='#') { sumlt=sumrt=0; continue; }
			if(lt[x][y]) ret+=sumlt+sumrt-(x-1>=1&&lt[x-1][y]?1:0);
			if(rt[x][y]) ret+=sumlt+sumrt-(x-1>=1&&rt[x-1][y]?1:0);
			if(lt[x][y]) ++sumlt;
			if(rt[x][y]) ++sumrt;
//			printf("B after (%d,%d): %d\n",x,y,ret);
		}
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}