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

int n,m;
char hor[20],ver[20];

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) scanf(" %c",&hor[i]);
	REP(i,m) scanf(" %c",&ver[i]);
	bool ok=false;
	if(hor[0]=='>'&&ver[m-1]=='v'&&hor[n-1]=='<'&&ver[0]=='^') ok=true;
	if(hor[0]=='<'&&ver[m-1]=='^'&&hor[n-1]=='>'&&ver[0]=='v') ok=true;
	printf("%s\n",ok?"YES":"NO");
}

int main() {
	run();
	return 0;
}