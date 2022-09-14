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

int n,na,nb;
bool a[100],b[100];
int ans[100];

void run() {
	scanf("%d%d%d",&n,&na,&nb);
	memset(a,false,sizeof(a)); memset(b,false,sizeof(b));
	REP(i,na) { int x; scanf("%d",&x); --x; a[x]=true; }
	REP(i,nb) { int x; scanf("%d",&x); --x; b[x]=true; }
	REP(i,n) if(a[i]) ans[i]=1; else if(b[i]) ans[i]=2; else assert(false);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}