#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
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


void run(int casenr) {
	int n,sx,sy,ex,ey; scanf("%d%d%d%d%d",&n,&sx,&sy,&ex,&ey);
	string s(n,'?'); REP(i,n) scanf(" %c",&s[i]);
	int x=sx,y=sy;
	REP(i,n) {
		if(s[i]=='N'&&ey>y) ++y;
		if(s[i]=='S'&&ey<y) --y;
		if(s[i]=='E'&&ex>x) ++x;
		if(s[i]=='W'&&ex<x) --x;
		if(x==ex&&y==ey) { printf("%d\n",i+1); return; }
	}
	printf("-1\n");
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}