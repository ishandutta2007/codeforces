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

char ans[4][103];
int len[4];
bool great[4];

void run() {
	REP(i,4) scanf("%s",ans[i]);
	REP(i,4) len[i]=strlen(ans[i])-2;
	int ngreat=0;
	REP(i,4) {
		bool isshrt=true; REP(j,4) if(i!=j&&2*len[i]>len[j]) isshrt=false;
		bool islong=true; REP(j,4) if(i!=j&&len[i]<2*len[j]) islong=false;
		great[i]=islong||isshrt;
		if(great[i]) ngreat++;
	}
	if(ngreat==1) { REP(i,4) if(great[i]) printf("%c\n",'A'+i); } else printf("C\n");	
}

int main() {
	run();
	return 0;
}