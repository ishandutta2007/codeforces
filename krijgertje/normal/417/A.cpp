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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int cntmain,cntextra;
int getmain,need;
int have;

void run() {
	scanf("%d%d",&cntmain,&cntextra);
	scanf("%d%d",&getmain,&need); need*=getmain;
	scanf("%d",&have);

	int ret=INT_MAX;
	for(int i=0;;++i) {
		int a=have+i*getmain;
		int j=max(0,need-a);
		int cur=i*cntmain+j*cntextra;
		//printf("\t%d %d -> %d\n",i,j,cur);
		if(cur<ret) ret=cur;
		if(a>need) break;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}