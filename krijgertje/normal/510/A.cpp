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

int nrow,ncol;
char g[50][51];

void run() {
	scanf("%d%d",&nrow,&ncol);
	REP(i,nrow) { REP(j,ncol) g[i][j]='.'; g[i][ncol]='\0'; }
	for(int i=0;i<nrow;i+=2) REP(j,ncol) g[i][j]='#';
	for(int i=1;i<nrow;i+=4) g[i][ncol-1]='#';
	for(int i=3;i<nrow;i+=4) g[i][0]='#';
	REP(i,nrow) printf("%s\n",g[i]);
}

int main() {
	run();
	return 0;
}