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

int attack[4],defense[4];

void run() {
	REP(i,4) scanf("%d%d",&attack[i],&defense[i]);
	int ret=-1;
	REP(a1,2) {
		int d1=1-a1;
		int cur=+1;
		FOR(a2,2,4) {
			int d2=5-a2;
			int now;
			if(attack[a1]>defense[d2]&&defense[d1]>attack[a2]) now=+1;
			else if(attack[a2]>defense[d1]&&defense[d2]>attack[a1]) now=-1;
			else now=0;
			if(now<cur) cur=now;
		}
		if(cur>ret) ret=cur;
	}
	printf("%s\n",ret<0?"Team 2":ret>0?"Team 1":"Draw");
}

int main() {
	run();
	return 0;
}