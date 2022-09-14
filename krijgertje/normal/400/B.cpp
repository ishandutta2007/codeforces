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

int cnt[1001];
char s[1001];

void run(int casenr) {
	int n,m; scanf("%d%d",&n,&m);
	bool ok=true; int ret=0;
	memset(cnt,0,sizeof(cnt));
	REP(i,n) {
		scanf("%s",s);
		int dwarf=-1,candy=-1; REP(j,m) if(s[j]=='G') dwarf=j; else if(s[j]=='S') candy=j;
		if(dwarf==-1||candy==-1||dwarf>candy) { ok=false; continue; }
		int cur=candy-dwarf;
		if(++cnt[cur]==1) ++ret;
	}
	printf("%d\n",ok?ret:-1);
}

int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}