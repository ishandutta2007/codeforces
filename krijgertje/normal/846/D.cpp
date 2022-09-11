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

const int MAXH=500;
const int MAXW=500;
const int TMAX=1000000000;

int h,w,sz,nq;
int t[MAXH][MAXW];

int dp[MAXH][MAXW];

bool isbroken(int tt) {
	for(int x=h-1;x>=0;--x) for(int y=w-1;y>=0;--y) {
		if(t[x][y]>tt) { dp[x][y]=0; continue; }
		if(x+1>=h||y+1>=w) { dp[x][y]=1; if(dp[x][y]>=sz) return true; continue; }
		dp[x][y]=1+min(dp[x+1][y+1],min(dp[x+1][y],dp[x][y+1]));
		if(dp[x][y]>=sz) return true;
	}
	return false;
}

void run() {
	scanf("%d%d%d%d",&h,&w,&sz,&nq);
	REP(x,h) REP(y,w) t[x][y]=INT_MAX;
	REP(i,nq) { int x,y,tt; scanf("%d%d%d",&x,&y,&tt); --x,--y; t[x][y]=min(t[x][y],tt); }

	int l=-1,h=TMAX+1; // (l,h]
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(isbroken(m)) h=m; else l=m;
	}
	printf("%d\n",h>TMAX?-1:h);
}

int main() {
	run();
	return 0;
}