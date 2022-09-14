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
	string s(n,'?'); REP(i,n) scanf(" %c",&s[i]);
	int firstR=-1,lastR=-1,firstL=-1,lastL=-1; bool anyR=false,anyL=false;
	REP(i,n) if(s[i]=='R') { anyR=true; if(firstR==-1) firstR=i+1; lastR=i+1; }
	REP(i,n) if(s[i]=='L') { anyL=true; if(firstL==-1) firstL=i+1; lastL=i+1; }
	if(anyL&&anyR) {
		assert(lastR+1==firstL);
		printf("%d %d\n",firstR,lastR);
	} else if(anyL) {
		printf("%d %d\n",lastL,firstL-1);
	} else if(anyR) {
		printf("%d %d\n",firstR,lastR+1);
	} else {
		assert(false);
	}

	
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}