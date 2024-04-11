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

void run(int casenr) {
	int n; scanf("%d",&n);
	vector<int> x(2*n-1); REP(i,2*n-1) scanf("%d",&x[i]);
	int nneg=0,sumabs=0,minabs=abs(x[0]);
	REPSZ(i,x) { if(x[i]<0) ++nneg; sumabs+=abs(x[i]); if(abs(x[i])<minabs) minabs=abs(x[i]); }
	int ret;
	if(n%2==1) ret=sumabs;
	else if(nneg%2==0) ret=sumabs;
	else ret=sumabs-2*minabs;
	printf("%d\n",ret);
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}