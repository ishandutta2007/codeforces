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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int h,w;
char g[100][100];

bool same[100];

void run() {
	scanf("%d%d",&h,&w);
	REP(i,h) REP(j,w) scanf(" %c",&g[i][j]);
	REP(i,h) same[i]=true;
	int ret=0;
	REP(j,w) {
		bool ok=true;
		FOR(i,1,h) if(same[i]&&g[i][j]<g[i-1][j]) { ok=false; break; }
		if(!ok) { ++ret; continue; }
		FOR(i,1,h) if(same[i]&&g[i][j]>g[i-1][j]) same[i]=false;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}