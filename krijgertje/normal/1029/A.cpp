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

const int MAXTLEN=50;

char t[MAXTLEN+1]; int tlen;
int reps;

bool ok(int off) {
	FOR(i,off,tlen) if(t[i]!=t[i-off]) return false;
	return true;
}

void run() {
	scanf("%d%d",&tlen,&reps); scanf("%s",t);

	int off=tlen;
	FOR(i,1,tlen) if(ok(i)) off=min(off,i);
	REP(i,reps-1) { REP(j,off) printf("%c",t[j]); } printf("%s\n",t);
}

int main() {
	run();
	return 0;
}