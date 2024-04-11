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

char buff[1000001];


void run() {
	int n,d; scanf("%d%d",&n,&d);
	vector<int> x(n); REP(i,n) scanf("%d",&x[i]);
	int ret=0;
	FORSZ(i,1,x) if(x[i]<=x[i-1]) { int cnt=(x[i-1]-x[i])/d+1; ret+=cnt; x[i]+=d*cnt; }
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}