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

const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int n;
char g[100][100];

void run() {
	scanf("%d",&n);
	REP(x,n) REP(y,n) scanf(" %c",&g[x][y]);
	bool ok=true;
	REP(x,n) REP(y,n) {
		int cnt=0;
		REP(k,4) { int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=n||ny<0||ny>=n||g[nx][ny]!='o') continue; ++cnt; }
		if(cnt%2!=0) ok=false;
	}
	printf("%s\n",ok?"YES":"NO");
}

int main() {
	run();
	return 0;
}