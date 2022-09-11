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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int nq;

void run() {
	scanf("%d",&nq);
	int a=0,b=0;
	REP(i,nq) {
		char kind; scanf(" %c",&kind);
		if(kind=='+') { int x,y; scanf("%d%d",&x,&y); if(x<y) swap(x,y); a=max(a,x); b=max(b,y); }
		if(kind=='?') { int x,y; scanf("%d%d",&x,&y); if(x<y) swap(x,y); printf("%s\n",x>=a&&y>=b?"YES":"NO"); }
	}
}

int main() {
	run();
	return 0;
}