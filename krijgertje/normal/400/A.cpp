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
#include <cstring>
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

char s[20];
int ans[10],nans;

void run(int casenr) {
	scanf("%s",s);
	nans=0;
	FORE(i,1,12) if(12%i==0) {
		int h=i,w=12/i;
		bool anyok=false;
		REP(y,w) { bool curok=true; REP(x,h) if(s[x*w+y]!='X') curok=false; if(curok) anyok=true; }
		if(anyok) ans[nans++]=i;
	}
	printf("%d",nans); REP(i,nans) printf(" %dx%d",ans[i],12/ans[i]); puts("");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}