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

int nlight,nbutton;
int x[100];
int y[100];

void run() {
	scanf("%d%d",&nlight,&nbutton);
	REP(i,nbutton) { scanf("%d",&x[i]); --x[i]; }
	
	memset(y,-1,sizeof(y));
	int at=nlight-1; REP(i,nbutton) while(x[i]<=at) y[at--]=x[i];
	REP(i,nlight) { if(i!=0) printf(" "); printf("%d",y[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}