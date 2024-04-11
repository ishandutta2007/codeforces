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

int n;
int a[100000];

void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	for(int v=30;v>=0;--v) {
		bool any=false; int cur=0,cnt=0;
		REP(i,n) if((a[i]&(1<<v))!=0) if(!any) any=true,cur=a[i],++cnt; else cur&=a[i],++cnt;
		if(any&&cur!=0&&cur%(1<<v)==0) {
			printf("%d\n",cnt);
			bool first=true; REP(i,n) if((a[i]&(1<<v))!=0) { if(first) first=false; else printf(" "); printf("%d",a[i]); } puts(""); return;
		}
	}
	assert(false);
}

int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}