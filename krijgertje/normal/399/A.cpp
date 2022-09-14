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

int npages,at,maxstep;

void run() {
	scanf("%d%d%d",&npages,&at,&maxstep);
	bool first=true;
	FORE(i,at-maxstep,at+maxstep) {
		if(i<1||i>npages) continue;
		if(i==at-maxstep&&i>1) { printf("<<"); first=false; }
		if(!first) printf(" "); if(i==at) printf("("); printf("%d",i); if(i==at) printf(")"); first=false;
		if(i==at+maxstep&&i<npages) printf(" >>");
	}
	puts("");
}


int main() {
	run();
	return 0;
}