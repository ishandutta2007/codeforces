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

void run(int casenr) {
	scanf("%d",&n);
	if(n%2==0) { printf("-1\n"); return; }
	REP(i,n) { if(i!=0) printf(" "); printf("%d",i); } puts("");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",i); } puts("");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",2*i%n); } puts("");
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}