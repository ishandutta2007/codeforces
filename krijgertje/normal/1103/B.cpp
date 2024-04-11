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

bool isgreater(int a,int b) {
	printf("? %d %d\n",b,a); fflush(stdout);
	char res; scanf(" %c",&res); if(res=='e') exit(0); return res=='y';
}

void solve() {
	int fixed=0;
	while(true) {
		if(isgreater(2*fixed+1,fixed)) { fixed=fixed*2+1; continue; }
		int lo=fixed,hi=2*fixed+1;
		while(lo+1<hi) {
			int mi=lo+(hi-lo)/2;
			if(isgreater(mi,fixed)) lo=mi; else hi=mi;
		}
		printf("! %d\n",lo+1); fflush(stdout);
		break;
	}
}

void run() {
	char command[100];
	while(true) {
		scanf("%s",command);
		if(strcmp(command,"end")==0||strcmp(command,"mistake")==0) break;
		assert(strcmp(command,"start")==0);
		solve();
	}
}

int main() {
	run();
	return 0;
}