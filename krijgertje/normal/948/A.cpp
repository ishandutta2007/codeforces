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
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w;
char g[MAXH][MAXW+1];

bool solve() {
	REP(x,h) REP(y,w) if(g[x][y]=='W') {
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k];
			if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='W'||g[nx][ny]=='D') continue;
			if(g[nx][ny]=='S') return false;
			g[nx][ny]='D';
		}
	}
	return true;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%s",g[x]);

	if(!solve()) { printf("No\n"); return; }
	printf("Yes\n"); REP(x,h) printf("%s\n",g[x]);
}

int main() {
	run();
	return 0;
}