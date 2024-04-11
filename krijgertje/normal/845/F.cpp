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

const int MAXW=15;
const int MAXDIM=250;
const int MOD=1000000007;

int h,w;
char g[MAXDIM][MAXDIM];
char gtmp[MAXDIM][MAXDIM];

int dp[2][1<<MAXW][2][2]; // dp[z][dwnmask][rgt][empty]

void flip() {
	REP(x,h) REP(y,w) gtmp[y][x]=g[x][y]; swap(h,w); REP(x,h) REP(y,w) g[x][y]=gtmp[x][y]; REP(x,h) g[x][w]='\0';
}

void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

void run() {
	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]);
	
	if(h<w) flip();
	//REP(x,h) printf("%s\n",g[x]);

	int z=0; memset(dp[z],0,sizeof(dp[z])); dp[z][0][0][0]=1;
	REP(x,h) REP(y,w) {
		memset(dp[1-z],0,sizeof(dp[1-z]));
		REP(dwnmask,1<<w) REP(rgt,2) REP(empty,2) if(dp[z][dwnmask][rgt][empty]) REP(place,2) {
			int ndwnmask=dwnmask,nrgt=rgt,nempty=empty;
			if(g[x][y]=='x') {
				if(place==1) continue; else ndwnmask&=~(1<<y),nrgt=0;
			} else {
				if(place==1) ndwnmask|=1<<y,nrgt=1; else if(nrgt==0&&((ndwnmask>>y)&1)==0) if(nempty==1) continue; else ++nempty;
			}
			if(y==w-1) nrgt=0;
			inc(dp[1-z][ndwnmask][nrgt][nempty],dp[z][dwnmask][rgt][empty]);
		}
		z=1-z;
	}
	int ret=0; REP(dwnmask,1<<w) REP(rgt,2) REP(empty,2) if(dp[z][dwnmask][rgt][empty]) inc(ret,dp[z][dwnmask][rgt][empty]); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}